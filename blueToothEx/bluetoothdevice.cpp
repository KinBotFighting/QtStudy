#include "bluetoothdevice.h"
#include "ui_bluetoothdevice.h"
#include <QDebug>
#include "customframe.h"
#include <QDialog>
#include <QMetaEnum>
#include <QLineEdit>

QBluetoothUuid targetServiceUuid111(QString("4fafc201-1fb5-459e-8fcc-c5c9c331914b"));

#define labelDone       "background-color: green;"
#define labelLoading    "background-color: yellow;"

//#define labelDone       "color: green;"
//#define labelLoading    "color: yellow;"

BlueToothDevice::BlueToothDevice(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::BlueToothDevice)
{
    ui->setupUi(this);

    //1.初始化UI
    initUi();


    //2.蓝牙部分 设备初始化
    initBluetooth();


}

BlueToothDevice::~BlueToothDevice()
{
    delete ui;
    qDeleteAll(devices);
    qDeleteAll(m_characteristics);
    qDeleteAll(m_services);
    if (discoveryAgent)
    {
        delete discoveryAgent;
    }
    if (controller)
    {
        delete controller;
    }

}

///
/// \brief BlueToothDevice::initUi 初始化UI
///
void BlueToothDevice::initUi()
{
    //1.布局部分
    // 创建主布局
    QVBoxLayout *mainLayout = new QVBoxLayout(this);

    // 创建搜索按钮
    searchButton = new QPushButton("Search", this);
    mainLayout->addWidget(searchButton);
    connect(searchButton, &QPushButton::clicked, this, &BlueToothDevice::startSearch);

    // 创建用于显示搜索设备状态
    DeviceDisplayLabel = new QLabel("DeviceStatus: ", this);
    DeviceDisplayLabel->setStyleSheet(labelLoading);
    mainLayout->addWidget(DeviceDisplayLabel);

    // 创建滚动区域
    scrollArea = new QScrollArea(this);
    scrollArea->setWidgetResizable(true);

    // 创建设备容器
    deviceContainer = new QWidget(scrollArea);
    deviceLayout = new QVBoxLayout(deviceContainer);
    scrollArea->setWidget(deviceContainer);

    // 将滚动区域添加到主布局，并设置拉伸因子使其铺满窗口
    mainLayout->addWidget(scrollArea, 1);

    //用于显示服务搜索状态
    serviceStatusDisplayLabel = new QLabel("ServiceStatus: ", this);
    serviceStatusDisplayLabel->setStyleSheet(labelLoading);
    mainLayout->addWidget(serviceStatusDisplayLabel);

    // 创建服务滚动区域
    scrollAreaService = new QScrollArea(this);
    scrollAreaService->setWidgetResizable(true);
    // 创建服务容器
    serviceContainer = new QWidget(scrollAreaService);
    serviceLayout = new QVBoxLayout(serviceContainer);
    scrollAreaService->setWidget(serviceContainer);

    // 将滚动区域添加到主布局，并设置拉伸因子使其铺满窗口
    mainLayout->addWidget(scrollAreaService, 1);

    //用于显示特征搜索状态
    characteristicDisplayLabel = new QLabel("CharacteristicStatus:", this);
    characteristicDisplayLabel->setStyleSheet(labelLoading);
    mainLayout->addWidget(characteristicDisplayLabel);

    // 创建特征滚动区域
    scrollAreaCharacteristic = new QScrollArea(this);
    scrollAreaCharacteristic->setWidgetResizable(true);
    // 创建特征容器
    characteristicContainer = new QWidget(scrollAreaCharacteristic);
    characteristicLayout = new QVBoxLayout(characteristicContainer);
    scrollAreaCharacteristic->setWidget(characteristicContainer);

    // 将滚动区域添加到主布局，并设置拉伸因子使其铺满窗口
    mainLayout->addWidget(scrollAreaCharacteristic, 1);
}

///
/// \brief BlueToothDevice::initBluetooth 初始化蓝牙
///
void BlueToothDevice::initBluetooth()
{
    //    localDevice = new QBluetoothLocalDevice();
    //    localDevice->powerOn(); //开启本地蓝牙设备  此处只有开启之后才能搜索到附近的设备
    //    qDebug() << "adapterAddress:" << localDevice->address();
    discoveryAgent = new QBluetoothDeviceDiscoveryAgent();
    discoveryAgent->setLowEnergyDiscoveryTimeout(5000); // 添加这行设置超时时间
    //发现设备
    connect(discoveryAgent, &QBluetoothDeviceDiscoveryAgent::deviceDiscovered,
            this, &BlueToothDevice::handleDeviceDiscovered);
    //错误信息
    connect(discoveryAgent, QOverload<QBluetoothDeviceDiscoveryAgent::Error>::of(&QBluetoothDeviceDiscoveryAgent::error),
            this, &BlueToothDevice::deviceScanError);
    //搜查完毕
    connect(discoveryAgent, &QBluetoothDeviceDiscoveryAgent::finished,
            this, &BlueToothDevice::handleDiscoveryFinished);
}

///
/// \brief BlueToothDevice::isRandomAddress
///
bool BlueToothDevice::isRandomAddress() const
{
    return randomAddress;
}

///
/// \brief BlueToothDevice::cleanDeviceLayout 清除设备数据UI
///
void BlueToothDevice::cleanDeviceLayout()
{
    if(deviceLayout)
    {
        while (deviceLayout->count() > 0)
        {
            QLayoutItem *item = deviceLayout->takeAt(0); // 移除第一项
            if (item)
            {
                if (item->widget())
                {
                    // 如果该项包含一个窗口部件，则删除该窗口部件
                    delete item->widget();
                }
                // 删除布局项
                delete item;
            }
        }
    }
}

///
/// \brief BlueToothDevice::addDeviceLayout 添加设备框数据UI
///
void BlueToothDevice::addDeviceLayout(const QBluetoothDeviceInfo &deviceInfo)
{
    //检查是什么蓝牙
    QString codeConfig_str;
    switch (deviceInfo.coreConfigurations())
    {
        case deviceInfo.UnknownCoreConfiguration:
            codeConfig_str = "UnknownCoreConfiguration";
            break;
        case deviceInfo.BaseRateCoreConfiguration:
            codeConfig_str = "BaseRateCoreConfiguration";
            break;
        case deviceInfo.BaseRateAndLowEnergyCoreConfiguration:
            codeConfig_str = "BaseRateAndLowEnergyCoreConfiguration";
            break;
        case deviceInfo.LowEnergyCoreConfiguration:
            codeConfig_str = "LowEnergyCoreConfiguration";
            break;
        default:
            break;
    }

    // 创建一个QFrame作为蓝色框
    CustomFrame *deviceFrame = new CustomFrame();
    deviceFrame->setStyleSheet("background-color: lightblue;");
    QVBoxLayout *layout = new QVBoxLayout(deviceFrame);

    // 添加设备名称标签
    QLabel *nameLabel = new QLabel(deviceInfo.name());
    nameLabel->setAlignment(Qt::AlignCenter);
    layout->addWidget(nameLabel);

    // 添加设备蓝牙属性标签
    QLabel *codeConfigLabel = new QLabel(codeConfig_str);
    codeConfigLabel->setAlignment(Qt::AlignCenter);
    layout->addWidget(codeConfigLabel);

    // 添加设备地址标签
    QLabel *addressLabel = new QLabel(deviceInfo.address().toString());
    addressLabel->setAlignment(Qt::AlignCenter);
    layout->addWidget(addressLabel);

    // 将设备框添加到设备容器的布局中
    deviceLayout->addWidget(deviceFrame);

    QString address = deviceInfo.address().toString();

    // 连接自定义信号与槽
    connect(deviceFrame, &CustomFrame::clicked, [this, address]()
    {
        scanServices(address);
    });

}

///
/// \brief BlueToothDevice::cleanCharacteristicLayout 清除特征数据UI
///
void BlueToothDevice::cleanCharacteristicLayout()
{
    if(characteristicLayout)
    {
        while (characteristicLayout->count() > 0)
        {
            QLayoutItem *item = characteristicLayout->takeAt(0); // 移除第一项
            if (item)
            {
                if (item->widget())
                {
                    // 如果该项包含一个窗口部件，则删除该窗口部件
                    delete item->widget();
                }
                // 删除布局项
                delete item;
            }
        }
    }
}

///
/// \brief BlueToothDevice::addCharacteristicUI 添加特征框数据UI
///
void BlueToothDevice::addCharacteristicUI(QLowEnergyService *service)
{
    for (auto s : qAsConst(m_characteristics))
    {
        auto characteristicsInfo = qobject_cast<CharacteristicInfo*>(s);
        if (!characteristicsInfo)
            continue;

        // 创建一个QFrame作为蓝色框
        CustomFrame *deviceFrame = new CustomFrame();
        deviceFrame->setStyleSheet("background-color: lightyellow;");
        QVBoxLayout *mainLayout = new QVBoxLayout(deviceFrame);


        // 添加特征名称标签
        QLabel *characteristicLabel = new QLabel("characteristic uuid:" + characteristicsInfo->getUuid());
        characteristicLabel->setAlignment(Qt::AlignCenter);
        mainLayout->addWidget(characteristicLabel);

        //添加属性标签
        QLabel *permissionLabel = new QLabel("Permission:" + characteristicsInfo->getPermission());
        permissionLabel->setAlignment(Qt::AlignCenter);
        mainLayout->addWidget(permissionLabel);


        //如果能读取
        if (characteristicsInfo->getPermission().contains("Read"))
        {
            //添加一次读取
            QHBoxLayout *hLayout = new QHBoxLayout(deviceFrame);
            QLabel *readLabel = new QLabel("Read:");
            QLineEdit *readLineEdit = new QLineEdit();
            QPushButton *readBtn = new QPushButton("read");

            hLayout->addWidget(readLabel);
            hLayout->addWidget(readLineEdit);
            hLayout->addWidget(readBtn);
            mainLayout->addLayout(hLayout);

            // 连接特征读取完成的信号
            auto readConnection = QObject::connect(service, &QLowEnergyService::characteristicRead,
                                                   [readLineEdit](const QLowEnergyCharacteristic & characteristic, const QByteArray & value)
            {
                readLineEdit->setText(value);
                qDebug() << "Read characteristic:" << characteristic.uuid().toString() << "Value:" << value;
            });

            // 发起读取请求
            QLowEnergyCharacteristic ch = characteristicsInfo->getCharacteristic();
            //绑定按钮
            connect(readBtn, &QPushButton::clicked, [service, ch]()
            {
                if(service)
                    service->readCharacteristic(ch);
            });

            //当设备框架被销毁时，断开信号槽连接，避免第二次点击readLineEdit->setText(value);错误
            connect(deviceFrame, &QObject::destroyed, [readConnection]()
            {
                QObject::disconnect(readConnection);
            });

        }
        //如果能写入
        if (characteristicsInfo->getPermission().contains("Write"))
        {
            //添加一次读取
            QHBoxLayout *hLayout = new QHBoxLayout(deviceFrame);
            QLabel *writeLabel = new QLabel("Write:");
            QLineEdit *writeLineEdit = new QLineEdit();
            QPushButton *writeBtn = new QPushButton("Write");

            hLayout->addWidget(writeLabel);
            hLayout->addWidget(writeLineEdit);
            hLayout->addWidget(writeBtn);
            mainLayout->addLayout(hLayout);

            // 连接特征写入完成的信号
            auto writeConnection = QObject::connect(service, &QLowEnergyService::characteristicWritten,
                                                    [](const QLowEnergyCharacteristic & characteristic, const QByteArray & newValue)
            {
                qDebug() << "Written characteristic:" << characteristic.uuid().toString() << "New value:" << newValue;
            });

            // 发起写入请求
            QLowEnergyCharacteristic ch = characteristicsInfo->getCharacteristic();
            //绑定按钮
            connect(writeBtn, &QPushButton::clicked, [writeLineEdit, service, ch]()
            {

                // 准备要写入的数据
                QByteArray data = writeLineEdit->text().toUtf8();
                if(service)
                    // 发起写入请求
                    service->writeCharacteristic(ch, data);
            });

            // 当设备框架被销毁时，断开信号槽连接
            connect(deviceFrame, &QObject::destroyed, [writeConnection]()
            {
                QObject::disconnect(writeConnection);
            });
        }


        // 将特征框添加到设备容器的布局中
        characteristicLayout->addWidget(deviceFrame);
    }
}

///
/// \brief BlueToothDevice::cleanServiceLayout 清除服务数据UI
///
void BlueToothDevice::cleanServiceLayout()
{
    if(serviceLayout)
    {
        while (serviceLayout->count() > 0)
        {
            QLayoutItem *item = serviceLayout->takeAt(0); // 移除第一项
            if (item)
            {
                if (item->widget())
                {
                    // 如果该项包含一个窗口部件，则删除该窗口部件
                    delete item->widget();
                }
                // 删除布局项
                delete item;
            }
        }
    }
}

///
/// \brief BlueToothDevice::addServiceUI 添加服务框数据UI
/// \param uuid
///
void BlueToothDevice::addServiceUI(const QBluetoothUuid &uuid)
{
    // 创建一个QFrame作为蓝色框
    CustomFrame *deviceFrame = new CustomFrame();
    deviceFrame->setStyleSheet("background-color: lightgreen;");
    QVBoxLayout *layout = new QVBoxLayout(deviceFrame);


    // 添加服务名称标签
    QLabel *uuidLabel = new QLabel("characteristic uuid:" + uuid.toString());
    uuidLabel->setAlignment(Qt::AlignCenter);
    layout->addWidget(uuidLabel);

    // 将设备框添加到设备容器的布局中
    serviceLayout->addWidget(deviceFrame);

    // 连接自定义信号与槽
    connect(deviceFrame, &CustomFrame::clicked, [this, uuid]()
    {
        bool success = false;
        quint16 result16 = uuid.toUInt16(&success);
        if(success)
        {
            connectToService(QStringLiteral("0x") + QString::number(result16, 16));
            return;
        }

        quint32 result32 = uuid.toUInt32(&success);
        if (success)
        {
            connectToService(QStringLiteral("0x") + QString::number(result32, 16));
            return;
        }

        connectToService(uuid.toString().remove(QLatin1Char('{')).remove(QLatin1Char('}')));

    });

}

///
/// \brief BlueToothDevice::connectToService 点击服务 搜索特征
/// \param uuid
///
void BlueToothDevice::connectToService(const QString &uuid)
{
    characteristicDisplayLabel->setText("CharacteristicStatus: Loading...");
    qDebug() << "clicked uuid:" << uuid;
    QLowEnergyService *service = nullptr;
    for (auto s : qAsConst(m_services))
    {
        auto serviceInfo = qobject_cast<ServiceInfo*>(s);
        if (!serviceInfo)
            continue;

        if (serviceInfo->getUuid() == uuid)
        {

            service = serviceInfo->service();
            break;
        }
    }

    if (!service)
        return;

    qDeleteAll(m_characteristics);
    m_characteristics.clear();

    if (service->state() == QLowEnergyService::DiscoveryRequired)
    {
        connect(service, &QLowEnergyService::stateChanged,
                this, &BlueToothDevice::serviceDetailsDiscovered);
        service->discoverDetails();
        return;
    }

    //discovery already done
    const QList<QLowEnergyCharacteristic> chars = service->characteristics();
    cleanCharacteristicLayout();    //清除特征布局
    for (const QLowEnergyCharacteristic &ch : chars)
    {
        auto cInfo = new CharacteristicInfo(ch);
        m_characteristics.append(cInfo);
        qDebug() << "discovery already done service->characteristics(): " << ch.name() << ch.uuid();

    }
    addCharacteristicUI(service);

    characteristicDisplayLabel->setText("CharacteristicStatus: Done.");
}

///
/// \brief BlueToothDevice::startSearch 点击按钮开始搜索
///
void BlueToothDevice::startSearch()
{
    DeviceDisplayLabel->setText("DeviceStatus: Loading...");
    //清除原来存储的设备
    qDeleteAll(devices);
    devices.clear();

    //此处只针对低功耗
    discoveryAgent->start(QBluetoothDeviceDiscoveryAgent::LowEnergyMethod);

    if(discoveryAgent->isActive())
    {
        m_deviceScanState = true;
    }

}

///
/// \brief BlueToothDevice::handleDeviceDiscovered 点击设备搜索，当出现一个的时候执行
/// \param deviceInfo
///
void BlueToothDevice::handleDeviceDiscovered(const QBluetoothDeviceInfo &deviceInfo)
{
    addDeviceLayout(deviceInfo);
}

///
/// \brief BlueToothDevice::deviceScanError 点击设备搜索出错
/// \param error
///
void BlueToothDevice::deviceScanError(QBluetoothDeviceDiscoveryAgent::Error error)
{
    if (error == QBluetoothDeviceDiscoveryAgent::PoweredOffError)
        qDebug("The Bluetooth adaptor is powered off, power it on before doing discovery.");
    else if (error == QBluetoothDeviceDiscoveryAgent::InputOutputError)
        qDebug("Writing or reading from the device resulted in an error.");
    else
    {
        static QMetaEnum qme = discoveryAgent->metaObject()->enumerator(
                                   discoveryAgent->metaObject()->indexOfEnumerator("Error"));
        qDebug() << "Error: " + QLatin1String(qme.valueToKey(error));
//        qDebug("Error: " + QLatin1String(qme.valueToKey(error)));
    }

    m_deviceScanState = false;
}

///
/// \brief BlueToothDevice::handleDiscoveryFinished 设备全部搜索完毕
///
void BlueToothDevice::handleDiscoveryFinished()
{
    qDebug() << "BlueToothDevice::handleDiscoveryFinished()";
    const QList<QBluetoothDeviceInfo> foundDevices = discoveryAgent->discoveredDevices();
    for(auto nextDevice : foundDevices)
        if(nextDevice.coreConfigurations() & QBluetoothDeviceInfo::LowEnergyCoreConfiguration)
            devices.append(new DeviceInfo(nextDevice));

    m_deviceScanState = false;

    if(devices.isEmpty())
        qDebug() << "Scan Done! No Low Energy devices found...";
    else
        qDebug() << "Scan Done!";

    DeviceDisplayLabel->setText("DeviceStatus: Done.");
    DeviceDisplayLabel->setStyleSheet(labelDone);

}

///
/// \brief BlueToothDevice::scanServices    点击设备 搜索服务
/// \param address
///
void BlueToothDevice::scanServices(const QString &address)
{
    for(auto d : qAsConst(devices))
    {
        if(auto device = qobject_cast<DeviceInfo*>(d))
        {
            if(device->getAddress() == address)
            {
                currentDevice.setDevice(device->getDevice());
                break;
            }
        }
    }

    if(!currentDevice.getDevice().isValid())
    {
        qDebug() << "not a valid device";
        return;
    }

    //删除存在的特征和服务
    qDeleteAll(m_characteristics);
    m_characteristics.clear();
    qDeleteAll(m_services);
    m_services.clear();

    //删除存在的服务和特征UI
    cleanCharacteristicLayout();
    cleanServiceLayout();

    //如果已经存在控制器,且地址是当前地址则断开
    if(controller && m_previousAddress != currentDevice.getAddress())
    {
        controller->disconnectFromDevice();
        delete controller;
        controller = nullptr;
    }

    if(!controller)
    {
        // Connecting signals and slots for connecting to LE services.
        controller = QLowEnergyController::createCentral(currentDevice.getDevice());
        connect(controller, &QLowEnergyController::connected,
                this, &BlueToothDevice::deviceConnected);
        connect(controller, QOverload<QLowEnergyController::Error>::of(&QLowEnergyController::error),
                this, &BlueToothDevice::errorReceived);
        connect(controller, &QLowEnergyController::disconnected,
                this, &BlueToothDevice::deviceDisconnected);
        connect(controller, &QLowEnergyController::serviceDiscovered,
                this, &BlueToothDevice::addLowEnergyService);
        connect(controller, &QLowEnergyController::discoveryFinished,
                this, &BlueToothDevice::serviceScanDone);
    }

    if (isRandomAddress())
        controller->setRemoteAddressType(QLowEnergyController::RandomAddress);
    else
        controller->setRemoteAddressType(QLowEnergyController::PublicAddress);
    //开启连接
    controller->connectToDevice();

    m_previousAddress = currentDevice.getAddress();
}

///
/// \brief BlueToothDevice::addLowEnergyService 服务被发现的时候添加视图
/// \param uuid
///
void BlueToothDevice::addLowEnergyService(const QBluetoothUuid &uuid)
{
    serviceStatusDisplayLabel->setText("ServiceStatus: Loading....");
    qDebug() << "addLowEnergyService(const QBluetoothUuid &uuid) : " << uuid.toString();
    QLowEnergyService *service = controller->createServiceObject(uuid);
    if(!service)
    {
        qDebug() << "Cannot create service for uuid";
        return;
    }

    auto serv = new ServiceInfo(service);
    m_services.append(serv);

    //添加在视图
    addServiceUI(uuid);
}


///
/// \brief BlueToothDevice::deviceConnected 点击设备连接时候触发
///
void BlueToothDevice::deviceConnected()
{
    serviceStatusDisplayLabel->setText("ServiceStatus: Loading....");
    qDebug() << "Connected to the device. Starting service discovery...";
    connected = true;
    // 开始发现服务
    controller->discoverServices();
}

///
/// \brief BlueToothDevice::errorReceived 错误接收
///
void BlueToothDevice::errorReceived(QLowEnergyController::Error)
{
    qDebug() << "errorReceived(QLowEnergyController::Error)";
    qDebug() << "Error: " << controller->errorString();
}

///
/// \brief BlueToothDevice::serviceScanDone 设备搜索服务完毕
///
void BlueToothDevice::serviceScanDone()
{
    qDebug() << "serviceScanDone";
    serviceStatusDisplayLabel->setText("ServiceStatus: Done.");
    serviceStatusDisplayLabel->setStyleSheet(labelDone);
}

///
/// \brief BlueToothDevice::deviceDisconnected 设备断开的时候触发
///
void BlueToothDevice::deviceDisconnected()
{
    qDebug() << "Disconnect from device";
}

///
/// \brief BlueToothDevice::serviceDetailsDiscovered  服务状态改变的时候 详细服务数据
/// \param newState
///
void BlueToothDevice::serviceDetailsDiscovered(QLowEnergyService::ServiceState newState)
{
    qDebug() << "serviceDetailsDiscovered(QLowEnergyService::ServiceState newState)";
    if (newState != QLowEnergyService::ServiceDiscovered)
    {
        // do not hang in "Scanning for characteristics" mode forever
        // in case the service discovery failed
        // We have to queue the signal up to give UI time to even enter
        // the above mode
        if (newState != QLowEnergyService::DiscoveringServices)
        {
            QMetaObject::invokeMethod(this, "characteristicsUpdated",
                                      Qt::QueuedConnection);
        }
        return;
    }

    auto service = qobject_cast<QLowEnergyService*>(sender());
    if (!service)
        return;



    //! [les-chars]
    const QList<QLowEnergyCharacteristic> chars = service->characteristics();
    cleanCharacteristicLayout();    //清除布局
    for (const QLowEnergyCharacteristic &ch : chars)
    {
        auto cInfo = new CharacteristicInfo(ch);
        m_characteristics.append(cInfo);

    }
    //进行数据的修饰
    addCharacteristicUI(service);

    characteristicDisplayLabel->setText("CharacteristicStatus: Done.");
    characteristicDisplayLabel->setStyleSheet(labelDone);
}


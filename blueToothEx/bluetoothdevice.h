#ifndef BLUETOOTHDEVICE_H
#define BLUETOOTHDEVICE_H

#include <QWidget>
#include <QBluetoothDeviceDiscoveryAgent>
#include <QBluetoothDeviceInfo>
#include <QPushButton>
#include <QVBoxLayout>
#include <QPushButton>
#include <QScrollArea>
#include <QFrame>
#include <QLabel>
#include <QSet>
#include <QBluetoothAddress>
#include <QMap>
#include <QLowEnergyController>
#include <QBluetoothLocalDevice>
#include <QTimer>
#include "deviceinfo.h" //存储设备信息
#include "serviceinfo.h"    //存储服务信息
#include "characteristicinfo.h" //存储特征信息

namespace Ui
{
    class BlueToothDevice;
}

// 为 QBluetoothAddress 提供 qHash 重载
inline uint qHash(const QBluetoothAddress &key, uint seed = 0) noexcept
{
    return qHash(key.toUInt64(), seed);
}

class BlueToothDevice : public QWidget
{
    Q_OBJECT

public:
    explicit BlueToothDevice(QWidget *parent = nullptr);
    ~BlueToothDevice();

    void initUi();
    void initBluetooth();
    bool isRandomAddress() const;

private:
    void cleanDeviceLayout();
    void addDeviceLayout(const QBluetoothDeviceInfo &deviceInfo);
    void cleanCharacteristicLayout();
    void addCharacteristicUI(QLowEnergyService *service);
    void cleanServiceLayout();
    void addServiceUI(const QBluetoothUuid &uuid);

public slots:
    void connectToService(const QString &uuid);

private slots:
    //点击搜索
    void startSearch();

    //QBluetoothDeviceDiscoveryAgent related
    void handleDeviceDiscovered(const QBluetoothDeviceInfo &deviceInfo);
    void deviceScanError(QBluetoothDeviceDiscoveryAgent::Error error);
    void handleDiscoveryFinished();

    //点击设备
    void scanServices(const QString &address);

    //QLowEnergyController realted
    void addLowEnergyService(const QBluetoothUuid &uuid);
    void deviceConnected();
    void errorReceived(QLowEnergyController::Error);
    void serviceScanDone();
    void deviceDisconnected();

    // QLowEnergyService related
    void serviceDetailsDiscovered(QLowEnergyService::ServiceState newState);

private:
    Ui::BlueToothDevice* ui;

    bool m_deviceScanState = false;
    bool connected = false;
    bool randomAddress = false;

    QString m_previousAddress;

    QList<QObject*> devices;
    QList<QObject*> m_characteristics;
    QList<QObject*> m_services;
    DeviceInfo currentDevice;
    ServiceInfo currentServiceInfo;



    //蓝牙部分
//    QBluetoothLocalDevice* localDevice; //本地设备
    QBluetoothDeviceDiscoveryAgent* discoveryAgent = nullptr;
    QLowEnergyController* controller = nullptr;

    //ui部分
    QPushButton* searchButton;
    QScrollArea* scrollArea;
    QScrollArea* scrollAreaService;
    QScrollArea* scrollAreaCharacteristic;
    QWidget* deviceContainer;
    QWidget* serviceContainer;
    QWidget* characteristicContainer;
    QVBoxLayout* deviceLayout;
    QVBoxLayout* serviceLayout;
    QVBoxLayout* characteristicLayout;

    QLabel* DeviceDisplayLabel; // 用于显示服务查找状态
    QLabel* serviceStatusDisplayLabel; // 用于显示服务连接状态
    QLabel* characteristicDisplayLabel; // 用于显示特征连接状态

};

#endif // BLUETOOTHDEVICE_H

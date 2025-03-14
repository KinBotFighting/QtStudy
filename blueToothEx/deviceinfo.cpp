#include "deviceinfo.h"
#include <qbluetoothuuid.h>

DeviceInfo::DeviceInfo(const QBluetoothDeviceInfo &d)
{
    device = d;
}

QString DeviceInfo::getAddress() const
{
    return device.address().toString();
}

QString DeviceInfo::getName() const
{
    return device.name();
}

QBluetoothDeviceInfo DeviceInfo::getDevice()
{
    return device;
}

void DeviceInfo::setDevice(const QBluetoothDeviceInfo &dev)
{
    device = QBluetoothDeviceInfo(dev);
    Q_EMIT deviceChanged();
}

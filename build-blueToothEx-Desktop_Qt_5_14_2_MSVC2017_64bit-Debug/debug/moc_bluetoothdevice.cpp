/****************************************************************************
** Meta object code from reading C++ file 'bluetoothdevice.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.14.2)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include <memory>
#include "../../blueToothEx/bluetoothdevice.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'bluetoothdevice.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.14.2. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_BlueToothDevice_t {
    QByteArrayData data[24];
    char stringdata0[405];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_BlueToothDevice_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_BlueToothDevice_t qt_meta_stringdata_BlueToothDevice = {
    {
QT_MOC_LITERAL(0, 0, 15), // "BlueToothDevice"
QT_MOC_LITERAL(1, 16, 16), // "connectToService"
QT_MOC_LITERAL(2, 33, 0), // ""
QT_MOC_LITERAL(3, 34, 4), // "uuid"
QT_MOC_LITERAL(4, 39, 11), // "startSearch"
QT_MOC_LITERAL(5, 51, 22), // "handleDeviceDiscovered"
QT_MOC_LITERAL(6, 74, 20), // "QBluetoothDeviceInfo"
QT_MOC_LITERAL(7, 95, 10), // "deviceInfo"
QT_MOC_LITERAL(8, 106, 15), // "deviceScanError"
QT_MOC_LITERAL(9, 122, 37), // "QBluetoothDeviceDiscoveryAgen..."
QT_MOC_LITERAL(10, 160, 5), // "error"
QT_MOC_LITERAL(11, 166, 23), // "handleDiscoveryFinished"
QT_MOC_LITERAL(12, 190, 12), // "scanServices"
QT_MOC_LITERAL(13, 203, 7), // "address"
QT_MOC_LITERAL(14, 211, 19), // "addLowEnergyService"
QT_MOC_LITERAL(15, 231, 14), // "QBluetoothUuid"
QT_MOC_LITERAL(16, 246, 15), // "deviceConnected"
QT_MOC_LITERAL(17, 262, 13), // "errorReceived"
QT_MOC_LITERAL(18, 276, 27), // "QLowEnergyController::Error"
QT_MOC_LITERAL(19, 304, 15), // "serviceScanDone"
QT_MOC_LITERAL(20, 320, 18), // "deviceDisconnected"
QT_MOC_LITERAL(21, 339, 24), // "serviceDetailsDiscovered"
QT_MOC_LITERAL(22, 364, 31), // "QLowEnergyService::ServiceState"
QT_MOC_LITERAL(23, 396, 8) // "newState"

    },
    "BlueToothDevice\0connectToService\0\0"
    "uuid\0startSearch\0handleDeviceDiscovered\0"
    "QBluetoothDeviceInfo\0deviceInfo\0"
    "deviceScanError\0QBluetoothDeviceDiscoveryAgent::Error\0"
    "error\0handleDiscoveryFinished\0"
    "scanServices\0address\0addLowEnergyService\0"
    "QBluetoothUuid\0deviceConnected\0"
    "errorReceived\0QLowEnergyController::Error\0"
    "serviceScanDone\0deviceDisconnected\0"
    "serviceDetailsDiscovered\0"
    "QLowEnergyService::ServiceState\0"
    "newState"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_BlueToothDevice[] = {

 // content:
       8,       // revision
       0,       // classname
       0,    0, // classinfo
      12,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: name, argc, parameters, tag, flags
       1,    1,   74,    2, 0x0a /* Public */,
       4,    0,   77,    2, 0x08 /* Private */,
       5,    1,   78,    2, 0x08 /* Private */,
       8,    1,   81,    2, 0x08 /* Private */,
      11,    0,   84,    2, 0x08 /* Private */,
      12,    1,   85,    2, 0x08 /* Private */,
      14,    1,   88,    2, 0x08 /* Private */,
      16,    0,   91,    2, 0x08 /* Private */,
      17,    1,   92,    2, 0x08 /* Private */,
      19,    0,   95,    2, 0x08 /* Private */,
      20,    0,   96,    2, 0x08 /* Private */,
      21,    1,   97,    2, 0x08 /* Private */,

 // slots: parameters
    QMetaType::Void, QMetaType::QString,    3,
    QMetaType::Void,
    QMetaType::Void, 0x80000000 | 6,    7,
    QMetaType::Void, 0x80000000 | 9,   10,
    QMetaType::Void,
    QMetaType::Void, QMetaType::QString,   13,
    QMetaType::Void, 0x80000000 | 15,    3,
    QMetaType::Void,
    QMetaType::Void, 0x80000000 | 18,    2,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, 0x80000000 | 22,   23,

       0        // eod
};

void BlueToothDevice::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<BlueToothDevice *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->connectToService((*reinterpret_cast< const QString(*)>(_a[1]))); break;
        case 1: _t->startSearch(); break;
        case 2: _t->handleDeviceDiscovered((*reinterpret_cast< const QBluetoothDeviceInfo(*)>(_a[1]))); break;
        case 3: _t->deviceScanError((*reinterpret_cast< QBluetoothDeviceDiscoveryAgent::Error(*)>(_a[1]))); break;
        case 4: _t->handleDiscoveryFinished(); break;
        case 5: _t->scanServices((*reinterpret_cast< const QString(*)>(_a[1]))); break;
        case 6: _t->addLowEnergyService((*reinterpret_cast< const QBluetoothUuid(*)>(_a[1]))); break;
        case 7: _t->deviceConnected(); break;
        case 8: _t->errorReceived((*reinterpret_cast< QLowEnergyController::Error(*)>(_a[1]))); break;
        case 9: _t->serviceScanDone(); break;
        case 10: _t->deviceDisconnected(); break;
        case 11: _t->serviceDetailsDiscovered((*reinterpret_cast< QLowEnergyService::ServiceState(*)>(_a[1]))); break;
        default: ;
        }
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        switch (_id) {
        default: *reinterpret_cast<int*>(_a[0]) = -1; break;
        case 2:
            switch (*reinterpret_cast<int*>(_a[1])) {
            default: *reinterpret_cast<int*>(_a[0]) = -1; break;
            case 0:
                *reinterpret_cast<int*>(_a[0]) = qRegisterMetaType< QBluetoothDeviceInfo >(); break;
            }
            break;
        case 6:
            switch (*reinterpret_cast<int*>(_a[1])) {
            default: *reinterpret_cast<int*>(_a[0]) = -1; break;
            case 0:
                *reinterpret_cast<int*>(_a[0]) = qRegisterMetaType< QBluetoothUuid >(); break;
            }
            break;
        case 8:
            switch (*reinterpret_cast<int*>(_a[1])) {
            default: *reinterpret_cast<int*>(_a[0]) = -1; break;
            case 0:
                *reinterpret_cast<int*>(_a[0]) = qRegisterMetaType< QLowEnergyController::Error >(); break;
            }
            break;
        case 11:
            switch (*reinterpret_cast<int*>(_a[1])) {
            default: *reinterpret_cast<int*>(_a[0]) = -1; break;
            case 0:
                *reinterpret_cast<int*>(_a[0]) = qRegisterMetaType< QLowEnergyService::ServiceState >(); break;
            }
            break;
        }
    }
}

QT_INIT_METAOBJECT const QMetaObject BlueToothDevice::staticMetaObject = { {
    QMetaObject::SuperData::link<QWidget::staticMetaObject>(),
    qt_meta_stringdata_BlueToothDevice.data,
    qt_meta_data_BlueToothDevice,
    qt_static_metacall,
    nullptr,
    nullptr
} };


const QMetaObject *BlueToothDevice::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *BlueToothDevice::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_BlueToothDevice.stringdata0))
        return static_cast<void*>(this);
    return QWidget::qt_metacast(_clname);
}

int BlueToothDevice::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QWidget::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 12)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 12;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 12)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 12;
    }
    return _id;
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE

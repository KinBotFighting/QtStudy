/********************************************************************************
** Form generated from reading UI file 'bluetoothdevice.ui'
**
** Created by: Qt User Interface Compiler version 5.14.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_BLUETOOTHDEVICE_H
#define UI_BLUETOOTHDEVICE_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_BlueToothDevice
{
public:

    void setupUi(QWidget *BlueToothDevice)
    {
        if (BlueToothDevice->objectName().isEmpty())
            BlueToothDevice->setObjectName(QString::fromUtf8("BlueToothDevice"));
        BlueToothDevice->resize(659, 537);

        retranslateUi(BlueToothDevice);

        QMetaObject::connectSlotsByName(BlueToothDevice);
    } // setupUi

    void retranslateUi(QWidget *BlueToothDevice)
    {
        BlueToothDevice->setWindowTitle(QCoreApplication::translate("BlueToothDevice", "Form", nullptr));
    } // retranslateUi

};

namespace Ui {
    class BlueToothDevice: public Ui_BlueToothDevice {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_BLUETOOTHDEVICE_H

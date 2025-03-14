/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 5.14.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QLabel>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralwidget;
    QComboBox *deviceCBox;
    QPushButton *scanBtn;
    QPushButton *connetBtn;
    QComboBox *uuidCBox;
    QLabel *label;
    QLabel *label_2;
    QPushButton *connetServiceBtn;
    QMenuBar *menubar;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QString::fromUtf8("MainWindow"));
        MainWindow->resize(800, 600);
        centralwidget = new QWidget(MainWindow);
        centralwidget->setObjectName(QString::fromUtf8("centralwidget"));
        deviceCBox = new QComboBox(centralwidget);
        deviceCBox->setObjectName(QString::fromUtf8("deviceCBox"));
        deviceCBox->setGeometry(QRect(160, 40, 251, 41));
        scanBtn = new QPushButton(centralwidget);
        scanBtn->setObjectName(QString::fromUtf8("scanBtn"));
        scanBtn->setGeometry(QRect(440, 30, 101, 21));
        connetBtn = new QPushButton(centralwidget);
        connetBtn->setObjectName(QString::fromUtf8("connetBtn"));
        connetBtn->setGeometry(QRect(440, 60, 101, 21));
        uuidCBox = new QComboBox(centralwidget);
        uuidCBox->setObjectName(QString::fromUtf8("uuidCBox"));
        uuidCBox->setGeometry(QRect(130, 110, 431, 41));
        label = new QLabel(centralwidget);
        label->setObjectName(QString::fromUtf8("label"));
        label->setGeometry(QRect(40, 50, 71, 31));
        QFont font;
        font.setPointSize(18);
        label->setFont(font);
        label_2 = new QLabel(centralwidget);
        label_2->setObjectName(QString::fromUtf8("label_2"));
        label_2->setGeometry(QRect(40, 110, 81, 31));
        label_2->setFont(font);
        connetServiceBtn = new QPushButton(centralwidget);
        connetServiceBtn->setObjectName(QString::fromUtf8("connetServiceBtn"));
        connetServiceBtn->setGeometry(QRect(150, 260, 101, 21));
        MainWindow->setCentralWidget(centralwidget);
        menubar = new QMenuBar(MainWindow);
        menubar->setObjectName(QString::fromUtf8("menubar"));
        menubar->setGeometry(QRect(0, 0, 800, 21));
        MainWindow->setMenuBar(menubar);
        statusbar = new QStatusBar(MainWindow);
        statusbar->setObjectName(QString::fromUtf8("statusbar"));
        MainWindow->setStatusBar(statusbar);

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QCoreApplication::translate("MainWindow", "MainWindow", nullptr));
        scanBtn->setText(QCoreApplication::translate("MainWindow", "\346\220\234\347\264\242", nullptr));
        connetBtn->setText(QCoreApplication::translate("MainWindow", "\350\277\236\346\216\245\350\256\276\345\244\207", nullptr));
        label->setText(QCoreApplication::translate("MainWindow", "\350\256\276\345\244\207\357\274\232", nullptr));
        label_2->setText(QCoreApplication::translate("MainWindow", "\346\234\215\345\212\241ID\357\274\232", nullptr));
        connetServiceBtn->setText(QCoreApplication::translate("MainWindow", "\350\277\236\346\216\245\346\234\215\345\212\241", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H

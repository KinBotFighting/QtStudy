#include "mainwindow.h"

#include <QApplication>

#include <QTranslator>

int main(int argc, char *argv[])
{
    QCoreApplication::setAttribute(Qt::AA_EnableHighDpiScaling);

    QApplication a(argc, argv);

    QTranslator translator;
    if(translator.load(":/app_zh_CN.qm")){
        a.installTranslator(&translator);
    }

    MainWindow w;
    w.show();
    return a.exec();
}

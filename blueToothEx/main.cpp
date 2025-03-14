#include <QApplication>
#include "bluetoothdevice.h"

int main(int argc, char* argv[])
{
    QCoreApplication::setAttribute(Qt::AA_EnableHighDpiScaling);
    QApplication a(argc, argv);

    BlueToothDevice b;
    b.show();
    return a.exec();
}

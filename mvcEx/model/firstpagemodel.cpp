#include "firstpagemodel.h"
#include "controller/firstpagecontroller.h"
#include "singleton.h"
#include <QDebug>

FirstPageModel::FirstPageModel(QObject *parent) : QObject(parent)
{

}

void FirstPageModel::countSlot()
{
    int a = 1;
    int b = 1;
    //此处发送信号到控制端
    emit Singleton<FirstPageController>::getInstance().finishedCountSignal();
    qDebug() << QString("页面1的逻辑功能计算结果为==%1").arg(a + b);
}

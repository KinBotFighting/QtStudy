#include "firstpagecontroller.h"
#include <QDebug>

//FirstPageController::FirstPageController(QObject *parent) : QObject(parent)
//{
//    initController();
//}

FirstPageController::FirstPageController()
{
    initController();
}

FirstPageController::~FirstPageController()
{

}

void FirstPageController::initController()
{
    connect(this, SIGNAL(startedCountSignal()), this, SLOT(startCountSlot()));
}

void FirstPageController::startCountSlot()
{
    //控制端创建线程
    threadCount = new QThread;
    //将模型放入线程执行
    firstPageModel = new FirstPageModel();
    firstPageModel->moveToThread(threadCount);
    //线程开始则开始计算
    connect(threadCount, SIGNAL(started()), firstPageModel, SLOT(countSlot()));
    connect(threadCount, SIGNAL(finished()), threadCount, SLOT(deleteLater()));
    //保证线程先结束，再去更新UI，可以防止UI卡死
    connect(threadCount, SIGNAL(finished()), this, SLOT(finishedCountThreadSlot()));
    connect(this, SIGNAL(finishedCountSignal()), this, SLOT(quitCountThreadSlot()));
    threadCount->start();
}

void FirstPageController::quitCountThreadSlot()
{
    threadCount->quit();
    threadCount->wait();
}

void FirstPageController::finishedCountThreadSlot()
{
    qDebug() << "完成计算逻辑功能！！！";
    emit showFinishedCountUiSignal();   //发送给UI后在通知线程退出
}

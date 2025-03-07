#include "firstpageview.h"
#include <QPushButton>
#include <QDebug>
#include <QMessageBox>
#include "singleton.h"
#include "controller/firstpagecontroller.h"

FirstPageView::FirstPageView(QWidget *parent) : QWidget(parent)
{
    setUi();
}

void FirstPageView::setUi()
{
    QPushButton *firstPage = new QPushButton(tr("我是第一页的页面：点击我实现1+1计算功能（业务逻辑功能）"));
    connect(firstPage, SIGNAL(clicked(bool)), this, SLOT(showUiSlot()));
    mainLayout = new QVBoxLayout(this);
    mainLayout->setMargin(0);
    mainLayout->setSpacing(0);
    mainLayout->addWidget(firstPage);
    mainLayout->addStretch();

    //此处为通知UI接收控制的结束信号
    connect(&Singleton<FirstPageController>::getInstance(), SIGNAL(showFinishedCountUiSignal()),
            this, SLOT(showFinishedCountResultUiSlot()));

}

void FirstPageView::showUiSlot()
{
    //点击的时候开始计算
    emit Singleton<FirstPageController>::getInstance().startedCountSignal();
}

void FirstPageView::showFinishedCountResultUiSlot()
{
    qDebug()<<tr("显示计算后界面！！！");
          QMessageBox::warning(this,QStringLiteral("结果界面"),QStringLiteral("显示计算后界面！！！"),QMessageBox::Yes,QMessageBox::No);

}

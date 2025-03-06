#include "mybutton.h"
#include <QPainter>
#include <QMouseEvent>
#include <QAbstractAnimation>
#include <QDebug>

MyButton::MyButton(QWidget *parent) : QWidget(parent)
{
    this->setFixedSize(60, 20);
    animation = new QPropertyAnimation(this);
    animation->setTargetObject(this);
    animation->setStartValue(height() / 2);
    animation->setEndValue(width() - height() / 2);
    animation->setEasingCurve(QEasingCurve::InCubic);
    animation->setDuration(500);
    connect(animation, &QPropertyAnimation::valueChanged, this,
            [=](const QVariant &value){

        posX = value.toInt();
        qDebug() << "changed:" << posX;
        update();
    });
    qDebug() << "init:" << posX;
}

void MyButton::paintEvent(QPaintEvent *event)
{
    Q_UNUSED(event);
    QPainter painter(this);
    painter.setRenderHint(QPainter::Antialiasing, true);

    painter.setPen(Qt::NoPen);
    int radius = height() / 2;
    painter.setBrush(isOff ? offBgBrush : onBgBrush);
    painter.drawRoundedRect(this->rect(), radius, radius);


    painter.setBrush(isOff ? offRBrush : onRBrush);
    //实现圆的位置变换
    QPoint center;
//    center.setX(isOff ? radius : width() - radius);
    center.setX(posX);
    center.setY(radius);
    painter.drawEllipse(center, radius - radius/10, radius - radius/10);


    painter.setPen(Qt::white);
    painter.setFont(QFont("Arial", radius/5));
    painter.drawText(this->rect(), Qt::AlignCenter, isOff ? offText : onText);
}

void MyButton::mousePressEvent(QMouseEvent *event)
{
    if(event->button() == Qt::LeftButton){
        isOff ? animation->setDirection(QAbstractAnimation::Forward) : animation->setDirection(QAbstractAnimation::Backward);
        //按键按下调用动画
        animation->start();
        isOff = !isOff;
        update();
    }
}

void MyButton::resizeEvent(QResizeEvent *event)
{
    animation->setStartValue(height() / 2);
    animation->setEndValue(width() - height() / 2);
    qDebug() << "resizeEvent:" << posX;
}

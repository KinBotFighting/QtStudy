#include "mypanel.h"
#include <QPainter>
#include <QTimer>

MyPanel::MyPanel(QWidget *parent) : QWidget(parent)
{
    this->setFixedSize(300, 300);

    timer = new QTimer(this);
    connect(timer, &QTimer::timeout, this, [=](){
        curVal += 1;
        if(curVal >= maxVal){
            curVal = minVal;
        }
        update();
    });
    timer->start(100);
}

void MyPanel::paintEvent(QPaintEvent *event)
{
    Q_UNUSED(event);
    QPainter painter(this);
    painter.setRenderHint(QPainter::Antialiasing, true);

    painter.translate(rect().center());
    //渐变
    QRadialGradient ra(0, 0, qMin(width(), height())/2);
    ra.setColorAt(1, Qt::cyan);
    ra.setColorAt(0, Qt::white);
    painter.setBrush(ra);
    painter.setPen(Qt::NoPen);
    painter.drawEllipse(QPoint(0, 0),
                        qMin(width(), height())/2, qMin(width(), height())/2);

    /// --------右
    /// |
    /// |
    /// |
    /// 下
    qreal angle = 270*1.0/(maxVal - minVal);
    painter.rotate(135);    //转动角度
    painter.setPen(QPen(Qt::white, 4));
    painter.setFont(QFont("微软雅黑", 10));
    for(int i = minVal; i <= maxVal; ++i){
        if(i % 10 == 0){
            if( 135 + angle * i < 270){ //字体水平方向倒转
                painter.rotate(180);
                painter.drawText(QPoint(-(qMin(width(), height()) / 2 - 20 - 10), 10), QString::number(i));
                painter.rotate(-180);
            }else{
                painter.drawText(QPoint(qMin(width(), height()) / 2 - 20 - 50, 10), QString::number(i));
            }
            painter.drawLine(qMin(width(), height()) / 2 - 20, 0, qMin(width(), height()) / 2, 0);
        }else{
            painter.drawLine(qMin(width(), height()) / 2 - 10, 0, qMin(width(), height()) / 2, 0);
        }
        painter.rotate(angle);
    }

    //绘制中心圆圈，文本
    painter.rotate(-angle - 45);
    painter.setPen(QPen(Qt::black, 4));
    painter.drawEllipse(QPoint(0, 0), 20, 20);
    painter.drawText(QRect(-100, -100, 200, 200), Qt::AlignCenter, QString::number(curVal));

    //绘制指针
    painter.rotate(135 + curVal *angle);
    painter.drawLine(20, 0, qMin(width(), height())/2 - 20 - 50, 0);

    //绘制扇形
}

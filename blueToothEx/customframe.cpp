#include "customframe.h"


CustomFrame::CustomFrame(QWidget *parent) : QFrame(parent)
{

}

CustomFrame::~CustomFrame()
{

}

void CustomFrame::mousePressEvent(QMouseEvent *event)
{
    if(event->button() == Qt::LeftButton)
    {
        emit clicked();
    }
    QFrame::mousePressEvent(event);
}

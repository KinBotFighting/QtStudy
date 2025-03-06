#include "widget.h"
#include "ui_widget.h"
#include "mypanel.h"

Widget::Widget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Widget)
{
    ui->setupUi(this);
    MyPanel *panel = new MyPanel(this);
    panel->move(50,50);
}

Widget::~Widget()
{
    delete ui;
}


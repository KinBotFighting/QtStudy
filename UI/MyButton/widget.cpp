#include "widget.h"
#include "ui_widget.h"
#include "mybutton.h"

Widget::Widget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Widget)
{
    ui->setupUi(this);
    MyButton *btn = new MyButton(this);
    btn->move(100, 100);
    btn->setFixedSize(200, 50);
}

Widget::~Widget()
{
    delete ui;
}


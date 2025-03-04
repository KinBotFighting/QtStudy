#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QTranslator>


MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::on_comboBox_activated(int index)
{
    QTranslator translator;
    switch(index){
    case LANGUAGE::chinese:
        if(translator.load(":/app_zh_CN.qm")){
            qApp->installTranslator(&translator);
        }
        break;
    case LANGUAGE::english:
        if(translator.load(":/app_english.qm")){
            qApp->installTranslator(&translator);
        }
        break;
    default:
        break;
    }
    //重新翻译界面
    ui->retranslateUi(this);
}

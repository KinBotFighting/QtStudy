#ifndef WIDGET_H
#define WIDGET_H

#include <QWidget>

//#define QScrollAreaTest
//#define QHBoxLayoutTest
//#define QGridLayoutTest
//#define QListViewTest
//#define QTreeViewTest
//#define QTableViewTest
//#define QListWidgetTest
//#define QTreeWidgetTest
//#define QTableWidgetTest
//#define QColumnViewTest
//#define QGroupBoxTest
//#define QToolBoxTest
//#define QTabWidgetTest
//#define QStackedWidgetTest
//#define QDockWidgetTest
#define QMainWindowTest


QT_BEGIN_NAMESPACE
namespace Ui { class Widget; }
QT_END_NAMESPACE

class Widget : public QWidget
{
    Q_OBJECT

public:
    Widget(QWidget *parent = nullptr);
    ~Widget();

    void initLayout();


private:
    Ui::Widget *ui;
};
#endif // WIDGET_H

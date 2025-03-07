#ifndef WIDGET_H
#define WIDGET_H

#include <QWidget>
#include <QVBoxLayout>
#include <QButtonGroup>
#include <QStackedLayout>

QT_BEGIN_NAMESPACE
namespace Ui { class Widget; }
QT_END_NAMESPACE

class Widget : public QWidget
{
    Q_OBJECT

public:
    Widget(QWidget *parent = nullptr);
    ~Widget();

private:
    void setUi();
    void initMenu();
    void initStackWidget();

    QVBoxLayout *mainLayout;
    QButtonGroup *buttonGroup;
    QStackedLayout *stackLayout;

private slots:
    void buttonGroupSlot(int);

private:
    Ui::Widget *ui;
};
#endif // WIDGET_H

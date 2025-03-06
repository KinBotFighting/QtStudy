#ifndef MYBUTTON_H
#define MYBUTTON_H

#include <QWidget>
#include <QPropertyAnimation>

class MyButton : public QWidget
{
    Q_OBJECT
public:
    explicit MyButton(QWidget *parent = nullptr);

signals:

protected:
    void paintEvent(QPaintEvent *event) override;
    void mousePressEvent(QMouseEvent *event) override;
    void resizeEvent(QResizeEvent *event) override;
public slots:

private:
    QBrush offBgBrush   = Qt::black;
    QBrush offRBrush    = Qt::red;
    QBrush onBgBrush    = Qt::blue;
    QBrush onRBrush     = Qt::green;


    QString onText      = "ON";
    QString offText     = "OFF";
    bool isOff          = true;
    QPropertyAnimation  *animation;
    int posX            = height() / 2;
};

#endif // MYBUTTON_H

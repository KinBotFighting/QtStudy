#ifndef MYPANEL_H
#define MYPANEL_H

#include <QWidget>

class MyPanel : public QWidget
{
    Q_OBJECT
public:
    explicit MyPanel(QWidget *parent = nullptr);

protected:
    void paintEvent(QPaintEvent *event) override;
signals:

public slots:

private:
    int maxVal = 50;
    int minVal = 0;
    int curVal = 0;

    QTimer *timer = nullptr;
};

#endif // MYPANEL_H

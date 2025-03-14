#ifndef CUSTOMFRAME_H
#define CUSTOMFRAME_H

#include <QObject>
#include <QFrame>
#include <QMouseEvent>

class CustomFrame : public QFrame
{
    Q_OBJECT
public:
    CustomFrame(QWidget *parent = nullptr);
    ~CustomFrame();

signals:
    void clicked();

protected:
    void mousePressEvent(QMouseEvent *event) override;
};

#endif // CUSTOMFRAME_H

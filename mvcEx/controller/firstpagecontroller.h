#ifndef FIRSTPAGECONTROLLER_H
#define FIRSTPAGECONTROLLER_H

#include <QObject>
#include <QThread>
#include "singleton.h"
#include "model/firstpagemodel.h"

class FirstPageController : public QObject
{
    SINGLETON(FirstPageController); //此处为单例声明，没有父类
    Q_OBJECT
//public:
//    explicit FirstPageController(QObject *parent = nullptr);

signals:
    void startedCountSignal();
    void finishedCountSignal();
    void showFinishedCountUiSignal();

private:
    void initController();
    QThread *threadCount;
    FirstPageModel *firstPageModel;
private slots:
    void startCountSlot();
    void quitCountThreadSlot();
    void finishedCountThreadSlot();
public slots:
};

#endif // FIRSTPAGECONTROLLER_H

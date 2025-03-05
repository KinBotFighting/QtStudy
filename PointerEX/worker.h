#ifndef WORKER_H
#define WORKER_H

#include <QObject>
#include <QSharedPointer>
#include <QDebug>

class MyClass{
public:
    MyClass(){
        qDebug() << "MyClass";
    }
    ~MyClass(){
        qDebug() << "~MyClass";
    }
    void doSomething(){
        qDebug() << "doSomething";
    };
};

class Worker : public QObject {
    Q_OBJECT // 必须包含 Q_OBJECT 宏
public:
    Worker(QSharedPointer<MyClass> data, QObject* parent = nullptr)
        : QObject(parent), m_data(data) {}

public slots:
    void process() {
        if (!m_data.isNull()) {
            m_data->doSomething();
        }
    }

private:
    QSharedPointer<MyClass> m_data;
};

#endif // WORKER_H

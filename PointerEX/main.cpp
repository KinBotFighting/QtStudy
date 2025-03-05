#include <QCoreApplication>
#include <QDebug>
#include <iostream>
#include <QMap>
#include <QThread>


using namespace std;
//class MyClass{
//public:
//    MyClass(){
//        qDebug() << "MyClass";
//    }
//    ~MyClass(){
//        qDebug() << "~MyClass";
//    }
//    void doSomething(){
//        qDebug() << "doSomething";
//    };
//};

///1.区域指针 唯一指针 局部作用域的对象管理 std::unique_str
#include <QScopedPointer>
//1.1 工厂模式返回对象 明确所有权转移，避免内存泄漏
//unique_ptr<MyClass> createObject(){
//    return make_unique<MyClass>();
//}
//1.2 延迟初始化 只有在使用的时候才创建
//class LazyObject{
//public:
//    void doSomething(){
//        if(!m_object){
//            m_object = make_unique<MyClass>();
//        }
//        m_object->doSomething();
//    }
//private:
//    unique_ptr<MyClass> m_object;
//};

///2.共享指针  共享所有权的对象管理 std::shared_str
#include <QSharedPointer>
//2.1 缓存或资源池 缓存一些对象，但是不知道什么时候释放，引用计数在不需要的时候自动释放
//QMap<int, QSharedPointer<MyClass>> cache;
//void addToCache(int id, QSharedPointer<MyClass> obj){
//    cache[id] = obj;
//}

//QSharedPointer<MyClass> getFromCache(int id){
//    return cache.value(id, nullptr);
//}
//2.2 异步任务中的对象管理 对象可能被多个线程共享，确保线程安全
#include "worker.h"


///3.弱引用指针 不增加引用计数 std::weak_str
#include <QWeakPointer>



int main(int argc, char *argv[])
{
    ///3.弱引用指针
//    QSharedPointer<MyClass> myObject(new MyClass());
//    QWeakPointer<MyClass> weakObject = myObject;

//    if(!weakObject.isNull()){
//        QSharedPointer<MyClass> strongObject = weakObject.toStrongRef();
//        strongObject->doSomething();
//    }


    ///2.共享指针,能指向同一个对象
//    QSharedPointer<MyClass> myObject(new MyClass());
//    myObject->doSomething();
//    //计数增加
//    QSharedPointer<MyClass> anotherObject = myObject;
//    anotherObject->doSomething();
    //2.1 缓存或资源地
//    QSharedPointer<MyClass> myObject(new MyClass());
//    cache.insert(1, myObject);
//    QSharedPointer<MyClass> anotherObject = cache.value(1);
//    anotherObject->doSomething();
    //2.2 异步线程
//    QCoreApplication a(argc, argv);
//    QSharedPointer<MyClass> data(new MyClass());
//    QThread* thread = new QThread();
//    Worker* worker = new Worker(data);
//    worker->moveToThread(thread);
//    QObject::connect(thread, &QThread::started, worker, &Worker::process);
//    QObject::connect(thread, &QThread::finished, thread, &QThread::deleteLater);
//    thread->start();
//    return a.exec();

    ///1.区域指针,超出作用域的时候会销毁
//    QScopedPointer<MyClass> myObject(new MyClass());
//    myObject->doSomething();
    //1.1 工厂模式返回对象
//    auto obj = createObject();
//    obj->doSomething();
    //1.2 延迟使用，减少开销
//    LazyObject obj;
//    obj.doSomething();

    return 0;
//    QCoreApplication a(argc, argv);
//    return a.exec();
}

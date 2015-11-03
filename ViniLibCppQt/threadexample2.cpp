#include <QDebug>
#include <QThread>
#include "threadexample2.h"

ThreadExample2::ThreadExample2()
{
    qDebug() << " = ThreadExample2(). Start. -------------------"<< endl;

    QThread *myThread = new QThread;
    Worker *worker = new Worker;
    worker->moveToThread(myThread);

    connect(myThread, SIGNAL(started()), worker, SLOT(processToTheEnd()));
    connect(worker, SIGNAL(finished()), myThread, SLOT(quit()));
    connect(worker, SIGNAL(finished()), worker, SLOT(deleteLater()));
    connect(myThread, SIGNAL(finished()), myThread, SLOT(deleteLater()));
    qDebug() << " = myThread->start() - before."<< endl;
    myThread->start();
    qDebug() << " = myThread->start() - after."<< endl;
}

Worker::Worker()
{
    qDebug() << " = Worker(). Constructor."<< endl;
}

Worker::~Worker()
{
    qDebug() << " = ~Worker(). Destructor. -------------------"<< endl;
}

void Worker::processToTheEnd()
{
    //Allocate new objects here.
    qDebug() << " = processToTheEnd()."<< endl;
    emit finished();
}

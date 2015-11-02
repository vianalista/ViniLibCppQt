#include <QDebug>
#include "threadexample1.h"

void ThreadExample1::run()
{
    qDebug() << " + ThreadExample1. The secondary" << thread()->currentThreadId() << endl;
}

void ThreadExample1::threadSecondary(Qt::HANDLE num)
{
    ThreadExample1 obj;
    obj.start();
    qDebug() << " + Main thread started: " << num << endl;
    obj.wait();
}

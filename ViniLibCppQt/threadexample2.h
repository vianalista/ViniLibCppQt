#ifndef THREADEXAMPLE2
#define THREADEXAMPLE2
#include <QObject>

class ThreadExample2 : public QObject
{
    Q_OBJECT
public:
    ThreadExample2();
};

class Worker : public QObject
{
    Q_OBJECT
public:
    Worker();
    ~Worker();
public slots:
    void processToTheEnd();

signals:
    void finished();
    void error(QString err);

};


#endif // THREADEXAMPLE2


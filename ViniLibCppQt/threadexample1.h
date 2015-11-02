#ifndef THREADEXAMPLE1
#define THREADEXAMPLE1
#include <QThread>

class ThreadExample1 : public QThread
{
    Q_OBJECT
public:
    void threadSecondary(Qt::HANDLE num);
private:
    void run();
};

#endif // THREADEXAMPLE1

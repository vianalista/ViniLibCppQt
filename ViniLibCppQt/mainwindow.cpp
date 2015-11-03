#include <QMessageBox>
#include "mainwindow.h"
#include "ui_mainwindow.h"

#include "threadexample1.h"
#include "threadexample2.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    connect(ui->rbtThread_1, SIGNAL(toggled(bool)), this, SLOT(showMsg1(bool)));
    connect(ui->rbtThread_2, SIGNAL(toggled(bool)), this, SLOT(showMsg2(bool)));
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::showMsg1(bool checked)
{
    if (checked)
    {
        ui->textEdit->setText("Thread Example - How to make one. Start.");

        ThreadExample1 myThread;
        myThread.threadSecondary(this->thread()->currentThreadId());
        ui->textEdit->setText("Thread Example - How to make one. The End.");
    }
}

void MainWindow::showMsg2(bool checked)
{
    if (checked)
    {
        ui->textEdit->setText("Thread Example - How to make two. Start");

        ThreadExample2 obj;

        ui->textEdit->setText("Thread Example - How to make two. The End");
    }
}

#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);


    //Создаём объект класса
    RN = new RosNode();
    //Создаём поток объекта класса
    RN_thread = new QThread;
    //Отправляем класс в поток
    RN->moveToThread(RN_thread);
    //Подключение сигналов
    connect(RN_thread, SIGNAL(started()), RN, SLOT(process()));
    RN_thread->start();
}
MainWindow::~MainWindow()
{
    delete ui;
    //    RN->isAllowProcess = false;
    delete RN;
    delete RN_thread;
}


void MainWindow::setMap(vector<int> maps){
    RN->setMap(maps);
}

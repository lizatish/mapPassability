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


void MainWindow::setMap(int** opMap){
    vector<int> map;
    for(int i = 0; i < 20; i++)
        for(int j = 0; j < 20; j++)
            map.push_back(opMap[i][j]);
    RN->setMap(map);
}

void MainWindow::setPath(vector<pair<int, int>> path){
    RN->setPath(path);
}


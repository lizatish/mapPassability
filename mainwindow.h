#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "rosnode.h"
#include <QThread>



namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

public slots:
    void setMap(int** openMap);
    void setPath(vector<pair<int, int>> path);

private:
    Ui::MainWindow *ui;
    RosNode *RN;
    QThread *RN_thread;
};

#endif // MAINWINDOW_H

#include "mainwindow.h"
#include "ui_mainwindow.h"aw
MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    G=new gTwo(ui->result,ui->score,ui->best,ui->label_1,ui->label_2,ui->label_3,ui->label_4,ui->label_5,ui->label_6,ui->label_7,ui->label_8,ui->label_9,ui->label_10,ui->label_11,ui->label_12,ui->label_13,ui->label_14,ui->label_15,ui->label_16);
    setFixedSize(333,518);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::keyPressEvent(QKeyEvent* event)
{
    if(!G->IsStop)
    {
        switch(event->key())
        {
            case Qt::Key_W:
                G->run_Up();
                break;
            case Qt::Key_S:
                G->run_Down();
                break;
            case Qt::Key_A:
                G->run_Left();
                break;
            case Qt::Key_D:
                G->run_Right();
                break;
            case Qt::Key_R:
                G->begin();
                break;
        }
        G->check();
    }
    else
        if(event->key()==Qt::Key_R)
            G->begin();
}

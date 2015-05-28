#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <gTwo.h>

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();
    void keyPressEvent(QKeyEvent*);

private slots:
    void restart()
    {
        G->begin();
    }

private:
    Ui::MainWindow *ui;
    gTwo *G;
};

#endif // MAINWINDOW_H

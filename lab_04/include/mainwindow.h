#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>

#include "elevator.h"

namespace Ui
{
    class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

private slots:
    void OnButtonCabin1Clicked();
    void OnButtonCabin2Clicked();
    void OnButtonCabin3Clicked();
    void OnButtonCabin4Clicked();
    void OnButtonCabin5Clicked();
    void OnButtonCabin6Clicked();
    void OnButtonCabin7Clicked();
    void OnButtonCabin8Clicked();
    void OnButtonCabin9Clicked();
    void OnButtonCabin10Clicked();
    void OnButtonFloor1Clicked();
    void OnButtonFloor2Clicked();
    void OnButtonFloor3Clicked();
    void OnButtonFloor4Clicked();
    void OnButtonFloor5Clicked();
    void OnButtonFloor6Clicked();
    void OnButtonFloor7Clicked();
    void OnButtonFloor8Clicked();
    void OnButtonFloor9Clicked();
    void OnButtonFloor10Clicked();

private:
    Ui::MainWindow *ui_;
    Elevator elevator_;
};

#endif

#include "qdebug.h"

#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) : QMainWindow(parent),
                                          ui_(new Ui::MainWindow)
{
    qDebug() << "Elevator is located at the floor #1, doors are closed.\n"
                "Elevator is being in waiting state.";
    ui_->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete ui_;
}

void MainWindow::OnButtonCabin1Clicked()
{
    qDebug() << "Button 1 was pressed in elevator";
    elevator_.Click(1);
}

void MainWindow::OnButtonCabin2Clicked()
{
    qDebug() << "Button 2 was pressed in elevator";
    elevator_.Click(2);
}

void MainWindow::OnButtonCabin3Clicked()
{
    qDebug() << "Button 3 was pressed in elevator";
    elevator_.Click(3);
}

void MainWindow::OnButtonCabin4Clicked()
{
    qDebug() << "Button 4 was pressed in elevator";
    elevator_.Click(4);
}

void MainWindow::OnButtonCabin5Clicked()
{
    qDebug() << "Button 5 was pressed in elevator";
    elevator_.Click(5);
}

void MainWindow::OnButtonCabin6Clicked()
{
    qDebug() << "Button 6 was pressed in elevator";
    elevator_.Click(6);
}

void MainWindow::OnButtonCabin7Clicked()
{
    qDebug() << "Button 7 was pressed in elevator";
    elevator_.Click(7);
}

void MainWindow::OnButtonCabin8Clicked()
{
    qDebug() << "Button 8 was pressed in elevator";
    elevator_.Click(8);
}

void MainWindow::OnButtonCabin9Clicked()
{
    qDebug() << "Button 9 was pressed in elevator";
    elevator_.Click(9);
}

void MainWindow::OnButtonCabin10Clicked()
{
    qDebug() << "Button 10 was pressed in elevator";
    elevator_.Click(10);
}

void MainWindow::OnButtonFloor1Clicked()
{
    qDebug() << "Elevator was called at the floor #1";
    elevator_.Click(1);
}

void MainWindow::OnButtonFloor2Clicked()
{
    qDebug() << "Elevator was called at the floor #2";
    elevator_.Click(2);
}

void MainWindow::OnButtonFloor3Clicked()
{
    qDebug() << "Elevator was called at the floor #3";
    elevator_.Click(3);
}

void MainWindow::OnButtonFloor4Clicked()
{
    qDebug() << "Elevator was called at the floor #4";
    elevator_.Click(4);
}

void MainWindow::OnButtonFloor5Clicked()
{
    qDebug() << "Elevator was called at the floor #5";
    elevator_.Click(5);
}

void MainWindow::OnButtonFloor6Clicked()
{
    qDebug() << "Elevator was called at the floor #6";
    elevator_.Click(6);
}

void MainWindow::OnButtonFloor7Clicked()
{
    qDebug() << "Elevator was called at the floor #7";
    elevator_.Click(7);
}

void MainWindow::OnButtonFloor8Clicked()
{
    qDebug() << "Elevator was called at the floor #8";
    elevator_.Click(8);
}

void MainWindow::OnButtonFloor9Clicked()
{
    qDebug() << "Elevator was called at the floor #9";
    elevator_.Click(9);
}

void MainWindow::OnButtonFloor10Clicked()
{
    qDebug() << "Elevator was called at the floor #10";
    elevator_.Click(10);
}

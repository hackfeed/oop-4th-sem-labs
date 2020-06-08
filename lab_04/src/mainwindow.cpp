#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "qdebug.h"

MainWindow::MainWindow(QWidget *parent) : QMainWindow(parent),
                                          ui(new Ui::MainWindow)
{
    qDebug() << "Лифт находится на этаже 1, двери закрыты.\n"
                "Лифт находится в режиме ожидания.";
    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_button_cabin_1_clicked()
{
    qDebug() << "В лифте нажали кнопку 1.";
    lift.click(1);
}

void MainWindow::on_button_cabin_2_clicked()
{
    qDebug() << "В лифте нажали кнопку 2.";
    lift.click(2);
}

void MainWindow::on_button_cabin_3_clicked()
{
    qDebug() << "В лифте нажали кнопку 3.";
    lift.click(3);
}

void MainWindow::on_button_cabin_4_clicked()
{
    qDebug() << "В лифте нажали кнопку 4.";
    lift.click(4);
}

void MainWindow::on_button_cabin_5_clicked()
{
    qDebug() << "В лифте нажали кнопку 5.";
    lift.click(5);
}

void MainWindow::on_button_cabin_6_clicked()
{
    qDebug() << "В лифте нажали кнопку 6.";
    lift.click(6);
}

void MainWindow::on_button_cabin_7_clicked()
{
    qDebug() << "В лифте нажали кнопку 7.";
    lift.click(7);
}

void MainWindow::on_button_cabin_8_clicked()
{
    qDebug() << "В лифте нажали кнопку 8.";
    lift.click(8);
}

void MainWindow::on_button_cabin_9_clicked()
{
    qDebug() << "В лифте нажали кнопку 9.";
    lift.click(9);
}

void MainWindow::on_button_cabin_10_clicked()
{
    qDebug() << "В лифте нажали кнопку 10.";
    lift.click(10);
}

void MainWindow::on_button_floor_1_clicked()
{
    qDebug() << "Вызов лифта на 1 этаже.";
    lift.click(1);
}

void MainWindow::on_button_floor_2_clicked()
{
    qDebug() << "Вызов лифта на 2 этаже.";
    lift.click(2);
}

void MainWindow::on_button_floor_3_clicked()
{
    qDebug() << "Вызов лифта на 3 этаже.";
    lift.click(3);
}

void MainWindow::on_button_floor_4_clicked()
{
    qDebug() << "Вызов лифта на 4 этаже.";
    lift.click(4);
}

void MainWindow::on_button_floor_5_clicked()
{
    qDebug() << "Вызов лифта на 5 этаже.";
    lift.click(5);
}

void MainWindow::on_button_floor_6_clicked()
{
    qDebug() << "Вызов лифта на 6 этаже.";
    lift.click(6);
}

void MainWindow::on_button_floor_7_clicked()
{
    qDebug() << "Вызов лифта на 7 этаже.";
    lift.click(7);
}

void MainWindow::on_button_floor_8_clicked()
{
    qDebug() << "Вызов лифта на 8 этаже.";
    lift.click(8);
}

void MainWindow::on_button_floor_9_clicked()
{
    qDebug() << "Вызов лифта на 9 этаже.";
    lift.click(9);
}

void MainWindow::on_button_floor_10_clicked()
{
    qDebug() << "Вызов лифта на 10 этаже.";
    lift.click(10);
}

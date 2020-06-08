#include "mainwindow.h"

MainWindow::MainWindow(QWidget *parent) : QMainWindow(parent),
                                          ui(new Ui::MainWindow),
                                          _facade(nullptr)
{
    ui->setupUi(this);
    this->setup_scene();
    this->_facade = std::shared_ptr<facade>(facade::instance());
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::check_cam_exist()
{
    if (!this->_facade->cams_count())
    {
        std::string message = "No camera found.";
        throw camera_error(message);
    }
}

void MainWindow::check_models_exist()
{
    if (!this->_facade->models_count())
    {
        std::string message = "No models found.";
        throw model_error(message);
    }
}

void MainWindow::on_move_button_clicked()
{
    try
    {
        check_cam_exist();
        check_models_exist();
    }
    catch (const camera_error &error)
    {
        QMessageBox::critical(NULL, "Ошибка", "Не загружено ни одной камеры.");
        return;
    }
    catch (const model_error &error)
    {
        QMessageBox::critical(NULL, "Ошибка", "Не загружено ни одной модели");
        return;
    }

    move_model move_command(10, 10, 10, 1);
    move_command.execute(_facade);
    update_scene();
}

void MainWindow::on_scale_button_clicked()
{
    try
    {
        check_cam_exist();
        check_models_exist();
    }
    catch (const camera_error &error)
    {
        QMessageBox::critical(NULL, "Ошибка", "Не загружено ни одной камеры.");
        return;
    }
    catch (const model_error &error)
    {
        QMessageBox::critical(NULL, "Ошибка", "Не загружено ни одной модели");
        return;
    }

    scale_model scale_command(2, 2, 2, 1);
    scale_command.execute(_facade);
    update_scene();
}

void MainWindow::on_turn_button_clicked()
{
    try
    {
        check_cam_exist();
        check_models_exist();
    }
    catch (const camera_error &error)
    {
        QMessageBox::critical(NULL, "Ошибка", "Не загружено ни одной камеры.");
        return;
    }
    catch (const model_error &error)
    {
        QMessageBox::critical(NULL, "Ошибка", "Не загружено ни одной модели");
        return;
    }

    turn_model turn_command(3, 3, 3, 1);
    turn_command.execute(_facade);
    update_scene();
}

void MainWindow::on_load_button_clicked()
{
    try
    {
        check_cam_exist();
    }
    catch (const camera_error &error)
    {
        QMessageBox::critical(NULL, "Ошибка", "Прежде чем добавлять модель, добавьте хотя бы одну камеру.");
        return;
    }

    load_model load_command("/home/alexey/reps/oop/lab_03/data/model.csv");

    try
    {
        load_command.execute(_facade);
    }
    catch (const file_error &error)
    {
        QMessageBox::critical(NULL, "Ошибка", "Что-то не так пошло при загрузке файла...");
        return;
    }

    update_scene();
}

void MainWindow::setup_scene()
{
    this->_scene = new QGraphicsScene(this);
    ui->graphicsView->setScene(_scene);
    ui->graphicsView->setAlignment(Qt::AlignTop | Qt::AlignLeft);
    this->_scene->setSceneRect(0, 0, win_x, win_y);

    std::shared_ptr<abstract_factory> factory(new qt_factory);
    std::shared_ptr<base_drawer> drawer(new qt_drawer(this->_scene));
    this->_drawer = drawer;
}

void MainWindow::update_scene()
{
    draw_scene draw_command(this->_drawer);
    draw_command.execute(_facade);
}

void MainWindow::on_add_camera_clicked()
{
    add_camera camera_command(win_x / 2, win_y / 2, 0);
    camera_command.execute(_facade);
}

void MainWindow::on_right_button_clicked()
{
    try
    {
        check_cam_exist();
        check_models_exist();
    }
    catch (const camera_error &error)
    {
        QMessageBox::critical(NULL, "Ошибка", "Не загружено ни одной камеры.");
        return;
    }
    catch (const model_error &error)
    {
        QMessageBox::critical(NULL, "Ошибка", "Не загружено ни одной модели");
        return;
    }

    move_camera camera_command(1, 10, 0);
    camera_command.execute(_facade);
    update_scene();
}

void MainWindow::on_up_button_clicked()
{
    try
    {
        check_cam_exist();
        check_models_exist();
    }
    catch (const camera_error &error)
    {
        QMessageBox::critical(NULL, "Ошибка", "Не загружено ни одной камеры.");
        return;
    }
    catch (const model_error &error)
    {
        QMessageBox::critical(NULL, "Ошибка", "Не загружено ни одной модели");
        return;
    }

    move_camera camera_command(1, 0, 10);
    camera_command.execute(_facade);
    update_scene();
}

void MainWindow::on_down_button_clicked()
{
    try
    {
        check_cam_exist();
        check_models_exist();
    }
    catch (const camera_error &error)
    {
        QMessageBox::critical(NULL, "Ошибка", "Не загружено ни одной камеры.");
        return;
    }
    catch (const model_error &error)
    {
        QMessageBox::critical(NULL, "Ошибка", "Не загружено ни одной модели");
        return;
    }

    move_camera camera_command(1, 0, -10);
    camera_command.execute(_facade);
    update_scene();
}

void MainWindow::on_left_button_clicked()
{
    try
    {
        check_cam_exist();
        check_models_exist();
    }
    catch (const camera_error &error)
    {
        QMessageBox::critical(NULL, "Ошибка", "Не загружено ни одной камеры.");
        return;
    }
    catch (const model_error &error)
    {
        QMessageBox::critical(NULL, "Ошибка", "Не загружено ни одной модели");
        return;
    }

    move_camera camera_command(1, -10, 0);
    camera_command.execute(_facade);
    update_scene();
}

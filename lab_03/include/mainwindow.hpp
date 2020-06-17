#pragma once

#include <math.h>

#include <QFileDialog>
#include <QMainWindow>
#include <QMessageBox>
#include <memory>

#include "command_base.hpp"
#include "commands.hpp"
#include "qt_drawer.hpp"
#include "facade.hpp"

namespace Ui
{
    class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

    class DrawDirector
    {
        friend class MainWindow;

    private:
        std::shared_ptr<QGraphicsScene> _scene_view;

    public:
        DrawDirector() = default;
        void set_scene(std::shared_ptr<QGraphicsScene> &scene_view) { this->_scene_view = scene_view; }
        std::shared_ptr<BaseDrawer> get_drawer(const char *fp, std::shared_ptr<AbstractFactory> &f);
    };

private slots:

    void on_pushButton_AddModel_clicked();

    void on_pushButton_AddCamera_clicked();

    void on_pushButton_SetCamera_clicked();

    void on_pushButton_RemoveCamera_clicked();

    void on_pushButton_RemoveModel_clicked();

    void on_pushButton_moveModel_clicked();

    void on_pushButton_scaleModel_clicked();

    void on_pushButton_rotateModel_clicked();

    void on_pushButton_moveCamera_clicked();

    void on_pushButton_rotateCamera_clicked();

private:
    Ui::MainWindow *ui;
    std::shared_ptr<QGraphicsScene> scene_view;
    // QPixmap pixmap;
    DrawDirector director;
    std::unique_ptr<Facade> facade_viewer;
    size_t index_model;
    size_t index_camera;
    friend class DrawDirector;
    char *development_environment;
    void render();
    std::string readConfigFile(const char *filename);
};

#pragma once

#include <QGraphicsScene>

#include "qt_drawer.hpp"
#include "loader_abstract.hpp"
#include "manager_camera.hpp"
#include "manager_draw.hpp"
#include "manager_scene.hpp"
#include "manager_transform.hpp"
#include "scene.hpp"

class Controller
{
public:
    static std::shared_ptr<Controller> GetInstance();
    Controller(Controller &) = delete;
    Controller(const Controller &) = delete;
    ~Controller() = default;

    void addModel(std::string model_name, std::string file_name);
    void addCamera(std::string cam_name);
    void setCamera(std::string cam_name);
    void removeCamera(std::string cam_name);
    void removeModel(std::string model_name);

    void transformCamera(std::string cam_name, Point<double> &move, Point<double> &rotate);
    void transformModel(std::string model_name, Point<double> &move, Point<double> &scale, Point<double> &rotate);

    void draw(std::shared_ptr<BaseDrawer> drawer);

private:
    Controller();
    CameraManager camera_manager;
    SceneManager scene_manager;
    TransformManager transform_manager;
    std::shared_ptr<AbstractLoader> uploader;
    std::shared_ptr<DrawManager> draw_manager;
};

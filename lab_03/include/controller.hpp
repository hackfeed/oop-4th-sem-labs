#ifndef CONTROLLER_HPP
#define CONTROLLER_HPP

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

    void AddModel(std::string model_name, std::string file_name);
    void AddCamera(std::string cam_name);
    void SetCamera(std::string cam_name);
    void RemoveCamera(std::string cam_name);
    void RemoveModel(std::string model_name);

    void TransformCamera(std::string cam_name, Point<double> &move, Point<double> &rotate);
    void TransformModel(std::string model_name, Point<double> &move, Point<double> &scale, Point<double> &rotate);

    void Draw(std::shared_ptr<BaseDrawer> drawer);

private:
    Controller();
    CameraManager camera_manager_;
    SceneManager scene_manager_;
    TransformManager transform_manager_;
    std::shared_ptr<AbstractLoader> uploader_;
    std::shared_ptr<DrawManager> draw_manager_;
};

#endif
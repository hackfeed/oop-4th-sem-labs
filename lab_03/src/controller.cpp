#include "controller.hpp"

#include "model_builder.hpp"
#include "loader_file.hpp"
#include "loader_model.hpp"

#include "exception_scene.hpp"

std::shared_ptr<Controller> Controller::GetInstance()
{
    static std::shared_ptr<Controller> instance_(new Controller());
    return instance_;
}

Controller::Controller() : draw_manager_(std::make_shared<DrawManager>())
{
    std::shared_ptr<SourceLoader> ldr(std::make_shared<FileLoader>());
    std::shared_ptr<BaseModelBuilder> bld(std::make_shared<ModelBuilder>());
    std::shared_ptr<AbstractLoader> uploader_(std::make_shared<ModelLoader>(ldr, bld));
    this->uploader_ = uploader_;
}

void Controller::AddModel(std::string name, std::string file_name)
{
    std::shared_ptr<Model> model = uploader_->loadModel(name, file_name);
    scene_manager_.getScene()->Add(std::shared_ptr<Model>(model));
}

void Controller::AddCamera(std::string name)
{
    auto camera = new Camera(name);
    scene_manager_.getScene()->Add(std::shared_ptr<Camera>(camera));
}

void Controller::SetCamera(std::string cam_name)
{
    scene_manager_.setCurrentCamera(cam_name);
}

void Controller::RemoveCamera(std::string cam_name)
{
    auto scene = scene_manager_.getScene();
    IteratorObject it = scene->getObject()->begin();
    IteratorObject it_e = scene->getObject()->end();
    bool flag = true;
    while (it != it_e && flag)
    {
        auto tmp = *it;
        if (tmp->getName() == cam_name)
            flag = false;
        if (flag)
            ++it;
    }
    time_t t_time = time(NULL);
    if (it != it_e)
        scene->Remove(it);
    else
        throw CameraError(__FILE__, typeid(*this).name(), __LINE__, ctime(&t_time));
}

void Controller::RemoveModel(std::string model_name)
{
    auto scene = scene_manager_.getScene();
    IteratorObject it = scene->getObject()->begin();
    IteratorObject it_e = scene->getObject()->end();
    bool flag = true;
    while (it != it_e && flag)
    {
        auto tmp = *it;
        if (tmp->getName() == model_name)
            flag = false;
        if (flag)
            ++it;
    }
    time_t t_time = time(NULL);
    if (it != it_e)
        scene->Remove(it);
    else
        throw ObjectError(__FILE__, typeid(*this).name(), __LINE__, ctime(&t_time));
}

void Controller::TransformCamera(std::string cam_name, Point<double> &move, Point<double> &rotate)
{
    auto camera = std::dynamic_pointer_cast<Camera>(scene_manager_.getScene()->getObject(cam_name));
    transform_manager_.moveObject(camera, move.getX(), move.getY(), move.getZ());
    camera_manager_.roll(camera, rotate.getX());
    camera_manager_.pitch(camera, rotate.getY());
    camera_manager_.yaw(camera, rotate.getZ());
}

void Controller::TransformModel(std::string model_name, Point<double> &move, Point<double> &scale, Point<double> &rotate)
{
    auto obj = scene_manager_.getScene()->getObject(model_name);
    transform_manager_.moveObject(obj, move.getX(), move.getY(), move.getZ());
    transform_manager_.scaleObject(obj, scale.getX(), scale.getY(), scale.getZ());
    transform_manager_.rotateObjectOX(obj, rotate.getX());
    transform_manager_.rotateObjectOY(obj, rotate.getY());
    transform_manager_.rotateObjectOZ(obj, rotate.getZ());
}

void Controller::Draw(std::shared_ptr<BaseDrawer> drawer)
{
    draw_manager_->setDrawer(drawer);
    draw_manager_->SetCamera(scene_manager_.getCurrentCamera());
    scene_manager_.getScene()->getObject()->accept(draw_manager_);
}

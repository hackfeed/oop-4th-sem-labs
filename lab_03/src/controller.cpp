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
    std::shared_ptr<Model> model = uploader_->LoadModel(name, file_name);

    scene_manager_.GetScene()->Add(std::shared_ptr<Model>(model));
}

void Controller::AddCamera(std::string name)
{
    auto camera = new Camera(name);

    scene_manager_.GetScene()->Add(std::shared_ptr<Camera>(camera));
}

void Controller::SetCamera(std::string cam_name)
{
    scene_manager_.SetCurrentCamera(cam_name);
}

void Controller::RemoveCamera(std::string cam_name)
{
    auto scene = scene_manager_.GetScene();
    IteratorObject iter = scene->GetObject()->begin();
    IteratorObject iter_end = scene->GetObject()->end();
    bool flag = true;

    while (iter != iter_end && flag)
    {
        auto tmp = *iter;
        if (tmp->GetName() == cam_name)
        {
            flag = false;
        }
        if (flag)
        {
            ++iter;
        }
    }

    time_t t_time = time(NULL);

    if (iter != iter_end)
    {
        scene->Remove(iter);
    }
    else
    {
        throw CameraError(__FILE__, typeid(*this).name(), __LINE__, ctime(&t_time));
    }
}

void Controller::RemoveModel(std::string model_name)
{
    auto scene = scene_manager_.GetScene();
    IteratorObject iter = scene->GetObject()->begin();
    IteratorObject iter_end = scene->GetObject()->end();
    bool flag = true;

    while (iter != iter_end && flag)
    {
        auto tmp = *iter;
        if (tmp->GetName() == model_name)
        {
            flag = false;
        }
        if (flag)
        {
            ++iter;
        }
    }

    time_t t_time = time(NULL);

    if (iter != iter_end)
    {
        scene->Remove(iter);
    }
    else
    {
        throw ObjectError(__FILE__, typeid(*this).name(), __LINE__, ctime(&t_time));
    }
}

void Controller::TransformCamera(std::string cam_name, Point<double> &move, Point<double> &rotate)
{
    auto camera = std::dynamic_pointer_cast<Camera>(scene_manager_.GetScene()->GetObject(cam_name));

    transform_manager_.MoveObject(camera, move.getX(), move.getY(), move.getZ());

    camera_manager_.Roll(camera, rotate.getX());
    camera_manager_.Pitch(camera, rotate.getY());
    camera_manager_.Bend(camera, rotate.getZ());
}

void Controller::TransformModel(std::string model_name, Point<double> &move, Point<double> &scale, Point<double> &rotate)
{
    auto obj = scene_manager_.GetScene()->GetObject(model_name);

    transform_manager_.MoveObject(obj, move.getX(), move.getY(), move.getZ());
    transform_manager_.ScaleObject(obj, scale.getX(), scale.getY(), scale.getZ());
    transform_manager_.RotateX(obj, rotate.getX());
    transform_manager_.RotateY(obj, rotate.getY());
    transform_manager_.RotateZ(obj, rotate.getZ());
}

void Controller::Draw(std::shared_ptr<BaseDrawer> drawer)
{
    draw_manager_->SetDrawer(drawer);
    draw_manager_->SetCamera(scene_manager_.GetCurrentCamera());

    scene_manager_.GetScene()->GetObject()->Accept(draw_manager_);
}

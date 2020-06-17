#include "commands.hpp"
#include "point.hpp"

AddCameraCommand::AddCameraCommand(std::string name) : name_(name) {}

void AddCameraCommand::Run(std::shared_ptr<Controller> controller)
{
    controller->addCamera(name_);
}

AddModelCommand::AddModelCommand(std::string model_name, std::string file_name) : model_name(model_name), file_name(file_name) {}

void AddModelCommand::Run(std::shared_ptr<Controller> controller)
{
    controller->addModel(model_name, file_name);
}

RemoveCameraCommand::RemoveCameraCommand(std::string object_name) : object_name_(object_name) {}

void RemoveCameraCommand::Run(std::shared_ptr<Controller> controller)
{
    controller->removeCamera(object_name_);
}

RemoveModelCommand::RemoveModelCommand(std::string object_name) : object_name_(object_name) {}

void RemoveModelCommand::Run(std::shared_ptr<Controller> controller)
{
    controller->removeModel(object_name_);
}

DrawCommand::DrawCommand(std::shared_ptr<BaseDrawer> drawer) : drawer_(drawer) {}

void DrawCommand::Run(std::shared_ptr<Controller> controller)
{
    controller->draw(drawer_);
}

SetCameraCommand::SetCameraCommand(std::string name) : name_(name) {}

void SetCameraCommand::Run(std::shared_ptr<Controller> controller)
{
    controller->setCamera(name_);
}

TransformCameraCommand::TransformCameraCommand(std::string object_name, Point<double> &move, Point<double> &rotate) : object_name_(object_name), move_(move), rotate_(rotate) {}

void TransformCameraCommand::Run(std::shared_ptr<Controller> controller)
{
    controller->transformCamera(object_name_, move_, rotate_);
}

TransformModelCommand::TransformModelCommand(std::string object_name, Point<double> &move, Point<double> &scale, Point<double> &rotate) : object_name_(object_name), move_(move), scale_(scale), rotate_(rotate) {}

void TransformModelCommand::Run(std::shared_ptr<Controller> controller)
{
    controller->transformModel(object_name_, move_, scale_, rotate_);
}

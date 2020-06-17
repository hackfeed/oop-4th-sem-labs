#include "commands.hpp"
#include "point.hpp"

AddCameraCommand::AddCameraCommand(std::string name) : _name(name) {}

void AddCameraCommand::Execute(std::shared_ptr<Controller> controller)
{
    controller->addCamera(_name);
}

AddModelCommand::AddModelCommand(std::string model_name, std::string file_name) : model_name(model_name), file_name(file_name) {}

void AddModelCommand::Execute(std::shared_ptr<Controller> controller)
{
    controller->addModel(model_name, file_name);
}

RemoveCameraCommand::RemoveCameraCommand(std::string object_name) : _object_name(object_name) {}

void RemoveCameraCommand::Execute(std::shared_ptr<Controller> controller)
{
    controller->removeCamera(_object_name);
}

RemoveModelCommand::RemoveModelCommand(std::string object_name) : _object_name(object_name) {}

void RemoveModelCommand::Execute(std::shared_ptr<Controller> controller)
{
    controller->removeModel(_object_name);
}

DrawCommand::DrawCommand(std::shared_ptr<BaseDrawer> drawer) : _drawer(drawer) {}

void DrawCommand::Execute(std::shared_ptr<Controller> controller)
{
    controller->draw(_drawer);
}

SetCameraCommand::SetCameraCommand(std::string name) : _name(name) {}

void SetCameraCommand::Execute(std::shared_ptr<Controller> controller)
{
    controller->setCamera(_name);
}

TransformCameraCommand::TransformCameraCommand(std::string object_name, Point<double> &move, Point<double> &rotate) : _object_name(object_name), _move(move), _rotate(rotate) {}

void TransformCameraCommand::Execute(std::shared_ptr<Controller> controller)
{
    controller->transformCamera(_object_name, _move, _rotate);
}

TransformModelCommand::TransformModelCommand(std::string object_name, Point<double> &move, Point<double> &scale, Point<double> &rotate) : _object_name(object_name), _move(move), _scale(scale), _rotate(rotate) {}

void TransformModelCommand::Execute(std::shared_ptr<Controller> controller)
{
    controller->transformModel(_object_name, _move, _scale, _rotate);
}

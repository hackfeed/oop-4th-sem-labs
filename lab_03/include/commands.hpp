#pragma once

#include "command_base.hpp"
#include "controller.hpp"
#include "abstract_factory.hpp"
#include "qt_drawer.hpp"
#include "loader_file.hpp"

class AddCameraCommand : public BaseCommand
{
public:
    explicit AddCameraCommand(std::string name);
    void Run(std::shared_ptr<Controller> controller) override;

private:
    std::string _name;
};

class AddModelCommand : public BaseCommand
{
public:
    explicit AddModelCommand(std::string model_name, std::string file_name);

    void Run(std::shared_ptr<Controller> controller) override;

private:
    std::string model_name;
    std::string file_name;
};

class RemoveCameraCommand : public BaseCommand
{
public:
    RemoveCameraCommand(std::string object_name);
    void Run(std::shared_ptr<Controller> controller) override;

private:
    std::string _object_name;
};

class RemoveModelCommand : public BaseCommand
{
public:
    RemoveModelCommand(std::string object_name);
    void Run(std::shared_ptr<Controller> controller) override;

private:
    std::string _object_name;
};

class TransformCameraCommand : public BaseCommand
{
public:
    TransformCameraCommand(std::string _object_name, Point<double> &move, Point<double> &rotate);
    void Run(std::shared_ptr<Controller> controller) override;

private:
    std::string _object_name;
    Point<double> _move;
    Point<double> _rotate;
};

class TransformModelCommand : public BaseCommand
{
public:
    TransformModelCommand(std::string object_name, Point<double> &move, Point<double> &scale, Point<double> &rotate);
    void Run(std::shared_ptr<Controller> controller) override;

private:
    std::string _object_name;
    Point<double> _move;
    Point<double> _scale;
    Point<double> _rotate;
};

class DrawCommand : public BaseCommand
{
public:
    explicit DrawCommand(std::shared_ptr<BaseDrawer> drawer);
    void Run(std::shared_ptr<Controller> controller) override;

private:
    std::shared_ptr<BaseDrawer> _drawer;
    std::shared_ptr<AbstractFactory> _factory;
};

class SetCameraCommand : public BaseCommand
{
public:
    explicit SetCameraCommand(std::string name);
    void Run(std::shared_ptr<Controller> Controller) override;

private:
    std::string _name;
};

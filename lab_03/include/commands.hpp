#ifndef COMMANDS_HPP
#define COMMANDS_HPP

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
    std::string name_;
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
    std::string object_name_;
};

class RemoveModelCommand : public BaseCommand
{
public:
    RemoveModelCommand(std::string object_name);
    void Run(std::shared_ptr<Controller> controller) override;

private:
    std::string object_name_;
};

class TransformCameraCommand : public BaseCommand
{
public:
    TransformCameraCommand(std::string object_name_, Point<double> &move, Point<double> &rotate);
    void Run(std::shared_ptr<Controller> controller) override;

private:
    std::string object_name_;
    Point<double> move_;
    Point<double> rotate_;
};

class TransformModelCommand : public BaseCommand
{
public:
    TransformModelCommand(std::string object_name, Point<double> &move, Point<double> &scale, Point<double> &rotate);
    void Run(std::shared_ptr<Controller> controller) override;

private:
    std::string object_name_;
    Point<double> move_;
    Point<double> scale_;
    Point<double> rotate_;
};

class DrawCommand : public BaseCommand
{
public:
    explicit DrawCommand(std::shared_ptr<BaseDrawer> drawer);
    void Run(std::shared_ptr<Controller> controller) override;

private:
    std::shared_ptr<BaseDrawer> drawer_;
    std::shared_ptr<AbstractFactory> factory_;
};

class SetCameraCommand : public BaseCommand
{
public:
    explicit SetCameraCommand(std::string name);
    void Run(std::shared_ptr<Controller> Controller) override;

private:
    std::string name_;
};

#endif
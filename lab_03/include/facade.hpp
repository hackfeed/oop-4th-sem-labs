#pragma once

#include "command_base.hpp"
#include "commands.hpp"
#include "controller.hpp"
#include "exception_base.hpp"

class Facade
{
public:
    Facade();
    ~Facade();

    void ExecuteCommand(std::shared_ptr<BaseCommand> command);

private:
    std::shared_ptr<Controller> _controller;
};

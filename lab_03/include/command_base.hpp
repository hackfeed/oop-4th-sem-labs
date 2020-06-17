#ifndef COMMAND_BASE_HPP
#define COMMAND_BASE_HPP

#include "controller.hpp"

class BaseCommand
{
public:
    BaseCommand() = default;
    ~BaseCommand() = default;

    virtual void Run(std::shared_ptr<Controller> controller) = 0;
};

#endif
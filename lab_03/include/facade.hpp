#ifndef FACADE_HPP
#define FACADE_HPP

#include "command_base.hpp"
#include "commands.hpp"
#include "controller.hpp"
#include "exception_base.hpp"

class Facade
{
public:
    Facade();
    ~Facade();

    void RunCommand(std::shared_ptr<BaseCommand> command);

private:
    std::shared_ptr<Controller> controller_;
};

#endif
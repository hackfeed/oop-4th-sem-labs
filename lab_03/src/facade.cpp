#include "facade.hpp"

Facade::Facade() : controller_(Controller::GetInstance()) {}

Facade::~Facade()
{
    controller_.reset();
}

void Facade::RunCommand(std::shared_ptr<BaseCommand> command)
{
    command->Run(controller_);
}

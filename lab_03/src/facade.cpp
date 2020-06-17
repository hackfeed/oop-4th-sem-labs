#include "facade.hpp"

Facade::Facade() : _controller(Controller::GetInstance()) {}

Facade::~Facade()
{
    _controller.reset();
}

void Facade::ExecuteCommand(std::shared_ptr<BaseCommand> command)
{
    command->Run(_controller);
}

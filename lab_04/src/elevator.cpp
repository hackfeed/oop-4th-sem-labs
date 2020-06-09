#include "elevator.h"

Elevator::Elevator()
{
    QObject::connect(&controller_, SIGNAL(SetTarget(int, Direction)), &cabin_, SLOT(CabinCall(int, Direction)));
    QObject::connect(&cabin_, SIGNAL(CabinTraversingFloor(int, Direction)), &controller_, SLOT(TraversedFloor(int)));
    QObject::connect(&cabin_, SIGNAL(CabinStopped(int)), &controller_, SLOT(ReachedFloor(int)));
}

void Elevator::Click(int floor)
{
    controller_.SetNewTarget(floor);
}

#include "elevator.h"

Elevator::Elevator()
{
    QObject::connect(&controller_, SIGNAL(SetTarget(int, direction_)), &cabin_, SLOT(CabinCall(int, direction_)));
    QObject::connect(&cabin_, SIGNAL(CabinTraversingFloor(int, direction_)), &controller_, SLOT(TraversedFloor(int)));
    QObject::connect(&cabin_, SIGNAL(CabinStopped(int)), &controller_, SLOT(ReachedFloor(int)));
}

void Elevator::Click(int floor)
{
    controller_.SetNewTarget(floor);
}

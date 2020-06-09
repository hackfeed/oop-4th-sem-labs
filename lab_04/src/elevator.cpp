#include "elevator.h"

Elevator::Elevator()
{
    QObject::connect(&controller_, SIGNAL(SetTarget(int)), &cabin_, SLOT(CabinCall(int)));
    QObject::connect(&cabin_, SIGNAL(CabinTraversingFloor(int)), &controller_, SLOT(TraversedFloor(int)));
    QObject::connect(&cabin_, SIGNAL(CabinStopped(int)), &controller_, SLOT(ReachedFloor(int)));
}

void Elevator::Click(int floor)
{
    controller_.SetNewTarget(floor);
}

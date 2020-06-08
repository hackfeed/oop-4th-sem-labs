#include "lift.h"

Lift::Lift()
{
    QObject::connect(&control_panel, SIGNAL(set_target(int, direction)), &lift_cabin, SLOT(cabin_call(int, direction)));
    QObject::connect(&lift_cabin, SIGNAL(cabin_crossing_floor(int, direction)), &control_panel, SLOT(passed_floor(int)));
    QObject::connect(&lift_cabin, SIGNAL(cabin_stopped(int)), &control_panel, SLOT(achieved_floor(int)));
}

void Lift::click(int floor)
{
    control_panel.set_new_target(floor);
}

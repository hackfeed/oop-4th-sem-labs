#ifndef CONSTANTS_H
#define CONSTANTS_H

#include <QTextEdit>
#include <QTimer>

enum Direction
{
    kDown = -1,
    kStay,
    kUp
};

#define FLOOR_TRAVERSING_TIME 1500
#define DOORS_ACTIVITY_TIME 2000
#define ELEVATOR_WAITING_TIME 2000
#define FLOORS_AMOUNT 10
#define START_STATE -1

#endif

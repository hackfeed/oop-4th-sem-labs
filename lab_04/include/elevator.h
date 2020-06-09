#ifndef ELEVATOR_H
#define ELEVATOR_H

#include <QObject>
#include <QTextEdit>

#include "constants.h"
#include "elevator_cabin.h"
#include "elevator_controller.h"

class Elevator : public QObject
{
    Q_OBJECT

public:
    Elevator();
    void Click(int floor);

private:
    ElevatorController controller_;
    ElevatorCabin cabin_;
};

#endif

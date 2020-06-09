#ifndef ELEVATOR_CONTROLLER_H
#define ELEVATOR_CONTROLLER_H

#include <QObject>
#include <QVector>

#include "constants.h"

class ElevatorController : public QObject
{
    Q_OBJECT
    enum ControllerState
    {
        kFree,
        kBusy
    };

public:
    explicit ElevatorController(QObject *parent = nullptr);
    void SetNewTarget(int floor);

signals:
    void SetTarget(int floor, Direction dir);

public slots:
    void ReachedFloor(int floor);
    void TraversedFloor(int floor);

private:
    int cur_floor_;
    int cur_target_ = -1;
    QVector<bool> is_target_;
    ControllerState cur_state_;
    Direction cur_direction_;
    bool NextTarget(int &floor);
    void FindNewTarget();
};

#endif

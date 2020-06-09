#include "qdebug.h"

#include <QString>

#include "elevator_cabin.h"

ElevatorCabin::ElevatorCabin(QObject *parent) : QObject(parent),
                                                cur_floor_(1),
                                                target_(START_STATE),
                                                new_target_(false),
                                                cur_state_(kStop),
                                                cur_direction_(kStay)
{
    QObject::connect(this, SIGNAL(CabinCalled()), &doors_, SLOT(Closing()));
    QObject::connect(this, SIGNAL(CabinReachedTarget(int)), this, SLOT(CabinStop()));
    QObject::connect(this, SIGNAL(CabinStopped(int)), &doors_, SLOT(Openning()));

    QObject::connect(&doors_, SIGNAL(ClosedDoors()), this, SLOT(CabinMove()));

    traversing_floor_timer_.setSingleShot(true);
    QObject::connect(&traversing_floor_timer_, SIGNAL(timeout()), this, SLOT(CabinMove()));
}

void ElevatorCabin::CabinMove()
{
    if (new_target_ && cur_state_ == kWait)
    {
        cur_state_ = kMove;

        if (cur_floor_ == target_)
        {
            emit CabinReachedTarget(cur_floor_);
        }
        else
        {
            traversing_floor_timer_.start(FLOOR_TRAVERSING_TIME);
        }
    }
    else if (cur_state_ == kMove)
    {
        cur_state_ = kMove;

        cur_floor_ += cur_direction_;

        if (cur_floor_ == target_)
        {
            emit CabinReachedTarget(cur_floor_);
        }
        else
        {
            emit CabinTraversingFloor(cur_floor_);
            traversing_floor_timer_.start(FLOOR_TRAVERSING_TIME);
        }
    }
}

void ElevatorCabin::CabinStop()
{
    if (cur_state_ == kMove)
    {
        cur_state_ = kStop;
        qDebug() << "Elevator stopped at the floor #" << cur_floor_;
        emit CabinStopped(cur_floor_);
    }
}

void ElevatorCabin::CabinCall(int floor)
{
    if (cur_state_ == kStop)
    {
        new_target_ = true;
        cur_state_ = kWait;
        target_ = floor;

        if (target_ > cur_floor_)
        {
            cur_direction_ = kUp;
        }
        else if (target_ < cur_floor_)
        {
            cur_direction_ = kDown;
        }
        else
        {
            cur_direction_ = kStay;
        }

        emit CabinCalled();
    }
}

#include "qdebug.h"

#include <QString>

#include "elevator_cabin.h"

ElevatorCabin::ElevatorCabin(QObject *parent) : QObject(parent),
                                                cur_floor_(1),
                                                target_(-1),
                                                new_target_(false),
                                                cur_state_(kWait),
                                                cur_direction_(kStay)
{
    traversing_floor_timer_.setSingleShot(true);

    QObject::connect(this, SIGNAL(CabinCalled()), &doors_, SLOT(StartClosing()));
    QObject::connect(this, SIGNAL(CabinReachedTarget(int)), this, SLOT(CabinStop()));
    QObject::connect(this, SIGNAL(CabinStopped(int)), &doors_, SLOT(StartOpenning()));
    QObject::connect(&doors_, SIGNAL(ClosedDoors()), this, SLOT(CabinMove()));
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
            traversing_floor_timer_.start(TRAVERSING_FLOOR);
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
            emit CabinTraversingFloor(cur_floor_, cur_direction_);
            traversing_floor_timer_.start(TRAVERSING_FLOOR);
        }
    }
}

void ElevatorCabin::CabinStop()
{
    if (cur_state_ == kMove)
    {
        cur_state_ = kStop;
        qDebug() << "Elevator stopped at the floor # " << QString::number(cur_floor_) << ".";
        emit CabinStopped(cur_floor_);
    }
}

void ElevatorCabin::CabinCall(int floor, Direction dir)
{
    if (cur_state_ == kStop)
    {
        new_target_ = true;
        cur_state_ = kWait;
        target_ = floor;

        cur_direction_ = dir;
        emit CabinCalled();
    }
}

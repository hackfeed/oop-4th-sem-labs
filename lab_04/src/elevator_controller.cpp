#include "iostream"
#include "qdebug.h"

#include "elevator_controller.h"

ElevatorController::ElevatorController(QObject *parent) : QObject(parent),
                                                          cur_floor_(1),
                                                          cur_target_(START_STATE),
                                                          is_target_(FLOORS_AMOUNT, false),
                                                          cur_state_(kFree),
                                                          cur_direction_(kStay) {}

void ElevatorController::SetNewTarget(int floor)
{
    cur_state_ = kBusy;
    is_target_[floor - 1] = true;

    if (cur_target_ == START_STATE)
    {
        cur_target_ = floor;
    }

    if ((cur_direction_ == kUp && floor > cur_target_) ||
        (cur_direction_ == kDown && floor < cur_target_))
    {
        cur_target_ = floor;
    }

    NextTarget(floor);

    if (cur_floor_ > cur_target_)
    {
        cur_direction_ = kDown;
    }
    else
    {
        cur_direction_ = kUp;
    }

    emit SetTarget(floor);
}

void ElevatorController::ReachedFloor(int floor)
{
    if (cur_state_ == kBusy)
    {
        cur_floor_ = floor;
        is_target_[floor - 1] = false;

        if (cur_floor_ == cur_target_)
        {
            cur_target_ = START_STATE;
            FindNewTarget();
        }

        if (NextTarget(floor))
        {
            if (cur_floor_ > cur_target_)
            {
                cur_direction_ = kDown;
            }
            else
            {
                cur_direction_ = kUp;
            }

            emit SetTarget(floor);
        }
        else
        {
            cur_state_ = kFree;
        }
    }
}

void ElevatorController::TraversedFloor(int floor)
{
    cur_floor_ = floor;
    qDebug() << "Moving, floor #" << floor;
}

void ElevatorController::FindNewTarget()
{
    int state = false;

    if (cur_direction_ == kUp && !state)
    {
        for (int i = FLOORS_AMOUNT; i >= 1; i--)
        {
            if (is_target_[i - 1] == true)
            {
                state = true;
                cur_target_ = i;
            }
        }
    }
    else
    {
        for (int i = 1; i <= FLOORS_AMOUNT && !state; i++)
        {
            if (is_target_[i - 1])
            {
                state = true;
                cur_target_ = i;
            }
        }
    }
}

bool ElevatorController::NextTarget(int &floor)
{
    int state = false;
    bool flag = true;

    if (cur_target_ > cur_floor_)
    {
        for (int i = cur_floor_; i <= FLOORS_AMOUNT && flag; i += 1)
        {
            if (is_target_[i - 1])
            {
                floor = i;
                state = true;
                flag = false;
            }
        }
    }
    else
    {
        for (int i = cur_floor_; i >= 1 && flag; i -= 1)
        {
            if (is_target_[i - 1])
            {
                floor = i;
                state = true;
                flag = false;
            }
        }
    }

    return state;
}

#include "qdebug.h"

#include "elevator_doors.h"

ElevatorDoors::ElevatorDoors(QObject *parent) : QObject(parent),
                                                cur_state_(kClosed)
{
    doors_wait_timer_.setInterval(WAITING_TIME);
    doors_wait_timer_.setSingleShot(true);

    doors_open_timer_.setSingleShot(true);
    doors_close_timer_.setSingleShot(true);

    QObject::connect(&doors_open_timer_, SIGNAL(timeout()), this, SLOT(Open()));
    QObject::connect(&doors_close_timer_, SIGNAL(timeout()), this, SLOT(Close()));
    QObject::connect(this, SIGNAL(OpenedDoors()), &doors_wait_timer_, SLOT(start()));
    QObject::connect(&doors_wait_timer_, SIGNAL(timeout()), this, SLOT(StartClosing()));
}

void ElevatorDoors::StartOpenning()
{
    if (cur_state_ == kClosed)
    {
        cur_state_ = kOpenning;
        qDebug() << "Doors are openning";
        doors_open_timer_.start(DOORS_TIME);
    }
    if (cur_state_ == kClosing)
    {
        cur_state_ = kOpenning;
        qDebug() << "Doors are openning";
        int t = doors_close_timer_.remainingTime();
        doors_close_timer_.stop();
        doors_open_timer_.start(DOORS_TIME - t);
    }
}

void ElevatorDoors::StartClosing()
{
    if (cur_state_ == kOpened)
    {
        cur_state_ = kClosing;
        qDebug() << "Doors are closing";
        doors_close_timer_.start(DOORS_TIME);
    }
    else if (cur_state_ == kClosed)
    {
        emit ClosedDoors();
    }
}

void ElevatorDoors::Open()
{
    if (cur_state_ == kOpenning)
    {
        cur_state_ = kOpened;
        qDebug() << "Doors are opened. Elevator is waiting for incoming and outcoming passengers";
        emit OpenedDoors();
    }
}

void ElevatorDoors::Close()
{
    if (cur_state_ == kClosing)
    {
        cur_state_ = kClosed;
        qDebug() << "Doors are closed";
        emit ClosedDoors();
    }
}

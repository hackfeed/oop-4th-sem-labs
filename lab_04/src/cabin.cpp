#include "cabin.h"

#include <QString>

#include "qdebug.h"

Lift_cabin::Lift_cabin(QObject *parent) : QObject(parent),
                                          current_floor(1),
                                          target(-1),
                                          new_target(false),
                                          current_state(STOP),
                                          current_direction(STAY) {
    crossing_floor_timer.setSingleShot(true);

    QObject::connect(this, SIGNAL(cabin_called()), &doors, SLOT(start_closing()));
    QObject::connect(this, SIGNAL(cabin_reached_target(int)), this, SLOT(cabin_stopping()));
    QObject::connect(this, SIGNAL(cabin_stopped(int)), &doors, SLOT(start_openning()));
    QObject::connect(&doors, SIGNAL(closed_doors()), this, SLOT(cabin_move()));
    QObject::connect(&crossing_floor_timer, SIGNAL(timeout()), this, SLOT(cabin_move()));
}

void Lift_cabin::cabin_move() {
    if (new_target && current_state == WAIT) {
        current_state = MOVE;
        if (current_floor == target) {
            emit cabin_reached_target(current_floor);
        } else {
            crossing_floor_timer.start(CROSSING_FLOOR);
        }
    } else if (current_state == MOVE) {
        current_state = MOVE;

        current_floor += current_direction;

        if (current_floor == target) {
            emit cabin_reached_target(current_floor);
        } else {
            emit cabin_crossing_floor(current_floor, current_direction);
            crossing_floor_timer.start(CROSSING_FLOOR);
        }
    }
}

void Lift_cabin::cabin_stopping() {
    if (current_state == MOVE) {
        current_state = STOP;
        qDebug() << "Лифт остановился на этаже " << QString::number(current_floor) << ".";
        emit cabin_stopped(current_floor);
    }
}

void Lift_cabin::cabin_call(int floor, direction dir) {
    if (current_state == STOP) {
        new_target = true;
        current_state = WAIT;
        target = floor;

        current_direction = dir;
        emit cabin_called();
    }
}

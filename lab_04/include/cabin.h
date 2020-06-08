#ifndef LIFTCAB_H
#define LIFTCAB_H

#include <QObject>

#include "constants.h"
#include "controlpanel.h"
#include "doors.h"

class Lift_cabin : public QObject {
    Q_OBJECT
    enum cabin_state {
        MOVE,
        WAIT,
        STOP
    };

   public:
    explicit Lift_cabin(QObject *parent = nullptr);

   signals:
    void cabin_called();
    void cabin_crossing_floor(int floor, direction d);
    void cabin_reached_target(int floor);
    void cabin_stopped(int floor);

   public slots:
    void cabin_move();
    void cabin_stopping();
    void cabin_call(int floor, direction dir);

   private:
    int current_floor;
    int target;
    bool new_target;
    cabin_state current_state;
    direction current_direction;
    Lift_doors doors;
    QTimer crossing_floor_timer;
};

#endif  // LIFTCAB_H

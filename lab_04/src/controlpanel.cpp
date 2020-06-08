#include "controlpanel.h"

#include "iostream"
#include "qdebug.h"

// начальное состояние контрольной панели
Control_panel::Control_panel(QObject *parent) : QObject(parent),
                                                cur_floor(1),
                                                cur_target(-1),
                                                is_target(NUM_FLOORS, false),
                                                current_state(FREE),
                                                cur_direction(STAY) {}

void Control_panel::set_new_target(int floor) {
    current_state = BUSY;
    is_target[floor - 1] = true;

    if (cur_target == -1) {
        cur_target = floor;
    }

    if ((cur_direction == UP && floor > cur_target) || (cur_direction == DOWN && floor < cur_target)) {
        cur_target = floor;
    }

    next_target(floor);  // выбор следующей цели
    cur_direction = (cur_floor > cur_target) ? DOWN : UP;
    emit set_target(floor, cur_direction);  // передача цели кабине
}

void Control_panel::achieved_floor(int floor) {
    if (current_state == BUSY) {
        cur_floor = floor;
        is_target[floor - 1] = false;
        if (cur_floor == cur_target) {
            cur_target = -1;
            find_new_target();
        }

        if (next_target(floor)) {  // если существует еще какой-то вызов

            cur_direction = (cur_floor > cur_target) ? DOWN : UP;

            emit set_target(floor, cur_direction);
        } else {
            current_state = FREE;
        }
    }
}

void Control_panel::passed_floor(int floor) {
    cur_floor = floor;
    qDebug() << "Движение, этаж" << floor;
}

void Control_panel::find_new_target() {
    int state = false;
    if (cur_direction == UP && !state) {
        for (int i = NUM_FLOORS; i >= 1; i--) {
            if (is_target[i - 1] == true) {
                state = true;
                cur_target = i;
            }
        }
    } else {
        for (int i = 1; i <= NUM_FLOORS && !state; i++) {
            if (is_target[i - 1]) {
                state = true;
                cur_target = i;
            }
        }
    }
}

// выбирается следующий этаж, на который поедет лифт
bool Control_panel::next_target(int &floor) {
    int state = false;
    bool flag = true;
    if (cur_target > cur_floor) {
        for (int i = cur_floor; i <= NUM_FLOORS && flag; i += 1) {
            if (is_target[i - 1]) {
                floor = i;
                state = true;
                flag = false;
            }
        }
    } else {
        for (int i = cur_floor; i >= 1 && flag; i -= 1) {
            if (is_target[i - 1]) {
                floor = i;
                state = true;
                flag = false;
                ;
            }
        }
    }
    return state;
}

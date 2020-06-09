#ifndef ELEVATOR_DOORS_H
#define ELEVATOR_DOORS_H

#include <QObject>

#include "constants.h"

class ElevatorDoors : public QObject
{
    Q_OBJECT
    enum DoorsState
    {
        kOpened,
        kClosed,
        kOpenning,
        kClosing
    };

public:
    explicit ElevatorDoors(QObject *parent = nullptr);

signals:
    void ClosedDoors();
    void OpenedDoors();

public slots:
    void Openning();
    void Closing();

private slots:
    void Open();
    void Close();

private:
    DoorsState cur_state_;
    QTimer doors_open_timer_;
    QTimer doors_close_timer_;
    QTimer doors_wait_timer_;
};

#endif

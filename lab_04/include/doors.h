#ifndef LIFTDOORS_H
#define LIFTDOORS_H

#include <QObject>

#include "constants.h"

class Lift_doors : public QObject
{
    Q_OBJECT
    enum doors_state
    {
        OPENED,
        CLOSED,
        OPENNING,
        CLOSING
    };

public:
    explicit Lift_doors(QObject *parent = nullptr);

signals:
    void closed_doors();
    void opened_doors();

public slots:
    void start_openning();
    void start_closing();

private slots:
    void open();
    void close();

private:
    doors_state current_state;
    QTimer doors_open_timer;
    QTimer doors_close_timer;
    QTimer doors_stay_open_timer;
};

#endif // LIFTDOORS_H

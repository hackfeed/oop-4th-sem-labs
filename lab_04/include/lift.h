#ifndef LIFT_H
#define LIFT_H

#include <QObject>
#include <QTextEdit>

#include "cabin.h"
#include "constants.h"
#include "controlpanel.h"

class Lift : public QObject
{
    Q_OBJECT

public:
    Lift();
    void click(int floor);

private:
    Control_panel control_panel;
    Lift_cabin lift_cabin;
};

#endif // LIFT_H

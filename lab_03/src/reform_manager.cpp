#include "reform_manager.h"

void reform_manager::reform_object(std::shared_ptr<object> _object, const point &move, const point &scale, const point &turn)
{
    _object->reform(move, scale, turn);
}

void reform_manager::move_object(std::shared_ptr<object> _object, const double &dx, const double &dy, const double &dz)
{
    point move(dx, dy, dz);
    point scale(1, 1, 1);
    point turn(0, 0, 0);

    _object->reform(move, scale, turn);
}

void reform_manager::scale_object(std::shared_ptr<object> _object, const double &kx, const double &ky, const double &kz)
{
    point move(0, 0, 0);
    point scale(kx, ky, kz);
    point turn(0, 0, 0);

    _object->reform(move, scale, turn);
}

void reform_manager::turn_object(std::shared_ptr<object> _object, const double &ox, const double &oy, const double &oz)
{
    point move(0, 0, 0);
    point scale(1, 1, 1);
    point turn(ox, oy, oz);

    _object->reform(move, scale, turn);
}


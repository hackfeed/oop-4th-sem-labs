#include "camera.h"
#include "visitor.h"

void camera::move_x(const double &shift)
{
    this->current_pos.set_x(this->current_pos.get_x() + shift);
}

void camera::move_y(const double &shift)
{
    this->current_pos.set_y(this->current_pos.get_y() + shift);
}

void camera::move_z(const double &shift)
{
    this->current_pos.set_z(this->current_pos.get_z() + shift);
}

void camera::reform(const point &new_pos, const point &scale, const point &turn)
{
    this->move_x(new_pos.get_x());
    this->move_y(new_pos.get_y());
}

void camera::accept(std::shared_ptr<visitor> _visitor)
{
    _visitor->visit(*this);
}

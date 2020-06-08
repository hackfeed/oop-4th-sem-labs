#include "model.h"

model::model(const model &_model)
{
    this->_details = _model.get_details();
}

std::unique_ptr<model> model::clone()
{
    return std::unique_ptr<model>(new model(*this));
}

void model::add_point(const point &point)
{
    this->_details->add_point(point);
}

void model::add_link(const link &link)
{
    this->_details->add_link(link);
}

void model::reform(const point &move_coeff, const point &scale_coeff, const point &turn_coeff)
{
    this->_details->reform(move_coeff, scale_coeff, turn_coeff);
}

void model::accept(std::shared_ptr<visitor> _visitor)
{
    _visitor->visit(*this);
}

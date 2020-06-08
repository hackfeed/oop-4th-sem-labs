#include "builder.h"

bool model_builder::is_build() const
{
    return this->model_ptr != nullptr;
}

void model_builder::build()
{
    this->model_ptr = std::make_shared<model>();
}

void model_builder::build_point(const double &x, const double &y, const double &z)
{
    if (!is_build())
    {
        qDebug() << "point fail";
    }

    point pt_obj(x, y, z);
    this->model_ptr->add_point(pt_obj);
}

void model_builder::build_link(const size_t &pt1, const size_t &pt2)
{
    if (!is_build())
    {
        qDebug() << "link fail";
    }

    link link_obj(pt1, pt2);
    this->model_ptr->add_link(link_obj);
}

std::shared_ptr<model> model_builder::get()
{
    return model_ptr;
}

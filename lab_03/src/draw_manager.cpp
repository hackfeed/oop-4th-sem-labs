#include "draw_manager.h"
#include "model.h"
#include "camera.h"

void draw_manager::set_drawer(std::shared_ptr<base_drawer> drawer_)
{
    this->_drawer = drawer_;
}

void draw_manager::set_cam(std::shared_ptr<camera> new_cam)
{
    this->cam = new_cam;
}

void draw_manager::visit(const model &_model)
{
    auto points = _model.get_details()->get_points();

    for (auto link : _model.get_details()->get_links())
    {

        this->_drawer->draw_line(
            proect_point(points.at(link.get_fst())),
            proect_point(points.at(link.get_snd())));
    }
}

point draw_manager::proect_point(const point &_point)
{
    point new_point(_point);
    point cam_pos(cam->get_pos());
    new_point.set_x(new_point.get_x() + cam_pos.get_x());
    new_point.set_y(new_point.get_y() + cam_pos.get_y());

    return new_point;
}

void draw_manager::visit(const camera &camera){};
void draw_manager::visit(const composite &composite){};

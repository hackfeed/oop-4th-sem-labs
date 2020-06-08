#include "details.h"

void details::add_point(const point &pt)
{
    this->points.push_back(pt);
}

void details::add_link(const link &link)
{
    this->links.push_back(link);
}

const vector<point> &details::get_points() const
{
    return this->points;
}

const vector<link> &details::get_links() const
{
    return this->links;
}

void details::reform(const point &_move, const point &_scale, const point &_turn)
{
    for (auto &pt: points)
    {
        pt.move(_move.get_x(), _move.get_y(), _move.get_z());
        pt.scale(_scale.get_x(), _scale.get_y(), _scale.get_z());
        pt.turn(_turn.get_x(), _turn.get_y(), _turn.get_z());
    }
}

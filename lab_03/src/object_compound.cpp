#include "object_compound.hpp"

void Compound::AddPoints(const Vector<Point<double>> &points)
{
    points_ = points;
}

void Compound::AddLinks(const Vector<Link> &links)
{
    edges_ = links;
}

Compound::Compound(const Vector<Point<double>> &points, const Vector<Link> &links)
{
    points_ = points;
    edges_ = links;
}

Vector<Link> &Compound::GetLinks()
{
    return edges_;
}

Vector<Point<double>> &Compound::GetPoints()
{
    return points_;
}

void Compound::Transform(const std::shared_ptr<Matrix<double>> mtr)
{
    for (int i = 0; i < points_.size(); i++)
    {
        points_[i].Transform(mtr);
    }
}

Vector<pair<Point<double>, Point<double>>> Compound::GetLines()
{
    Vector<pair<Point<double>, Point<double>>> lines;
    for (int i = 0; i < edges_.size(); i++)
    {
        pair<Point<double>, Point<double>> tmp(points_[edges_[i].getBegin()], points_[edges_[i].getEnd()]);
        lines.push_back(tmp);
    }

    return lines;
}

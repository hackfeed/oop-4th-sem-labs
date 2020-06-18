#include "object_compound.hpp"

void Compound::AddPoints(const Vector<Point<double>> &points)
{
    points_ = points;
}

void Compound::AddLinks(const Vector<Link> &links)
{
    links_ = links;
}

Compound::Compound(const Vector<Point<double>> &points, const Vector<Link> &links)
{
    points_ = points;
    links_ = links;
}

Vector<Link> &Compound::GetLinks()
{
    return links_;
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

Vector<Pair<Point<double>, Point<double>>> Compound::GetLines()
{
    Vector<Pair<Point<double>, Point<double>>> lines;

    for (int i = 0; i < links_.size(); i++)
    {
        Pair<Point<double>, Point<double>> tmp(points_[links_[i].GetBegin()], points_[links_[i].GetEnd()]);
        lines.push_back(tmp);
    }

    return lines;
}

#include "object_compound.hpp"

void Compound::addPoints(const Vector<Point<double>> &points)
{
    _points = points;
}

void Compound::addEdges(const Vector<Link> &edges)
{
    _edges = edges;
}

Compound::Compound(const Vector<Point<double>> &points, const Vector<Link> &edges)
{
    _points = points;
    _edges = edges;
}

Vector<Link> &Compound::getEdges()
{
    return _edges;
}

Vector<Point<double>> &Compound::getPoints()
{
    return _points;
}

void Compound::transform(const std::shared_ptr<Matrix<double>> mtr)
{
    for (int i = 0; i < _points.size(); i++)
    {
        _points[i].transform(mtr);
    }
}

Vector<pair<Point<double>, Point<double>>> Compound::getLines()
{
    Vector<pair<Point<double>, Point<double>>> lines;
    for (int i = 0; i < _edges.size(); i++)
    {
        pair<Point<double>, Point<double>> tmp(_points[_edges[i].getBegin()], _points[_edges[i].getEnd()]);
        lines.push_back(tmp);
    }

    return lines;
}

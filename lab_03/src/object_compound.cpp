#include "object_compound.hpp"

void Mesh::addPoints(const Vector<Point<double>> &points)
{
    _points = points;
}

void Mesh::addEdges(const Vector<Edge> &edges)
{
    _edges = edges;
}

Mesh::Mesh(const Vector<Point<double>> &points, const Vector<Edge> &edges)
{
    _points = points;
    _edges = edges;
}

Vector<Edge> &Mesh::getEdges()
{
    return _edges;
}

Vector<Point<double>> &Mesh::getPoints()
{
    return _points;
}

void Mesh::transform(const std::shared_ptr<matrix<double>> mtr)
{
    for (int i = 0; i < _points.size(); i++)
    {
        _points[i].transform(mtr);
    }
}

Vector<pair<Point<double>, Point<double>>> Mesh::getLines()
{
    Vector<pair<Point<double>, Point<double>>> lines;
    for (int i = 0; i < _edges.size(); i++)
    {
        pair<Point<double>, Point<double>> tmp(_points[_edges[i].getBegin()], _points[_edges[i].getEnd()]);
        lines.push_back(tmp);
    }

    return lines;
}

#pragma once

#include "matrix.hpp"
#include "pair.hpp"
#include "vector.hpp"
#include "link.hpp"
#include "point.hpp"

class Compound
{ // свести к базовому классу
public:
    Compound() = default;
    Compound(const Vector<Point<double>> &points, const Vector<Edge> &edges);
    ~Compound() = default;
    void addPoints(const Vector<Point<double>> &points);
    void addEdges(const Vector<Edge> &edges);
    Vector<Edge> &getEdges();
    Vector<Point<double>> &getPoints();
    void transform(const std::shared_ptr<matrix<double>> mtr);
    Vector<pair<Point<double>, Point<double>>> getLines();

private:
    Vector<Point<double>> _points;
    Vector<Edge> _edges;
};

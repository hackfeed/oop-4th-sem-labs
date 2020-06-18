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
    Compound(const Vector<Point<double>> &points, const Vector<Link> &edges);
    ~Compound() = default;
    void addPoints(const Vector<Point<double>> &points);
    void addEdges(const Vector<Link> &edges);
    Vector<Link> &getEdges();
    Vector<Point<double>> &getPoints();
    void transform(const std::shared_ptr<Matrix<double>> mtr);
    Vector<pair<Point<double>, Point<double>>> getLines();

private:
    Vector<Point<double>> _points;
    Vector<Link> _edges;
};

#ifndef OBJECT_COMPOUND_HPP
#define OBJECT_COMPOUND_HPP

#include "matrix.hpp"
#include "pair.hpp"
#include "vector.hpp"
#include "link.hpp"
#include "point.hpp"

class Compound
{
public:
    Compound() = default;
    Compound(const Vector<Point<double>> &points, const Vector<Link> &links);
    ~Compound() = default;

    void AddPoints(const Vector<Point<double>> &points);
    void AddLinks(const Vector<Link> &links);
    Vector<Point<double>> &GetPoints();
    Vector<Link> &GetLinks();
    void Transform(const std::shared_ptr<Matrix<double>> mtr);
    Vector<Pair<Point<double>, Point<double>>> GetLines();

private:
    Vector<Point<double>> points_;
    Vector<Link> edges_;
};

#endif
#pragma once

#include <cmath>

#include "matrix.hpp"

class MoveMatrix : public matrix<double>
{
public:
    MoveMatrix(double x, double y, double z);
};

class ScaleMatrix : public matrix<double>
{
public:
    ScaleMatrix(double x, double y, double z);
};

class RotateOxMatrix : public matrix<double>
{
public:
    RotateOxMatrix(double angle);
};

class RotateOyMatrix : public matrix<double>
{
public:
    RotateOyMatrix(double angle);
};

class RotateOzMatrix : public matrix<double>
{
public:
    RotateOzMatrix(double angle);
};

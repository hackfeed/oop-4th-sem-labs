#pragma once

#include <cmath>

#include "matrix.hpp"

class MoveMatrix : public Matrix<double>
{
public:
    MoveMatrix(double x, double y, double z);
};

class ScaleMatrix : public Matrix<double>
{
public:
    ScaleMatrix(double x, double y, double z);
};

class RotateOxMatrix : public Matrix<double>
{
public:
    RotateOxMatrix(double angle);
};

class RotateOyMatrix : public Matrix<double>
{
public:
    RotateOyMatrix(double angle);
};

class RotateOzMatrix : public Matrix<double>
{
public:
    RotateOzMatrix(double angle);
};

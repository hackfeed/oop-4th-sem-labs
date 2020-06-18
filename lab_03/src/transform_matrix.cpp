#include "transform_matrix.h"

MoveMatrix::MoveMatrix(double x, double y, double z) : Matrix<double>(4, 4, 0)
{
    (*this)[0][0] = 1;
    (*this)[1][1] = 1;
    (*this)[2][2] = 1;
    (*this)[3][3] = 1;
    (*this)[0][3] = x;
    (*this)[1][3] = y;
    (*this)[2][3] = z;
}

ScaleMatrix::ScaleMatrix(double x, double y, double z) : Matrix<double>(4, 4, 0)
{
    (*this)[0][0] = x;
    (*this)[1][1] = y;
    (*this)[2][2] = z;
    (*this)[3][3] = 1;
}

RotateOxMatrix::RotateOxMatrix(double angle) : Matrix<double>(4, 4, 0)
{
    (*this)[0][0] = 1;
    (*this)[1][1] = cos(angle);
    (*this)[1][2] = -sin(angle);
    (*this)[2][1] = sin(angle);
    (*this)[2][2] = cos(angle);
    (*this)[3][3] = 1;
}

RotateOyMatrix::RotateOyMatrix(double angle) : Matrix<double>(4, 4, 0)
{
    (*this)[0][0] = cos(angle);
    (*this)[1][1] = 1;
    (*this)[2][0] = -sin(angle);
    (*this)[0][2] = sin(angle);
    (*this)[2][2] = cos(angle);
    (*this)[3][3] = 1;
}

RotateOzMatrix::RotateOzMatrix(double angle) : Matrix<double>(4, 4, 0)
{
    (*this)[0][0] = cos(angle);
    (*this)[0][1] = -sin(angle);
    (*this)[1][0] = sin(angle);
    (*this)[1][1] = cos(angle);
    (*this)[2][2] = 1;
    (*this)[3][3] = 1;
}

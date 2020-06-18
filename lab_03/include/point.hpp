#pragma once

#include <istream>
#include <memory>

#include "vector.hpp"
#include "matrix.hpp"

template <typename T>
class Point
{
public:
    explicit Point();
    explicit Point(const T &x, const T &y, const T &z);
    Point(const Point &other);
    Point &operator=(const Point &rhs);

    T getX() const;
    T getY() const;
    T getZ() const;

    void setX(T x);
    void setY(T y);
    void setZ(T z);

    void transform(const std::shared_ptr<Matrix<T>> mtr);

    Point &operator+=(const Point &);
    Point &operator+=(const T &);
    Point &operator-=(const Point &);
    Point &operator-=(const T &);
    Point &operator*=(const Point &);
    Point &operator*=(const T &);
    Point &operator/=(const Point &);
    Point &operator/=(const T &);

private:
    T x_, y_, z_;
};

template <typename T>
std::istream &operator>>(std::istream &is, Point<T> &point);

template <typename T>
Point<T>::Point() : x_(0), y_(0), z_(0) {}

template <typename T>
Point<T>::Point(const T &x, const T &y, const T &z)
    : x_(x), y_(y), z_(z) {}

template <typename T>
Point<T>::Point(const Point<T> &other)
    : Point(other.x_, other.y_, other.z_) {}

template <typename T>
Point<T> &Point<T>::operator=(const Point<T> &rhs)
{
    x_ = rhs.x_;
    y_ = rhs.y_;
    z_ = rhs.z_;

    return *this;
}

template <typename T>
Point<T> &Point<T>::operator+=(const Point<T> &pnt)
{
    x_ += pnt.x_;
    y_ += pnt.y_;
    z_ += pnt.z_;

    return *this;
}

template <typename T>
Point<T> &Point<T>::operator+=(const T &value)
{
    x_ += value;
    y_ += value;
    z_ += value;

    return *this;
}

template <typename T>
Point<T> &Point<T>::operator-=(const Point<T> &rhs)
{
    x_ -= rhs.x_;
    y_ -= rhs.y_;
    z_ -= rhs.z_;

    return *this;
}

template <typename T>
Point<T> &Point<T>::operator-=(const T &value)
{
    x_ -= value;
    y_ -= value;
    z_ -= value;

    return *this;
}

template <typename T>
Point<T> &Point<T>::operator*=(const Point<T> &rhs)
{
    x_ *= rhs.x_;
    y_ *= rhs.y_;
    z_ *= rhs.z_;

    return *this;
}

template <typename T>
Point<T> &Point<T>::operator*=(const T &value)
{
    x_ *= value;
    y_ *= value;
    z_ *= value;

    return *this;
}

template <typename T>
Point<T> &Point<T>::operator/=(const Point<T> &rhs)
{
    x_ /= rhs.x_;
    y_ /= rhs.y_;
    z_ /= rhs.z_;

    return *this;
}

template <typename T>
Point<T> &Point<T>::operator/=(const T &value)
{
    x_ /= value;
    y_ /= value;
    z_ /= value;

    return *this;
}

template <typename T>
T Point<T>::getX() const
{
    return x_;
}

template <typename T>
T Point<T>::getY() const
{
    return y_;
}

template <typename T>
T Point<T>::getZ() const
{
    return z_;
}

template <typename T>
void Point<T>::setX(T x)
{
    x_ = x;
}

template <typename T>
void Point<T>::setY(T y)
{
    y_ = y;
}

template <typename T>
void Point<T>::setZ(T z)
{
    z_ = z;
}

template <typename T>
void Point<T>::transform(const std::shared_ptr<Matrix<T>> mtr)
{
    Vector<T> result(4, 0);
    Vector<T> data = {x_, y_, z_, 1.0};
    for (size_t i = 0; i < 4; i++)
    {
        for (size_t j = 0; j < 4; j++)
        {
            result[i] += data[j] * (*mtr)[i][j];
        }
    }

    this->setX(result[0]);
    this->setY(result[1]);
    this->setZ(result[2]);
}

template <typename T>
std::istream &operator>>(std::istream &is, Point<T> &point)
{
    T x, y, z;
    is >> x >> y >> z;
    point.setX(x);
    point.setY(y);
    point.setZ(z);

    return is;
}

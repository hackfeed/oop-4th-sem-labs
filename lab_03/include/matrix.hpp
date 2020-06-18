#pragma once

#include "matrix_base.hpp"

template <class T>
class matrix : public MatrixBase<T>
{
public:
    typedef typename MatrixBase<T>::iterator iterator;
    typedef typename MatrixBase<T>::const_iterator const_iterator;

    explicit matrix(size_t, size_t);
    explicit matrix(size_t, size_t, const T &);
    matrix(size_t, size_t, iterator, iterator);
    matrix(size_t, size_t, const_iterator, const_iterator);
    matrix(size_t, size_t, std::initializer_list<T>);
    matrix(const matrix &);
    matrix(matrix &&);
    virtual ~matrix() = default;
    matrix &operator=(const matrix &);
    matrix &operator=(matrix &&);
    matrix &operator=(std::initializer_list<T>);

    template <class U>
    friend matrix<U> operator+(const matrix<U> &, const matrix<U> &);
    template <class U>
    friend matrix<U> operator+(const matrix<U> &, const U &);
    matrix &operator+=(const matrix &);
    matrix &operator+=(const T &);
    template <class U>
    friend matrix<U> operator-(const matrix<U> &, const matrix<U> &);
    template <class U>
    friend matrix<U> operator-(const matrix<U> &, const U &);
    matrix &operator-=(const matrix &);
    matrix &operator-=(const T &);
    template <class U>
    friend matrix<U> operator*(const matrix<U> &, const matrix<U> &);
    template <class U>
    friend matrix<U> operator*(const matrix<U> &, const U &);
    matrix &operator*=(const matrix &);
    matrix &operator*=(const T &);
    template <class U>
    friend matrix<U> operator/(const matrix<U> &, const U &);
    matrix &operator/=(const T &);
};

template <class T>
matrix<T>::matrix(size_t row_count, size_t col_count)
    : MatrixBase<T>(row_count, col_count)
{
}

template <class T>
matrix<T>::matrix(size_t row_count, size_t col_count, const T &value)
    : MatrixBase<T>(row_count, col_count, value)
{
}

template <class T>
matrix<T>::matrix(size_t row_count, size_t col_count, iterator first, iterator last)
    : MatrixBase<T>(row_count, col_count, first, last)
{
}

template <class T>
matrix<T>::matrix(size_t row_count, size_t col_count, const_iterator first, const_iterator last)
    : MatrixBase<T>(row_count, col_count, first, last)
{
}

template <class T>
matrix<T>::matrix(size_t row_count, size_t col_count, std::initializer_list<T> lst)
    : MatrixBase<T>(row_count, col_count, lst)
{
}

template <class T>
matrix<T>::matrix(const matrix &other)
    : MatrixBase<T>(other)
{
}

template <class T>
matrix<T>::matrix(matrix &&other)
    : MatrixBase<T>(std::move(other))
{
}

template <class T>
matrix<T> &matrix<T>::operator=(const matrix<T> &rhs)
{
    MatrixBase<T>::operator=(rhs);

    return *this;
}

template <class T>
matrix<T> &matrix<T>::operator=(matrix<T> &&rhs)
{
    MatrixBase<T>::operator=(std::move(rhs));

    return *this;
}

template <class T>
matrix<T> &matrix<T>::operator=(std::initializer_list<T> lst)
{
    MatrixBase<T>::operator=(lst);

    return *this;
}

template <class T>
matrix<T> operator+(const matrix<T> &lhs, const matrix<T> &rhs)
{
    matrix<T> result = lhs;
    size_t rows_count = lhs.rows() < rhs.rows() ? lhs.rows() : rhs.rows();
    size_t cols_count = lhs.columns() < rhs.columns() ? lhs.columns() : rhs.columns();

    for (size_t i = 0; i < rows_count; ++i)
    {
        for (size_t j = 0; j < cols_count; ++j)
        {
            result[i][j] += rhs[i][j];
        }
    }

    return result;
}

template <class T>
matrix<T> operator+(const matrix<T> &mtx, const T &value)
{
    matrix<T> result = mtx;

    for (size_t i = 0; i < mtx.capacity(); ++i)
    {
        result._data[i] += value;
    }

    return result;
}

template <class T>
matrix<T> &matrix<T>::operator+=(const matrix<T> &rhs)
{
    size_t rows_count = this->rows() < rhs.rows() ? this->rows() : rhs.rows();
    size_t cols_count = this->columns() < rhs.columns() ? this->columns() : rhs.columns();

    for (size_t i = 0; i < rows_count; ++i)
    {
        for (size_t j = 0; j < cols_count; ++j)
        {
            (*this)[i][j] += rhs[i][j];
        }
    }

    return *this;
}

template <class T>
matrix<T> &matrix<T>::operator+=(const T &value)
{
    for (size_t i = 0; i < this->capacity(); ++i)
    {
        this->_data[i] += value;
    }

    return *this;
}

template <class T>
matrix<T> operator-(const matrix<T> &lhs, const matrix<T> &rhs)
{
    matrix<T> result = lhs;
    size_t rows_count = lhs.rows() < rhs.rows() ? lhs.rows() : rhs.rows();
    size_t cols_count = lhs.columns() < rhs.columns() ? lhs.columns() : rhs.columns();

    for (size_t i = 0; i < rows_count; ++i)
    {
        for (size_t j = 0; j < cols_count; ++j)
        {
            result[i][j] -= rhs[i][j];
        }
    }

    return result;
}

template <class T>
matrix<T> operator-(const matrix<T> &mtx, const T &value)
{
    matrix<T> result = mtx;

    for (size_t i = 0; i < mtx.capacity(); ++i)
    {
        result._data[i] -= value;
    }

    return result;
}

template <class T>
matrix<T> &matrix<T>::operator-=(const matrix<T> &rhs)
{
    size_t rows_count = this->rows() < rhs.rows() ? this->rows() : rhs.rows();
    size_t cols_count = this->columns() < rhs.columns() ? this->columns() : rhs.columns();

    for (size_t i = 0; i < rows_count; ++i)
    {
        for (size_t j = 0; j < cols_count; ++j)
        {
            (*this)[i][j] -= rhs[i][j];
        }
    }

    return *this;
}

template <class T>
matrix<T> &matrix<T>::operator-=(const T &value)
{
    for (size_t i = 0; i < this->capacity(); ++i)
    {
        this->_data[i] -= value;
    }

    return *this;
}

template <class T>
matrix<T> operator*(const matrix<T> &lhs, const matrix<T> &rhs)
{
    if (lhs.columns() == rhs.rows())
    {
        matrix<T> result = lhs;

        for (size_t i = 0; i < lhs.rows(); ++i)
        {
            for (size_t j = 0; j < rhs.columns(); ++j)
            {
                for (size_t k = 0; k < lhs.columns(); ++k)
                {
                    result[i][j] += lhs[i][k] * rhs[k][j];
                }
            }
        }

        return result;
    }
    else
    {
        time_t t_time(NULL);
        throw RangeError(__FILE__, "matrix<T>::operator*", __LINE__, ctime(&t_time));
    }
}

template <class T>
matrix<T> &operator*(const matrix<T> &mtx, const T &value)
{
    matrix<T> result = mtx;

    for (size_t i = 0; i < mtx.capacity(); ++i)
    {
        result._data[i] *= value;
    }

    return result;
}

template <class T>
matrix<T> &matrix<T>::operator*=(const matrix<T> &rhs)
{
    if (this->columns() == rhs.rows())
    {
        for (size_t i = 0; i < this->rows(); ++i)
        {
            for (size_t j = 0; j < rhs.columns(); ++j)
            {
                for (size_t k = 0; k < this->columns(); ++k)
                {
                    (*this)[i][j] = (*this)[i][k] * rhs[k][j];
                }
            }
        }

        return *this;
    }
    else
    {
        time_t t_time(NULL);
        throw RangeError(__FILE__, typeid((*this).name(), __LINE__, ctime(&t_time)));
    }
}

template <class T>
matrix<T> &matrix<T>::operator*=(const T &value)
{
    for (size_t i = 0; i < this->capacity(); ++i)
    {
        this->_data[i] *= value;
    }

    return *this;
}

template <class T>
matrix<T> &operator/(const matrix<T> &mtx, const T &value)
{
    matrix<T> result = mtx;

    for (size_t i = 0; i < mtx.capacity(); ++i)
    {
        result._data[i] /= value;
    }

    return result;
}

template <class T>
matrix<T> &matrix<T>::operator/=(const T &value)
{
    for (size_t i = 0; i < this->capacity(); ++i)
    {
        this->_data[i] /= value;
    }

    return *this;
}

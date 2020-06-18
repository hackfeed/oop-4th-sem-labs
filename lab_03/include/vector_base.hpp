#ifndef VECTOR_BASE_HPP
#define VECTOR_BASE_HPP

template <typename T>
class BaseVector
{
public:
    BaseVector() = default;
    ~BaseVector() = default;
    virtual void clean() = 0;
    virtual size_t size() const = 0;

protected:
    size_t size_ = 0;
};

#endif
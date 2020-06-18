#ifndef EXCEPTION_CONTAINER_HPP
#define EXCEPTION_CONTAINER_HPP

#include "exception_base.hpp"

class MemError : public BaseError
{
public:
    MemError(
        const std::string &filename,
        const std::string &classname,
        const int line,
        const char *time,
        const std::string &info = "A memory allocation error") : BaseError(filename, classname, line, time, info) {}
};

class RangeError : public BaseError
{
public:
    RangeError(
        const std::string &filename,
        const std::string &classname,
        const int line,
        const char *time,
        const std::string &info = "Out of range error") : BaseError(filename, classname, line, time, info) {}
};

#endif
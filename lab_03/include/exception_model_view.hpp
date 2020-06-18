#ifndef EXCEPTION_MODEL_VIEW_HPP
#define EXCEPTION_MODEL_VIEW_HPP

#include "exception_base.hpp"

class ModelOutOfRangeError : public BaseError
{
public:
    ModelOutOfRangeError(
        const std::string &filename,
        const std::string &classname,
        const int line,
        const char *time,
        const std::string &info = "Model is out of range") : BaseError(filename, classname, line, time, info) {}
};

#endif
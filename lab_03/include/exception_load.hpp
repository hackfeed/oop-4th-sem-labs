#ifndef EXCEPTION_LOAD_HPP
#define EXCEPTION_LOAD_HPP

#include "exception_base.hpp"

class OpenStreamError : public BaseError
{
public:
    OpenStreamError(
        const std::string &filename,
        const std::string &classname,
        const int line,
        const char *time,
        const std::string &info = "Error while opening stream") : BaseError(filename, classname, line, time, info) {}
};

class ReadStreamError : public BaseError
{
public:
    ReadStreamError(
        const std::string &filename,
        const std::string &classname,
        const int line,
        const char *time,
        const std::string &info = "Error while reading stream") : BaseError(filename, classname, line, time, info) {}
};

class FileFormatError : public BaseError
{
public:
    FileFormatError(
        const std::string &filename,
        const std::string &classname,
        const int line,
        const char *time,
        const std::string &info = "Wrong format of file") : BaseError(filename, classname, line, time, info) {}
};

#endif
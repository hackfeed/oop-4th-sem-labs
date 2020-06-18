#ifndef EXCEPTION_DRAW_HPP
#define EXCEPTION_DRAW_HPP

#include "exception_base.hpp"

class DrawerError : public BaseError
{
public:
    DrawerError(
        const std::string &filename,
        const std::string &classname,
        const int line,
        const char *time,
        const std::string &info = "Drawer wasn't set") : BaseError(filename, classname, line, time, info) {}
};

class CameraError : public BaseError
{
public:
    CameraError(
        const std::string &filename,
        const std::string &classname,
        const int line,
        const char *time,
        const std::string &info = "Camera wasn't set") : BaseError(filename, classname, line, time, info) {}
};

#endif
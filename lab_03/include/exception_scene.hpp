#ifndef EXCEPTION_SCENE_HPP
#define EXCEPTION_SCENE_HPP

#include "exception_scene.hpp"

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

class ObjectError : public BaseError
{
public:
    ObjectError(
        const std::string &filename,
        const std::string &classname,
        const int line,
        const char *time,
        const std::string &info = "Object wasn't found.") : BaseError(filename, classname, line, time, info) {}
};

#endif
#ifndef CAMERA_ERROR_H
#define CAMERA_ERROR_H

#include "base_error.h"

class camera_error : public base_error
{
public:
    camera_error() = default;
    camera_error(std::string &message) : base_error(message){};

    const char *what() const noexcept override
    {
        return "Camera doesn't set.";
    }
};

#endif

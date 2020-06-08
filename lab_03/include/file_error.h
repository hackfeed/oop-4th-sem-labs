#ifndef FILE_ERROR_H
#define FILE_ERROR_H

#include "base_error.h"

class file_error : public base_error
{
public:
    file_error() = default;
    file_error(std::string &message) : base_error(message){};

    const char *what() const noexcept override
    {
        return "File corrupt or does not exist.";
    }
};

#endif

#ifndef BASE_ERROR_H
#define BASE_ERROR_H

#include <exception>
#include <string>

class base_error : public std::exception
{
public:
    base_error() = default;
    base_error(std::string &message) : error_info(message){};

    const char *what() const noexcept override
    {
        return "Something wrong with viewer.";
    }

    const std::string &get_info() const noexcept
    {
        return error_info;
    }

protected:
    std::string error_info;
};

#endif

#ifndef EXCEPTION_BASE_HPP
#define EXCEPTION_BASE_HPP

#include <exception>
#include <string>

class BaseError : public std::exception
{
public:
    explicit BaseError(
        const std::string &filename,
        const std::string &classname,
        const int line,
        const char *time,
        const std::string &info)
    {
        msg_ = "In: " + filename +
               "\n inside: " + classname +
               "\nat line: " + std::to_string(line) +
               "\nat: " + time +
               "\noccured: " + info;
    }
    const char *what() const noexcept override
    {
        return msg_.c_str();
    }

private:
    std::string msg_;
};

#endif
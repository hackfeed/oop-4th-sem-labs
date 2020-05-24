#ifndef _ERRORS_H_
#define _ERRORS_H_

#include <exception>

class ListErrorBase : public std::exception
{
public:
    explicit ListErrorBase(
        const std::string &filename,
        const std::string &classname,
        const int line,
        const char *time,
        const std::string &info)
    {
        message = "In " + filename +
                  "\nInside " + classname + " class" +
                  "\nAt line " + std::to_string(line) +
                  "\nAt time " + time +
                  "\nOccured error: " + info;
    }

    virtual const char *what() const noexcept override
    {
        return message.c_str();
    }

protected:
    std::string message;
};

class ListMemoryError : public ListErrorBase
{
public:
    ListMemoryError(
        const std::string &filename,
        const std::string &classname,
        const int line,
        const char *time,
        const std::string &info = "Memory allocation error") : ListErrorBase(filename, classname, line, time, info) {}
};

class ListEmptyError : public ListErrorBase
{
public:
    ListEmptyError(
        const std::string &filename,
        const std::string &classname,
        const int line,
        const char *time,
        const std::string &info = "List is empty") : ListErrorBase(filename, classname, line, time, info) {}
};

class ListRangeError : public ListErrorBase
{
public:
    ListRangeError(
        const std::string &filename,
        const std::string &classname,
        const int line,
        const char *time,
        const std::string &info = "Index out of range") : ListErrorBase(filename, classname, line, time, info) {}
};

class ListIteratorError : public ListErrorBase
{
public:
    ListIteratorError(
        const std::string &filename,
        const std::string &classname,
        const int line,
        const char *time,
        const std::string &info = "Invalid iterator") : ListErrorBase(filename, classname, line, time, info) {}
};

#endif

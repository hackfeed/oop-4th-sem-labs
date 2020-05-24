#ifndef _ERRORS_H_
#define _ERRORS_H_

#include <exception>

// когда, в каком методе, какая ошибка, Данные, котороые привели к ошибке

class ListErrorBase : public std::exception
{
public:
    ListErrorBase();
    explicit ListErrorBase(const char *message) : message(message) {}
    explicit ListErrorBase(const std::string &message) : message(message) {}

    virtual const char *what() const noexcept override
    {
        return message.c_str();
    }

protected:
    std::string message;
};

class ListMemoryError : public ListErrorBase
{
private:
    static constexpr const char *ErrorMsg = "Allocation error";

public:
    explicit ListMemoryError() : ListErrorBase(ErrorMsg) {}
    explicit ListMemoryError(const std::string &message) : ListErrorBase(ErrorMsg + message) {}
};

class EmptyError : public ErrorBase
{
private:
    static constexpr const char *ErrorMsg = "List is empty";

public:
    explicit EmptyError() : ErrorBase(ErrorMsg) {}
    explicit EmptyError(const std::string &message) : ErrorBase(ErrorMsg + message) {}
};

class RangeError : public ErrorBase
{
private:
    static constexpr const char *ErrorMsg = "Index out of range";

public:
    explicit RangeError() : ErrorBase(ErrorMsg) {}
    explicit RangeError(const std::string &message) : ErrorBase(ErrorMsg + message) {}
};

// Ошибки итератора

#endif

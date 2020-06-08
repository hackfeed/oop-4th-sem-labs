#ifndef MODEL_ERROR_H
#define MODEL_ERROR_H

#include "base_error.h"

class model_error : public base_error
{
public:
    model_error() = default;
    model_error(std::string &message) : base_error(message){};

    const char *what() const noexcept override
    {
        return "Error while building model.";
    }
};

#endif

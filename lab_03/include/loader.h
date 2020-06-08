#ifndef LOADER_H
#define LOADER_H

#include <string>
#include <fstream>

#include "builder.h"
#include "file_error.h"
#include "model.h"
#include "abstract_loader.h"

class base_loader
{
public:
    base_loader() = default;
    virtual ~base_loader() = default;

    virtual std::shared_ptr<model> load_model(std::shared_ptr<base_builder> builder) = 0;
    virtual void fopen(std::string &fname) = 0;
    virtual void fclose() = 0;
};

class file_loader : public base_loader
{
public:
    file_loader() = default;
    virtual ~file_loader() = default;

    virtual std::shared_ptr<model> load_model(std::shared_ptr<base_builder> builder) override;
    virtual void fopen(std::string &fname) override;
    virtual void fclose() override;

protected:
    std::ifstream file;
};


#endif

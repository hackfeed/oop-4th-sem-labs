#ifndef ABSTRACT_LOADER_H
#define ABSTRACT_LOADER_H

#include <memory>

#include "builder.h"

class model;
class base_loader;

class abstract_loader
{
public:
    abstract_loader() = default;
    ~abstract_loader() = default;

    virtual std::shared_ptr<model> load_model(std::string &name) = 0;
    virtual void set_loader(std::shared_ptr<base_loader> _loader) { this->loader = _loader; };

protected:
    std::shared_ptr<base_loader> loader;
};

class model_loader : public abstract_loader
{
public:
    model_loader(std::shared_ptr<base_loader> _loader) : builder(new model_builder), loader(_loader){};
    ~model_loader() = default;

    virtual std::shared_ptr<model> load_model(std::string &name) override;

private:
    std::shared_ptr<base_builder> builder;
    std::shared_ptr<base_loader> loader;
};

#endif

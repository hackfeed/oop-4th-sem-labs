#ifndef BUILDER_H
#define BUILDER_H

#include "model.h"

class base_builder
{
public:
    base_builder() = default;
    ~base_builder() = default;

    virtual bool is_build() const = 0;
    virtual void build() = 0;
    virtual void build_point(const double &x, const double &y, const double &z) = 0;
    virtual void build_link(const size_t &pt1, const size_t &pt2) = 0;

    virtual std::shared_ptr<model> get() = 0;
};

class model_builder : public base_builder
{
public:
    model_builder() : model_ptr(nullptr){};
    ~model_builder() = default;

    virtual bool is_build() const override;
    virtual void build() override;
    virtual void build_point(const double &x, const double &y, const double &z) override;
    virtual void build_link(const size_t &pt1, const size_t &pt2) override;

    virtual std::shared_ptr<model> get() override;

private:
    std::shared_ptr<model> model_ptr;
};

#endif // BUILDER_H

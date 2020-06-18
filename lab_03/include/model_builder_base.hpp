#ifndef MODEL_BUILDER_BASE_HPP
#define MODEL_BUILDER_BASE_HPP

#include "object_model.hpp"

class BaseModelBuilder
{
public:
    BaseModelBuilder() = default;
    ~BaseModelBuilder() = default;

    virtual void BuildPoints(const Vector<Point<double>> &points) = 0;
    virtual void BuildLinks(const Vector<Link> &links) = 0;
    virtual void reset(std::string name) = 0;
    virtual std::shared_ptr<Model> GetModel() = 0;
};

#endif
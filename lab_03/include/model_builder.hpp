#pragma once

#include <memory>

#include "model_builder_base.hpp"
#include "loader_source.hpp"
#include "object_model.hpp"

class ModelBuilder : public BaseModelBuilder
{
public:
    void reset(std::string name) override;
    ModelBuilder() = default;
    ~ModelBuilder() = default;
    void buildPoints(const Vector<Point<double>> &points) override;
    void buildEdges(const Vector<Link> &edges) override;
    std::shared_ptr<Model> getModel() override;

private:
    std::shared_ptr<Model> model;
};

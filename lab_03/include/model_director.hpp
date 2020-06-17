#pragma once

#include <memory>

#include "model_builder_base.hpp"
#include "loader_source.hpp"
#include "object_model.hpp"

class ModelDirector
{
public:
    std::shared_ptr<Model> build(const Vector<Point<double>> &points, const Vector<Edge> &edges);
    void setBuilder(std::shared_ptr<BaseModelBuilder> builder);

private:
    std::shared_ptr<BaseModelBuilder> builder_;
};

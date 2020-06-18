#include "model_director.hpp"

#include <memory>

void ModelDirector::setBuilder(std::shared_ptr<BaseModelBuilder> builder)
{
    builder_ = std::move(builder);
}

std::shared_ptr<Model> ModelDirector::build(const Vector<Point<double>> &points, const Vector<Link> &edges)
{
    builder_->buildPoints(points);
    builder_->buildEdges(edges);
    return builder_->getModel();
}

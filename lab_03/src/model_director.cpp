#include "model_director.hpp"

#include <memory>

void ModelDirector::SetBuilder(std::shared_ptr<BaseModelBuilder> builder)
{
    builder_ = std::move(builder);
}

std::shared_ptr<Model> ModelDirector::Build(const Vector<Point<double>> &points, const Vector<Link> &links)
{
    builder_->BuildPoints(points);
    builder_->BuildLinks(links);

    return builder_->GetModel();
}

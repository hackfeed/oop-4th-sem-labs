#ifndef MODEL_DIRECTOR_HPP
#define MODEL_DIRECTOR_HPP

#include <memory>

#include "model_builder_base.hpp"
#include "loader_source.hpp"
#include "object_model.hpp"

class ModelDirector
{
public:
    std::shared_ptr<Model> Build(const Vector<Point<double>> &points, const Vector<Link> &links);
    void SetBuilder(std::shared_ptr<BaseModelBuilder> builder);

private:
    std::shared_ptr<BaseModelBuilder> builder_;
};

#endif
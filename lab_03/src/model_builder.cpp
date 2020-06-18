#include "model_builder.hpp"

void ModelBuilder::BuildPoints(const Vector<Point<double>> &points)
{
    model->add(points);
}

void ModelBuilder::reset(std::string name)
{
    model.reset();
    model = std::shared_ptr<Model>(std::make_shared<Model>(name));
}

void ModelBuilder::BuildLinks(const Vector<Link> &links)
{
    model->add(links);
}

std::shared_ptr<Model> ModelBuilder::GetModel()
{
    return model;
}

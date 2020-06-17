#include "model_builder.hpp"

void ModelBuilder::buildPoints(const Vector<Point<double>> &points)
{
    model->add(points);
}

void ModelBuilder::reset(std::string name)
{
    model.reset();
    model = std::shared_ptr<Model>(std::make_shared<Model>(name));
}

void ModelBuilder::buildEdges(const Vector<Edge> &edges)
{
    model->add(edges);
}

std::shared_ptr<Model> ModelBuilder::getModel()
{
    return model;
}

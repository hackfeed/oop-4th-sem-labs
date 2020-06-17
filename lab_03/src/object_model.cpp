#include "object_model.hpp"

Model::Model(std::string name) : _mesh(std::make_shared<Mesh>())
{
    this->_name = name;
}

Model::Model(const Model &other) : VisibleObject(), _mesh(other._mesh) {}

Model::Model(Model &&other) noexcept : _mesh(other._mesh) {}

Model &Model::operator=(const Model &other)
{
    if (this != &other)
    {
        _mesh = other._mesh;
    }
    return *this;
}

Model &Model::operator=(Model &&other) noexcept
{
    if (this != &other)
    {
        _mesh = other._mesh;
    }

    return *this;
}

std::shared_ptr<Mesh> Model::getMesh()
{
    return _mesh;
}

void Model::transform(const std::shared_ptr<matrix<double>> mtr)
{
    _mesh->transform(mtr);
}

void Model::accept(std::shared_ptr<Visitor> visitor)
{
    visitor->visit(*this);
}

void Model::add(const Vector<Point<double>> &points)
{
    _mesh->addPoints(points);
}

void Model::add(const Vector<Edge> &edges)
{
    _mesh->addEdges(edges);
}
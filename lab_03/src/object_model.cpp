#include "object_model.hpp"

Model::Model(std::string name) : compound_(std::make_shared<Compound>())
{
    this->name_ = name;
}

Model::Model(const Model &other) : VisibleObject(), compound_(other.compound_) {}

Model::Model(Model &&other) noexcept : compound_(other.compound_) {}

Model &Model::operator=(const Model &other)
{
    if (this != &other)
    {
        compound_ = other.compound_;
    }
    return *this;
}

Model &Model::operator=(Model &&other) noexcept
{
    if (this != &other)
    {
        compound_ = other.compound_;
    }

    return *this;
}

std::shared_ptr<Compound> Model::getMesh()
{
    return compound_;
}

void Model::transform(const std::shared_ptr<Matrix<double>> mtr)
{
    compound_->transform(mtr);
}

void Model::accept(std::shared_ptr<Visitor> visitor)
{
    visitor->Visit(*this);
}

void Model::add(const Vector<Point<double>> &points)
{
    compound_->addPoints(points);
}

void Model::add(const Vector<Link> &edges)
{
    compound_->addEdges(edges);
}
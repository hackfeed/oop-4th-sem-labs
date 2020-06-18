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

std::shared_ptr<Compound> Model::GetCompound()
{
    return compound_;
}

void Model::Transform(const std::shared_ptr<Matrix<double>> mtr)
{
    compound_->Transform(mtr);
}

void Model::Accept(std::shared_ptr<Visitor> visitor)
{
    visitor->Visit(*this);
}

void Model::Add(const Vector<Point<double>> &points)
{
    compound_->AddPoints(points);
}

void Model::Add(const Vector<Link> &links)
{
    compound_->AddLinks(links);
}
#include "composite.h"
#include "visitor.h"

composite::composite(std::shared_ptr<object> &component)
{
    this->objects.push_back(component);
}

composite::composite(vector<std::shared_ptr<object>> vector)
{
    this->objects = vector;
}

bool composite::add(const std::shared_ptr<object> &component)
{
    this->objects.push_back(component);
    return true;
}

bool composite::remove(const iterator<std::shared_ptr<object>> &iterator)
{
    this->objects.remove(iterator);
    return true;
}

iterator<std::shared_ptr<object>> composite::begin()
{
    return this->objects.begin();
}

iterator<std::shared_ptr<object>> composite::end()
{
    return this->objects.end();
}

bool composite::is_composite() const
{
    return true;
}

size_t composite::size() const
{
    return this->objects.get_size();
}

void composite::reform(const point &move, const point &scale, const point &turn)
{
    for (auto elem : objects)
    {
        elem->reform(move, scale, turn);
    }
}

void composite::accept(std::shared_ptr<visitor> visitor)
{
    for (auto obj : objects)
    {
        obj->accept(visitor);
    }
}

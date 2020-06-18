#include "object_composite.hpp"

#include "iterator.hpp"

bool CompositeObject::isComposite() const
{
    return true;
}

bool CompositeObject::add(std::shared_ptr<SceneObject> obj)
{
    _scene_objects.push_back(obj);
    return true;
}

bool CompositeObject::Visible() const
{
    return true;
}

void CompositeObject::transform(const std::shared_ptr<matrix<double>> matrix)
{
    for (auto &obj : _scene_objects)
    {
        obj->transform(matrix);
    }
}

void CompositeObject::accept(std::shared_ptr<Visitor> visitor)
{
    visitor->Visit(*this);

    for (auto &obj : _scene_objects)
    {
        obj->accept(visitor);
    }
}

bool CompositeObject::remove(IteratorObject &it)
{
    _scene_objects.erase(it);
    return true;
}

IteratorObject CompositeObject::begin()
{
    return _scene_objects.begin();
}

IteratorObject CompositeObject::end()
{
    return _scene_objects.end();
}

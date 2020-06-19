#include "object_composite.hpp"
#include "iterator.hpp"

bool CompositeObject::IsComposite() const
{
    return true;
}

bool CompositeObject::Add(std::shared_ptr<SceneObject> obj)
{
    scene_objects_.push_back(obj);

    return true;
}

bool CompositeObject::IsVisible() const
{
    return true;
}

void CompositeObject::Transform(const std::shared_ptr<Matrix<double>> Matrix)
{
    for (auto &obj : scene_objects_)
    {
        obj->Transform(Matrix);
    }
}

void CompositeObject::Accept(std::shared_ptr<Visitor> visitor)
{
    visitor->Visit(*this);

    for (auto &obj : scene_objects_)
    {
        obj->Accept(visitor);
    }
}

bool CompositeObject::Remove(IteratorObject &iter)
{
    scene_objects_.erase(iter);

    return true;
}

IteratorObject CompositeObject::begin()
{
    return scene_objects_.begin();
}

IteratorObject CompositeObject::end()
{
    return scene_objects_.end();
}

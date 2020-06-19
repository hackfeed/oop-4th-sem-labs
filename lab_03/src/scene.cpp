#include <memory.h>

#include "scene.hpp"
#include "vector_iterator.hpp"
#include "exception_scene.hpp"

Scene::Scene() : object_(new CompositeObject) {}

void Scene::Add(std::shared_ptr<SceneObject> object)
{
    object_->Add(std::move(object));
}

void Scene::Remove(IteratorObject &iter)
{
    object_->Remove(iter);
}

std::shared_ptr<CompositeObject> Scene::GetObject()
{
    return object_;
}

std::shared_ptr<SceneObject> Scene::GetObject(std::string object)
{
    auto iter = object_->begin();
    auto iter_end = object_->end();
    bool flag = true;

    while (iter != iter_end && flag)
    {
        auto t = iter.get();
        if (iter.get()->GetName() == object)
        {
            flag = false;
        }
        if (flag)
        {
            ++iter;
        }
    }

    if (flag)
    {
        time_t t_time = time(NULL);
        throw ObjectError(__FILE__, typeid(*this).name(), __LINE__, ctime(&t_time));
    }

    return iter.get();
}

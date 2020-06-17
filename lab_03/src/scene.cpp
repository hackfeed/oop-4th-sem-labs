#include "scene.hpp"

#include <memory.h>

#include "vector_iterator.hpp"

#include "exception_scene.hpp"

Scene::Scene() : object_(new CompositeObject) {}

void Scene::Add(std::shared_ptr<SceneObject> object)
{
    object_->add(std::move(object));
}

void Scene::Remove(IteratorObject &it)
{
    object_->remove(it);
}

std::shared_ptr<CompositeObject> Scene::getObject()
{
    return object_;
}

std::shared_ptr<SceneObject> Scene::getObject(std::string object)
{
    auto it = object_->begin();
    auto it_e = object_->end();
    bool flag = true;
    while (it != it_e && flag)
    {
        auto t = it.get();
        if (it.get()->getName() == object)
        {
            flag = false;
        }
        if (flag)
        {
            ++it;
        }
    }
    if (flag)
    {
        time_t t_time = time(NULL);
        throw ObjectError(__FILE__, typeid(*this).name(), __LINE__, ctime(&t_time));
    }
    return it.get();
}

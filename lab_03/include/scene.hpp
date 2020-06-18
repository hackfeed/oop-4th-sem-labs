#ifndef SCENE_HPP
#define SCENE_HPP

#include <memory>

#include "object_composite.hpp"

class Scene
{
public:
    Scene();

    void Add(std::shared_ptr<SceneObject> object);
    void Remove(IteratorObject &it);
    std::shared_ptr<SceneObject> GetObject(std::string object);
    std::shared_ptr<CompositeObject> GetObject();

private:
    std::shared_ptr<CompositeObject> object_;
};

#endif
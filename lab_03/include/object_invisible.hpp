#ifndef OBJECT_INVISIBLE_HPP
#define OBJECT_INVISIBLE_HPP

#include "object_scene.hpp"

class InvisibleObject : public SceneObject
{
public:
    explicit InvisibleObject() = default;
    ~InvisibleObject() = default;

    bool IsVisible() const final;
};

#endif
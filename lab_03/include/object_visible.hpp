#ifndef OBJECT_VISIBLE_HPP
#define OBJECT_VISIBLE_HPP

#include "object_scene.hpp"

class VisibleObject : public SceneObject
{
public:
    explicit VisibleObject() = default;
    ~VisibleObject() = default;

    bool IsVisible() const final;
};

#endif

#pragma once

#include "object_scene.hpp"

class VisibleObject : public SceneObject
{
public:
    explicit VisibleObject() = default;
    ~VisibleObject() = default;

    bool Visible() const final;
};

#pragma once

#include "object_scene.hpp"

class InvisibleObject : public SceneObject
{
public:
    explicit InvisibleObject() = default;
    ~InvisibleObject() = default;

    bool Visible() const final;
};

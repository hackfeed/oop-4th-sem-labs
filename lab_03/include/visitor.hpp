#pragma once

class Model;
class Camera;
class CompositeObject;

class Visitor
{
public:
    Visitor() = default;
    virtual ~Visitor() = default;

    virtual void Visit(Camera &camera) = 0;
    virtual void Visit(Model &model) = 0;
    virtual void Visit(CompositeObject &composite) = 0;
};

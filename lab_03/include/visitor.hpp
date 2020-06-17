#pragma once

class Model;
class Camera;
class CompositeObject;

class Visitor
{
public:
    Visitor() = default;
    virtual ~Visitor() = default;

    virtual void visit(Camera &camera) = 0;
    virtual void visit(Model &model) = 0;
    virtual void visit(CompositeObject &composite) = 0;
};

#ifndef OBJECT_SCENE_HPP
#define OBJECT_SCENE_HPP

#include <cstdio>

#include "matrix.hpp"
#include "vector_iterator.hpp"
#include "vector.hpp"
#include "visitor.hpp"

class SceneObject;

using VectorObject = Vector<std::shared_ptr<SceneObject>>;
using IteratorObject = VectorObject::iterator;

class SceneObject
{
public:
    SceneObject() = default;
    SceneObject(std::string name) : name_(name){};
    ~SceneObject() = default;

    virtual bool IsVisible() const = 0;
    virtual bool IsComposite() const { return false; }
    virtual bool Add(std::shared_ptr<SceneObject> obj) { return false; }
    virtual bool Remove(IteratorObject &iter) { return false; }
    virtual void Transform(std::shared_ptr<Matrix<double>> Matrix) = 0;
    virtual void Accept(std::shared_ptr<Visitor> visitor) = 0;
    virtual std::string GetName() { return name_; }

    virtual IteratorObject begin() { return IteratorObject(); }
    virtual IteratorObject end() { return IteratorObject(); }

protected:
    std::string name_;
};

#endif
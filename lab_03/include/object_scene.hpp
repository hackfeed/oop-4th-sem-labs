#pragma once

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

    virtual bool Visible() const = 0;
    virtual bool isComposite() const { return false; }
    virtual bool add(std::shared_ptr<SceneObject> obj) { return false; }
    virtual bool remove(IteratorObject &it) { return false; }
    virtual void transform(std::shared_ptr<matrix<double>> matrix) = 0;
    virtual void accept(std::shared_ptr<Visitor> visitor) = 0;
    virtual std::string getName() { return name_; }

    virtual IteratorObject begin() { return IteratorObject(); }
    virtual IteratorObject end() { return IteratorObject(); }

protected:
    std::string name_;
};

#pragma once

#include <memory>

#include "object_camera.hpp"
#include "object_model.hpp"

class CompositeObject : public SceneObject
{
public:
    CompositeObject() = default;

    bool Visible() const override;
    bool add(std::shared_ptr<SceneObject> obj) override;
    bool remove(IteratorObject &it) override;
    bool isComposite() const override;
    virtual IteratorObject begin() override;
    virtual IteratorObject end() override;
    void transform(const std::shared_ptr<matrix<double>> matrix);
    void accept(std::shared_ptr<Visitor> visitor);

private:
    VectorObject _scene_objects;
};

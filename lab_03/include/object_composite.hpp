#ifndef OBJECT_COMPOSITE_HPP
#define OBJECT_COMPOSITE_HPP

#include <memory>

#include "object_camera.hpp"
#include "object_model.hpp"

class CompositeObject : public SceneObject
{
public:
    CompositeObject() = default;

    bool Add(std::shared_ptr<SceneObject> obj) override;
    bool Remove(IteratorObject &iter) override;
    bool IsVisible() const override;
    bool IsComposite() const override;
    virtual IteratorObject begin() override;
    virtual IteratorObject end() override;
    void Transform(const std::shared_ptr<Matrix<double>> Matrix);
    void Accept(std::shared_ptr<Visitor> visitor);

private:
    VectorObject scene_objects_;
};

#endif
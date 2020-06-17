#pragma once

#include "matrix.hpp"
#include "vector.hpp"
#include "visitor.hpp"
#include "link.hpp"
#include "point.hpp"
#include "object_compound.hpp"
#include "object_visible.hpp"

class Model : public VisibleObject
{
public:
    Model() = default;
    explicit Model(std::string name);
    Model(const Model &);
    Model(Model &&) noexcept;
    ~Model() = default;

    Model &operator=(const Model &);
    Model &operator=(Model &&) noexcept;
    void transform(const std::shared_ptr<matrix<double>> mtr) override;
    void accept(std::shared_ptr<Visitor> visitor) override;

    std::shared_ptr<Mesh> getMesh();
    void add(const Vector<Point<double>> &points);
    void add(const Vector<Edge> &edges);

private:
    std::shared_ptr<Mesh> _mesh;
};

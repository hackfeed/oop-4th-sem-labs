#ifndef OBJECT_MODEL_HPP
#define OBJECT_MODEL_HPP

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
    void Transform(const std::shared_ptr<Matrix<double>> mtr) override;
    void Accept(std::shared_ptr<Visitor> visitor) override;

    std::shared_ptr<Compound> GetCompound();
    void Add(const Vector<Point<double>> &points);
    void Add(const Vector<Link> &links);

private:
    std::shared_ptr<Compound> compound_;
};

#endif
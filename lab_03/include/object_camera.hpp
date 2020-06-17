#pragma once

#include "matrix.hpp"
#include "visitor.hpp"
#include "object_invisible.hpp"
#include "point.hpp"

class Camera : public InvisibleObject
{
public:
    Camera(std::string name);

    const Point<double> &getPosition() const;
    void setPosition(const Point<double> &position);

    double getXAngle() const;
    void setXAngle(double x_angle);

    double getYAngle() const;
    void setYAngle(double y_angle);

    double getZAngle() const;
    void setZAngle(double z_angle);

    void transform(const std::shared_ptr<matrix<double>> mtr);
    void accept(std::shared_ptr<Visitor> visitor) override;

private:
    Point<double> position;
    double x_angle;
    double y_angle;
    double z_angle;
};

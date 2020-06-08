#ifndef MODEL_H
#define MODEL_H

#include <memory>

#include "draw_manager.h"
#include "details.h"
#include "component.h"
#include "link.h"
#include "point.h"

class model : public visible_object
{
public:
    model() : _details(new details){};
    model(const std::shared_ptr<details> details) : _details(details){};
    model(const model &model);
    ~model() = default;

    std::unique_ptr<model> clone();

    const std::shared_ptr<details> get_details() const { return _details; };
    void add_point(const point &point);
    void add_link(const link &link);

    virtual void reform(const point &move, const point &scale, const point &turn) override;
    virtual void accept(std::shared_ptr<visitor> visitor) override;

private:
    std::shared_ptr<details> _details;
};

#endif

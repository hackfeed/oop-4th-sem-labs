#ifndef DRAW_MANAGER_H
#define DRAW_MANAGER_H

#include <memory>
#include "drawer.h"
#include "visitor.h"
#include "base_manager.h"

class draw_manager : public visitor, public base_manager
{
public:
    draw_manager() = default;
    draw_manager(draw_manager &manager) : _drawer(manager._drawer), cam(manager.cam){};
    ~draw_manager() = default;

    virtual void visit(const camera &cam) override;
    virtual void visit(const model &model) override;
    virtual void visit(const composite &composite) override;

    void set_drawer(std::shared_ptr<base_drawer>);
    void set_cam(std::shared_ptr<camera>);

private:
    point proect_point(const point &point);
    std::shared_ptr<base_drawer> _drawer;
    std::shared_ptr<camera> cam;
};

#endif

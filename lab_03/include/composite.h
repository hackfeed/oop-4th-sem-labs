#ifndef COMPOSITE_H
#define COMPOSITE_H

#include "component.h"
#include "model.h"

class composite : public object
{
public:
    composite() = default;
    composite(std::shared_ptr<object> &component);
    composite(vector<std::shared_ptr<object>> vector);

    size_t size() const;

    virtual bool add(const std::shared_ptr<object> &component) override;
    virtual bool remove(const iterator<std::shared_ptr<object>> &iterator) override;

    virtual iterator<std::shared_ptr<object>> begin() override;
    virtual iterator<std::shared_ptr<object>> end() override;

    virtual bool is_composite() const override;
    virtual void reform(const point &move, const point &scale, const point &turn) override;
    virtual void accept(std::shared_ptr<visitor> visitor) override;

    vector<std::shared_ptr<object>> &get_objects() { return objects; };

private:
    vector<std::shared_ptr<object>> objects;

};

#endif

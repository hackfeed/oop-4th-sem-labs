#ifndef COMPONENT_H
#define COMPONENT_H

#include <memory>

#include "iterator.hpp"
#include "point.h"

class visitor;

class object
{
public:
    object() = default;
    virtual ~object() = default;

    virtual bool add(const std::shared_ptr<object> &) { return false; };
    virtual bool remove(const iterator<std::shared_ptr<object>> &) { return false; };

    virtual iterator<std::shared_ptr<object>> begin(){};
    virtual iterator<std::shared_ptr<object>> end(){};

    virtual bool is_composite() const { return false; };
    virtual void accept(std::shared_ptr<visitor> visitor) = 0;
    virtual void reform(const point &move, const point &scale, const point &turn) = 0;
};

class visible_object : public object
{
public:
    visible_object() = default;
    ~visible_object() = default;

    virtual bool is_visible() { return true; }
};

class invisible_object : public object
{
public:
    invisible_object() = default;
    ~invisible_object() = default;

    virtual bool is_visible() { return false; }
};

#endif

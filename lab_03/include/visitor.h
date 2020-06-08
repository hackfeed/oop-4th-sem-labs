#ifndef VISITOR_H
#define VISITOR_H

class camera;
class model;
class composite;

class visitor
{
public:
    visitor() = default;
    ~visitor() = default;

    virtual void visit(const camera &cam) = 0;
    virtual void visit(const model &model) = 0;
    virtual void visit(const composite &composite) = 0;
};

#endif

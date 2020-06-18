#include "link.hpp"

Link::Link()
{
    this->begin = 0;
    this->end = 0;
}

Link::Link(const size_t begin, const size_t end)
{
    this->begin = begin;
    this->end = end;
}

Link::Link(const Link &link)
{
    this->begin = link.getBegin();
    this->end = link.getEnd();
}

Link::~Link() {}

Link &Link::operator=(const Link &link)
{
    this->begin = link.getBegin();
    this->end = link.getEnd();
    return *this;
}

size_t Link::getBegin() const
{
    return begin;
}

size_t Link::getEnd() const
{
    return end;
}

void Link::setBegin(size_t begin)
{
    this->begin = begin;
}

void Link::setEnd(size_t end)
{
    this->end = end;
}

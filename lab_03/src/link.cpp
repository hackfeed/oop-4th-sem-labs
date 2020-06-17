#include "link.hpp"

Edge::Edge()
{
    this->begin = 0;
    this->end = 0;
}

Edge::Edge(const size_t begin, const size_t end)
{
    this->begin = begin;
    this->end = end;
}

Edge::Edge(const Edge &edge)
{
    this->begin = edge.getBegin();
    this->end = edge.getEnd();
}

Edge::~Edge() {}

Edge &Edge::operator=(const Edge &edge)
{
    this->begin = edge.getBegin();
    this->end = edge.getEnd();
    return *this;
}

size_t Edge::getBegin() const
{
    return begin;
}

size_t Edge::getEnd() const
{
    return end;
}

void Edge::setBegin(size_t begin)
{
    this->begin = begin;
}

void Edge::setEnd(size_t end)
{
    this->end = end;
}

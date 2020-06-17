#pragma once

#include <istream>

class Edge
{
public:
    Edge();
    Edge(const size_t begin, const size_t end);
    explicit Edge(const Edge &edge);

    ~Edge();

    Edge &operator=(const Edge &edge);

    size_t getBegin() const;
    size_t getEnd() const;

    void setBegin(size_t begin);
    void setEnd(size_t end);

private:
    size_t begin;
    size_t end;
};

inline std::istream &operator>>(std::istream &is, Edge &edge)
{
    size_t p1, p2;
    is >> p1 >> p2;
    edge.setBegin(p1);
    edge.setEnd(p2);
    return is;
}

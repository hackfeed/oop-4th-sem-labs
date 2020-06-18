#pragma once

#include "vector.hpp"
#include "link.hpp"
#include "point.hpp"

class SourceLoader
{
public:
    SourceLoader() = default;
    ~SourceLoader() noexcept = default;

    virtual void open(std::string source_name) = 0;
    virtual bool isOpen() const = 0;
    virtual void close() = 0;
    virtual Vector<Point<double>> readPoints() = 0;
    virtual Vector<Link> readEdges() = 0;
};

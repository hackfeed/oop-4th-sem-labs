#ifndef LOADER_SOURCE_HPP
#define LOADER_SOURCE_HPP

#include "vector.hpp"
#include "link.hpp"
#include "point.hpp"

class SourceLoader
{
public:
    SourceLoader() = default;
    ~SourceLoader() noexcept = default;

    virtual void open(std::string source_name) = 0;
    virtual bool IsOpen() const = 0;
    virtual void close() = 0;
    virtual Vector<Point<double>> ReadPoints() = 0;
    virtual Vector<Link> ReadLinks() = 0;
};

#endif
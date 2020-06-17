#pragma once

#include <fstream>

#include "vector.hpp"
#include "link.hpp"
#include "loader_source.hpp"

class FileLoader : public SourceLoader
{
public:
    FileLoader() = default;
    ~FileLoader();
    void open(std::string source_name) override;
    bool isOpen() const override;
    void close() override;
    Vector<Point<double>> readPoints() override;
    Vector<Edge> readEdges() override;

private:
    std::ifstream _file;
};

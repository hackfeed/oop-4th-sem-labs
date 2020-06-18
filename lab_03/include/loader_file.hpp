#ifndef LOADER_FILE_HPP
#define LOADER_FILE_HPP

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
    bool IsOpen() const override;
    void close() override;
    Vector<Point<double>> ReadPoints() override;
    Vector<Link> ReadLinks() override;

private:
    std::ifstream file_;
};

#endif
#include "loader_file.hpp"

#include <ctime>

#include "vector.hpp"
#include "exception_load.hpp"

FileLoader::~FileLoader()
{
    close();
}

void FileLoader::open(std::string source_name)
{
    if (isOpen())
    {
        close();
    }

    time_t t_time = time(NULL);
    _file.open(source_name);
    if (!_file)
    {
        throw OpenStreamError(__FILE__, typeid(*this).name(), __LINE__, ctime(&t_time));
    }
}

bool FileLoader::isOpen() const
{
    return _file.is_open();
}

void FileLoader::close()
{
    _file.close();
    _file.clear();
}

Vector<Point<double>> FileLoader::readPoints()
{
    time_t t_time = time(NULL);
    if (!isOpen())
    {
        throw ReadStreamError(__FILE__, typeid(*this).name(), __LINE__, ctime(&t_time));
    }
    size_t n_points = 0;
    _file >> n_points;

    if (n_points < 1)
    {
        throw FileFormatError(__FILE__, typeid(*this).name(), __LINE__, ctime(&t_time));
    }

    Vector<Point<double>> points(n_points, Point<double>(0, 0, 0));
    for (size_t i = 0; i < n_points; ++i)
    {
        if (!(_file >> points[i]))
        {
            throw FileFormatError(__FILE__, typeid(*this).name(), __LINE__, ctime(&t_time));
        }
    }
    return points;
}

Vector<Link> FileLoader::readEdges()
{
    time_t t_time = time(NULL);
    if (!isOpen())
    {
        throw ReadStreamError(__FILE__, typeid(*this).name(), __LINE__, ctime(&t_time));
    }
    size_t n_edges = 0;
    _file >> n_edges;

    if (n_edges < 1)
    {
        throw FileFormatError(__FILE__, typeid(*this).name(), __LINE__, ctime(&t_time));
    }

    Vector<Link> edges(n_edges, Link());
    for (size_t i = 0; i < n_edges; ++i)
    {
        if (!(_file >> edges[i]))
        {
            throw FileFormatError(__FILE__, typeid(*this).name(), __LINE__, ctime(&t_time));
        }
    }
    return edges;
}

#include <ctime>

#include "loader_file.hpp"
#include "vector.hpp"
#include "exception_load.hpp"

FileLoader::~FileLoader()
{
    close();
}

void FileLoader::open(std::string source_name)
{
    if (IsOpen())
    {
        close();
    }

    time_t t_time = time(NULL);

    file_.open(source_name);
    if (!file_)
    {
        throw OpenStreamError(__FILE__, typeid(*this).name(), __LINE__, ctime(&t_time));
    }
}

bool FileLoader::IsOpen() const
{
    return file_.is_open();
}

void FileLoader::close()
{
    file_.close();
    file_.clear();
}

Vector<Point<double>> FileLoader::ReadPoints()
{
    time_t t_time = time(NULL);

    if (!IsOpen())
    {
        throw ReadStreamError(__FILE__, typeid(*this).name(), __LINE__, ctime(&t_time));
    }

    size_t n_points = 0;
    file_ >> n_points;

    if (n_points < 1)
    {
        throw FileFormatError(__FILE__, typeid(*this).name(), __LINE__, ctime(&t_time));
    }

    Vector<Point<double>> points(n_points, Point<double>(0, 0, 0));

    for (size_t i = 0; i < n_points; ++i)
    {
        if (!(file_ >> points[i]))
        {
            throw FileFormatError(__FILE__, typeid(*this).name(), __LINE__, ctime(&t_time));
        }
    }

    return points;
}

Vector<Link> FileLoader::ReadLinks()
{
    time_t t_time = time(NULL);

    if (!IsOpen())
    {
        throw ReadStreamError(__FILE__, typeid(*this).name(), __LINE__, ctime(&t_time));
    }

    size_t n_edges = 0;
    file_ >> n_edges;

    if (n_edges < 1)
    {
        throw FileFormatError(__FILE__, typeid(*this).name(), __LINE__, ctime(&t_time));
    }

    Vector<Link> links(n_edges, Link());

    for (size_t i = 0; i < n_edges; ++i)
    {
        if (!(file_ >> links[i]))
        {
            throw FileFormatError(__FILE__, typeid(*this).name(), __LINE__, ctime(&t_time));
        }
    }

    return links;
}

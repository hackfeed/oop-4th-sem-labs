#include "loader.h"

std::shared_ptr<model> file_loader::load_model(std::shared_ptr<base_builder> builder)
{
    builder->build();

    size_t points_count;
    this->file >> points_count;

    for (size_t i = 0; i < points_count; i++)
    {
        double x, y, z;
        this->file >> x >> y >> z;
        builder->build_point(x, y, z);
    }

    size_t links_count;
    this->file >> links_count;

    for (size_t i = 0; i < links_count; i++)
    {
        size_t pt1, pt2;
        this->file >> pt1 >> pt2;
        builder->build_link(pt1, pt2);
    }

    return builder->get();
}

void file_loader::fopen(std::string &fname)
{
    this->file.open(fname);

    if (!this->file)
    {
        std::string message = "Error while open file.";
        throw file_error(message);
    }
}

void file_loader::fclose()
{
    try
    {
        this->file.close();
    }
    catch (std::ifstream::failure &error)
    {
        error.what();
    }
}

std::shared_ptr<model> model_loader::load_model(std::string &fname)
{
    this->loader->fopen(fname);
    std::shared_ptr<model> model(loader->load_model(this->builder));
    this->loader->fclose();

    return model;
}

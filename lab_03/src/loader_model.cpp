#include "loader_model.hpp"

#include <memory.h>

#include "model_director.hpp"

ModelLoader::ModelLoader(std::shared_ptr<SourceLoader> ldr, std::shared_ptr<BaseModelBuilder> bld)
{
    loader_ = ldr;
    builder_ = bld;
}

std::shared_ptr<Model> ModelLoader::LoadModel(std::string model_name, std::string source_name)
{
    loader_->open(source_name);
    builder_->reset(model_name);

    Vector<Point<double>> points = this->loader_->ReadPoints();
    Vector<Link> links = this->loader_->ReadLinks();
    loader_->close();

    ModelDirector director;
    director.SetBuilder(builder_);

    return director.Build(points, links);
}

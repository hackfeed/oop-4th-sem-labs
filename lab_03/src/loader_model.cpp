#include "loader_model.hpp"

#include <memory.h>

#include "model_director.hpp"

ModelLoader::ModelLoader(std::shared_ptr<SourceLoader> ldr, std::shared_ptr<BaseModelBuilder> bld)
{
    loader_ = ldr;
    _builder = bld;
}

std::shared_ptr<Model> ModelLoader::loadModel(std::string model_name, std::string source_name)
{
    loader_->open(source_name);
    _builder->reset(model_name);

    Vector<Point<double>> points = this->loader_->readPoints();
    Vector<Link> edges = this->loader_->readEdges();
    loader_->close();

    ModelDirector director;
    director.setBuilder(_builder);

    return director.build(points, edges);
}

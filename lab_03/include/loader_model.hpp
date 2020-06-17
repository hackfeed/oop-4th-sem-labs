#pragma once

#include "loader_abstract.hpp"

class ModelLoader : public AbstractLoader
{
public:
    ModelLoader(std::shared_ptr<SourceLoader> ldr, std::shared_ptr<BaseModelBuilder> bld);
    std::shared_ptr<Model> loadModel(std::string model_name, std::string source_name) override;

private:
    std::shared_ptr<BaseModelBuilder> _builder;
};

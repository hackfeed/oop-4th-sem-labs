#pragma once

#include <memory>

#include "model_builder_base.hpp"
#include "manager_base.hpp"
#include "object_model.hpp"
#include "loader_source.hpp"

class AbstractLoader
{
public:
    virtual ~AbstractLoader() = default;
    virtual std::shared_ptr<Model> loadModel(std::string model_name, std::string source_name) = 0;

protected:
    std::shared_ptr<SourceLoader> _loader;
};

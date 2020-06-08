#include "scene.h"

void scene::add_model(std::shared_ptr<object> model)
{
    this->models->add(model);
}

void scene::remove_model(const size_t index)
{
    //this->models->remove(index);
}

void scene::add_camera(const std::shared_ptr<camera> &camera)
{
    this->cams.push_back(camera);
}

void scene::remove_camera(const size_t index)
{
    this->cams.remove(index);
}

vector<std::shared_ptr<object>> scene::get_models()
{
    return this->models->get_objects();
}

std::shared_ptr<composite> scene::get_composite()
{
    return this->models;
}

vector<std::shared_ptr<camera>> scene::get_cams()
{
    return this->cams;
}

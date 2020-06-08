#include "facade.h"

void facade::load_model(std::string fname)
{
    std::shared_ptr<model> model = this->_load_manager->load_model(fname);
    this->_scene_manager.get_scene()->add_model(model);
}

void facade::add_model(const std::shared_ptr<object> &model)
{
    this->_scene_manager.get_scene()->add_model(model);
}

void facade::remove_model(const size_t &index)
{
    this->_scene_manager.get_scene()->remove_model(index);
}

void facade::add_camera(const point &cam_pos)
{
    std::shared_ptr<camera> cam(new camera);
    cam->reform(cam_pos, cam_pos, cam_pos);

    this->_scene_manager.get_scene()->add_camera(cam);
    this->_scene_manager.set_cam(_scene_manager.get_scene()->get_cams().get_size() - 1);
}

void facade::remove_camera(const size_t &index)
{
    this->_scene_manager.get_scene()->remove_camera(index);
}

void facade::reform_model(const size_t &model_numb, const point &move, const point &scale, const point &turn)
{
    std::shared_ptr<object> model = _scene_manager.get_scene()->get_models().at(model_numb - 1);
    this->_reform_manager.reform_object(model, move, scale, turn);
}

void facade::set_camera(const size_t &camera_numb)
{
    _scene_manager.set_cam(camera_numb);
}

void facade::draw_scene(std::shared_ptr<base_drawer> _drawer)
{
    _drawer->clear_scene();
    _draw_manager->set_drawer(_drawer);
    _draw_manager->set_cam(_scene_manager.get_cam());
    _scene_manager.get_scene()->get_composite()->accept(_draw_manager);
}

void facade::reform_cam(const size_t &cam_numb, const point &shift)
{
    auto camera = _scene_manager.get_scene()->get_cams().at(cam_numb - 1);
    this->_reform_manager.reform_object(camera, shift, shift, shift);
}

size_t facade::cams_count()
{
    return _scene_manager.get_scene()->get_cams().get_size();
}

size_t facade::models_count()
{
    return _scene_manager.get_scene()->get_cams().get_size();
}

facade::facade()
{
    this->_draw_manager = std::shared_ptr<draw_manager>(new draw_manager);
    std::shared_ptr<base_loader> floader(new file_loader);
    this->_load_manager = std::shared_ptr<abstract_loader>(new model_loader(floader));
}

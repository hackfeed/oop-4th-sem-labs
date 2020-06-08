#ifndef SCENE_H
#define SCENE_H

#include "ui_mainwindow.h"
#include "composite.h"
#include "camera.h"

class scene
{
public:
    scene() : models(new composite){};
    ~scene() = default;

    void add_model(std::shared_ptr<object> model);
    void remove_model(const size_t model_index);

    void add_camera(const std::shared_ptr<camera> &camera);
    void remove_camera(const size_t cam_index);

    vector<std::shared_ptr<object>> get_models();
    std::shared_ptr<composite> get_composite();
    vector<std::shared_ptr<camera>> get_cams();

protected:
    std::shared_ptr<composite> models;
    vector<std::shared_ptr<camera>> cams;
};

#endif

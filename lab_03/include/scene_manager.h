#ifndef SCENE_MANAGER_H
#define SCENE_MANAGER_H

#include "camera.h"
#include "scene.h"
#include "base_manager.h"

class scene_manager : public base_manager
{
public:
    scene_manager();
    ~scene_manager() = default;

    std::shared_ptr<scene> get_scene() const;
    std::shared_ptr<camera> get_cam() const;

    void set_scene(std::shared_ptr<scene> scene_);
    void set_cam(const size_t &cam_numb);
    void next_cam();

private:
    std::shared_ptr<scene> _scene;
    std::shared_ptr<camera> current_cam;
};

#endif

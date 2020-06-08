#ifndef FACADE_H
#define FACADE_H

#include "loader.h"
#include "draw_manager.h"
#include "scene_manager.h"
#include "reform_manager.h"

class facade
{
public:
    static std::shared_ptr<facade> instance()
    {
        static std::shared_ptr<facade> _facade(new facade());

        return _facade;
    }

    ~facade() = default;

    void load_model(std::string fname);
    void add_model(const std::shared_ptr<object> &);
    void remove_model(const size_t &index);

    void add_camera(const point &cam_pos);
    void remove_camera(const size_t &index);
    void set_camera(const size_t &camera_numb);

    void draw_scene(std::shared_ptr<base_drawer> _drawer);

    void reform_model(const size_t &model_numb, const point &move, const point &scale, const point &turn);
    void reform_cam(const size_t &cam_numb, const point &shift);

    size_t cams_count();
    size_t models_count();

private:
    facade();
    facade(const facade &) = delete;
    facade &operator=(const facade &) = delete;

    scene_manager _scene_manager;
    reform_manager _reform_manager;
    std::shared_ptr<abstract_loader> _load_manager;
    std::shared_ptr<draw_manager> _draw_manager;
};

#endif

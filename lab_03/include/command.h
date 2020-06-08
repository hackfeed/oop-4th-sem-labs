#ifndef BASE_COMMAND_H
#define BASE_COMMAND_H

#include <string>
#include "facade.h"
#include "model.h"
#include "camera.h"

class base_command
{
public:
    base_command() = default;
    virtual ~base_command() = default;
    virtual void execute(std::shared_ptr<facade> &facade) = 0;
};

class move_model : public base_command
{
public:
    move_model() = delete;
    move_model(const double &dx, const double &dy, const double &dz, const size_t &mnumb) : dx(dx), dy(dy), dz(dz), model_numb(mnumb){};
    ~move_model() = default;

    virtual void execute(std::shared_ptr<facade> &facade) override
    {
        point move(dx, dy, dz);
        point scale(1, 1, 1);
        point turn(0, 0, 0);

        facade->reform_model(model_numb, move, scale, turn);
    }

private:
    double dx;
    double dy;
    double dz;

    size_t model_numb;
};

class scale_model : public base_command
{
public:
    scale_model() = delete;
    scale_model(const double &kx, const double &ky, const double &kz, const size_t &mnumb) : kx(kx), ky(ky), kz(kz), model_numb(mnumb){};
    ~scale_model() = default;

    virtual void execute(std::shared_ptr<facade> &facade) override
    {
        point move(0, 0, 0);
        point scale(kx, ky, kz);
        point turn(0, 0, 0);

        facade->reform_model(model_numb, move, scale, turn);
    }

private:
    double kx;
    double ky;
    double kz;

    size_t model_numb;
};

class turn_model : public base_command
{
public:
    turn_model() = delete;
    turn_model(const double &ox, const double &oy, const double &oz, const size_t &mnumb) : ox(ox), oy(oy), oz(oz), model_numb(mnumb){};
    ~turn_model() = default;

    virtual void execute(std::shared_ptr<facade> &facade) override
    {
        point move(0, 0, 0);
        point scale(1, 1, 1);
        point turn(ox, oy, oz);

        facade->reform_model(model_numb, move, scale, turn);
    }

private:
    double ox;
    double oy;
    double oz;

    size_t model_numb;
};

class load_model : public base_command
{
public:
    load_model() = delete;
    load_model(const std::string &fname) : fname(fname){};
    ~load_model() = default;

    virtual void execute(std::shared_ptr<facade> &facade) override
    {
        facade->load_model(this->fname);
    }

private:
    std::string fname;
};

class add_model : public base_command
{
public:
    add_model() = delete;
    add_model(const std::shared_ptr<object> &model) : model(model){};
    ~add_model() = default;

    virtual void execute(std::shared_ptr<facade> &facade) override
    {
        facade->add_model(model);
    }

private:
    std::shared_ptr<object> model;
};

class remove_model : public base_command
{
public:
    remove_model() = delete;
    remove_model(const size_t &model_numb) : model_numb(model_numb){};
    ~remove_model() = default;

    virtual void execute(std::shared_ptr<facade> &facade) override
    {
        facade->remove_model(model_numb);
    }

private:
    size_t model_numb;
};

class add_camera : public base_command
{
public:
    add_camera() = delete;
    add_camera(const double x, const double y, const double z) : x_pos(x), y_pos(y), z_pos(z){};
    ~add_camera() = default;

    virtual void execute(std::shared_ptr<facade> &facade) override
    {
        point cam_pos(x_pos, y_pos, z_pos);
        facade->add_camera(cam_pos);
    }

private:
    double x_pos;
    double y_pos;
    double z_pos;
};

class remove_camera : public base_command
{
public:
    remove_camera() = delete;
    remove_camera(const size_t &camera_numb) : camera_numb(camera_numb){};
    ~remove_camera() = default;

    virtual void execute(std::shared_ptr<facade> &facade) override
    {
        facade->remove_camera(camera_numb);
    }

private:
    size_t camera_numb;
};

class draw_scene : public base_command
{
public:
    draw_scene() = delete;
    draw_scene(std::shared_ptr<base_drawer> drawer) : _drawer(drawer){};
    ~draw_scene() = default;

    virtual void execute(std::shared_ptr<facade> &facade) override
    {
        facade->draw_scene(_drawer);
    }

private:
    std::shared_ptr<base_drawer> _drawer;
};

class reform_model : public base_command
{
public:
    reform_model() = delete;
    reform_model(const size_t &numb, const point &move, const point &scale, const point &turn) : model_numb(numb), move(move), scale(scale), turn(turn){};
    ~reform_model() = default;

    virtual void execute(std::shared_ptr<facade> &facade) override
    {
        facade->reform_model(model_numb, move, scale, turn);
    }

private:
    size_t model_numb;

    point move;
    point scale;
    point turn;
};

class move_camera : public base_command
{
public:
    move_camera() = delete;
    move_camera(const size_t &cam_number, const double &shift_ox, const double &shift_oy) : cam_number(cam_number), shift_ox(shift_ox), shift_oy(shift_oy){};
    ~move_camera() = default;

    virtual void execute(std::shared_ptr<facade> &facade) override
    {
        point shift(shift_ox, shift_oy, 0);
        facade->reform_cam(cam_number, shift);
    }

private:
    size_t cam_number;

    double shift_ox;
    double shift_oy;
};

#endif

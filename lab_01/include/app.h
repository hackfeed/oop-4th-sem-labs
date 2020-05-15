#ifndef _APP_H_
#define _APP_H_

#include "figure.h"
#include "constants.h"
#include "codes.h"
#include "io_figure.h"
#include "task_manager.h"
#include "event.h"

#include <iostream>
#include <gtkmm-3.0/gtkmm.h>
#include <cmath>

#define RGB_NUM 3

enum
{
    MOVE_SIZE = 6,
    SCALE_SIZE = 2,
    ROTATE_SIZE = 6,
    ENTRY_SIZE = 3
};

const double DEFAULT_SCREEN_RGB[RGB_NUM] = {0.1, 0.2, 0.3};
const double DEFAULT_LINE_RGB[RGB_NUM] = {0.9, 0.8, 0.7};
const int DEFAULT_LINE_WIDTH = 2;

class myApplication
{
public:
    myApplication(const char *const filename);
    Gtk::Window *get_window();

protected:
    Gtk::Window *main_window = nullptr;
    Gtk::DrawingArea *drawing_area = nullptr;
    Gtk::Button *move_btns[MOVE_SIZE];
    Gtk::Button *scale_btns[SCALE_SIZE];
    Gtk::Button *rotate_btns[ROTATE_SIZE];
    Gtk::Entry *entry_arr[ENTRY_SIZE];

    err_t read_entry(double &value, const Gtk::Entry &entry);
    void on_button_clicked(const char command, const char code);
};

#endif

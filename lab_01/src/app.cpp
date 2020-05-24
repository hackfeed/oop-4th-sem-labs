#include "app.h"

static const char *MOVE_NAMES[] = {"move_up", "move_down", "move_right",
                                   "move_left", "move_front", "move_back"};
static const char *SCALE_NAMES[] = {"scale_plus", "scale_minus"};
static const char *ROTATE_NAMES[] = {"rotate_up", "rotate_down", "rotate_left",
                                     "rotate_right", "rotate_rightup", "rotate_leftup"};
static const char *ENTRY_NAMES[] = {"move_entry", "scale_entry", "rotate_entry"};

myApplication::myApplication(const char *const filename)
{
    Glib::RefPtr<Gtk::Builder> builder = Gtk::Builder::create();
    builder->add_from_file(filename);

    builder->get_widget("main_window", main_window);
    main_window->set_title("Лабораторная №1.");
    Gdk::RGBA color, color2;
    color.set_rgba(0.1, 0.2, 0.3);
    color2.set_rgba(1.0, 1.0, 1.0);
    main_window->override_background_color(color);

    builder->get_widget("drawing_area", drawing_area);

    for (int i = 0; i < MOVE_SIZE; i++)
    {
        builder->get_widget(MOVE_NAMES[i], move_btns[i]);
        move_btns[i]->signal_clicked().connect(sigc::bind<char, char>(sigc::mem_fun(*this,
                                                                                    &myApplication::on_button_clicked),
                                                                      MOVE, 1 << i));
        move_btns[i]->override_background_color(color2);
        move_btns[i]->override_color(color);
    }

    for (int i = 0; i < SCALE_SIZE; i++)
    {
        builder->get_widget(SCALE_NAMES[i], scale_btns[i]);
        scale_btns[i]->signal_clicked().connect(sigc::bind<char, char>(sigc::mem_fun(*this,
                                                                                     &myApplication::on_button_clicked),
                                                                       SCALE, i));
        scale_btns[i]->override_background_color(color2);
        scale_btns[i]->override_color(color);
    }

    for (int i = 0; i < ROTATE_SIZE; i++)
    {
        builder->get_widget(ROTATE_NAMES[i], rotate_btns[i]);
        rotate_btns[i]->signal_clicked().connect(sigc::bind<char, char>(sigc::mem_fun(*this,
                                                                                      &myApplication::on_button_clicked),
                                                                        ROTATE, 1 << i));
        rotate_btns[i]->override_background_color(color2);
        rotate_btns[i]->override_color(color);
    }

    for (int i = 0; i < CMD_N; i++)
    {
        builder->get_widget(ENTRY_NAMES[i], entry_arr[i]);
        entry_arr[i]->get_buffer()->set_text("0");
        entry_arr[i]->override_background_color(color2);
        entry_arr[i]->override_color(color);
    }
}

void myApplication::on_button_clicked(const char command, const char code)
{
    static fpr_t figure_projection = init_projection();

    double value = 0;
    if (read_entry(value, *entry_arr[(int)(command)]))
    {
        printf("Can't read entry.");
        return;
    }

    event_t click_event = init_event(command);
    event_t draw_event = init_event(DRAW);

    event_data_t data = init_data();

    transform_t trans_data = init_transform();

    if (command == MOVE)
    {
        trans_data = init_transform(value * (CHECK_CODE(code, MOVE_RIGHT) - CHECK_CODE(code, MOVE_LEFT)),
                                    value * (CHECK_CODE(code, MOVE_DOWN) - CHECK_CODE(code, MOVE_UP)),
                                    value * (CHECK_CODE(code, MOVE_FRONT) - CHECK_CODE(code, MOVE_BACK)));
    }

    else if (command == ROTATE)
    {
        value *= M_PI / 180;
        trans_data = init_transform(value * (CHECK_CODE(code, ROTATE_UP) - CHECK_CODE(code, ROTATE_DOWN)),
                                    value * (CHECK_CODE(code, ROTATE_LEFT) - CHECK_CODE(code, ROTATE_RIGHT)),
                                    value * (CHECK_CODE(code, ROTATE_LEFTUP) - CHECK_CODE(code, ROTATE_RIGHTUP)));
    }

    else if (command == SCALE)
    {
        if (fabs(value) < DBL_EPSILON)
        {
            printf("Incorrect scale value");
            return;
        }

        if (code == SCALE_PLUS)
        {
            trans_data = init_transform(value, value, value);
        }
        else if (code == SCALE_MINUS)
        {
            double rev_value = 1 / value;
            trans_data = init_transform(rev_value, rev_value, rev_value);
        }
    }

    else
    {
        printf("Incorrect code!");
        return;
    }

    add_trans_data(data, &trans_data);
    add_prj_data(data, &figure_projection);

    err_t rc = task_manager(click_event, data);

    if (rc)
    {
        printf("Can't process clicked button.");
        return;
    }

    Cairo::RefPtr<Cairo::Context> cr = drawing_area->get_window()->create_cairo_context();
    cr->set_source_rgb(DEFAULT_SCREEN_RGB[0], DEFAULT_SCREEN_RGB[1], DEFAULT_SCREEN_RGB[2]);
    cr->paint();
    cr->stroke();

    cr->set_source_rgb(DEFAULT_LINE_RGB[0], DEFAULT_LINE_RGB[1], DEFAULT_LINE_RGB[2]);
    cr->set_line_width(DEFAULT_LINE_WIDTH);
    add_draw_data(data, &cr);

    if ((rc = task_manager(draw_event, data)))
    {
        printf("Can't draw the projection.");
    }
}

Gtk::Window *myApplication::get_window()
{
    return main_window;
}

err_t myApplication::read_entry(double &value, const Gtk::Entry &entry)
{
    std::string str = static_cast<std::string>(entry.get_buffer()->get_text());
    try
    {
        value = std::stod(str);
    }
    catch (const std::invalid_argument &ia)
    {
        std::cerr << "Invalid argument: " << ia.what() << '\n';
        return READ_ERROR;
    }
    return OK;
}

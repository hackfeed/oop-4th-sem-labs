#include "main.h"

using namespace std;

int main(int argc, char *argv[])
{
    int window_argc = 1;
    auto app = Gtk::Application::create(window_argc, argv);

    event_t load_event = init_event(LOAD_DATA);
    event_data_t data = init_data();

    const char *data_filename;
    if (argc > DATA_FILENAME_POS)
        data_filename = argv[DATA_FILENAME_POS];
    else
        data_filename = default_data_filename;

    add_load_data(data, data_filename);
    event_data_t error_data = init_data();

    err_t rc = task_manager(load_event, data);
    if (rc)
    {
        event_t quit_event = init_event(QUIT);
        task_manager(quit_event, error_data);
        return rc;
    }

    const char *forms_filename;
    if (argc > FORMS_FILENAME_POS)
        forms_filename = argv[FORMS_FILENAME_POS];
    else
        forms_filename = default_forms_filename;

    myApplication application(forms_filename);
    return app->run(*application.get_window());
}

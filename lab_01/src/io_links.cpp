#include "io_links.h"

static err_t allocate_link(larr_t &links_array)
{
    link_t *tmp = (link_t *)realloc(links_array.arr,
                                    sizeof(link_t) * (links_array.size + 1));
    if (!tmp)
    {
        return ALLOCATION_ERROR;
    }
    links_array.arr = tmp;

    return OK;
}

static err_t add_link(larr_t &links_array, const unsigned int l1, const unsigned int l2)
{
    err_t rc = allocate_link(links_array);
    if (!rc)
    {
        link_t *&larray = links_array.arr;
        unsigned int &size = links_array.size;
        larray[size].l1 = l1;
        larray[size].l2 = l2;

        size++;
    }
    return rc;
}

static void assign_links(larr_t &links, larr_t &links_to_assign)
{
    links = links_to_assign;
}

static err_t get_links(larr_t &main_links_array, FILE *const f)
{
    unsigned int l1, l2;
    larr_t links_array = init_links_arr();
    err_t rc = OK;

    while (fscanf(f, "%u%u", &l1, &l2) == 2 * READED && rc == OK)
    {
        if (add_link(links_array, l1, l2))
        {
            rc = ALLOCATION_ERROR;
        }
    }

    if (rc)
    {
        destroy_links(links_array);
    }
    else
    {
        assign_links(main_links_array, links_array);
    }

    return rc;
}

static err_t verify_links(larr_t &links_array, const unsigned int max_index)
{
    link_t *&larray = links_array.arr;
    err_t rc = OK;
    for (unsigned int i = 0; i < links_array.size && rc == OK; ++i)
    {
        if (larray[i].l1 > max_index || larray[i].l2 > max_index)
        {
            rc = DATA_ERROR;
        }
    }

    if (rc)
    {
        destroy_links(links_array);
    }

    return rc;
}

err_t handle_links(larr_t &main_links_array, FILE *const f, const unsigned int max_index)
{
    err_t rc = get_links(main_links_array, f);
    if (rc)
    {
        return rc;
    }
    return verify_links(main_links_array, max_index);
}

void destroy_links(larr_t &links)
{
    if (links.arr != NULL)
    {
        free(links.arr);
        links.arr = NULL;
    }
}

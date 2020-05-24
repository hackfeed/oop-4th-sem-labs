#include "io_points.h"

err_t find_center(parr_t &points)
{
    if (points.size <= 0)
    {
        return DATA_ERROR;
    }

    point_t &center = points.cp;
    center = init_point(0, 0, 0);
    const point_t *const &points_array = points.arr;
    for (unsigned int i = 0; i < points.size; i++)
    {
        center.x += points_array[i].x;
        center.y += points_array[i].y;
        center.z += points_array[i].z;
    }

    center.x /= points.size;
    center.y /= points.size;
    center.z /= points.size;

    return OK;
}

err_t allocate_points(parr_t &points)
{
    points.arr = (point_t *)(calloc(points.size, sizeof(point_t)));
    if (!points.arr)
    {
        return ALLOCATION_ERROR;
    }
    return OK;
}

err_t read_points(parr_t &points_array, FILE *const f)
{
    for (unsigned int i = 0; i < points_array.size; i++)
    {
        if (fscanf(f, "%lf%lf%lf", &points_array.arr[i].x, &points_array.arr[i].y,
                   &points_array.arr[i].z) != 3 * READED)
        {
            return READ_ERROR;
        }
    }

    return OK;
}

void destroy_points(parr_t &points)
{
    if (points.arr != NULL)
    {
        free(points.arr);
        points.arr = NULL;
    }
}

void destroy_ppoints(pparr_t &points)
{
    if (points.arr != NULL)
    {
        free(points.arr);
        points.arr = NULL;
    }
}

static int read_size(FILE *const f, unsigned int *size)
{
    return fscanf(f, "%u", size);
}

static void assign_points(parr_t &points, parr_t &points_to_assign)
{
    points = points_to_assign;
}

err_t get_points(parr_t &points, FILE *const f)
{
    parr_t tmp_points = init_points_arr();

    if (read_size(f, &tmp_points.size) != READED)
    {
        return READ_ERROR;
    }

    err_t rc = OK;

    if ((rc = allocate_points(tmp_points)))
    {
        ;
    }

    else if ((rc = read_points(tmp_points, f)))
    {
        destroy_points(tmp_points);
    }
    else
    {
        assign_points(points, tmp_points);
    }

    return rc;
}

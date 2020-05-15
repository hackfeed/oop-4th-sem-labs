#include "io_points.h"

err_t find_center(parr_t &points)
{
    point_t &center = points.cp;
    center = init_point(0, 0, 0);
    err_t rc = OK;

    if (points.size <= 0)
    {
        rc = DATA_ERROR;
    }

    if (!rc)
    {
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
    }

    return rc;
}

err_t allocate_points(parr_t &points)
{
    err_t rc = OK;
    points.arr = (point_t *)(calloc(points.size, sizeof(point_t)));
    if (!points.arr)
    {
        rc = ALLOCATION_ERROR;
    }
    return rc;
}

err_t read_points(parr_t &points_array, FILE *const f)
{
    err_t rc = OK;
    for (unsigned int i = 0; i < points_array.size && !rc; i++)
    {
        if (fscanf(f, "%lf%lf%lf", &points_array.arr[i].x, &points_array.arr[i].y,
                   &points_array.arr[i].z) != 3 * READED)
        {
            rc = READ_ERROR;
        }
    }

    return rc;
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

err_t get_points(parr_t &points, FILE *const f)
{
    err_t rc = OK;
    parr_t tmp_points = init_points_arr();

    if (fscanf(f, "%u", &tmp_points.size) != READED)
    {
        rc = READ_ERROR;
    }

    else if ((rc = allocate_points(tmp_points)))
    {
        ;
    }

    else if ((rc = read_points(tmp_points, f)))
    {
        destroy_points(tmp_points);
    }
    else
    {
        points = tmp_points;
    }

    return rc;
}

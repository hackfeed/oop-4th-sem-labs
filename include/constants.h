#ifndef _CONSTANTS_H_
#define _CONSTANTS_H_

#define READ 1
typedef enum
{
    OK = 0,
    FILE_ERROR,
    ALLOCATION_ERROR,
    READ_ERROR,
    DATA_ERROR,
    MOVE_ERROR,
    ROTATE_ERROR,
    SCALE_ERROR,
    COMMAND_ERROR
} err_t;

#endif

#ifndef _CODES_H_
#define _CODES_H_

// Number of conversion commands (move, scale, rotate).
#define CMD_N 3
#define CHECK_CODE(CODE, PROPERTY) ((CODE & PROPERTY) ? 1 : 0)
// Move codes.
enum
{
    MOVE_UP = 0b1,
    MOVE_DOWN = 0b10,
    MOVE_RIGHT = 0b100,
    MOVE_LEFT = 0b1000,
    MOVE_FRONT = 0b10000,
    MOVE_BACK = 0b100000
};
// Scale codes.
enum
{
    SCALE_PLUS = 0,
    SCALE_MINUS
};
// Rotate codes.
enum
{
    ROTATE_UP = 0b1,
    ROTATE_DOWN = 0b10,
    ROTATE_LEFT = 0b100,
    ROTATE_RIGHT = 0b1000,
    ROTATE_RIGHTUP = 0b10000,
    ROTATE_LEFTUP = 0b100000
};

// Conversion command codes (conversion commands).
enum
{
    MOVE,
    SCALE,
    ROTATE
};
// Non-conversion commands (first index one value bigger than last elem's in command codes enum).
enum
{
    LOAD_DATA = ROTATE + 1,
    UPDATE_PROJECTION,
    DRAW,
    QUIT
};

#endif

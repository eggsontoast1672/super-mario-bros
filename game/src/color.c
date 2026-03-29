#include "smbc/color.h"

const Color COLOR_BACKGROUND = {0x8e, 0x7a, 0xff, 0xff};

Color color_from_rgb(uint8_t r, uint8_t g, uint8_t b)
{
    /* 
     * ANSI C is so silly. We cannot just return a compound literal from this function to make it a
     * one-liner, since C90 does not support those. We also cannot declare the color in one line
     * with aggregate initialization, since the arguments have to be known at compile time! So we
     * have to do it this way.
     */

    Color color;

    color.r = r;
    color.g = g;
    color.b = b;
    color.a = 0xff;

    return color;
}

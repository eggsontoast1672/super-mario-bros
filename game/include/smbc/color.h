#pragma once

#include <stdint.h>

typedef struct Color {
    uint8_t r;
    uint8_t g;
    uint8_t b;
    uint8_t a;
} Color;

extern const Color COLOR_BACKGROUND;

/**
 * Create a color from its red, green, and blue components.
 * 
 * This function returns a color with the specified components, while setting the alpha component
 * to 255. This is useful for creating an opaque color.
 */
Color color_from_rgb(uint8_t r, uint8_t g, uint8_t b);

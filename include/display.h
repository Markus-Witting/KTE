#pragma once

#include <stdlib.h>
#include <stdio.h>

struct DISPLAY{
    char *buffer;

    size_t rows;
    size_t width;
    
    void (*Blitz)(struct DISPLAY* display);
    void (*Update)(struct DISPLAY* display, const char *i_buffer, size_t t_row, size_t b_row);
};

struct DISPLAY *Display(size_t rows, size_t width);

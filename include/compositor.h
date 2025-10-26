#pragma once

#include <stdlib.h>

#include "frame.h"

struct COMPST{
    struct FRAME **frames;
    size_t frames_count;

    char *buffer;

    size_t rows;
    size_t width;

    size_t byte_size;
    
    void (*Blitz)(struct COMPST *compst);
    void (*Update)(struct COMPST *compst, const char *i_buffer, size_t t_row, size_t b_row);

    void (*AddFrame)(struct COMPST *compst, struct FRAME *frame_ptr);
};

struct COMPST *Compst(size_t rows, size_t width);

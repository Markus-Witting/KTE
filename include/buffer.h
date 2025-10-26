#pragma once

#include <stdlib.h>

typedef struct{
    char byte[4]; 
} CELL;

struct BUFFER {
    CELL **data;

    int row_count;
    int width;

    int byte_width; // CELL byte_width
    
    void (*Set)(int row_index, int width_index);
    void (*Index)(int row_index, int width_index);
    void (*Free)(struct BUFFER *buf);
};

struct BUFFER *Buffer(int rows, int width, int byte_width);


#include "buffer.h"

#include <stdlib.h>


static void Free_IMPL(struct BUFFER *buf){
    for (int i = 0; i < buf->row_count; i++){
        free(buf->data[i]);
    }

    free(buf->data);
    free(buf);
}

struct BUFFER *Buffer(int row_count, int width, int byte_width){
    struct BUFFER *buf = malloc(sizeof(struct BUFFER)); // alloc mem for the BUFFER struct
    if (!buf) return NULL;

    buf->row_count = row_count;
    buf->width = width;

    buf->byte_width = byte_width;
    
    buf->Free = Free_IMPL;

    buf->data = malloc(sizeof(CELL*) * row_count);

    for (int i = 0; i < row_count; i++){
        buf->data[i] = malloc(sizeof(CELL) * width);

        if (!buf->data[i]){
            for (int n = 0; n < i; n++) free(buf->data[i]);

            free(buf->data);
            free(buf);

            return NULL;
        }
    }

    return buf;
}


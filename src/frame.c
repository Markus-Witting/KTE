#include <stdlib.h>

#include "frame.h"

static void Free_IMPL(struct FRAME *frame){
    free(frame->buffer); // Free output buffer 

    free(frame);
}

// Move to compositor -- for 
static void UpdateOBuffer_IMPL(struct FRAME *frame){
    int spacing = 1; // To avoid border chars

    if (frame->border == NONE) spacing = 0;

    // Loop for every row except top and 
    for (int i = spacing; i < frame->rows - spacing; i++){
        for (int j = spacing; j < frame->width - spacing; j++){
            frame->buffer[(i * frame->width) + j] = '+';
        }
    }
}


struct FRAME *Frame(int top, int bottom, int left, int right, FLEX flex, BORDER border){
    struct FRAME *frame = malloc(sizeof(struct FRAME));
    if (!frame) return NULL;

    frame->top = top;
    frame->bottom = bottom;
    frame->left = left;
    frame->right = right;
    frame->flex = flex;
    frame->border = border;

    int rows = bottom-top;
    int width = right - left;

    frame->buffer = malloc(sizeof(rows * width));

    ApplyBorder(frame->buffer, rows, width);

    frame->UpdateBuffer = UpdateOBuffer_IMPL;
    frame->Free = Free_IMPL;

    return frame;
}
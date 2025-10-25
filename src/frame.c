#include <stdlib.h>

#include "frame.h"

void Free_IMPL(struct FRAME *frame){
    free(frame);
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

    frame->Free = Free_IMPL;

    return frame;
}
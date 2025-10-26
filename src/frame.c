#include <stdlib.h>

#include "frame.h"

static void Free_IMPL(struct FRAME *frame){
    if (frame->buffer) free(frame->buffer); // Free output buffer 
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

static BORDERCHARSET GetBorderCharSet(enum BORDER border){

    switch (border){
        case NORMAL:
            BORDERCHARSET chs = {
                "\xE2\x94\x82\x00",
                "\xE2\x94\x80\x00",

                "\xE2\x94\x8C\x00",
                "\xE2\x94\x90\x00",
                
                "\xE2\x94\x94\x00",
                "\xE2\x94\x98\x00"
            };
            
            return chs;
            break;
    }

}

struct FRAME *Frame(int top, int bottom, int left, int right, enum FLEX flex, enum BORDER border){
    struct FRAME *frame = malloc(sizeof(struct FRAME));
    if (!frame) return NULL;

    frame->top = top;
    frame->bottom = bottom;
    frame->left = left;
    frame->right = right;

    frame->flex = flex;


    frame->border = border;
    

    frame->border_charset = GetBorderCharSet(border); 


    int rows = bottom-top;
    int width = right - left;

    frame->buffer = malloc(rows * width);
    if (!frame->buffer) return NULL;

    frame->UpdateBuffer = UpdateOBuffer_IMPL;
    frame->Free = Free_IMPL;

    return frame;
}
/*
chs->l_v = "\xE2\x94\x82\x00";

*/
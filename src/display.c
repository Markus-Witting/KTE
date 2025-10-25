#include "display.h"

// thought it was Blitz not Blit, sounds cool so im keeping it
static void Blitz_IMPL(struct DISPLAY *display){
    fputs(display->buffer, stdout);
}

static void Update_IMPL(struct DISPLAY *display, const char *input_buf, size_t t_row, size_t b_row){
    printf("UPDATING\n");
}


struct DISPLAY *Display(size_t rows, size_t width){
    struct DISPLAY *display = malloc(sizeof(struct DISPLAY));
    if (!display) return NULL;

    display->rows = rows;
    display->width = width;
    
    display->buffer = calloc(rows * (width + 1), sizeof(char));
    if (!display->buffer){
        free(display);
        return NULL;
    }

    display->Blitz = Blitz_IMPL;
    display->Update = Update_IMPL;

    return display;
}
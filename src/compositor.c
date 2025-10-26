#include "compositor.h"
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

// thought it was Blitz not Blit, sounds cool so im keeping it
static void Blitz_IMPL(struct COMPST *compst){
    printf("\n");
    write(1, compst->buffer, compst->byte_size);
}

static void Update_IMPL(struct COMPST *compst, const char *input_buf, size_t t_row, size_t b_row){
    printf("UPDATING\n");
}

static void Add_Frame_IMPL(struct COMPST *compst, struct FRAME *frame_ptr){
    struct FRAME **temp_frames = realloc(compst->frames, sizeof(struct FRAME) * compst->frames_count + 1);
    if (temp_frames == NULL) perror("Could not reallocate frames array pointer");
    
    compst->frames = temp_frames;
}

static void Free_IMPL(struct COMPST *compst){
    if (compst->frames != NULL){
        for (size_t i = 0; i < compst->frames_count; i++){
            compst->frames[i]->Free(compst->frames[i]);
        }
    }

    free(compst->frames);

    free(compst->buffer);

    free(compst);
}

struct COMPST *Compst(size_t rows, size_t width){
    struct COMPST *compst = malloc(sizeof(struct COMPST));
    if (!compst) return NULL;

    compst->rows = rows;
    compst->width = width;

    compst->byte_size = (rows * width) * 4; // UTF-8 bytes require maximum 4 
    
    compst->buffer = malloc(compst->byte_size);
    if (!compst->buffer){
        free(compst);
        return NULL;
    }

    compst->Blitz = Blitz_IMPL;
    compst->Update = Update_IMPL;

    return compst;
}


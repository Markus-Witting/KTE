#pragma once

// FLEX is rellevant only for user.
// FRAME position data can always be overidden in code
enum FLEX{
    FIXED,      // Static for user
    STABLE,     // Still at initialisation -- moveable at runtime
    OVERLAY,    // Static -- controlled through code -- Composited over all other frames
};

enum BORDER{
    NONE,
    NORMAL,
    BOLD,
    DOTTED,
    DUAL,
} ;

typedef struct{
    // Lines
    char *l_v; // vertical
    char *l_h; // horizontal

    // Corners -- top
    char *c_tl; 
    char *c_tr;

    // Corners -- bottom
    char *c_bl;
    char *c_br;
} BORDERCHARSET;

struct FRAME{
    int top;
    int bottom;
    int left;
    int right;

    int rows;
    int width;

    enum FLEX flex;

    enum BORDER border;

    BORDERCHARSET border_charset;

    char *buffer; // FRAME buffer -- parsed to compositor

    void (*UpdateBuffer)(struct FRAME *frame);
    void (*Free)(struct FRAME *frame);
};

struct FRAME *Frame(int top, int bottom, int left, int right, enum FLEX flex, enum BORDER border);
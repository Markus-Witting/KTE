#pragma once

// FLEX is rellevant only for user.
// FRAME position data can always be overidden in code
typedef enum {
    FIXED,      // Static for user
    STABLE,     // Still at initialisation -- moveable at runtime
    EXPAND,     // Expands at initialisation & runtime
    OVERLAY,    // Static -- controlled through code -- Composited over all other frames
} FLEX;

typedef enum {
    NONE,
    NORMAL,
    BOLD,
    DOTTED,
    DUAL,
} BORDER;

struct FRAME{
    int top;
    int bottom;
    int left;
    int right;

    FLEX flex;

    BORDER border;

    void (*Free)(struct FRAME* frame);
};

struct FRAME* Frame(int top, int bottom, int left, int right, FLEX flex, BORDER border);
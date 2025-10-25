#pragma once

#include <stdlib.h>

// FLEX is irrelevant in code as FRAME position data can always be overidden
enum FLEX{
    fixed,      // Static for user
    stable,     // Still at initialisation -- moveable at runtime
    expand      // Expands at initialisation & runtime
};

struct FRAME{
    u_int top;
    u_int bottom;
    u_int left;
    u_int right;

    enum FLEX flex;
};

void Frame(u_int t, u_int b, u_int l, u_int r);
#pragma once

#include <stdlib.h>

// FLEX is irrelevant in code as FRAME position data can always be overidden
enum FLEX{
    fixed,      // Static for user
    stable,     // Still at initialisation -- moveable at runtime
    expand      // Expands at initialisation & runtime
};

struct FRAME{
    size_t top;
    size_t bottom;
    size_t left;
    size_t right;

    enum FLEX flex;
};

void Frame(size_t t, size_t b, size_t l, size_t r);
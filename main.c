#include <stdio.h>

#include "display.h"

int main(){
    struct DISPLAY* display = Display(50, 140); 

    display->Blitz(display);

    return 0;
}
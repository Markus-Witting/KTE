#include <stdio.h>

#include "display.h"
#include "input.h"

enum STATE {
    INACTIVE,
    ACTIVE,
    UPDATING
};

int main(){
    struct DISPLAY* display = Display(50, 140); 

    enum STATE state = ACTIVE;

    while (state == ACTIVE){
        state = INACTIVE;
    }

    //display->Blitz(display);

    return 0;
}
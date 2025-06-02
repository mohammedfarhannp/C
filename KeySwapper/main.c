#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <X11/Xlib.h>
#include <X11/keysym.h>
#include <unistd.h>

#include "random.h"

const char ascii_lowercase[] = "abcdefghijklmnopqrstuvwxyz";

void swap_keys(Display*, const char*, const char*);

int main(int argc, char* argv[]) {
    srand(time(0));

    Display* display = XOpenDisplay(NULL);
    if(!display){
        return 1;
    }

    char key_0[2], key_1[2], key_2[2];

    key_0[0] = ascii_lowercase[random_num(0, 25)];
    key_0[1] = '\0';
    
    key_1[0] = ascii_lowercase[random_num(0, 25)];
    key_1[1] = '\0';
    
    key_2[0] = ascii_lowercase[random_num(0, 25)];
    key_2[1] = '\0';

    swap_keys(display, key_0, key_1);
    swap_keys(display, key_1, key_2);
    swap_keys(display, key_2, key_0);

    XCloseDisplay(display);

    return 0;
}

void swap_keys(Display* dsply, const char* from, const char* to) {
    KeyCode from_code = XKeysymToKeycode(dsply, XStringToKeysym(from));
    KeySym to_sym = XStringToKeysym(to);

    if (from_code && to_sym) {
        XChangeKeyboardMapping(dsply, from_code, 1, &to_sym, 1);
        XFlush(dsply);
    }
}

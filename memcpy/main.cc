#include "mem.h"
#include <stdio.h>

int main(int argc, char** argv) {
    char a = 'a';
    char b = 'b';
    memCpy(&b, &a, 1);
    printf("%c\n", b);
}
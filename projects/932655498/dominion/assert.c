
#include <stdio.h>
#include <stdlib.h>

//my assert function
void assert(int input, char *error) {
    if (!input) {
        fprintf(stderr, "Program fail: %s\n", error);
        exit (0);
    }
}

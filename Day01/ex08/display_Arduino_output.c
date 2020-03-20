#include <stddef.h>
#include <stdio.h>
#include <stdlib.h>

int main(void)
{
    FILE *stream = fopen("/dev/ttyACM0", "r");
    char *str = NULL;
    size_t n = 0;

    while (1) {
        getline(&str, &n, stream);
        printf(str);
    }
}
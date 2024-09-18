/* Codes from CSAPP.*/

#include <stdio.h>

typedef unsigned char *byte_pointer;


void show_bytes(byte_pointer start, size_t len)
{
    size_t i;
    for (i = 0; i < len; i++){
        printf("%p\t0x%.2x\n", &start[i], start[i]);
    }
    printf("\n");
}


int main(void)
{
    // Example.
    int x = 1;
    show_bytes((byte_pointer) &x, sizeof(int));

    return 0;
}


/*
CSAPP: 2.
*/
#include <stdio.h>
#include <string.h>
#include <math.h>

typedef unsigned char *byte_pointer;


void show_bytes(byte_pointer start, size_t len)
{
    size_t i;
    for (i = 0; i < len; i++){
        printf("%p\t0x%.2x\n", &start[i], start[i]);
    }
    printf("\n");
}


void show_int(int x) {
    show_bytes((byte_pointer) &x, sizeof(int));
}


void show_unsigned_int(unsigned int x) {
    show_bytes((byte_pointer) &x, sizeof(unsigned int));
}


void show_encoding(char *comment, unsigned int ux, int x){
    printf("################################################################################\n");
    printf("%s\n\n", comment);
    printf("Unsigned int: %u\n\n", ux);
    show_unsigned_int(ux);
    printf("--------------------------------------------------\n");
    printf("Signed int: %d\n\n", x);
    show_int(x);
}


int main(void)
{
    /*
    1. If x >= 0, the encodings of unsigned and signed are the same.
    */

    unsigned int ux;
    int x;
    char *comment;

    comment = "1. If x >= 0, the encodings of unsigned and signed are the same.";
    ux = 5;
    x = 5;
    show_encoding(comment, ux, x);

    comment = "2. If x < 0, the two's complement encoding of signed is:";
    x = -5;
    printf("--------------------------------------------------\n");
    printf("%s\n\n", comment);
    printf("Signed int: %d\n\n", x);
    show_int(x);

    comment = "3. If x > 0 and is too large, it will overflow.";
    // >>> 2^32 = 4294967296
    // >>> 2^31 = 2147483648
    ux = 2147483648;
    // warning: overflow in expression; result is -2147483648 with type 'int'.
    x = 2147483647 + 1;
    show_encoding(comment, ux, x);
    printf("ux - 2^32: %ld\n\n", ux - 4294967296);

    comment = "4. If x > 0 and is too large, it will overflow.";
    ux = 4294967296 - 1;
    // warning: implicit conversion from 'long' to 'int' changes value from 4294967295 to -1
    x = 4294967296 - 1;
    show_encoding(comment, ux, x);

    return 0;
}

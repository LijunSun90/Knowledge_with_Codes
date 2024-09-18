// TODO.

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
    float zero, inf, nan;

    zero = 0x00000000;
    inf = 0x7f800000;
    nan = 0x7fffffff;

    printf("zero:\n");
    show_bytes((byte_pointer) &zero, sizeof(float));
    printf("inf:\n");
    show_bytes((byte_pointer) &inf, sizeof(float));
    printf("nan:\n");
    show_bytes((byte_pointer) &nan, sizeof(float));

    printf("nan: %f, nan<0: %d, nan>0: %d\n", nan, nan<0, nan>0);

    /*
    zero:
    0x16dc6b3a8	0x00
    0x16dc6b3a9	0x00
    0x16dc6b3aa	0x00
    0x16dc6b3ab	0x00

    inf:
    0x16dc6b3a4	0x00
    0x16dc6b3a5	0x00
    0x16dc6b3a6	0xff
    0x16dc6b3a7	0x4e

    nan:
    0x16dc6b3a0	0x00
    0x16dc6b3a1	0x00
    0x16dc6b3a2	0x00
    0x16dc6b3a3	0x4f

    nan: 2147483648.000000, nan<0: 0, nan>0: 1
    */

    return 0;
}

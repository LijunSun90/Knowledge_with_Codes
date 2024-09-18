#include <stdio.h>
#define DELTA sizeof(int)


int main(void)
{
    unsigned i, j;
    i = 1;
    j = i - 2;
    // 2^32 = 4294967296
    // ui=1, di=1, uj=4294967295, dj=-1, j>=0:1, j>=0:1
    printf("ui=%u, di=%d, uj=%u, dj=%d, j>=0:%u, j>=0:%d\n", i, i, j, j, j>=0, j>=0);

    // DELTA:4
    printf("DELTA:%lu\n", DELTA);
    i = 3;
    // i-DELTA >= 0:1
    // Explanation: DELTA is defined as unsigned because the return type of sizeof() is unsigned.
    // When there are signed and unsigned values in an expression, the signed will be casted to unsigned.
    // So, the result of "i-DELTA" will be interpreted as unsigned,
    // and the unsigned interpretation of -1 (= 3 - 4) is a big positive integer (UMax in this case).
    // Therefore, "i-DELTA >=0" is True.
    printf("i-DELTA >= 0:%d\n", i-DELTA >= 0);
    // Infinite loop.
//    for (i = 3; i-DELTA >= 0; i-= DELTA){
//        printf("i:%d", i);
//    }

    return 0;
}

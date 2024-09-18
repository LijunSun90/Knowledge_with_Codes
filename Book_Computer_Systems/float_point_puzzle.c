// TODO.

#include <stdio.h>

int main(void)
{
    int x;
    float f;
    double d;

    // 1. x == (int)(float) x,
    //x = 5;
    x = 258;
    printf("x == (int)(float) x, %d\n", x == (int)(float) x);

    // 2. x == (int)(double) x

    // 3. x == (int)(double) x

    // 4. d == (double)(float) d

    // 5. f == -(-f)

    // 6. 2/3 == 2/3.0

    // 7. d < 0.0	 ⇒ 	((d*2) < 0.0)

    // 8. d * d >= 0.0

    // 9. (d+f)-d == f

    printf("\n");
    return 0;
}

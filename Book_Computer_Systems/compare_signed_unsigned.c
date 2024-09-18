#include <stdio.h>

int main(void)
{
    /*
    TMax_w = 2^{w-1} - 1
    TMin_w = -2^{w-1}
    >>> 2^64 = 18446744073709551616
    >>> 2^63 = 9223372036854775808
    >>> 2^32 = 4294967296
    >>> 2^31 = 2147483648
    */

    /*
    1. How to translate the constant: data type, long? int?
    2. The constant number "-2^{w - 1}" is taken and interpreted as unsigned.
    */

    // warning: format specifies type 'int' but the argument has type 'long'
    // %d -> %ld
    printf("9223372036854775807: %d\n", 9223372036854775807);

    // OK.
    printf("9223372036854775807: %ld\n", 9223372036854775807);

    // warning: format specifies type 'int' but the argument has type 'long'
    // %d -> %ld
    printf("-9223372036854775807: %d\n", -9223372036854775807);

    // OK.
    printf("-9223372036854775807: %ld\n", -9223372036854775807);

    // warning: integer literal is too large to be represented in a signed integer type, interpreting as unsigned
    // warning: format specifies type 'int' but the argument has type 'unsigned long long'
    // %d -> %llu
    printf("-9223372036854775808: %d\n", -9223372036854775808);

    // warning: integer literal is too large to be represented in a signed integer type, interpreting as unsigned
    // warning: format specifies type 'long' but the argument has type 'unsigned long long'
    // %d -> %llu
    printf("-9223372036854775808: %ld\n", -9223372036854775808);

    // warning: integer literal is too large to be represented in a signed integer type, interpreting as unsigned
    printf("-9223372036854775808: %lld\n", -9223372036854775808);

   // OK.
    printf("2147483647: %d\n", 2147483647);

    /*
    3. The right way to write the constant number "-2^{w - 1}" is "-TMax - 1", where "TMax = 2^{w - 1} - 1".
    */

    // +

    // OK. TMax.
    printf("0 < 9223372036854775808: %d\n", 0 < 9223372036854775807);

    // Warning. (TMax + 1).
    // warning: integer literal is too large to be represented in a signed integer type, interpreting as unsigned
    printf("0 < 9223372036854775808: %d\n", 0 < 9223372036854775808);

    // Warning. TMax + 1.
    // warning: overflow in expression; result is -9223372036854775808 with type 'long'
    printf("0 < 9223372036854775808: %d\n", 0 < 9223372036854775807 + 1);

    // -

    // Warning. -TMin.
    // warning: integer literal is too large to be represented in a signed integer type, interpreting as unsigned
    printf("-9223372036854775808 < 0: %d\n", -9223372036854775808 < 0);

    // 0K. (-TMax - 1)
    printf("-9223372036854775807 - 1 < 0: %d\n", -9223372036854775807 - 1  < 0);

    /*
    Three test results by different expressions with the same logic.
    */

    // 0
    // Explanation: -9223372036854775808 (TMin) is a special number that is interpreted as unsigned.
    // The constant 9223372036854775807 is first taken as a signed number in C.
    // But, in the expression "-9223372036854775808 < 9223372036854775807", there is an unsigned and a signed number.
    // So, the signed number is implicitly casted to unsigned.
    // Therefore, the result of the expression is 0.
    printf("-9223372036854775808 < 9223372036854775807: %d\n", -9223372036854775808 < 9223372036854775807);

    // 1
    // Explanation: the variable i is explicitly a signed number.
    // So, the expression "i < 9223372036854775807" is the comparison of two signed number.
    // Therefore, the result is 1.
    int i = -9223372036854775808;
    printf("i < 9223372036854775807: %d\n", i < 9223372036854775807);

    // 1
    // Explanation: the ""-9223372036854775807 - 1 < 9223372036854775807" is the comparison of two signed number.
    // Therefore, the result is 1.
    printf("-9223372036854775807 - 1 < 9223372036854775807: %d\n", -9223372036854775807 - 1 < 9223372036854775807);
    return 0;
}


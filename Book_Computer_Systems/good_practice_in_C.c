
/* Portable across machines (of different size in the data representation) */
/* Portable mask pattern*/
/* yield a mask of all ones (from CSAPP:2.1.7) */
~0
/* A bit pattern valued 2^k - 1, i.e, (0, ..., 0, 1, ..., 1) with the number of 1 being k.*/
(1<<k) - 1


/* Prefix and postfix operators (from K&RC) */
/* Prefix operator: increment before its value is used */
++n
/* Postfix operator: increment after its value has been used */
n++

/*
Shift operation (CSAPP:2.1.9):

Logical right shift: "fill the left with zeros".
Arithmetic right shift: "fill the left with repetitions of the most significant bit".

1. C standards does not precise define the behavior of x >> K to be either one.
2. In practice, for signed, arithmetic right shift; for unsigned, logical right shift.
*/
x >> k

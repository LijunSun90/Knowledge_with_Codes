
/* Portable across machines (of different size in the data representation) */
/* yield a mask of all ones (from CSAPP:2.1.7) */
~0

/* Prefix and postfix operators (from K&RC) */
/* Prefix operator: increment before its value is used */
++n
/* Postfix operator: increment after its value has been used */
n++

/*
Shift operation (CSAPP:2.1.9):

Logical right shift: "fill the left with zeros".
Arithmetic right shift: "fill the left with repetitions of the most significant bit".

1. C stands does not precise define the behavior of x >> K to be either one.
2. In practice, for signed, arithmetic right shift; for unsigned, logical right shift.
*/
x >> k

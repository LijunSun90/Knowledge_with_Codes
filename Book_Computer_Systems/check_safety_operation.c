

/* From CSAPP: Problem 2.27 */
/* Determine whether arguments can be added without overflow */
int uadd_ok(unsigned x, unsigned y) {
    unsigned sum = x+y;
    return sum >= x;
}


/* From CSAPP: Problem 2.30 */
/* Determine whether arguments can be added without overflow */
int tadd_ok(int x, int y){
    int sum = x+y;
    int neg_over = x < 0 && y < 0 && sum >= 0;
    int pos_over = x >= 0 && y >= 0 && sum < 0;
    return !neg_over && !pos_over;
}


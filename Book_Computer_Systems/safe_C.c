#include <stdio.h>


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



void safe_loop_count_down_with_unsigned(cnt)
{
    unsigned i;
    for (i = cnt-2; i < cnt; i--)
        printf('i:%u\n', i);
}

void safe_loop_count_down_with_unsigned_better(cnt)
{
    // Work even if cnt = UMax.
    size_t i;
    for (i = cnt-2; i < cnt; i--)
        printf('i:%u\n', i);
}


void safe_loop_count_up(len)
{
    size_t i;
    for (i = 0; i < len; i++)
        printf('i:%u\n', i);
}


int main(void)
{
    return 0;
}

#include <stdlib.h>
#include "../../allocator.c"

int main(void)
{
    void *a = malloc_name(100, "Test Allocation: 0");
    void *b = malloc_name(100, "Test Allocation: 1"); /* Will be deleted */
    void *c = malloc_name(100, "Test Allocation: 2");
    void *d = malloc_name(10, "Test Allocation: 3");  /* Will be deleted */
    void *e = malloc_name(100, "Test Allocation: 4");
    void *f = malloc_name(100, "Test Allocation: 5");

    free(b);
    free(d);

    /* This will split:
     * - b with first fit
     * - d with best fit
     * - f with worst fit
     */
    void *g = malloc_name(10, "Test Allocation: 6");

    print_memory();

    return 0;
}

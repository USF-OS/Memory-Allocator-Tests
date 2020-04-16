#include <stdlib.h>
#include "vmsize.h"
#include "../../allocator.c"

int main(void)
{
    unsigned long vm_start = vmsize();

    void *a = malloc_name(500, "Test Allocation: 0");
    void *b = malloc_name(1000, "Test Allocation: 1");
    void *c = malloc_name(250, "Test Allocation: 2");
    void *d = malloc_name(250, "Test Allocation: 3");
    void *e = malloc_name(500, "Test Allocation: 4");

    free(b);
    free(d);

    void *f = malloc_name(600, "Test Allocation: 5");
    void *g = malloc_name(150, "Test Allocation: 6");
    void *h = malloc_name(50, "Test Allocation: 7");

    unsigned long vm_end = vmsize();

    printf("Pages at start = %lu; pages after allocations = %lu\n",
            vm_start, vm_end);
    if (vm_end - vm_start > 1) {
        printf("Allocated too many pages!\n");
        return 1;
    }

    return 0;
}

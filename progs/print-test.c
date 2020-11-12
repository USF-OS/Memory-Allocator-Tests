#include <stdlib.h>
#include "vmsize.h"
#include "../../allocator.c"

int main(void)
{
    void *a = malloc(120);
    void *b = malloc(345);
    void *c = malloc(15);
    void *d = malloc(3);
    void *f = malloc(10999);
    void *e = malloc(894);

    print_memory();

    return 0;
}

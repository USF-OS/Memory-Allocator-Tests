#include <stdio.h>
#include <stdlib.h>

int main(void)
{
    setenv("ALLOCATOR_SCRIBBLE", "1", 1);

    puts("Printing uninitialized variables:");
    int *x = malloc(sizeof(int));
    printf("%d\n", *x);
    *x = 42;
    free(x);
    int *y = malloc(sizeof(int));
    printf("%d\n", *y);

    int *i = malloc(sizeof(int));
    unsigned long *ul = malloc(sizeof(unsigned long));
    unsigned char *arr = malloc(sizeof(unsigned char) * 5000);

    printf("%d\n", *i);
    printf("%lu\n", *ul);
    printf("%x\n", *i);
    printf("%lx\n", *ul);

    puts("Totalling up uninitialized arrays:");
    int l;
    unsigned long total = 0;
    for (l = 0; l < 5000; ++l) {
        total += arr[l];
    }
    printf("%lu\n", total);

// Disabled: technically, realloc could scribble over the *new* data portion and
// leave the old data untouched, but this wasn't a project requirement so we
// won't test for it here.
//    arr = realloc(arr, sizeof(unsigned char) * 10000);
//    total = 0;
//    for (l = 0; l < 10000; ++l) {
//        total += arr[l];
//    }
//    printf("%lu\n", total);

    puts("calloc should still zero out the memory:");
    int *cleared = calloc(sizeof(int), 450);
    total = 0;
    for (l = 0; l < 450; ++l) {
        total += cleared[l];
    }
    printf("%lu\n", total);

    return 0;
}

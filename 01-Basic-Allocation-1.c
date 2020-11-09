#if 0
    source "${TEST_DIR}/lib/crunner" -lallocator
#endif

#include <fcntl.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <unistd.h>

#define ALLOC_SZ 1048576

unsigned long djb32(unsigned char *str)
{
    unsigned long hash = 5381;
    int c;

    while ((c = *str++)) {
        hash = ((hash << 5) + hash) + c; /* hash * 33 + c */
    }

    return hash;
}

test_start("Makes sure basic malloc() functionality works");

subtest("'Hello World' String",
{
    char *str = "Hello World!";
    char *allocation = malloc(1024);
    strcpy(allocation, str);
    test_assert_str(str, "==", allocation, 1024);
});


subtest("1 MB allocation filled with random values. Hash should be equal after two passes.",
{
    unsigned char *allocation = malloc(ALLOC_SZ);

    unsigned long hash = 5381;
    int c;

    for (int i = 0; i < ALLOC_SZ - 1; ++i) {
        c = rand() % 255 + 1;
        allocation[i] = c;
        hash = ((hash << 5) + hash) + c;
    }
    allocation[ALLOC_SZ - 1] = 0;

    printf("\n\nIncremental (online) Hash: %lu\n", hash);
    unsigned long alloc_hash = djb32(allocation);
    printf("Hash in allocated block: %lu\n", alloc_hash);

    test_assert(hash == alloc_hash);
});

test_end

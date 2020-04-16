
CFLAGS += -Wall -g -pthread -Wno-unused-variable

all_progs = allocations-1 allocations-2 allocations-3 print-test scribble thread-safety

all: $(all_progs)

allocations-1: allocations-1.c ../../allocator.c
	$(CC) $(CFLAGS) $(LDFLAGS) allocations-1.c -o allocations-1
allocations-2: allocations-2.c ../../allocator.c
	$(CC) $(CFLAGS) $(LDFLAGS) allocations-2.c -o allocations-2
allocations-3: allocations-3.c ../../allocator.c
	$(CC) $(CFLAGS) $(LDFLAGS) allocations-3.c -o allocations-3

print-test: print-test.c
scribble: scribble.c
thread-safety: thread-safety.c

clean:
	rm -f $(all_progs)


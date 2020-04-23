source "${TEST_DIR}/lib/funcs.bash"

test_start "Unix Utilities" \
    "Runs 'df', 'w', and 'ps' with custom memory allocator"

# Check to make sure the library exists
[[ -e "./allocator.so" ]] || test_end 1

LD_PRELOAD=./allocator.so   df      || test_end
LD_PRELOAD=./allocator.so   w       || test_end
LD_PRELOAD=./allocator.so   ps aux  || test_end

test_end

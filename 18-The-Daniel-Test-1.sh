source "${TEST_DIR}/lib/funcs.bash"

test_start "I'm proud of you, class" \
    "-- Daniel Barajas"

# Check to make sure the library exists
[[ -e "./allocator.so" ]] || test_end 1

expected_count=$(find /usr 2> /dev/null | wc -l)

actual_count=$(LD_PRELOAD=./allocator.so find /usr | wc -l)

echo "Counts: expected=${expected_count}; actual=${actual_count}"

if [[ "${expected_count}" -ne "${actual_count}" ]]; then
    # Incorrect number of files found
    test_end 1
fi

test_end 0

source "${TEST_DIR}/lib/funcs.bash"

expected_order=$(cat <<EOM
Test Allocation: 0
Test Allocation: 1
Test Allocation: 2
Test Allocation: 3
Test Allocation: 4
Test Allocation: 5
Test Allocation: 6
EOM
)

test_start "Basic Worst Fit"

output=$( \
    ALLOCATOR_ALGORITHM=worst_fit \
    tests/progs/allocations-1 2> /dev/null)

echo "${output}"

# Get the block ordering from the output. We ignore unnamed allocations.
block_order=$(grep 'Test Allocation:' <<< "${output}" \
    | sed "s/.*'Test Allocation: \([0-9]*\)'.*/Test Allocation: \1/g")

compare <(echo "${expected_order}") <(echo "${block_order}") || test_end

test_end

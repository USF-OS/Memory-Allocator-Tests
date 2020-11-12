source "${TEST_DIR}/lib/funcs.bash"

expected_order=$(cat <<EOM
Test Allocation: 0
Test Allocation: 5
Test Allocation: 6
Test Allocation: 7
Test Allocation: 2
Test Allocation: 3
Test Allocation: 4
EOM
)

algo="best_fit"

test_start "Testing ${algo}"

# Check to make sure there were no extra pages
ALLOCATOR_ALGORITHM=${algo} \
tests/progs/allocations-2 2> /dev/null || test_end

output=$( \
    ALLOCATOR_ALGORITHM=${algo} \
    tests/progs/allocations-3)

echo "${output}"

# Get the block ordering from the output. We ignore unnamed allocations.
block_order=$(grep 'Test Allocation:' <<< "${output}" \
    | sed "s/.*'Test Allocation: \([0-9]*\)'.*/Test Allocation: \1/g")

compare <(echo "${expected_order}") <(echo "${block_order}") || test_end

test_end

#!/bin/bash

# Configuration
TEST_CASES=1

# Replacement for e_header
echo "=============================="
echo "        Test Cases"
echo "=============================="

for (( i=0; i<TEST_CASES; i++ )); do
    rm -f "input.txt"
    
    # Ensure input file exists before copying
    if [[ -f "input_${i}.in" ]]; then
        cp "input_${i}.in" "input.txt"
    else
        echo "Error: input_${i}.in not found."
        exit 1
    fi

    java gtest < input.txt > "answer_${i}.ans"

    # Standard diff check (replaces colordiff and diff-so-fancy)
    # -w ignores whitespace, -u provides a readable "unified" format
    if diff -w "answer_${i}.ans" "out_${i}.out" > /dev/null; then
        # Replacement for e_success
        printf "\e[32m✔ Passed %d\e[0m\n" "$((i+1))"
    else
        # Show the difference to the user before failing
        echo "Differences found in test case $((i+1)):"
        diff -w -u "answer_${i}.ans" "out_${i}.out"
        
        # Replacement for e_error
        printf "\e[31m✘ Failed %d\e[0m\n" "$((i+1))"
        exit 1
    fi
done

printf "\e[32m\nCongratulations, ACCEPTED\e[0m\n"

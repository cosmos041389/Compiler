#!/bin/bash

dir_a="output"
dir_b="solutions"

for file_a in "$dir_a"/*; do
    filename=$(basename "$file_a" .out)  # extract file name without extension
    file_b="$dir_b/s_${filename}.txt"    # construct file name for dir_b

    if [[ -f "$file_b" ]]; then          # check if file_b exists
        diff_output=$(diff -b --strip-trailing-cr "$file_a" "$file_b")   # compare file_a and file_b
        if [[ $? -eq 0 ]]; then          # check if files are the same
            echo "$filename: same"       # print result to console
        else
            echo "$filename: different"
            diff "$file_a" "$file_b" > "compare/${filename}.diff"  # save diff to file
        fi
    else
        echo "$filename: file not found in $dir_b"
    fi
done

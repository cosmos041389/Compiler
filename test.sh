#!/bin/bash

dir_out=output

for file in testcases/*.txt; do
	filename=$(basename "${file}" .txt)
	echo $filename
	./MiniC "$file" > "output/${filename}.out"
done

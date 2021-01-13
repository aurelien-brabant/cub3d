#! /bin/bash

# ------ CONFIG ------ #

# The path to the cub3D binary, generated by the Makefile.
CUB3D_BIN_PATH=../cub3D;

# The path where the test files are found. Provided maps are in the ./test-files directory.
TEST_FILES_DIR=./test-files;

# true: only the files listed in the below array will be used.
# false: all the files in TEST_FILES_DIR will be tested.
TEST_ONLY_LISTED="false"

listedFiles=(
)

# ------ COUNTER ------ #

passed=0
failed=0
tested=0
currFile=""

function markPassed() {
	passed=$(($passed+1))
	tested=$(($tested+1))
	printf "%-30s -> \033[0;32mPASS\033[0m ($2)\n" "$(basename $1)"
}

function markFailed() {
	failed=$(($failed+1));
	tested=$(($tested+1))
	printf "%-30s -> \033[0;31mFAIL\033[0m ($2)\n" "$(basename $1)"
}

# $1 is the path to the file
function setCurrFile() {
	currFile="${TEST_FILES_DIR}/$1"
}

# ------ SCRIPT ------ 

if [ TEST_ONLY_LISTED == "true" ]; then
	files=$listedFiles
else
	files=()
	for file in $TEST_FILES_DIR/*; do
		files+=($file)
	done
fi

for file in ${files[@]}; do
	$CUB3D_BIN_PATH $file 2> /tmp/error
	
	expect_error=$?
	out=$(</tmp/error)
	echo "$out" | grep -i "error" > /dev/null
	ret=$?
	out=$(echo "$out" | sed -n 3p)
	if [ $ret -eq 0 ]; then
		if echo $file | grep -i "error" > /dev/null; then 
			markPassed $file "$out"
		else
			markFailed $file "$out"
		fi
	else
		if echo $file | grep -i "error" > /dev/null; then 
			markFailed $file "$out"
		else
			markPassed $file "$out"
		fi
	fi
done

printf "\n\033[0;36mTOTAL\033[0m: $passed / $tested handled correctly.\n"
#!/usr/bin/env bash
IFS=$'\n'

TESTING_DIR=t
UTIL_F=util.bash

declare -a SKIP_FILES=(
	"test_util.h"
)

not_test_file () {
	local test=$1

	for (( i=0; i < ${#SKIP_FILES[@]}; i++ )); do
		if [[ $test == ${SKIP_FILES[i]} ]]; then
			return 1
		else
			return 0
		fi
	done
}

run_test () {
	local file_name="$1"

	make unix
	gcc -I ./src/ -c "$TESTING_DIR/$file_name" -o main.o
	gcc -o main main.o -L./ -lin

	export LD_LIBRARY_PATH=$HOME/repositories/lib.in/src/:$LD_LIBRARY_PATH
	green "\n[+] Running test...\n\n"

	./main
}

main () {
	echo $(ls $TESTING_DIR | filter not_test_file) | for_each run_test
}

. "$(dirname "$(readlink -f "$BASH_SOURCE")")"/$UTIL_F
main $*

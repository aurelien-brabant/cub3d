#! /bin/bash

# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    tester.sh                                          :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: abrabant <abrabant@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/02/05 15:19:01 by abrabant          #+#    #+#              #
#    Updated: 2021/02/05 15:19:01 by abrabant         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# A tester provided to ensure cub3d's parsing is working as expected.

###############################################################################
#                               VARS                                          #
###############################################################################

TEST_MAP_DIR_BONUS=asset/map/bonus
TEST_MAP_DIR_MANDATORY=asset/map/mandatory

EXEC_MANDATORY=./cub3D
EXEC_BONUS=./cub3D_bonus

test_nb=1

###############################################################################
#                              FUNCTIONS                                      #
###############################################################################

function submit() {
	$1 &> test/$test_nb.test
	cat test/$test_nb.test | grep -i "ko" > /dev/null
	if [ $? -eq 0 ]; then
		if [ $2 == "EXPECT_KO" ]; then
			printf "TEST $test_nb\t[\033[1;32mOK\033[0m] ($2) (\033[0;35mCMD\033: \033[0m$1) \n"
		else
			printf "TEST $test_nb\t[\033[1;31mKO\033[0m] ($2) (\033[0;35mCMD\033: \033[0m$1) \n"
		fi
	else
		if [ $2 == "EXPECT_OK" ]; then
			printf "TEST $test_nb\t[\033[1;32mOK\033[0m] ($2) (\033[0;35mCMD\033: \033[0m$1) \n"
		else
			printf "TEST $test_nb\t[\033[1;31mKO\033[0m] ($2) (\033[0;35mCMD\033: \033[0m$1) \n"
		fi
	fi
	test_nb=$(($test_nb+1))
}

###############################################################################
#                                 SETUP                                       #
###############################################################################

mkdir -p test 2> /dev/null

# No argument, no bonus
if [ $# -eq 0 ]; then
	EXEC=$EXEC_MANDATORY
	TEST_MAP_DIR=$TEST_MAP_DIR_MANDATORY
elif [ $# -eq 1 ] && [ $1 == "bonus" ]; then
	EXEC=$EXEC_BONUS
	TEST_MAP_DIR=$TEST_MAP_DIR_BONUS
else
	printf "Unrecognized format, aborting.\n"
	exit 1
fi

if [ ! -f $EXEC ]; then
	printf "No $EXEC executable found. Make the project first.\n"
	exit 1
fi

###############################################################################
#                               TEST                                          #
###############################################################################

submit "$EXEC --parse-only" "EXPECT_KO"
submit "$EXEC --parse-only asset/map/ERROR_no_extension" "EXPECT_KO"
submit "$EXEC --parse-only asset/map/VALID_3.cub --forbiddenToken" "EXPECT_KO"
submit "$EXEC --parse-only asset/map/VALID_3.cub too much positional arguments" "EXPECT_KO"
submit "$EXEC --parse-only this/path/does/not/exist" "EXPECT_KO"
submit "$EXEC --parse-only test" "EXPECT_KO"

for file in $TEST_MAP_DIR/*; do
	if echo $file | grep -i "error" > /dev/null; then
		submit "$EXEC --parse-only $file" "EXPECT_KO"
	else
		submit "$EXEC --parse-only $file" "EXPECT_OK"
	fi
done

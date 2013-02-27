###############################################################
# Justify & String
#
# CS 23001 Kent State University
# Make file for Project 2
#
# This makefile will work for all parts of the project.
# However, you will need to modify the "tests" rules as
# you add new test cases.
# 1) add test case to "Variables" section
# 2) add test to "Run all tests" section
# 3) add test to "clean"
#

###############################################################
# Variables
CPP     = g++
OPTIONS = -g -Wall -W -Wunused -Wuninitialized -Wshadow

CONSTRUCTORS = test_default_ctor.out test_cstring_ctor.out test_copy_constructor.out
OPERATORS = test_relational_operators.out test_add.out test_subtract.out test_division.out test_multiply.out
SEARCH =  test_findstring.out test_findchar.out test_substr.out test_strip_nl.out
IO =  test_output.out test_input.out
###############################################################
# The first rule is run if only make is typed
msg:
	@echo 'Targets are:'
	@echo '  string'
	@echo '  tests'
	@echo '  justify'
	@echo '  clean'

###############################################################
# Run all tests
#
# You will need to add your other below:
# For example: ./test_plus
#
string: $(CONSTRUCTORS) $(OPERATORS) $(SEARCH) $(IO)
	./test_default_ctor.out
	./test_cstring_ctor.out
	./test_relational_operators.out
	./test_add.out
	./test_subtract.out
	./test_multiply.out
	./test_division.out
	./test_findchar.out
	./test_findstring.out
	./test_substr.out
	./test_output.out
	./test_input.out
	make clean

tests:
	make string

###############################################################
# Compile string
#
string.o: string.h string.cpp
	$(CPP) -c $(OPTIONS) string.cpp

###############################################################
# Compile Justify
#
justify: string.h string.cpp justify.cpp
	$(CPP) $(OPTIONS) -o justify.out justify.o string.o

justify.o: justify.cpp string.h
	$(CPP) -c $(OPTIONS) justify.cpp


###############################################################
# Compile all test programs
#
test_%: string.o test_%.o
	$(CPP) string.o test_$*.o -o test_$*

test_%.o: string.h test_%.cpp
	$(CPP) $(OPTIONS) -c test_$*.cpp

###############################################################
# clean
# Removes all .o files and all executables
#
# You will need to add your other test cases executables here.
# For example: test_plus
clean:
	rm -f *.o
	rm -f *.out



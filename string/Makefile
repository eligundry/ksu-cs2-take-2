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
VALGRIND = valgrind -q

CONSTRUCTORS = test_default_ctor.out test_cstring_ctor.out test_copy_constructor.out
OPERATORS = test_relational_operators.out test_add.out
SEARCH =  test_findstring.out test_findchar.out test_substr.out test_strip_nl.out
IO =  test_output.out test_input.out
DYNAMIC = test_swap.out test_force_overflow.out test_reallocate.out
FUN = test_subtract.out test_division.out test_multiply.out test_zip.out test_reverse.out test_split.out
JUST = test_next_blank.out test_replace_char.out test_justify.out
###############################################################
# The first rule is run if only make is typed
msg:
	@echo 'Targets are:'
	@echo '  string'
	@echo '  tests'
	@echo '  valgrind'
	@echo '  justify'
	@echo '  clean'

###############################################################
# Run all tests

string: $(CONSTRUCTORS) $(OPERATORS) $(SEARCH) $(IO) $(DYNAMIC) $(FUN) $(JUST)
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
	./test_swap.out
	./test_reallocate.out
	./test_force_overflow.out
	./test_zip.out
	./test_reverse.out
	./test_next_blank.out
	./test_replace_char.out
	./test_split.out
	./test_justify.out
	make clean

tests:
	make string

valgrind: $(CONSTRUCTORS) $(OPERATORS) $(SEARCH) $(IO) $(DYNAMIC) $(FUN) $(JUST)
	$(VALGRIND) ./test_default_ctor.out
	$(VALGRIND) ./test_cstring_ctor.out
	$(VALGRIND) ./test_relational_operators.out
	$(VALGRIND) ./test_add.out
	$(VALGRIND) ./test_subtract.out
	$(VALGRIND) ./test_multiply.out
	$(VALGRIND) ./test_division.out
	$(VALGRIND) ./test_findchar.out
	$(VALGRIND) ./test_findstring.out
	$(VALGRIND) ./test_substr.out
	$(VALGRIND) ./test_output.out
	$(VALGRIND) ./test_input.out
	$(VALGRIND) ./test_swap.out
	$(VALGRIND) ./test_reallocate.out
	$(VALGRIND) ./test_force_overflow.out
	$(VALGRIND) ./test_zip.out
	$(VALGRIND) ./test_reverse.out
	$(VALGRIND) ./test_next_blank.out
	$(VALGRIND) ./test_replace_char.out
	$(VALGRIND) ./test_split.out
	$(VALGRIND) ./test_justify.out
	make clean

###############################################################
# Compile string
#
string.o: string.h string.cpp
	$(CPP) -c $(OPTIONS) string.cpp

###############################################################
# Compile Justify
#
justify:
	make string.o
	make justify.o
	make compile_justify
	./justify.out 10 50 data2-1.txt
	# make clean

compile_justify: string.h string.cpp justify.cpp
	$(CPP) $(OPTIONS) -o justify.out justify.o string.o

justify.o: justify.cpp string.h
	$(CPP) -c $(OPTIONS) justify.cpp


###############################################################
# Compile all test programs
#
test_%.out: string.o test_%.o
	$(CPP) string.o test_$*.o -o test_$*.out

test_%.o: string.h test_%.cpp
	$(CPP) $(OPTIONS) -c test_$*.cpp

###############################################################
# clean
# Removes all .o files and all executables
#
# You will need to add your other test cases executables here.
# For example: test_plus
clean:
	rm -f *.o *.out



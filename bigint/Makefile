###############################################################
# bigint
#
# CS 23001 Kent State University
# Make file for project 1
#
# This makefile will work for all three parts of the project.
# However, you will need to modify the "tests" rule for each part.
# 1) Add the tests to the rule
# 2) Remove the # for each test as needed so it is executed
#

###############################################################
# Variables
GCC  = g++
OPTS = -Wall -g

###############################################################
# The first rule is run if only make is typed
msg:
	@echo 'Targets are:'
	@echo '  tests:'
	@echo '  add:'
	@echo '  multiply:'
	@echo '  factorial:'
	@echo '  clean:'

###############################################################
# Build and run all tests and output demonstration
#
# For part 2 add: test_add test_subscript
# For part 3 add: test_times_10 test_times_single_digit test_multiply
tests: test_default_ctor test_int_ctor test_c_str_ctor test_add test_subscript test_times_10 test_times_single_digit test_multiply
	./test_default_ctor
	./test_int_ctor
	./test_c_str_ctor
#Part 2
	./test_add
	./test_subscript
#Part 3
	./test_times_10
	./test_times_single_digit
	./test_multiply

###############################################################
# Build and run part 2
add: part2
	./add

###############################################################
# Build and run part 3
multiply: part3
	./multiply

###############################################################
# Build and run factorial
factorial: part4
	./factorial


#==============================================================
# bigint type
bigint.o: bigint.h bigint.cpp
	$(GCC) $(OPTS) -c bigint.cpp

#==============================================================
# Test default ctor
test_default_ctor: test_default_ctor.o bigint.o
	$(GCC) $(OPTS) -o test_default_ctor test_default_ctor.o bigint.o

test_default_ctor.o: bigint.h test_default_ctor.cpp
	$(GCC) $(OPTS) -c test_default_ctor.cpp

#==============================================================
# Test int ctor
test_int_ctor: test_int_ctor.o bigint.o
	$(GCC) $(OPTS) -o test_int_ctor test_int_ctor.o bigint.o

test_int_ctor.o: bigint.h test_int_ctor.cpp
	$(GCC) $(OPTS) -c test_int_ctor.cpp

#==============================================================
# Test C-string ctor
test_c_str_ctor: test_c_str_ctor.o bigint.o
	$(GCC) $(OPTS) -o test_c_str_ctor test_c_str_ctor.o bigint.o

test_c_str_ctor.o: bigint.h test_c_str_ctor.cpp
	$(GCC) $(OPTS) -c test_c_str_ctor.cpp

#==============================================================
# Test C-string ctor
test_add: test_add.o bigint.o
	$(GCC) $(OPTS) -o test_add test_add.o bigint.o

test_add.o: bigint.h test_add.cpp
	$(GCC) $(OPTS) -c test_add.cpp

#==============================================================
# Test C-string ctor
test_subscript: test_subscript.o bigint.o
	$(GCC) $(OPTS) -o test_subscript test_subscript.o bigint.o

test_subscript.o: bigint.h test_subscript.cpp
	$(GCC) $(OPTS) -c test_subscript.cpp

#==============================================================
# Test C-string ctor
test_times_10: test_times_10.o bigint.o
	$(GCC) $(OPTS) -o test_times_10 test_times_10.o bigint.o

test_times_10.o: bigint.h test_times_10.cpp
	$(GCC) $(OPTS) -c test_times_10.cpp

#==============================================================
# Test C-string ctor
test_times_single_digit: test_times_single_digit.o bigint.o
	$(GCC) $(OPTS) -o test_times_single_digit test_times_single_digit.o bigint.o

test_times_single_digit.o: bigint.h test_times_single_digit.cpp
	$(GCC) $(OPTS) -c test_times_single_digit.cpp

#==============================================================
# Test C-string ctor
test_multiply: test_multiply.o bigint.o
	$(GCC) $(OPTS) -o test_multiply test_multiply.o bigint.o

test_multiply.o: bigint.h test_multiply.cpp
	$(GCC) $(OPTS) -c test_multiply.cpp

#==============================================================
# For Part 2
part2: add.o bigint.o
	$(GCC) $(OPTS) -o add add.o bigint.o

add.o: bigint.h add.cpp
	$(GCC) $(OPTS) -c add.cpp

#==============================================================
# For Part 3
part3: multiply.o bigint.o
	$(GCC) $(OPTS) -o multiply multiply.o bigint.o

multiply.o: bigint.h multiply.cpp
	$(GCC) $(OPTS) -c multiply.cpp

#==============================================================
# For Part 3
part4: factorial bigint.o
	$(GCC) $(OPTS) -o factorial factorial.o bigint.o

factorial.o: bigint.h factorial.cpp
	$(GCC) $(OPTS) -c factorial.cpp


###############################################################
clean:
	rm -f *.o
	rm -f test_default_ctor test_int_ctor test_c_str_ctor
	rm -f test_add test_subscript
	rm -f test_times_10 test_times_single_digit test_multiply
	rm -f multiply add


#============================================================================
#  stack class makefile
#===========================================================================

CPP          = g++
CPP_FLAGS    = -g -Wall -W -Wunused -Wuninitialized -Wshadow
INCLUDE_OPT  = -iquote . -iquote ../string
VALGRIND = valgrind -q
TEST_1 = test_stack_int.out test_stack_string.out test_queue_int.out test_queue_string.out
TEST_2 = test_output.out
TEST_3 =

#-------------------------------------------------------------------------------
STRING_DIR = ../string/

#===========================================================================
msg:
	@echo 'Targets for compiling test programs:'
	@echo '   tests'
	@echo '   clean'
	@echo '   postfix'
	@echo '   assembler'

#===========================================================================
# Compile string.o from Project 2.

string.o: ${STRING_DIR}string.h ${STRING_DIR}string.cpp
	${CPP} ${CPP_FLAGS} ${INCLUDE_OPT} -c ${STRING_DIR}string.cpp

#===========================================================================
# Compile stack.o

# stack.o: stack.h  stack.cpp
# 	${CPP} ${CPP_FLAGS}  -c stack.cpp

#===========================================================================
# Compile test programs
#----------------------------------------------------------------------------
test_%.out: string.o test_%.o
	${CPP} ${CPP_FLAGS} string.o test_$*.o -o test_$*.out

test_%.o: ${STRING_DIR}string.h stack.h test_%.cpp
	${CPP} ${CPP_FLAGS} ${INCLUDE_OPT} -c test_$*.cpp


#===========================================================================
# Compile postfix

postfix: clean string.o postfix.o
	${CPP} ${CPP_FLAGS} string.o postfix.o -o postfix.out
	${VALGRIND} ./postfix.out data3-0.txt data3-0-postfix.txt
	${VALGRIND} ./postfix.out data3-1.txt data3-1-postfix.txt
	${VALGRIND} ./postfix.out data3-2-1.txt data3-2-1-postfix.txt

postfix.o: stack.h postfix.cpp
	${CPP} ${CPP_FLAGS} ${INCLUDE_OPT} -c postfix.cpp

#===========================================================================
# Compile assembler

assembler: clean string.o postfix.o assembler.o postfix
	${CPP} ${CPP_FLAGS} string.o assembler.o -o assembler.out
	${VALGRIND} ./assembler.out data3-0-postfix.txt data3-0-assembler.txt
	${VALGRIND} ./assembler.out data3-1-postfix.txt data3-1-assembler.txt
	${VALGRIND} ./assembler.out data3-2-1-postfix.txt data3-2-1-assembler.txt

assembler.o: stack.h postfix.cpp
	${CPP} ${CPP_FLAGS} ${INCLUDE_OPT} -c assembler.cpp


#===========================================================================
# Run test programs

tests: ${TEST_1} ${TEST_2} ${TEST_3}
	${VALGRIND} ./test_stack_int.out
	${VALGRIND} ./test_stack_string.out
	${VALGRIND} ./test_queue_int.out
	${VALGRIND} ./test_queue_string.out
	${VALGRIND} ./test_output.out
	make clean

#============================================================================
clean:
	rm -f *.o *.out
	rm -f *-postfix.txt *-assembler.txt

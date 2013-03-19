#============================================================================
#  stack class makefile
#===========================================================================

CPP          = g++
CPP_FLAGS    = -g -Wall -W -Wunused -Wuninitialized -Wshadow
INCLUDE_OPT  = -iquote . -iquote ../string
TEST_1 = test_stack_int.out
TEST_2 =
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

postfix.o: postfix.cpp string.h stack.h
	${CPP} ${CPP_FLAGS} -c postfix.cpp


postfix: stack.o string.o
	${CPP} ${CPP_FLAGS} postfix.o string.o stack.o -o postfix

#===========================================================================
# Compile assembler

assembler.o: assembler.cpp string.h stack.h
	${CPP} ${CPP_FLAGS} -c assembler.cpp

assembler: stack.o string.o
	${CPP} ${CPP_FLAGS} string.o stack.o -o postfix


#===========================================================================
# Run test programs

tests: ${TEST_1} ${TEST_2} ${TEST_3}
	./test_stack_int.out


#============================================================================
clean:
	rm -f *.o *.out

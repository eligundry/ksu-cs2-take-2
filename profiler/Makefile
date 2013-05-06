# Make file for Profiler

###############################################################
# Variables
CPP      = g++
#CPP_OPTS = -g -Wall
CPP_OPTS = -g -Wall -W -Wunused -Wuninitialized -Wshadow

# Test files
TESTS = test_destructor.out test_copy.out test_assignment.out test_swap.out

# Valgrind Command
VALGRIND = valgrind -q

###############################################################
# The first rule is run of only make is typed
msg:
	@echo 'Targets are:'
	@echo '  profiler:'
	@echo '  sort:'
	@echo '  p-sort:'
	@echo '  gprof:'
	@echo '  tests:'
	@echo '  clean:'

###############################################################
profiler : clean main.o ASTree.o
	$(CPP) $(CPP_OPTS) -o profiler main.o ASTree.o
	$(VALGRIND) ./profiler simple.cpp.xml
	$(VALGRIND) ./profiler sort.cpp.xml

main.o : main.cpp ASTree.hpp
	$(CPP) $(CPP_OPTS) -c main.cpp

ASTree.o   : ASTree.hpp ASTree.cpp
	$(CPP) $(CPP_OPTS) -c ASTree.cpp

#==============================================================
# sort
sort : sort.o sort_lib.o
	$(CPP) $(CPP_OPTS) -o sort sort.o sort_lib.o

sort.o: sort_lib.h sort.cpp
	$(CPP) $(CPP_OPTS) -c sort.cpp

sort_lib.o: sort_lib.h sort_lib.cpp
	$(CPP) $(CPP_OPTS) -c sort_lib.cpp

#==============================================================
# p-sort
# p-sort.cpp
# p-sort_lib.cpp

p-sort : profile.o p-sort.o p-sort_lib.o
	$(CPP) $(CPP_OPTS) -o p-sort profile.o p-sort.o p-sort_lib.o

p-sort.o: profile.hpp sort_lib.h p-sort.cpp
	$(CPP) $(CPP_OPTS) -c p-sort.cpp.xml.cpp

p-sort_lib.o: profile.hpp sort_lib.h p-sort_lib.cpp
	$(CPP) $(CPP_OPTS) -c p-sort_lib.cpp

profile.o: profile.hpp profile.cpp
	$(CPP) $(CPP_OPTS) -c profile.cpp

#==============================================================
# Profiling version of sort
gprof: CPP_OPTS   = -g -Wall -pg
gprof: clean sort
	@echo -n ''

#==============================================================
# Run tests

test_%.out: ASTree.o test_%.o
	$(CPP) $(CPP_OPTS) test_$*.o -o test_$*.out

test_%.o: test_%.cpp
	$(CPP) $(CPP_OPTS) -c test_$*.cpp

tests: $(TESTS)
	$(VALGRIND) ./test_destructor.out
	$(VALGRIND) ./test_copy.out
	$(VALGRIND) ./test_assignment.out
	$(VALGRIND) ./test_swap.out


###############################################################
#This will clean up everything via "make clean"
clean:
	rm -f profiler
	rm -f sort
	rm -f *.o *.out
	rm -f p-*


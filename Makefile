CXX := g++
CXXFLAGS := -g -Wall --std=c++11

OBJS=llrec.o llrec-test.o

all: llrec-test

#-----------------------------------------------------
# ADD target(s) to build your llrec-test executable
#-----------------------------------------------------

llrec-test: $(OBJS)
	$(CXX) $(CXXFLAGS) $(VALGRIND) -o $@ $(OBJS) 

llrec.o: llrec.cpp llrec.h
	$(CXX) $(CXXFLAGS) $(VALGRIND) -o $@ -c llrec.cpp

llrec-test.o: llrec-test.cpp llrec.h
	$(CXX) $(CXXFLAGS) $(VALGRIND) -o $@ -c llrec-test.cpp

valgrind:
	valgrind --tool=memcheck --leak-check=yes ./llrec-test
clean:
	rm -f *.o rh llrec-test *~

.PHONY: clean 
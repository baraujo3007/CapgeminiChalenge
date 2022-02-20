CC := g++
INCLUDES= -I./
CXXFLAGS = -Wall
SRCM= main.cpp \
	  func.cpp
OBJM = $(SRCM:.cpp=.o)
LINKFLAGS= -lcppunit

all: verifyPassword testRunner

verifyPassword: main.cpp func.cpp
	    g++ -o verifyPassword main.cpp func.cpp -Wall

testRunner: unitTest.cpp func.cpp
	    g++ -o testRunner unitTest.cpp func.cpp $(LINKFLAGS) $(LINKFLAGSLOG4) $(LIBLOG)


.cpp.o:
	    $(CXX) $(CXXFLAGS) -c $< -o $@

clean: verifyPassword testRunner
	rm -rf $^ *.o
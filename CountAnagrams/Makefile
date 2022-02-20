CC := g++
INCLUDES= -I./
CXXFLAGS = -Wall
LINKFLAGS= -lcppunit

all: countAnagrams testRunner

countAnagrams: main.cpp
	    $(CC) -o countAnagrams main.cpp $(CXXFLAGS)

testRunner: unitTest.cpp
	    $(CC) -o testRunner unitTest.cpp $(LINKFLAGS) $(LINKFLAGSLOG4) $(LIBLOG)


.cpp.o:
	    $(CXX) $(CXXFLAGS) -c $< -o $@

clean: 
	rm -rf countAnagrams testRunner *.o
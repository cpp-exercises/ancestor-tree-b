#!make -f

CXX=clang++-9 
CXXFLAGS=-std=c++2a

HEADERS=FamilyTree.hpp
OBJECTS=FamilyTree.o

run: test
	./$^

test: TestRunner.o Test_hila_shoshan.o Test_tom_latin.o $(OBJECTS)
	$(CXX) $(CXXFLAGS) $^ -o test

%.o: %.cpp $(HEADERS)
	$(CXX) $(CXXFLAGS) --compile $< -o $@

clean:
	rm -f *.o test

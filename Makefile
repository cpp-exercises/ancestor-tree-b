#!make -f

CXX=clang++-9 
CXXFLAGS=-std=c++2a

HEADERS=FamilyTree.hpp
OBJECTS=FamilyTree.o

run: test
	./$^

test: TestRunner.o Test_iris_Rav.o Test_shahar_glikman.o $(OBJECTS)
	$(CXX) $(CXXFLAGS) $^ -o test

%.o: %.cpp $(HEADERS)
	$(CXX) $(CXXFLAGS) --compile $< -o $@

clean:
	rm -f *.o test

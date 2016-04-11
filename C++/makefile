# The executable file name.
PROGRAM = C++

# The pre-processor and compiler.
CXX = g++

# The pre-processor and compiler option.
CXXFLAGS = -g -Wall

# Useful variables
COMPILE = $(CXX) $(CXXFLAGS) -c
LINK = $(CXX) $(CXXFLAGS)

CPPDIR = $(dir $(wildcard $(addprefix src/*/*, .cpp)))
OBJS = main.o Set.o Inheritance.o Matrices.o BooleanMatrix.o 

VPATH = src:$(strip $(addsuffix :,$(CPPDIR)))

test:
	@echo $(CPPDIR)

all: $(PROGRAM)

$(PROGRAM): $(OBJS)
	$(LINK) $(addprefix bin/, $(OBJS)) -o $@

main.o: main.cpp header.h
	$(COMPILE) src/main.cpp -o bin/$@

Set.o: Set.cpp Set.hpp
	$(COMPILE) src/Set/Set.cpp -o bin/$@

Inheritance.o: Inheritance.cpp Inheritance.hpp
	$(COMPILE) src/Inheritance/Inheritance.cpp -o bin/$@

Matrices.o: Matrices.cpp Matrices.hpp
	$(COMPILE) src/Matrices/Matrices.cpp -o bin/$@

BooleanMatrix.o: BooleanMatrix.cpp BooleanMatrix.hpp
	$(COMPILE) src/BooleanMatrix/BooleanMatrix.cpp -o bin/$@

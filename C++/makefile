# The executable file name.
PROGRAM = ./C++

# The creating test data executable file name.
TEST = ./test_data

# The random test data file name.
TESTFILE = text.txt

# The pre-processor and compiler.
CXX = g++

# The pre-processor and compiler option.
CXXFLAGS = -g -Wall

# Useful variables
COMPILE = $(CXX) $(CXXFLAGS) -c
LINK = $(CXX) $(CXXFLAGS)

CPPDIR = $(dir $(wildcard $(addprefix src/*/*, .cpp)))
OBJS = main.o \
Set.o \
Inheritance.o \
Matrix.o BooleanMatrix.o \
ProductSet.o Relation.o BinaryRelation.o \
BinaryTree.o BinarySearchTree.o

.PHONY: clean all run test

VPATH = src:$(strip $(addsuffix :,$(CPPDIR)))


test: $(TEST) all
	$(PROGRAM) < $(TESTFILE)

run: all
	$(PROGRAM)


all: $(PROGRAM)


$(PROGRAM): $(OBJS)
	$(LINK) $(addprefix bin/, $(OBJS)) -o $@

main.o: main.cpp header.h
	$(COMPILE) src/main.cpp -o bin/$@

Set.o: Set.cpp Set.hpp
	$(COMPILE) src/Set/Set.cpp -o bin/$@

Inheritance.o: Inheritance.cpp Inheritance.hpp
	$(COMPILE) src/Inheritance/Inheritance.cpp -o bin/$@

Matrix.o: Matrix.cpp Matrix.hpp
	$(COMPILE) src/Matrix/Matrix.cpp -o bin/$@

BooleanMatrix.o: BooleanMatrix.cpp BooleanMatrix.hpp
	$(COMPILE) src/Matrix/BooleanMatrix.cpp -o bin/$@

ProductSet.o: ProductSet.cpp ProductSet.hpp
	$(COMPILE) src/ProductSet/ProductSet.cpp -o bin/$@

Relation.o: Relation.cpp Relation.hpp
	$(COMPILE) src/ProductSet/Relation.cpp -o bin/$@

BinaryRelation.o: BinaryRelation.cpp BinaryRelation.hpp
	$(COMPILE) src/ProductSet/BinaryRelation.cpp -o bin/$@

BinaryTree.o: BinaryTree.cpp BinaryTree.hpp
	$(COMPILE) src/Tree/BinaryTree.cpp -o bin/$@

BinarySearchTree.o: BinarySearchTree.cpp BinarySearchTree.hpp
	$(COMPILE) src/Tree/BinarySearchTree.cpp -o bin/$@

$(TEST): test.c
	gcc src/test.c -o $@
	$(TEST) > $(TESTFILE)

clean:
	rm $(PROGRAM) $(TEST) $(TESTFILE) $(addprefix bin/, $(OBJS))

help:  
	@echo 'Created by 李天培 on 16/4/6.'
	@echo 'Copyright © 2016年 lee. All rights reserved.'
	@echo 'email: 1105208297@qq.com'
	@echo ''
	@echo 'Usage: make [TARGET]'
	@echo 'TARGETS:'
	@echo '  test 		(=make) run with input file $(TESTFILE).'
	@echo '  run 		run program.'
	@echo '  all		compile and link.'  
	@echo '  $(PROGRAM)		link.'
	@echo '  clean     	clean objects, the executable file, $(TESTFILE).'
	@echo '  $(TEST)   compile random data file test.c and create random data to $(TESTFILE)'  
	@echo '  *.o   	compile special .cpp file to .o file.' 
	@echo '  help      	print this message.'  
	@echo  	
	@echo 'Report bugs to my email.'

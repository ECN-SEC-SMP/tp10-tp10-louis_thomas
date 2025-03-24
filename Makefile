# A mettre a jour : répertoire d'installation de Google Test
GTEST_DIR = ../googletest/googletest
GTEST_LIB = ../googletest/lib

CPP_FLAGS = -isystem $(GTEST_DIR)/include  -g -Wall -Wextra -pthread -std=c++17

GTEST_HEADERS = $(GTEST_DIR)/include/gtest/*.h \
                $(GTEST_DIR)/include/gtest/internal/*.h

mytest.o: mytest.cpp Calculator.h
	g++ -c $(CPP_FLAGS) mytest.cpp

calculator.o: Calculator.cpp Calculator.h
	g++ -c $(CPP_FLAGS) Calculator.cpp

test: mytest.o Calculator.o
	g++ $(CPP_FLAGS) -o mytest.test mytest.o Calculator.o -lpthread $(GTEST_LIB)/libgtest.a $(GTEST_LIB)/libgtest_main.a

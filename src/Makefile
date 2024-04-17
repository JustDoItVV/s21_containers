# sudo apt install libgtest-dev
CC := g++
STANDARD := -std=c++17
CFLAGS := -Wall -Wextra -Werror $(STANDARD) -pedantic
TEST_FLAGS := $(shell pkg-config gtest --libs)
GCOV_FLAGS := -fprofile-arcs -ftest-coverage
OS := $(shell uname -s)

PROJECT := s21_containers

all : $(PROJECT).a


clean :
	rm -rf *.a *.o

rebuild : clean all


$(PROJECT).a : $(wildcard containers/*.cpp)
	$(CC) $(CFLAGS) -c $+
	ar rc $(PROJECT).a *.o
	ranlib $(PROJECT).a
	rm -rf *.o

format :
	clang-format --style=file:"../materials/linters/.clang-format" -i */*.cpp */*.h

check :
	clang-format --style=file:"../materials/linters/.clang-format" -n */*.cpp */*.h
	cppcheck --enable=all --suppress=missingIncludeSystem -$(STANDARD) --language=c++

valgrind_check :
	valgrind --tool=memcheck --leak-check=full --show-leak-kinds=all -s --track-origins=yes $(PROJECT)_test
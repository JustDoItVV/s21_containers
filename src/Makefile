# на школьном маке не работает g++
CC = g++
GCOV = gcov
FLAGS = -std=c++17
# OPTFLAGS = -pedantic
# для сборки и линковки на школьном маке
LTEST = $(shell pkg-config --cflags gtest) 
LLTEST = $(shell pkg-config --libs gtest) 

#  для компиляции НЕ на школьном маке 
#  g++ containers_tests/s21_containers_test.cpp -o test -lgtest -pthread

GOFLAGS = --coverage
GFLAGS = -fprofile-arcs -ftest-coverage

OS = $(shell uname)
OPENOS = vi
ifeq ($(shell uname -s), Linux)
		OPENOS = xdg-open
endif
ifeq ($(shell uname -s), Darwin)
		OPENOS = open -a "Google Chrome"
endif

.PHONY : all, clean, test,
				leaks style style-fix check valgrind clean rebuild

BUILD_DIR = build
TEST_DIR = containers_tests
BUILD_TEST_DIR = build_tests

S21_SOURCES = $(wildcard s21_*.cpp)
S21_OBJECTS=$(addprefix $(BUILD_DIR)/, $(S21_SOURCES:.cpp=.o))

TESTS = $(wildcard $(TEST_DIR)/*_test.cpp)
TEST_OBJECTS=$(addprefix $(BUILD_TEST_DIR)/, $(notdir $(TESTS:.cpp=.o)))

all: test

###############################################
# COMPILING AND RUNNING TESTS
###############################################

test: test_main
	./test

test_main:  $(TEST_OBJECTS) s21_containers_test.o
	$(CC) $(FLAGS) $(GOFLAGS) $^ -o test $(LLTEST)

$(TEST_OBJECTS) : $(BUILD_TEST_DIR)/%.o : $(TEST_DIR)/%.cpp s21_containers_test.h
	mkdir -p $(BUILD_TEST_DIR)
	$(CC) $(FLAGS) $(OPTFLAGS) -c $< -o $@ $(LTEST)

s21_containers_test.o: s21_containers_test.cpp
	$(CC) $(FLAGS) $(OPTFLAGS) -c s21_containers_test.cpp -o s21_containers_test.o $(LTEST)


###############################################
# CHECKS
###############################################

leaks: test_main
ifeq ($(OS), Linux)
	valgrind --leak-check=full --show-leak-kinds=all --track-origins=yes --verbose ./test
else
	leaks -atExit -- ./test
endif

style: 
	@cp ../materials/linters/.clang-format ./
	@echo =COPY DONE!=
	@clang-format --style=google -n */*.cpp *.h
	@clang-format --style=google -n containers/*.h
	@echo =CHECK COMPLETED=
	@rm -rf .clang-format
	@echo =REMOVE DONE!=

style-fix: 
	@cp ../materials/linters/.clang-format ./
	@echo =COPY DONE!=
	@clang-format --style=google -i */*.cpp *.h
	@clang-format --style=google -i containers/*.h
	@echo =CHECK COMPLETED=
	@rm -rf .clang-format
	@echo =REMOVE DONE!=

# CPP-check
check:
	cppcheck --enable=all --suppress=missingIncludeSystem ./

valgrind:
	docker build -t ubuntu_01:latest .
	docker run -p 8085:8085 --name matrix01 ubuntu_01:latest
	docker rm matrix01
	docker rmi ubuntu_01:latest

###############################################
# CLEAN AND REBUILD
###############################################

clean:
	@echo ==Cleaning...==
	@rm -rf test
	@rm -rf $(LIB)
	@rm -rf $(BUILD_DIR)
	@rm -rf $(BUILD_TEST_DIR)
	@rm -rf *.o
	@echo ==EVERYTHING REMOVED!==
	@echo ==Done!==

rebuild:
	$(MAKE) clean
	$(MAKE) all
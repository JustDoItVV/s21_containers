CC = clang++
GCOV = gcov
FLAGS = -Wall -Werror -Wextra -std=c++17
OPTFLAGS = -pedantic
LTEST = $(shell pkg-config --cflags gtest) 
LLTEST = $(shell pkg-config --libs gtest) 
GOFLAGS = --coverage
GFLAGS = -fprofile-arcs -ftest-coverage
LIB = s21_matrix_oop.a

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

test_main: $(TEST_OBJECTS)
	$(CC) $(FLAGS) $(GOFLAGS) $^ -o test $(LLTEST)

$(TEST_OBJECTS) : $(BUILD_TEST_DIR)/%.o : $(TEST_DIR)/%.cpp $(TEST_DIR)/s21_containers_test.h
	mkdir -p $(BUILD_TEST_DIR)
	$(CC) $(FLAGS) $(OPTFLAGS) -c $< -o $@ $(LTEST)


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
	@clang-format --style=google -n *.h containers/*.h containers_tests/*.cpp containers_tests/*.h
	@echo =CHECK COMPLETED=
	@rm -rf .clang-format
	@echo =REMOVE DONE!=

style-fix: 
	@cp ../materials/linters/.clang-format ./
	@echo =COPY DONE!=
	@clang-format --style=google -i *.h containers/*.h containers_tests/*.cpp containers_tests/*.h
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
	@echo ==EVERYTHING REMOVED!==
	@echo ==Done!==

rebuild:
	$(MAKE) clean
	$(MAKE) all
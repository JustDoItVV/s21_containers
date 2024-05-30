#silent mode

ifndef VERBOSE
.SILENT:
endif

#Common vars
OS = $(shell uname -s)
CODE_STYLE = -style=Google
OPENOS = vi
ifeq ($(OS), Linux)
  OPENOS = xdg-open
endif
ifeq ($(OS), Darwin)
  OPENOS = open -a "Google Chrome"
endif

#Color vars
GREEN = \033[0;32m
RED	= \033[0;31m

#Compile vars
CXX = g++
CPP_FLAGS = -Wall -Wextra -std=c++20
GCOV = gcov
DEBUG_FLAGS = -pedantic -g
TEST_FLAGS = -lgtest -lpthread
GO_FLAGS = --coverage
GFLAGS = -fprofile-arcs -ftest-coverage
GCOV_FLAGS = --exclude-unreachable-branches --exclude-throw-branches --exclude-noncode-lines --exclude-branches-by-pattern '.*throw std::out_of_range.*'

#Project vars
LIB_NAME = s21_containers

#Directory vars
BUILD_DIR = build
OBJ_DIR = obj
GCOV_OBJ_DIR = obj/gcov
TESTS_OBJ_DIR = obj/test
INCLUDE_DIR = containers
TEST_DIR = containers_tests
REPORT_DIR = report

#Components vars
SOURCES_H = $(shell find $(INCLUDE_DIR) -type f -name *.h)
TEST_CPP = $(notdir $(shell find $(TEST_DIR) -type f -name "*.cpp"))
TEST_H = $(shell find $(TEST_DIR) -type f -name "*.h")
TEST_O = $(addprefix $(TESTS_OBJ_DIR)/,$(TEST_CPP:%.cpp=%.o))
ALL_COMPONENTS = $(shell find $(TEST_DIR) -type f -name *.cpp) $(SOURCES_H) $(TEST_H)
ALL_TEST_DIRS = $(shell find $(TEST_DIR) -type d)

vpath %.cpp $(ALL_TEST_DIRS) $(SOURCES_DIR)
vpath %.o $(OBJ_DIR)

all: test

gcov_report: test $(GCOV_OBJ_DIR)
	gcovr ${GCOV_FLAGS} -r . --gcov-executable $(GCOV) --html --html-details -o $(GCOV_OBJ_DIR)/gcov_report.html
	$(OPENOS) ./$(GCOV_OBJ_DIR)/gcov_report.html

test: $(TESTS_OBJ_DIR) $(BUILD_DIR) $(TEST_O)
	$(CXX) $(DEBUG_FLAGS) $(GO_FLAGS) $(TEST_O) s21_containers_test.cpp -o $(BUILD_DIR)/test $(TEST_FLAGS)
	$(BUILD_DIR)/test

$(BUILD_DIR):
	mkdir -p $(BUILD_DIR)

$(OBJ_DIR):
	mkdir -p $(OBJ_DIR)

$(TESTS_OBJ_DIR):
	mkdir -p $(TESTS_OBJ_DIR)

$(GCOV_OBJ_DIR):
	mkdir -p $(GCOV_OBJ_DIR)

$(OBJ_DIR)/%.o: %.cpp
	$(CXX) $(CPP_FLAGS) $(GFLAGS) -c $< -o $@

$(TESTS_OBJ_DIR)/%.o: %.cpp $(TEST_H)
	$(CXX) $(CPP_FLAGS) -c $< -o $@

#Build and Style tests
check: cpplint cppcheck
ifeq ($(OS), Linux)
	$(MAKE) valgrind
else
	$(MAKE) leaks
endif

cpplint:
	clang-format -n $(ALL_COMPONENTS)

cppcheck:
	cppcheck --enable=all --suppress=missingIncludeSystem --language=c++ $(ALL_COMPONENTS)

valgrind:
ifeq ($(OS), Linux)
	touch valgrind_res.txt
	valgrind -s --leak-check=full --log-file="valgrind_res.txt" --track-origins=yes --show-reachable=yes $(BUILD_DIR)/test
	grep "ERROR" valgrind_res.txt
else
	echo "$(RED)ERROR: Valgrind is not avialibale on $(OS)"
endif

leaks:
	leaks --atExit -- ./$(TEST_EXE)

clean:
	rm -rf $(OBJ_DIR) $(BUILD_DIR)
	rm -rf valgrind_res.txt

.PHONY: all test gcov_report clean check cpplint cppcheck valgrind leaks
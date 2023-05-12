OS = $(shell uname)
ifeq ("$(OS)", "Linux")
    TEST_FLAGS = -lcheck  -pthread -lrt -lm -lsubunit
    LEAKS = valgrind
    OPEN = xdg-open
else
    TEST_FLAGS = -lcheck
    LEAKS = CK_FORK=no leaks -atExit --
    OPEN = open
endif

FLAGS = -Wall -Wextra -Werror -std=c++17
GCOV_FLAGS = -fprofile-arcs -ftest-coverage
CC = g++
THIS_FILE := $(lastword $(MAKEFILE_LIST))
REPORT = @mkdir -p report

all: test

comp_test:
	$(CC) ./tests/tests.cc -o test -lgtest -pthread -lgmock $(FLAGS)

leaks: comp_test
	$(LEAKS) ./test

test: comp_test
	./test

gcov_report:
	$(CC) ./tests/tests.cc -o gcov_test -lgtest -pthread -lgmock $(GCOV_FLAGS) -std=c++17
	./gcov_test
	$(REPORT)
	gcovr -r . --html --html-details -o report/report.html
	@$(MAKE) -f $(THIS_FILE) clean_src
	$(OPEN) ./report/report.html

clang:
	cp ../materials/linters/.clang-format .clang-format
	clang-format -n -verbose *.h */*.cc
	rm -f .clang-format

google_style:
	cp ../materials/linters/.clang-format .clang-format
	clang-format -i -verbose *.h */*.cc
	rm -f .clang-format

clean_src:
	rm -rf *.o *.gcda *.gcno *.gcov *.gch gcov_test

clean: clean_src
	rm -rf report *.a *_test .clang-format test

.PHONY:
	all clean clean_src google_style clang

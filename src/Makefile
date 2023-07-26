# COMMON
COMMON_SRCS+=common
# AUXILIARY
AUXILIARY_SRCS+=s21_strerror
AUXILIARY_SRCS+=s21_strncat
AUXILIARY_SRCS+=s21_strtok
# CALCULATE
CALCULATE_SRCS+=s21_strcspn
CALCULATE_SRCS+=s21_strlen
# COMPARE
COMPARE_SRCS+=s21_memcmp
COMPARE_SRCS+=s21_strncmp
# COPY
COPY_SRCS+=s21_memcpy
COPY_SRCS+=s21_memset
COPY_SRCS+=s21_strncpy
# IO
IO_SRCS+=s21_sprintf
# SEARCH
SEARCH_SRCS+=s21_memchr
SEARCH_SRCS+=s21_strchr
SEARCH_SRCS+=s21_strpbrk
SEARCH_SRCS+=s21_strrchr
SEARCH_SRCS+=s21_strstr
# SPECIAL
SPECIAL_SRCS+=s21_insert
SPECIAL_SRCS+=s21_to_lower
SPECIAL_SRCS+=s21_to_upper
SPECIAL_SRCS+=s21_trim
#################  DO NOT CHANGE BELOW  #################
BUILD_DIR=build/
COMMON_DIR=common/
AUXILIARY_DIR=auxiliary/
CALCULATE_DIR=calculate/
COMPARE_DIR=compare/
COPY_DIR=copy/
IO_DIR=io/
SEARCH_DIR=search/
SPECIAL_DIR=special/
UNIT_TESTS_DIR=unit_tests/
HEADERS_DIR=./ headers/
IFLAGS=$(addprefix -I, $(HEADERS_DIR))
CFLAGS=-Wall -Wextra -Werror -std=c11
COMPILER=gcc
COMMON_TARGETS_OBJ=$(addsuffix .o, $(addprefix $(COMMON_DIR), $(COMMON_SRCS)))
TARGETS+=$(addprefix $(AUXILIARY_DIR), $(AUXILIARY_SRCS))
TARGETS+=$(addprefix $(CALCULATE_DIR), $(CALCULATE_SRCS))
TARGETS+=$(addprefix $(COMPARE_DIR), $(COMPARE_SRCS))
TARGETS+=$(addprefix $(COPY_DIR), $(COPY_SRCS))
TARGETS+=$(addprefix $(IO_DIR), $(IO_SRCS))
TARGETS+=$(addprefix $(SEARCH_DIR), $(SEARCH_SRCS))
TARGETS+=$(addprefix $(SPECIAL_DIR), $(SPECIAL_SRCS))
TARGETS_OBJ=$(addsuffix .o, $(TARGETS))
TEST_TARGERS_OBJ=$(addprefix $(UNIT_TESTS_DIR), $(addsuffix _test.o, $(TARGETS)))
TEST_TARGERS_OBJ+=$(UNIT_TESTS_DIR)common_test.o


all: s21_string.a

s21_string.a: $(TARGETS_OBJ) $(COMMON_TARGETS_OBJ)
	ar rc $@ $(addprefix $(BUILD_DIR), $(COMMON_TARGETS_OBJ)) $(addprefix $(BUILD_DIR), $(TARGETS_OBJ))
	ranlib $@

test: s21_string.a $(TEST_TARGERS_OBJ)
	$(COMPILER) $(CFLAGS) $(IFLAGS) $(addprefix $(BUILD_DIR), $(TEST_TARGERS_OBJ)) $(UNIT_TESTS_DIR)s21_string_tests_runner.c -o s21_string_test.out s21_string.a `pkg-config --cflags --libs check` -lm
test_debug: CFLAGS+=-g -DS21_NOFORK
test_debug: test

style:
	clang-format -i *.c */*.c */*/*.c *.h */*.h */*/*.h

debug: CFLAGS+=-g
debug: s21_string.a
	$(COMPILER) $(CFLAGS) $(IFLAGS) debug_function.c s21_string.a -o debug_function.out
	./debug_function.out

gcov_report: CFLAGS += -fprofile-arcs -ftest-coverage
gcov_report: test
	-./s21_string_test.out
	lcov -t "report" -o report.info -c -d .
	genhtml -o "html_report" report.info
	open html_report/index.html

clean:
	-rm -rf $(BUILD_DIR)
	-rm s21_string.a
	-rm *.gcda
	-rm *.gcno
	-rm -rf html_report
	-rm report.info
	-rm s21_string_test.out
	-rm debug_function

%.o: %.c
	mkdir -p $(BUILD_DIR)$(@D)
	$(COMPILER) $(CFLAGS) $(IFLAGS) -c $< -o $(BUILD_DIR)$@

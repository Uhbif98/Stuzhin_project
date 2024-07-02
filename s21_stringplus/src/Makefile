TESTS_DIR := ./tests
C_SRCS := $(wildcard *.c ./common/*.c)
C_OBJS := $(C_SRCS:%.c=%.o)

all: clean s21_string.a

s21_string.a: $(C_OBJS)
	ar rcs ./$@ $^
	ranlib s21_string.a

%.o: %.c
	gcc -c -std=c11 -g -Wall -Werror -Wextra $< -o $@

test: clean s21_string.a $(TESTS_DIR)/main.c
	gcc -std=c11 -Wall -Werror -Wextra $(TESTS_DIR)/*.c -o $(TESTS_DIR)/test.o -L. s21_string.a -lcheck -lsubunit -lm
	$(TESTS_DIR)/test.o

clean:
	rm -rf *.o ./*/*.o *.a
	rm -rf *.gcno *.gcda *.info report.out *.gcov

gcov_report: clean s21_string.a
	gcc -fprofile-arcs -ftest-coverage -Wall -Werror -Wextra -std=c11 *.c ./common/*.c $(TESTS_DIR)/*.c -o a.o -L. s21_string.a -lcheck -lsubunit -lm
	./a.o
	gcov -f $(C_SRCS)
	lcov -t "gcov_report" -o Coverage_Report.info -c -d .
	genhtml -o ./report Coverage_Report.info
	make clean

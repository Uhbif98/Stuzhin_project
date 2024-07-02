all: rebuild

rebuild: clean build

build: s21_grep

s21_grep:
	gcc -Wall -Wextra -Werror -std=c11 -g main_function.c main.c -o s21_grep

clean:
	rm -rf *.o s21_grep test
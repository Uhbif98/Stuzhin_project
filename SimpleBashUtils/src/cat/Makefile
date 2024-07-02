all: rebuild

rebuild: clean build

build: s21_cat

s21_cat:
	gcc -Wall -Wextra -Werror -std=c11 main_function.c main.c -o s21_cat

clean:
	rm -rf *.o s21_cat test
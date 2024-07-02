#include "s21_string.h"

void *s21_memset(void *str, int c, s21_size_t n) {
  unsigned char *parsed_str = str;

  while (n > 0) {
    *parsed_str = c;

    parsed_str++;
    n--;
  }

  return str;
}
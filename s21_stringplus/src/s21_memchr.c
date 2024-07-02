#include "s21_string.h"

void *s21_memchr(const void *str, int c, s21_size_t n) {
  void *result = s21_NULL;
  const unsigned char *parsed_str = str;

  while (result == s21_NULL && n > 0) {
    if (*parsed_str == c) {
      result = (void *)parsed_str;
    }

    parsed_str++;
    n--;
  }

  return result;
}
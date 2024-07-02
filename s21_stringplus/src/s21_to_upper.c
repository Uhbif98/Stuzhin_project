#include "s21_string.h"

void *s21_to_upper(const char *str) {
  if (str == s21_NULL) {
    return s21_NULL;
  }

  s21_size_t str_length = s21_strlen(str);
  char *copy_str = (char *)calloc(str_length + 1, sizeof(char));

  if (copy_str != s21_NULL) {
    for (s21_size_t i = 0; i < str_length; i++) {
      char c = *(str + i);
      if (c >= 'a' && c <= 'z') {
        c -= 'a' - 'A';
      }
      *(copy_str + i) = c;
    }
  }

  return copy_str;
}
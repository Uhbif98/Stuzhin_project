#include "s21_string.h"

int s21_strncmp(const char *str1, const char *str2, s21_size_t n) {
  int is_compare = 0;

  s21_size_t str1_length = s21_strlen(str1);
  s21_size_t str2_length = s21_strlen(str2);
  if (n > str1_length && n > str2_length) {
    n = str1_length > str2_length ? str1_length : str2_length;
  }

  for (s21_size_t i = 0; i < n && is_compare == 0; i++) {
    is_compare = str1[i] - str2[i];
  }

  return is_compare;
}
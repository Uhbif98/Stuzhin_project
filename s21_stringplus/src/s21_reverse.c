#include "s21_string.h"

char* s21_reverse(char* str) {
  if (str == s21_NULL) {
    return s21_NULL;
  }

  s21_size_t left_index = 0;
  s21_size_t right_index = s21_strlen(str) == 0 ? 0 : s21_strlen(str) - 1;

  while (left_index < right_index) {
    char tmp_value = str[left_index];
    str[left_index] = str[right_index];
    str[right_index] = tmp_value;

    left_index++;
    right_index--;
  }

  return str;
}
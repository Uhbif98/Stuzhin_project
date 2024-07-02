#include "s21_string.h"

s21_size_t s21_strcspn(const char *str1, const char *str2) {
  s21_size_t count_uniq = 0;

  while (*(str1 + count_uniq) &&
         s21_strchr(str2, *(str1 + count_uniq)) == s21_NULL) {
    count_uniq++;
  }

  return count_uniq;
}
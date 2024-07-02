#include "s21_string.h"

void *s21_insert(const char *src, const char *str, s21_size_t start_index) {
  if (src == s21_NULL || str == s21_NULL || start_index > s21_strlen(src)) {
    return s21_NULL;
  }

  s21_size_t src_length = s21_strlen(src);
  s21_size_t str_length = s21_strlen(str);
  char *result = (char *)calloc(src_length + str_length + 1, sizeof(char));

  if (result != s21_NULL) {
    s21_strncpy(result, src, start_index);
    s21_strncpy(result + start_index, str, str_length);
    s21_strncpy(result + start_index + str_length, src + start_index,
                src_length - start_index);
  }

  return result;
}
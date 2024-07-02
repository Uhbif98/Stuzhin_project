#include "s21_string.h"

void *s21_trim(const char *src, const char *trim_chars) {
  if (src == s21_NULL || trim_chars == s21_NULL) {
    return s21_NULL;
  }

  s21_size_t src_length = s21_strlen(src);
  s21_size_t start_index = 0, end_index = src_length - 1;

  for (; *(src + start_index) && s21_strchr(trim_chars, *(src + start_index));
       start_index++)
    ;
  for (; end_index >= start_index && *(src + end_index) &&
         s21_strchr(trim_chars, *(src + end_index));
       end_index--)
    ;

  char *result = s21_NULL;
  if (start_index <= end_index) {
    s21_size_t result_length = end_index - start_index + 1;
    result = (char *)calloc(result_length + 1, sizeof(char));

    if (result != s21_NULL) {
      s21_strncat(result, src + start_index, result_length);
    }
  } else {
    result = (char *)calloc(1, sizeof(char));
  }

  return result;
}
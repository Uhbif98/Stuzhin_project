#include "s21_string.h"

char *s21_strstr(const char *haystack, const char *needle) {
  if (s21_strlen(needle) == 0) {
    return (char *)haystack;
  }

  s21_size_t haystack_length = s21_strlen(haystack);
  s21_size_t needle_length = s21_strlen(needle);
  s21_size_t max_length =
      needle_length > haystack_length ? 0 : haystack_length - needle_length;

  char *found_str = s21_NULL;

  for (s21_size_t i = 0; i <= max_length && !found_str; i++) {
    int is_compare = 1;
    for (s21_size_t j = 0; j < needle_length && is_compare; j++) {
      is_compare = *(haystack + i + j) == *(needle + j);
    }

    if (is_compare) {
      found_str = (char *)(haystack + i);
    }
  }

  return found_str;
}
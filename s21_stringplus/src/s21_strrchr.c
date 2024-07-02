#include "s21_string.h"

char *s21_strrchr(const char *str, int c) {
  if (c == '\0') {
    return (char *)(str + s21_strlen(str));
  }

  char *found_symbol = s21_NULL;

  for (s21_size_t i = 0; *(str + i); i++) {
    if (*(str + i) == c) {
      found_symbol = (char *)(str + i);
    }
  }

  return found_symbol;
}
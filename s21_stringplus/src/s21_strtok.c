#include "s21_string.h"

char *s21_strtok(char *str, const char *delim) {
  static char *curr_str = s21_NULL;
  static char *next_str = s21_NULL;

  if (str != s21_NULL) {
    curr_str = str;
    next_str = str;
  }

  while (next_str != s21_NULL && *next_str && s21_strchr(delim, *next_str)) {
    next_str++;
  }

  if (next_str != s21_NULL && *next_str == '\0') {
    curr_str = s21_NULL;
  } else {
    curr_str = next_str;

    while (next_str != s21_NULL && *next_str && !s21_strchr(delim, *next_str)) {
      next_str++;
    }

    if (next_str != s21_NULL && *next_str != '\0') {
      *next_str = '\0';
      next_str++;
    }
  }

  return curr_str;
}
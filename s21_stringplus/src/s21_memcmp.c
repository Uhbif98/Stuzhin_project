#include "s21_string.h"

int s21_memcmp(const void* str1, const void* str2, s21_size_t n) {
  int result = 0;
  const unsigned char* parsed_str1 = str1;
  const unsigned char* parsed_str2 = str2;

  while (n > 0 && result == 0) {
    result = *parsed_str1 - *parsed_str2;

    parsed_str1++;
    parsed_str2++;
    n--;
  }

  return result;
}
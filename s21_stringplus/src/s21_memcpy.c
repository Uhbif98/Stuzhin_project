#include "s21_string.h"

void *s21_memcpy(void *dest, const void *src, s21_size_t n) {
  unsigned char *parsed_dest = dest;
  const unsigned char *parsed_src = src;

  while (n > 0) {
    *parsed_dest = *parsed_src;

    parsed_dest++;
    parsed_src++;
    n--;
  }
  return dest;
}
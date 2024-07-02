#include "./common/digits_helper.h"
#include "s21_string.h"

s21_size_t s21_itos(char* src, long digit) {
  if (src == s21_NULL) {
    return 0;
  }

  s21_size_t curr_index = 0;

  if (digit < 0) {
    src[curr_index++] = '-';
  }

  int count_digits = get_count_digits(digit);

  digit = reverse_digit(digit);
  while (digit > 0 || count_digits > 0) {
    src[curr_index++] = (digit % 10) + '0';

    digit /= 10;
    count_digits--;
  }

  return curr_index;
}
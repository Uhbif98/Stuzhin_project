#include "digits_helper.h"

int get_count_digits(long double value) {
  int count_digits = 0;

  value = value < 0 ? value * -1 : value;

  do {
    value /= 10;
    count_digits++;
  } while (value >= 1);

  return count_digits;
}

long int reverse_digit(long long int value) {
  long long int reversed_digit = 0;

  while (value != 0) {
    reversed_digit *= 10;
    reversed_digit += abs((int)(value % 10));

    value /= 10;
  }

  return reversed_digit;
}

// Получить кол-во значимых чисел
int get_count_sign_digits(long long int value, int max_count_digits) {
  int count_get_digits = 0;
  int count_digits = get_count_digits(value) - 1;

  value *= value < 0 ? -1 : 1;

  int i = 0;
  while (value >= 10 && count_get_digits == 0) {
    if (value % 10 > 0 && count_digits - i <= max_count_digits) {
      count_get_digits = count_digits - i;
    }

    value /= 10;
    i++;
  }

  return count_get_digits;
}

exp_ld_t get_exp_ld(long double value) {
  exp_ld_t exp_data = {0};
  int exponent = 0;

  value = value < 0 ? value * -1 : value;

  while (value >= 10.0) {
    value /= 10.0;
    exponent++;
  }
  while (value > 0 && value < 1.0) {
    value *= 10.0;
    exponent--;
  }
  exp_data.exponent = exponent;
  exp_data.value = value;

  return exp_data;
}
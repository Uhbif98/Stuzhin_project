#ifndef DIGITS_HELPER_H_
#define DIGITS_HELPER_H_

#include <stdlib.h>

#define NUMBER_SYSTEM "0123456789ABCDEF"

// информация об экспоненте
typedef struct {
  int exponent;
  long double value;
} exp_ld_t;

int get_count_digits(long double value);
int get_count_sign_digits(long long int value, int max_count_digits);
long int reverse_digit(long long int value);

exp_ld_t get_exp_ld(long double value);

#endif
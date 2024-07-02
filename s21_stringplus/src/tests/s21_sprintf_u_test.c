#include <check.h>
#include <limits.h>
#include <locale.h>

#include "../s21_string.h"

START_TEST(test_1) {
  char str[100] = {0};
  char str2[100] = {0};

  char* format = "%u";

  unsigned x = 35;

  int resultOne = s21_sprintf(str, format, x);
  int resultTwo = sprintf(str2, format, x);

  ck_assert_int_eq(resultOne, resultTwo);
  ck_assert_pstr_eq(str, str2);
}
END_TEST

START_TEST(test_2) {
  char str[100] = {0};
  char str2[100] = {0};

  char* format = "%lu %lu % lu %% %-lu %+lu %+-lu";
  unsigned long x = 30;

  int resultOne = s21_sprintf(str, format, x, x, x, x, x, x);
  int resultTwo = sprintf(str2, format, x, x, x, x, x, x);

  ck_assert_int_eq(resultOne, resultTwo);
  ck_assert_pstr_eq(str, str2);
}
END_TEST

START_TEST(test_3) {
  char str[100] = {0};
  char str2[100] = {0};

  char* format = "%.3u %.3u %0u %u % 3u % 3u";

  unsigned x = 35.5;

  int resultOne = s21_sprintf(str, format, x, x, x, x, x, x);
  int resultTwo = sprintf(str2, format, x, x, x, x, x, x);

  ck_assert_int_eq(resultOne, resultTwo);
  ck_assert_pstr_eq(str, str2);
}
END_TEST

START_TEST(test_4) {
  char str[100] = {0};
  char str2[100] = {0};

  char* format = "%.3u %.3u %0u %u % 3u % 3u";

  unsigned x = 0;

  int resultOne = s21_sprintf(str, format, x, x, x, x, x, x);
  int resultTwo = sprintf(str2, format, x, x, x, x, x, x);

  ck_assert_int_eq(resultOne, resultTwo);
  ck_assert_pstr_eq(str, str2);
}
END_TEST

TCase* sprintf_u_get_tests(void) {
  TCase* test_cases = tcase_create("test_sprintf_u");

  tcase_add_test(test_cases, test_1);
  tcase_add_test(test_cases, test_2);
  tcase_add_test(test_cases, test_3);
  tcase_add_test(test_cases, test_4);

  return test_cases;
}
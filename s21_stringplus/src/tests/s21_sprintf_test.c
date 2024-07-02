#include <check.h>
#include <limits.h>

// %[flags][width][.precision][length]specifier.

#include "../s21_string.h"

#define TEST_FLAGS "-+ #0"
#define TEST_WIDTH_AND_PRECISION "015*"
#define TEST_LENGTH = "hlL"

START_TEST(test_specifier_d) {
  char s21_sprintf_result[100] = {0};
  char sprintf_result[100] = {0};
  int test_arg = 1;
  s21_sprintf(s21_sprintf_result, "This number is: %d", test_arg);
  sprintf(sprintf_result, "This number is: %d", test_arg);
  ck_assert_str_eq(s21_sprintf_result, sprintf_result);
  s21_memset(s21_sprintf_result, 0, 100);
  s21_memset(sprintf_result, 0, 100);
  test_arg = 10;
  s21_sprintf(s21_sprintf_result, "This number is: %6d", test_arg);
  sprintf(sprintf_result, "This number is: %6d", test_arg);
  ck_assert_str_eq(s21_sprintf_result, sprintf_result);
  s21_memset(s21_sprintf_result, 0, 100);
  s21_memset(sprintf_result, 0, 100);
  test_arg = 100;
  s21_sprintf(s21_sprintf_result, "This number is: %.6d", test_arg);
  sprintf(sprintf_result, "This number is: %.6d", test_arg);
  ck_assert_str_eq(s21_sprintf_result, sprintf_result);
}
END_TEST

TCase* sprintf_get_tests(void) {
  TCase* test_cases = tcase_create("test_cases");

  tcase_add_test(test_cases, test_specifier_d);

  return test_cases;
}

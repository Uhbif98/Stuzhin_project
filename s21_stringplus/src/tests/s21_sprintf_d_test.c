#include <check.h>
#include <limits.h>

// %[flags][width][.precision][length]specifier.

#include "../s21_string.h"

#define TEST_FLAGS "-+ #0"
#define TEST_WIDTH_AND_PRECISION "015*"
#define TEST_LENGTH = "hlL"

START_TEST(test_specifier_d1) {
  char s21_sprintf_result[100] = {0};
  char sprintf_result[100] = {0};
  int test_arg = 1;
  s21_sprintf(s21_sprintf_result, "This number is: %d", test_arg);
  sprintf(sprintf_result, "This number is: %d", test_arg);
  ck_assert_str_eq(s21_sprintf_result, sprintf_result);
}
END_TEST

START_TEST(test_specifier_d2) {
  char s21_sprintf_result[100] = {0};
  char sprintf_result[100] = {0};
  int test_arg = 10;
  s21_sprintf(s21_sprintf_result, "This number is: %6d", test_arg);
  sprintf(sprintf_result, "This number is: %6d", test_arg);
  ck_assert_str_eq(s21_sprintf_result, sprintf_result);
}
END_TEST

START_TEST(test_specifier_d3) {
  char s21_sprintf_result[100] = {0};
  char sprintf_result[100] = {0};
  int test_arg = 100;
  s21_sprintf(s21_sprintf_result, "This number is: %.6d", test_arg);
  sprintf(sprintf_result, "This number is: %.6d", test_arg);
  ck_assert_str_eq(s21_sprintf_result, sprintf_result);
}
END_TEST

START_TEST(test_specifier_d4) {
  char s21_sprintf_result[100] = {0};
  char sprintf_result[100] = {0};
  short int test_arg = 1000;
  s21_sprintf(s21_sprintf_result, "This number is: %hd", test_arg);
  sprintf(sprintf_result, "This number is: %hd", test_arg);
  ck_assert_str_eq(s21_sprintf_result, sprintf_result);
}
END_TEST

START_TEST(test_specifier_d5) {
  char s21_sprintf_result[100] = {0};
  char sprintf_result[100] = {0};
  int test_arg = 1000;
  s21_sprintf(s21_sprintf_result, "This number is: %d and %-d", test_arg,
              test_arg);
  sprintf(sprintf_result, "This number is: %d and %-d", test_arg, test_arg);
  ck_assert_str_eq(s21_sprintf_result, sprintf_result);
}
END_TEST

START_TEST(test_specifier_d6) {
  char s21_sprintf_result[100] = {0};
  char sprintf_result[100] = {0};
  int test_arg = 1000;
  s21_sprintf(s21_sprintf_result, "This number is: %+d", test_arg);
  sprintf(sprintf_result, "This number is: %+d", test_arg);
  ck_assert_str_eq(s21_sprintf_result, sprintf_result);
}
END_TEST

START_TEST(test_specifier_d7) {
  char s21_sprintf_result[100] = {0};
  char sprintf_result[100] = {0};
  int test_arg = 1000;
  s21_sprintf(s21_sprintf_result, "This number is: % d", test_arg);
  sprintf(sprintf_result, "This number is: % d", test_arg);
  ck_assert_str_eq(s21_sprintf_result, sprintf_result);
}
END_TEST

START_TEST(test_specifier_d8) {
  char s21_sprintf_result[100] = {0};
  char sprintf_result[100] = {0};
  long int test_arg = 100000000;
  s21_sprintf(s21_sprintf_result, "This number is: %ld", test_arg);
  sprintf(sprintf_result, "This number is: %ld", test_arg);
  ck_assert_str_eq(s21_sprintf_result, sprintf_result);
}
END_TEST

START_TEST(test_specifier_d9) {
  char s21_sprintf_result[100] = {0};
  char sprintf_result[100] = {0};
  short int test_arg = 659;

  s21_sprintf(s21_sprintf_result, "This number is: %+3.3hd", test_arg);
  sprintf(sprintf_result, "This number is: %+3.3hd", test_arg);
  ck_assert_str_eq(s21_sprintf_result, sprintf_result);
}
END_TEST

START_TEST(test_specifier_d10) {
  char s21_sprintf_result[100] = {0};
  char sprintf_result[100] = {0};
  short int test_arg = 659;
  int width = 2;
  int exact = 2;

  s21_sprintf(s21_sprintf_result, "This number is: %*.*hd", width, exact,
              test_arg);
  sprintf(sprintf_result, "This number is: %*.*hd", width, exact, test_arg);
  ck_assert_str_eq(s21_sprintf_result, sprintf_result);
}
END_TEST

START_TEST(test_specifier_d11) {
  char s21_sprintf_result[100] = {0};
  char sprintf_result[100] = {0};
  int test_arg = 659;

  s21_sprintf(s21_sprintf_result, "This number is: %06d", test_arg);
  sprintf(sprintf_result, "This number is: %06d", test_arg);
  ck_assert_str_eq(s21_sprintf_result, sprintf_result);
}
END_TEST

START_TEST(test_specifier_d12) {
  char s21_sprintf_result[100] = {0};
  char sprintf_result[100] = {0};
  int test_arg = 659;

  s21_sprintf(s21_sprintf_result, "This number is: %15d", test_arg);
  sprintf(sprintf_result, "This number is: %15d", test_arg);
  ck_assert_str_eq(s21_sprintf_result, sprintf_result);
}
END_TEST

TCase* sprintf_d_get_tests(void) {
  TCase* test_cases = tcase_create("test_cases");

  tcase_add_test(test_cases, test_specifier_d1);
  tcase_add_test(test_cases, test_specifier_d2);
  tcase_add_test(test_cases, test_specifier_d3);
  tcase_add_test(test_cases, test_specifier_d4);
  tcase_add_test(test_cases, test_specifier_d5);
  tcase_add_test(test_cases, test_specifier_d6);
  tcase_add_test(test_cases, test_specifier_d7);
  tcase_add_test(test_cases, test_specifier_d8);
  tcase_add_test(test_cases, test_specifier_d9);
  tcase_add_test(test_cases, test_specifier_d10);
  tcase_add_test(test_cases, test_specifier_d11);
  tcase_add_test(test_cases, test_specifier_d12);

  return test_cases;
}

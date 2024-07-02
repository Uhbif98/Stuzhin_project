#include <check.h>
#include <limits.h>
#include <locale.h>

#include "../s21_string.h"

START_TEST(test_1) {
  char str[100] = {0};
  char str2[100] = {0};

  char* format = "%p";

  int x = 345;

  int result_one = s21_sprintf(str, format, &x);
  int result_two = sprintf(str2, format, &x);

  ck_assert_int_eq(result_one, result_two);
  ck_assert_pstr_eq(str, str2);
}
END_TEST

START_TEST(test_2) {
  char str[100] = {0};
  char str2[100] = {0};

  char* format = "% p %3p %.3p %lp";

  char* x = NULL;

  int result_one = s21_sprintf(str, format, &x, &x, &x, &x);
  int result_two = sprintf(str2, format, &x, &x, &x, &x);

  ck_assert_int_eq(result_one, result_two);
  ck_assert_pstr_eq(str, str2);
}
END_TEST

START_TEST(test_3) {
  char str[100] = {0};
  char str2[100] = {0};

  char* format = "%hp % hp % 3hp %.3hp";

  char x = 'g';

  int result_one = s21_sprintf(str, format, &x, &x, &x, &x);
  int result_two = sprintf(str2, format, &x, &x, &x, &x);

  ck_assert_int_eq(result_one, result_two);
  ck_assert_pstr_eq(str, str2);
}
END_TEST

START_TEST(test_4) {
  char str[100] = {0};
  char str2[100] = {0};

  char* format = "%p %p %p";

  char x = 'x';

  int result_one = s21_sprintf(str, format, &x, &x, &x);
  int result_two = sprintf(str2, format, &x, &x, &x);

  ck_assert_int_eq(result_one, result_two);
  ck_assert_pstr_eq(str, str2);
}
END_TEST

START_TEST(test_5) {
  char str[100] = {0};
  char str2[100] = {0};

  char* format = "%p %p";

  float x = -3.3545;

  int result_one = s21_sprintf(str, format, &x, &x);
  int result_two = sprintf(str2, format, &x, &x);

  ck_assert_int_eq(result_one, result_two);
  ck_assert_pstr_eq(str, str2);
}
END_TEST

START_TEST(test_6) {
  char str[100] = {0};
  char str2[100] = {0};

  char* format = "%-p %+p %+-p %-+p";

  double x = -0.00;

  int result_one = s21_sprintf(str, format, &x, &x, &x, &x);
  int result_two = sprintf(str2, format, &x, &x, &x, &x);

  ck_assert_int_eq(result_one, result_two);
  ck_assert_pstr_eq(str, str2);
}
END_TEST

START_TEST(test_7) {
  char str[100] = {0};
  char str2[100] = {0};

  char* format = "%p %.4p";

  double x = 0.00;

  int result_one = s21_sprintf(str, format, &x, &x);
  int result_two = sprintf(str2, format, &x, &x);

  ck_assert_int_eq(result_one, result_two);
  ck_assert_pstr_eq(str, str2);
}
END_TEST

START_TEST(test_8) {
  char str[100] = {0};
  char str2[100] = {0};

  char* format = "%lp %p %p %p %p";

  unsigned x_1 = 2343;
  int x_2 = 3449;
  double x_3 = 23.32492;
  int x_4 = 0;
  int x_5 = -50;

  int result_one = s21_sprintf(str, format, &x_1, &x_2, &x_3, &x_4, &x_5);
  int result_two = sprintf(str2, format, &x_1, &x_2, &x_3, &x_4, &x_5);

  ck_assert_int_eq(result_one, result_two);
  ck_assert_pstr_eq(str, str2);
}
END_TEST

TCase* sprintf_p_get_tests(void) {
  TCase* test_cases = tcase_create("test_sprintf_p");

  tcase_add_test(test_cases, test_1);
  tcase_add_test(test_cases, test_2);
  tcase_add_test(test_cases, test_3);
  tcase_add_test(test_cases, test_4);
  tcase_add_test(test_cases, test_5);
  tcase_add_test(test_cases, test_6);
  tcase_add_test(test_cases, test_7);
  tcase_add_test(test_cases, test_8);

  return test_cases;
}
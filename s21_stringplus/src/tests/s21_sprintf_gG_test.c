#include <check.h>
#include <limits.h>
#include <math.h>

#include "../s21_string.h"

START_TEST(test_flags_g) {
  char s21_result[100];
  char original_result[100];

  double val = 123.456;
  int a = s21_sprintf(s21_result, "%g", val);
  int b = sprintf(original_result, "%g", val);
  ck_assert_str_eq(s21_result, original_result);
  ck_assert_int_eq(a, b);

  a = s21_sprintf(s21_result, "%+g", val);
  b = sprintf(original_result, "%+g", val);
  ck_assert_str_eq(s21_result, original_result);
  ck_assert_int_eq(a, b);

  a = s21_sprintf(s21_result, "%-g", val);
  b = sprintf(original_result, "%-g", val);
  ck_assert_str_eq(s21_result, original_result);
  ck_assert_int_eq(a, b);

  a = s21_sprintf(s21_result, "% g", val);
  b = sprintf(original_result, "% g", val);
  ck_assert_str_eq(s21_result, original_result);
  ck_assert_int_eq(a, b);

  a = s21_sprintf(s21_result, "%#g", val);
  b = sprintf(original_result, "%#g", val);
  ck_assert_str_eq(s21_result, original_result);
  ck_assert_int_eq(a, b);

  a = s21_sprintf(s21_result, "%010g", val);
  b = sprintf(original_result, "%010g", val);
  ck_assert_str_eq(s21_result, original_result);
  ck_assert_int_eq(a, b);

  a = s21_sprintf(s21_result, "%+10.2g", val);
  b = sprintf(original_result, "%+10.2g", val);
  ck_assert_str_eq(s21_result, original_result);
  ck_assert_int_eq(a, b);

  a = s21_sprintf(s21_result, "%010.5g", val);
  b = sprintf(original_result, "%010.5g", val);
  ck_assert_str_eq(s21_result, original_result);
  ck_assert_int_eq(a, b);
}
END_TEST

START_TEST(test_width_g) {
  char s21_result[100];
  char original_result[100];

  double val = 123.456;

  int a = s21_sprintf(s21_result, "%10g", val);
  int b = sprintf(original_result, "%10g", val);

  ck_assert_str_eq(s21_result, original_result);
  ck_assert_int_eq(a, b);
}
END_TEST

START_TEST(test_accuracy_g) {
  char s21_result[100];
  char original_result[100];

  double val = 123.456;

  int a = s21_sprintf(s21_result, "%.2g", val);
  int b = sprintf(original_result, "%.2g", val);

  ck_assert_str_eq(s21_result, original_result);
  ck_assert_int_eq(a, b);
}
END_TEST

START_TEST(test_length_g) {
  char s21_result[100];
  char original_result[100];

  double val = 123.456;

  int a = s21_sprintf(s21_result, "%lg", val);
  int b = sprintf(original_result, "%lg", val);

  ck_assert_str_eq(s21_result, original_result);
  ck_assert_int_eq(a, b);
}
END_TEST

START_TEST(test_width_accuracy_g) {
  char s21_result[100];
  char original_result[100];

  double val = 123.456;

  int a = s21_sprintf(s21_result, "%10.2g", val);
  int b = sprintf(original_result, "%10.2g", val);

  ck_assert_str_eq(s21_result, original_result);
  ck_assert_int_eq(a, b);
}
END_TEST

START_TEST(test_g_large_value) {
  char s21_result[1000];
  char original_result[1000];

  double large_val = 1.23e+308;

  int a = s21_sprintf(s21_result, "%g", large_val);
  int b = sprintf(original_result, "%g", large_val);

  ck_assert_str_eq(s21_result, original_result);
  ck_assert_int_eq(a, b);
}
END_TEST

START_TEST(test_g_small_value) {
  char s21_result[1000];
  char original_result[1000];

  double small_val = 1.23e-10;

  int a = s21_sprintf(s21_result, "%g", small_val);
  int b = sprintf(original_result, "%g", small_val);

  ck_assert_str_eq(s21_result, original_result);
  ck_assert_int_eq(a, b);
}
END_TEST

START_TEST(test_g_many_formats) {
  char s21_result[1000];
  char original_result[1000];

  double val = 123.456;
  int a = s21_sprintf(s21_result, "%g %g %g %g %g %g %g %g %g %g", val, val,
                      val, val, val, val, val, val, val, val);
  int b = sprintf(original_result, "%g %g %g %g %g %g %g %g %g %g", val, val,
                  val, val, val, val, val, val, val, val);
  ck_assert_str_eq(s21_result, original_result);
  ck_assert_int_eq(a, b);

  a = s21_sprintf(s21_result, "%#010.5g", val);
  b = sprintf(original_result, "%#010.5g", val);

  ck_assert_str_eq(s21_result, original_result);
  ck_assert_int_eq(a, b);
}
END_TEST

START_TEST(test_g_negative_value) {
  char s21_result[100];
  char original_result[100];

  double val = -123.456;

  int a = s21_sprintf(s21_result, "%g", val);
  int b = sprintf(original_result, "%g", val);

  ck_assert_str_eq(s21_result, original_result);
  ck_assert_int_eq(a, b);
}
END_TEST

START_TEST(test_g_round) {
  char s21_result[100];
  char original_result[100];

  double val = 123.456789;

  int a = s21_sprintf(s21_result, "%.4g", val);
  int b = sprintf(original_result, "%.4g", val);

  ck_assert_str_eq(s21_result, original_result);
  ck_assert_int_eq(a, b);
}
END_TEST

START_TEST(test_g_zero_value) {
  char s21_result[100];
  char original_result[100];

  double val = 0.0;

  int a = s21_sprintf(s21_result, "%g", val);
  int b = sprintf(original_result, "%g", val);

  ck_assert_str_eq(s21_result, original_result);
  ck_assert_int_eq(a, b);
}
END_TEST

START_TEST(test_g_nan) {
  char s21_result[100];
  char original_result[100];

  double val = 0.0;
  double zero = 0;

  int a = s21_sprintf(s21_result, "%g", val / zero);
  int b = sprintf(original_result, "%g", val / zero);

  ck_assert_str_eq(s21_result, original_result);
  ck_assert_int_eq(a, b);
}
END_TEST

START_TEST(test_g_all_flags) {
  char s21_result[100];
  char original_result[100];

  double x = -32.534245;

  int a = s21_sprintf(s21_result, "%+3g %-2g %+-4g %05g %.5g", x, x, x, x, x);
  int b = sprintf(original_result, "%+3g %-2g %+-4g %05g %.5g", x, x, x, x, x);

  ck_assert_str_eq(s21_result, original_result);
  ck_assert_int_eq(a, b);
}
END_TEST

START_TEST(test_G_flags) {
  char s21_result[100];
  char original_result[100];

  double val = 123.456;

  int a = s21_sprintf(s21_result, "%G", val);
  int b = sprintf(original_result, "%G", val);
  ck_assert_str_eq(s21_result, original_result);
  ck_assert_int_eq(a, b);

  a = s21_sprintf(s21_result, "%010G", val);
  b = sprintf(original_result, "%010G", val);
  ck_assert_str_eq(s21_result, original_result);
  ck_assert_int_eq(a, b);

  a = s21_sprintf(s21_result, "%+G", val);
  b = sprintf(original_result, "%+G", val);
  ck_assert_str_eq(s21_result, original_result);
  ck_assert_int_eq(a, b);

  a = s21_sprintf(s21_result, "%-G", val);
  b = sprintf(original_result, "%-G", val);
  ck_assert_str_eq(s21_result, original_result);
  ck_assert_int_eq(a, b);

  a = s21_sprintf(s21_result, "% G", val);
  b = sprintf(original_result, "% G", val);
  ck_assert_str_eq(s21_result, original_result);
  ck_assert_int_eq(a, b);
}
END_TEST

START_TEST(test_width_G) {
  char s21_result[100];
  char original_result[100];

  double val = 123.456;
  int a = s21_sprintf(s21_result, "%*G", 10, val);
  int b = sprintf(original_result, "%*G", 10, val);

  ck_assert_str_eq(s21_result, original_result);
  ck_assert_int_eq(a, b);

  a = s21_sprintf(s21_result, "%10G", val);
  b = sprintf(original_result, "%10G", val);

  ck_assert_str_eq(s21_result, original_result);
  ck_assert_int_eq(a, b);
}
END_TEST

START_TEST(test_accuracy_G) {
  char s21_result[100];
  char original_result[100];

  double val = 123.456;

  int a = s21_sprintf(s21_result, "%.*G", 2, val);
  int b = sprintf(original_result, "%.*G", 2, val);
  ck_assert_str_eq(s21_result, original_result);
  ck_assert_int_eq(a, b);

  a = s21_sprintf(s21_result, "%.5G", val);
  b = sprintf(original_result, "%.5G", val);
  ck_assert_str_eq(s21_result, original_result);
  ck_assert_int_eq(a, b);

  a = s21_sprintf(s21_result, "%10.5G", val);
  b = sprintf(original_result, "%10.5G", val);
  ck_assert_str_eq(s21_result, original_result);
  ck_assert_int_eq(a, b);

  a = s21_sprintf(s21_result, "%010.5G", val);
  b = sprintf(original_result, "%010.5G", val);
  ck_assert_str_eq(s21_result, original_result);
  ck_assert_int_eq(a, b);
}
END_TEST

START_TEST(test_G_widhth_accuracy_flags) {
  char s21_result[100];
  char original_result[100];
  double val = 123.456;

  int a = s21_sprintf(s21_result, "%#010.5G", val);
  int b = sprintf(original_result, "%#010.5G", val);

  ck_assert_str_eq(s21_result, original_result);
  ck_assert_int_eq(a, b);
}
END_TEST

START_TEST(test_length_G) {
  char s21_result[100];
  char original_result[100];

  //   double val = 123.456;
  long double lval = 123.456L;

  int a = s21_sprintf(s21_result, "%LG", lval);
  int b = sprintf(original_result, "%LG", lval);

  ck_assert_str_eq(s21_result, original_result);
  ck_assert_int_eq(a, b);
}
END_TEST

START_TEST(test_G_zero_value) {
  char s21_result[100];
  char original_result[100];

  double val = 0.0;

  int a = s21_sprintf(s21_result, "%G", val);
  int b = sprintf(original_result, "%G", val);

  ck_assert_str_eq(s21_result, original_result);
  ck_assert_int_eq(a, b);
}
END_TEST

START_TEST(test_G_all_flags) {
  char s21_result[100];
  char original_result[100];

  double x = -32.534245;

  int a = s21_sprintf(s21_result, "%+3G %-2G %+-4G %05G %.5G", x, x, x, x, x);
  int b = sprintf(original_result, "%+3G %-2G %+-4G %05G %.5G", x, x, x, x, x);

  ck_assert_str_eq(s21_result, original_result);
  ck_assert_int_eq(a, b);
}
END_TEST

START_TEST(test_G_1) {
  char s21_result[100];
  char original_result[100];

  double x = 999.9;

  int a = s21_sprintf(s21_result, "%g %G %lg %lG %3g", x, x, x, x, x);
  int b = sprintf(original_result, "%g %G %lg %lG %3g", x, x, x, x, x);

  ck_assert_str_eq(s21_result, original_result);
  ck_assert_int_eq(a, b);
}
END_TEST

START_TEST(test_G_2) {
  char s21_result[100];
  char original_result[100];

  double x = 999.9;

  int a = s21_sprintf(s21_result, "%.3g %3G %3.3lg %11lG %.11g", x, x, x, x, x);
  int b =
      sprintf(original_result, "%.3g %3G %3.3lg %11lG %.11g", x, x, x, x, x);

  ck_assert_str_eq(s21_result, original_result);
  ck_assert_int_eq(a, b);
}
END_TEST

START_TEST(test_G_3) {
  char s21_result[100];
  char original_result[100];

  double x = 1000.00000009;

  int a = s21_sprintf(s21_result, "%.9g %9g %9.9g %.3g %g", x, x, x, x, x);
  int b = sprintf(original_result, "%.9g %9g %9.9g %.3g %g", x, x, x, x, x);

  ck_assert_str_eq(s21_result, original_result);
  ck_assert_int_eq(a, b);
}
END_TEST

START_TEST(test_G_4) {
  char s21_result[100];
  char original_result[100];

  double x = 1000.00000001;

  int a = s21_sprintf(s21_result, "%.9g %9g %9.9g %.3g %g", x, x, x, x, x);
  int b = sprintf(original_result, "%.9g %9g %9.9g %.3g %g", x, x, x, x, x);

  ck_assert_str_eq(s21_result, original_result);
  ck_assert_int_eq(a, b);
}
END_TEST

TCase *sprintf_gG_get_tests(void) {
  TCase *test_cases = tcase_create("test_sprintf_gG");

  tcase_add_test(test_cases, test_flags_g);
  tcase_add_test(test_cases, test_width_g);
  tcase_add_test(test_cases, test_accuracy_g);
  tcase_add_test(test_cases, test_length_g);

  tcase_add_test(test_cases, test_width_accuracy_g);
  tcase_add_test(test_cases, test_g_large_value);
  tcase_add_test(test_cases, test_g_small_value);
  tcase_add_test(test_cases, test_g_many_formats);
  tcase_add_test(test_cases, test_g_negative_value);
  tcase_add_test(test_cases, test_g_round);

  tcase_add_test(test_cases, test_g_zero_value);
  tcase_add_test(test_cases, test_g_nan);
  tcase_add_test(test_cases, test_g_all_flags);
  tcase_add_test(test_cases, test_G_flags);
  tcase_add_test(test_cases, test_width_G);
  tcase_add_test(test_cases, test_accuracy_G);
  tcase_add_test(test_cases, test_G_widhth_accuracy_flags);
  tcase_add_test(test_cases, test_length_G);
  tcase_add_test(test_cases, test_G_zero_value);
  tcase_add_test(test_cases, test_G_all_flags);

  tcase_add_test(test_cases, test_G_1);
  tcase_add_test(test_cases, test_G_2);
  tcase_add_test(test_cases, test_G_3);
  tcase_add_test(test_cases, test_G_4);

  return test_cases;
}

#include <check.h>
#include <limits.h>

#include "../s21_string.h"

START_TEST(test_o_flags_width) {
  char s21_result[100];
  char original_result[100];

  unsigned int val = 123;
  s21_sprintf(s21_result, "%#o", val);
  sprintf(original_result, "%#o", val);
  ck_assert_str_eq(s21_result, original_result);

  s21_sprintf(s21_result, "%010o", val);
  sprintf(original_result, "%010o", val);
  ck_assert_str_eq(s21_result, original_result);

  s21_sprintf(s21_result, "%-10o", val);
  sprintf(original_result, "%-10o", val);
  ck_assert_str_eq(s21_result, original_result);

  s21_sprintf(s21_result, "%o", val);
  sprintf(original_result, "%o", val);
  ck_assert_str_eq(s21_result, original_result);

  s21_sprintf(s21_result, "%#0o", val);
  sprintf(original_result, "%#0o", val);
  ck_assert_str_eq(s21_result, original_result);

  s21_sprintf(s21_result, "%-#10o", val);
  sprintf(original_result, "%-#10o", val);
  ck_assert_str_eq(s21_result, original_result);

  s21_sprintf(s21_result, "%010o", val);
  sprintf(original_result, "%010o", val);
  ck_assert_str_eq(s21_result, original_result);

  // flag and width
  s21_sprintf(s21_result, "%#-10.5o", val);
  sprintf(original_result, "%#-10.5o", val);
  ck_assert_str_eq(s21_result, original_result);

  s21_sprintf(s21_result, "%#010o", 0);
  sprintf(original_result, "%#010o", 0);
  ck_assert_str_eq(s21_result, original_result);

  s21_sprintf(s21_result, "%10.5o", val);
  sprintf(original_result, "%10.5o", val);
  ck_assert_str_eq(s21_result, original_result);

  s21_sprintf(s21_result, "%5.10o", val);
  sprintf(original_result, "%5.10o", val);
  ck_assert_str_eq(s21_result, original_result);

  s21_sprintf(s21_result, "%10.10o", val);
  sprintf(original_result, "%10.10o", val);
  ck_assert_str_eq(s21_result, original_result);
}
END_TEST

START_TEST(test_o_accuracy) {
  char s21_result[100];
  char original_result[100];

  unsigned int val = 123;
  s21_sprintf(s21_result, "%.5o", val);
  sprintf(original_result, "%.5o", val);
  ck_assert_str_eq(s21_result, original_result);
}
END_TEST

START_TEST(test_o_length) {
  char s21_result[100];
  char original_result[100];

  unsigned short val_h = 123;
  s21_sprintf(s21_result, "%ho", val_h);
  sprintf(original_result, "%ho", val_h);
  ck_assert_str_eq(s21_result, original_result);

  unsigned long val_l = 123;
  s21_sprintf(s21_result, "%lo", val_l);
  sprintf(original_result, "%lo", val_l);
  ck_assert_str_eq(s21_result, original_result);
}
END_TEST

START_TEST(test_o_zero) {
  char s21_result[100];
  char original_result[100];

  s21_sprintf(s21_result, "%o", 0);
  sprintf(original_result, "%o", 0);
  ck_assert_str_eq(s21_result, original_result);
}
END_TEST

START_TEST(test_o_max_value) {
  char s21_result[100];
  char original_result[100];

  unsigned int max_uint = ~0;
  s21_sprintf(s21_result, "%o", max_uint);
  sprintf(original_result, "%o", max_uint);
  ck_assert_str_eq(s21_result, original_result);
}
END_TEST

START_TEST(test_o_large_values) {
  char s21_result[100];
  char original_result[100];

  unsigned int large_val = 4294967295;  // 2^32 - 1, max for unsigned int
  s21_sprintf(s21_result, "%o", large_val);
  sprintf(original_result, "%o", large_val);
  ck_assert_str_eq(s21_result, original_result);
}
END_TEST

START_TEST(test_o_long_string) {
  char s21_result[1000];
  char original_result[1000];
  char long_string[1000];
  memset(long_string, 'a', 999);
  long_string[999] = '\0';
  s21_sprintf(s21_result, "%s", long_string);
  sprintf(original_result, "%s", long_string);
  ck_assert_str_eq(s21_result, original_result);
}
END_TEST

START_TEST(test_o_edge_width_and_precision) {
  char s21_result[100];
  char original_result[100];

  unsigned int val = 123;
  s21_sprintf(s21_result, "%1.0o", val);
  sprintf(original_result, "%1.0o", val);
  ck_assert_str_eq(s21_result, original_result);

  s21_sprintf(s21_result, "%.1o", val);
  sprintf(original_result, "%.1o", val);
  ck_assert_str_eq(s21_result, original_result);

  s21_sprintf(s21_result, "%1.1o", val);
  sprintf(original_result, "%1.1o", val);
  ck_assert_str_eq(s21_result, original_result);
}
END_TEST

START_TEST(test_o_specific_symbols) {
  char s21_result[100];
  char original_result[100];
  s21_sprintf(s21_result, "%o", '\n');
  sprintf(original_result, "%o", '\n');
  ck_assert_str_eq(s21_result, original_result);
}
END_TEST

START_TEST(test_o_combination_with_other_specifiers) {
  char s21_result[100];
  char original_result[100];

  unsigned int num = 12345;
  s21_sprintf(s21_result, "%o %x", num, num);
  sprintf(original_result, "%o %x", num, num);
  ck_assert_str_eq(s21_result, original_result);

  s21_sprintf(s21_result, "%o %u", num, num);
  sprintf(original_result, "%o %u", num, num);
  ck_assert_str_eq(s21_result, original_result);

  s21_sprintf(s21_result, "%o %s", num, "test");
  sprintf(original_result, "%o %s", num, "test");
  ck_assert_str_eq(s21_result, original_result);

  double dbl = 12345.6789;
  char ch = 'A';
  s21_sprintf(s21_result, "%o %f", num, dbl);
  sprintf(original_result, "%o %f", num, dbl);
  ck_assert_str_eq(s21_result, original_result);

  s21_sprintf(s21_result, "%o %c", num, ch);
  sprintf(original_result, "%o %c", num, ch);
  ck_assert_str_eq(s21_result, original_result);

  s21_sprintf(s21_result, "%o %e", num, dbl);
  sprintf(original_result, "%o %e", num, dbl);
  ck_assert_str_eq(s21_result, original_result);
}
END_TEST

START_TEST(test_o_with_negative_number) {
  char s21_result[100];
  char original_result[100];

  int num = -12345;
  s21_sprintf(s21_result, "%o", num);
  sprintf(original_result, "%o", num);
  ck_assert_str_eq(s21_result, original_result);
}
END_TEST

START_TEST(test_o_with_flag_number) {
  char s21_result[100];
  char original_result[100];

  int num = -12345;
  s21_sprintf(s21_result, "%#o", num);
  sprintf(original_result, "%#o", num);
  ck_assert_str_eq(s21_result, original_result);
}
END_TEST

TCase *sprintf_o_get_tests(void) {
  TCase *test_cases = tcase_create("test_sprintf_o");

  tcase_add_test(test_cases, test_o_flags_width);
  tcase_add_test(test_cases, test_o_accuracy);
  tcase_add_test(test_cases, test_o_length);
  tcase_add_test(test_cases, test_o_zero);
  tcase_add_test(test_cases, test_o_max_value);
  tcase_add_test(test_cases, test_o_long_string);
  tcase_add_test(test_cases, test_o_long_string);
  tcase_add_test(test_cases, test_o_specific_symbols);
  tcase_add_test(test_cases, test_o_edge_width_and_precision);
  tcase_add_test(test_cases, test_o_large_values);
  tcase_add_test(test_cases, test_o_combination_with_other_specifiers);
  tcase_add_test(test_cases, test_o_with_negative_number);
  tcase_add_test(test_cases, test_o_with_flag_number);

  return test_cases;
}

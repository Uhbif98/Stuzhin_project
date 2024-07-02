#include <check.h>
#include <limits.h>

#include "../s21_string.h"

START_TEST(test_trim_1) {
  const char *str = "  Hello world  ";
  const char *trim_chars = "d ";
  char expected[] = "Hello worl";
  char *s21_result = s21_trim(str, trim_chars);

  ck_assert_str_eq(expected, s21_result);
  if (s21_result) free(s21_result);
}
END_TEST

START_TEST(test_trim_2) {
  const char *str = "  Hello world  ";
  const char *trim_chars = "d w";
  char expected[] = "Hello worl";
  char *s21_result = s21_trim(str, trim_chars);
  ck_assert_str_eq(expected, s21_result);
  if (s21_result) free(s21_result);
}
END_TEST

START_TEST(test_trim_3) {
  const char *str = "123212321232123212321";
  const char *trim_chars = "12";
  char expected[] = "32123212321232123";
  char *s21_result = s21_trim(str, trim_chars);
  ck_assert_str_eq(expected, s21_result);
  if (s21_result) free(s21_result);
}
END_TEST

START_TEST(test_trim_str_null) {
  const char *trim_chars = "abc";
  char *s21_result = s21_trim(NULL, trim_chars);
  ck_assert_ptr_eq(s21_result, NULL);
  if (s21_result) free(s21_result);
}
END_TEST

START_TEST(test_trim_chars_null) {
  const char *str = "Hello world";
  char *s21_result = s21_trim(str, NULL);
  ck_assert_ptr_eq(s21_result, NULL);
  if (s21_result) free(s21_result);
}
END_TEST

START_TEST(test_trim_empty_string) {
  const char *str = "";
  const char *trim_chars = " ";
  char expected[] = "";
  char *s21_result = s21_trim(str, trim_chars);

  ck_assert_str_eq(expected, s21_result);
  if (s21_result) free(s21_result);
}
END_TEST

START_TEST(test_trim_no_trim_chars_found) {
  const char *str = "Hello world";
  const char *trim_chars = "xyz";
  char expected[] = "Hello world";
  char *s21_result = s21_trim(str, trim_chars);

  ck_assert_str_eq(expected, s21_result);
  if (s21_result) free(s21_result);
}
END_TEST

START_TEST(test_trim_all_chars_to_trim) {
  const char *str = "-----Hello world------";
  const char *trim_chars = "-";
  char expected[] = "Hello world";
  char *s21_result = s21_trim(str, trim_chars);

  ck_assert_str_eq(expected, s21_result);
  if (s21_result) free(s21_result);
}
END_TEST

START_TEST(test_trim_only_trim_chars) {
  const char *str = "xxxxx";
  const char *trim_chars = "x";
  char expected[] = "";
  char *s21_result = s21_trim(str, trim_chars);

  ck_assert_str_eq(expected, s21_result);
  if (s21_result) free(s21_result);
}
END_TEST

START_TEST(test_trim_non_printable_chars) {
  const char *str = "\t\n Hello world \t\n";
  const char *trim_chars = "\t\n ";
  char expected[] = "Hello world";
  char *s21_result = s21_trim(str, trim_chars);

  ck_assert_str_eq(expected, s21_result);
  if (s21_result) free(s21_result);
}
END_TEST

TCase *trim_get_tests(void) {
  TCase *test_cases = tcase_create("test_cases");

  tcase_add_test(test_cases, test_trim_1);
  tcase_add_test(test_cases, test_trim_2);
  tcase_add_test(test_cases, test_trim_3);
  tcase_add_test(test_cases, test_trim_str_null);
  tcase_add_test(test_cases, test_trim_chars_null);
  tcase_add_test(test_cases, test_trim_empty_string);
  tcase_add_test(test_cases, test_trim_no_trim_chars_found);
  tcase_add_test(test_cases, test_trim_all_chars_to_trim);
  tcase_add_test(test_cases, test_trim_only_trim_chars);
  tcase_add_test(test_cases, test_trim_non_printable_chars);

  return test_cases;
}

#include <check.h>
#include <limits.h>

#include "../s21_string.h"

#if defined(__APPLE__) || defined(__MACH__)
#define S21_ERRCOUNT_SIZE 107
#endif

#if defined(__linux__)
#define S21_ERRCOUNT_SIZE 134
#endif

START_TEST(test_1) {
  int err_num = 0;

  char* s21_error = s21_strerror(err_num);
  char* default_error = strerror(err_num);

  ck_assert_pstr_eq(s21_error, default_error);

  if (s21_error) free(s21_error);
}
END_TEST

START_TEST(test_2) {
  int err_num = 15;

  char* s21_error = s21_strerror(err_num);
  char* default_error = strerror(err_num);

  ck_assert_pstr_eq(s21_error, default_error);

  if (s21_error) free(s21_error);
}
END_TEST

START_TEST(test_3) {
  int err_num = 100;

  char* s21_error = s21_strerror(err_num);
  char* default_error = strerror(err_num);

  ck_assert_pstr_eq(s21_error, default_error);

  if (s21_error) free(s21_error);
}
END_TEST

START_TEST(test_4) {
  int err_num = 1000;

  char* s21_error = s21_strerror(err_num);
  char* default_error = strerror(err_num);

  ck_assert_pstr_eq(s21_error, default_error);

  if (s21_error) free(s21_error);
}
END_TEST

START_TEST(test_5) {
  int err_num = -1;

  char* s21_error = s21_strerror(err_num);
  char* default_error = strerror(err_num);

  ck_assert_pstr_eq(s21_error, default_error);

  if (s21_error) free(s21_error);
}
END_TEST

START_TEST(test_6) {
  int err_num = -100;

  char* s21_error = s21_strerror(err_num);
  char* default_error = strerror(err_num);

  ck_assert_pstr_eq(s21_error, default_error);

  if (s21_error) free(s21_error);
}
END_TEST

START_TEST(test_7) {
  int err_num = 106;

  char* s21_error = s21_strerror(err_num);
  char* default_error = strerror(err_num);

  ck_assert_pstr_eq(s21_error, default_error);

  if (s21_error) free(s21_error);
}
END_TEST

START_TEST(test_8) {
  int err_num = 133;

  char* s21_error = s21_strerror(err_num);
  char* default_error = strerror(err_num);

  ck_assert_pstr_eq(s21_error, default_error);

  if (s21_error) free(s21_error);
}
END_TEST

TCase* strerror_get_tests(void) {
  TCase* test_cases = tcase_create("test_cases");

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
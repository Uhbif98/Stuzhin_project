#include <check.h>
#include <limits.h>

#include "../s21_string.h"

START_TEST(test_1) {
  char* test_first = "Ba";
  char* test_second = "BB";
  s21_size_t n = 2;

  int res1 = s21_strncmp(test_first, test_second, n);
  int res2 = strncmp(test_first, test_second, n);

  if (res1 != 0) {
    res1 = res1 < 0 ? -1 : 1;
  }
  if (res2 != 0) {
    res2 = res2 < 0 ? -1 : 1;
  }

  ck_assert_int_eq(res1, res2);
}
END_TEST

START_TEST(test_2) {
  char* test_first = "Ea@";
  char* test_second = "Ea";
  s21_size_t n = 2;

  int res1 = s21_strncmp(test_first, test_second, n);
  int res2 = strncmp(test_first, test_second, n);

  res1 = res1 == 0 ? 0 : (res1 < 0 ? -1 : 1);
  res2 = res2 == 0 ? 0 : (res2 < 0 ? -1 : 1);

  ck_assert_int_eq(res1, res2);
}
END_TEST

START_TEST(test_3) {
  char* test_first = "^fsdff";
  char* test_second = "fs";
  s21_size_t n = 3;

  int res1 = s21_strncmp(test_first, test_second, n);
  int res2 = strncmp(test_first, test_second, n);

  res1 = res1 == 0 ? 0 : (res1 < 0 ? -1 : 1);
  res2 = res2 == 0 ? 0 : (res2 < 0 ? -1 : 1);

  ck_assert_int_eq(res1, res2);
}
END_TEST

START_TEST(test_4) {
  char* test_first = "\0 Bae";
  char* test_second = "\0";
  s21_size_t n = 1;

  int res1 = s21_strncmp(test_first, test_second, n);
  int res2 = strncmp(test_first, test_second, n);

  res1 = res1 == 0 ? 0 : (res1 < 0 ? -1 : 1);
  res2 = res2 == 0 ? 0 : (res2 < 0 ? -1 : 1);

  ck_assert_int_eq(res1, res2);
}
END_TEST

START_TEST(test_5) {
  char* test_first = "\n \n \"fsdf\"";
  char* test_second = "fs";
  s21_size_t n = 5;

  int res1 = s21_strncmp(test_first, test_second, n);
  int res2 = strncmp(test_first, test_second, n);

  res1 = res1 == 0 ? 0 : (res1 < 0 ? -1 : 1);
  res2 = res2 == 0 ? 0 : (res2 < 0 ? -1 : 1);

  ck_assert_int_eq(res1, res2);
}
END_TEST

START_TEST(test_6) {
  char* test_first = "000012345";
  char* test_second = "AbC";
  s21_size_t n = 4;

  int res1 = s21_strncmp(test_first, test_second, n);
  int res2 = strncmp(test_first, test_second, n);

  res1 = res1 == 0 ? 0 : (res1 < 0 ? -1 : 1);
  res2 = res2 == 0 ? 0 : (res2 < 0 ? -1 : 1);

  ck_assert_int_eq(res1, res2);
}
END_TEST

START_TEST(test_7) {
  char* test_first = "fs";
  char* test_second = "223523rsr";
  s21_size_t n = 3;

  int res1 = s21_strncmp(test_first, test_second, n);
  int res2 = strncmp(test_first, test_second, n);

  res1 = res1 == 0 ? 0 : (res1 < 0 ? -1 : 1);
  res2 = res2 == 0 ? 0 : (res2 < 0 ? -1 : 1);

  ck_assert_int_eq(res1, res2);
}
END_TEST

START_TEST(test_8) {
  char* test_first = "^I ^M";
  char* test_second = "\n \t";
  s21_size_t n = 4;

  int res1 = s21_strncmp(test_first, test_second, n);
  int res2 = strncmp(test_first, test_second, n);

  res1 = res1 == 0 ? 0 : (res1 < 0 ? -1 : 1);
  res2 = res2 == 0 ? 0 : (res2 < 0 ? -1 : 1);

  ck_assert_int_eq(res1, res2);
}
END_TEST

START_TEST(test_9) {
  char* test_first = "^I ^M";
  char* test_second = "\0";
  s21_size_t n = 2;

  int res1 = s21_strncmp(test_first, test_second, n);
  int res2 = strncmp(test_first, test_second, n);

  res1 = res1 == 0 ? 0 : (res1 < 0 ? -1 : 1);
  res2 = res2 == 0 ? 0 : (res2 < 0 ? -1 : 1);

  ck_assert_int_eq(res1, res2);
}
END_TEST

START_TEST(test_10) {
  char* test_first = "        ";
  char* test_second = "Hello";
  s21_size_t n = 5;

  int res1 = s21_strncmp(test_first, test_second, n);
  int res2 = strncmp(test_first, test_second, n);

  res1 = res1 == 0 ? 0 : (res1 < 0 ? -1 : 1);
  res2 = res2 == 0 ? 0 : (res2 < 0 ? -1 : 1);

  ck_assert_int_eq(res1, res2);
}

TCase* strncmp_get_tests(void) {
  TCase* test_cases = tcase_create("tset_strncmp");

  tcase_add_test(test_cases, test_1);
  tcase_add_test(test_cases, test_2);
  tcase_add_test(test_cases, test_3);
  tcase_add_test(test_cases, test_4);
  tcase_add_test(test_cases, test_5);
  tcase_add_test(test_cases, test_6);
  tcase_add_test(test_cases, test_7);
  tcase_add_test(test_cases, test_8);
  tcase_add_test(test_cases, test_9);
  tcase_add_test(test_cases, test_10);

  return test_cases;
}
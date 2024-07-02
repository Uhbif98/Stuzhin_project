#include <check.h>
#include <limits.h>

#include "../s21_string.h"

START_TEST(test_1) {
  const void* str = "a333b1C2d3e!Ace";
  const void* str2 = "3jgij3aw3g0";
  s21_size_t n = strlen(str2);

  ck_assert_int_eq(memcmp(str, str2, n), s21_memcmp(str, str2, n));
}
END_TEST

START_TEST(test_2) {
  const void* str = "a333b1C2d3e!Ace";
  const void* str2 = "a333b1C2d3e";
  s21_size_t n = strlen(str2);

  ck_assert_int_eq(memcmp(str, str2, n), s21_memcmp(str, str2, n));
}
END_TEST

START_TEST(test_3) {
  const void* str = "a333b1C2d3e!Ace";
  const void* str2 = "a333b1C2d3e";
  s21_size_t n = strlen(str2);

  ck_assert_int_eq(memcmp(str, str2, n), s21_memcmp(str, str2, n));
}
END_TEST

START_TEST(test_4) {
  const void* str = "Hello";
  const void* str2 = "";
  s21_size_t n = strlen(str2);

  ck_assert_int_eq(memcmp(str, str2, n), s21_memcmp(str, str2, n));
}
END_TEST

START_TEST(test_5) {
  const void* str = "He\n llo";
  const void* str2 = "Hello";
  s21_size_t n = strlen(str2);

  ck_assert_int_eq(memcmp(str, str2, n), s21_memcmp(str, str2, n));
}
END_TEST

START_TEST(test_6) {
  const void* str = "^I \t";
  const void* str2 = "^I";
  s21_size_t n = strlen(str2);

  ck_assert_int_eq(memcmp(str, str2, n), s21_memcmp(str, str2, n));
}
END_TEST

START_TEST(test_7) {
  const void* str = "";
  const void* str2 = "bb";
  s21_size_t n = strlen(str);

  ck_assert_int_eq(memcmp(str, str2, n), s21_memcmp(str, str2, n));
}
END_TEST

START_TEST(test_8) {
  const void* str = "";
  const void* str2 = "";
  s21_size_t n = strlen(str2);

  ck_assert_int_eq(memcmp(str, str2, n), s21_memcmp(str, str2, n));
}
END_TEST

START_TEST(test_9) {
  const void* str = "\0 dd";
  const void* str2 = "dd";
  s21_size_t n = strlen(str2);

  ck_assert_int_eq(memcmp(str, str2, n), s21_memcmp(str, str2, n));
}
END_TEST

START_TEST(test_10) {
  const void* str = "\n";
  const void* str2 = "";
  s21_size_t n = strlen(str2);

  ck_assert_int_eq(memcmp(str, str2, n), s21_memcmp(str, str2, n));
}
END_TEST

TCase* memcmp_get_tests(void) {
  TCase* test_cases = tcase_create("test_cases");

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
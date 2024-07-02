#include <check.h>
#include <limits.h>

#include "../s21_string.h"

START_TEST(test_1) {
  const void* str = "a333b1C2d3e!Ace";
  int find_char = 'C';
  s21_size_t n = 15;

  ck_assert_ptr_eq(memchr(str, find_char, n), s21_memchr(str, find_char, n));
}
END_TEST

START_TEST(test_2) {
  const void* str = "a333b1C2d3e!Ace";
  int find_char = '5';
  s21_size_t n = 3;

  ck_assert_ptr_eq(memchr(str, find_char, n), s21_memchr(str, find_char, n));
}
END_TEST

START_TEST(test_3) {
  const void* str = "a333b1C2d3e!Ace";
  int find_char = 'a';
  s21_size_t n = 0;

  ck_assert_ptr_eq(memchr(str, find_char, n), s21_memchr(str, find_char, n));
}
END_TEST

START_TEST(test_4) {
  const void* str = "\0g50!";
  int find_char = '5';
  s21_size_t n = 3;

  ck_assert_ptr_eq(memchr(str, find_char, n), s21_memchr(str, find_char, n));
}
END_TEST

START_TEST(test_5) {
  const void* str = " g5 0!_^I";
  int find_char = '^';
  s21_size_t n = 9;

  ck_assert_ptr_eq(memchr(str, find_char, n), s21_memchr(str, find_char, n));
}
END_TEST

START_TEST(test_6) {
  const void* str = "ae! 43 \0 @";
  int find_char = '@';
  s21_size_t n = 10;

  ck_assert_ptr_eq(memchr(str, find_char, n), s21_memchr(str, find_char, n));
}
END_TEST

START_TEST(test_7) {
  const void* str = "Hello \n World";
  int find_char = 'W';
  s21_size_t n = 13;

  ck_assert_ptr_eq(memchr(str, find_char, n), s21_memchr(str, find_char, n));
}
END_TEST

START_TEST(test_8) {
  const void* str = "Hello \n World";
  int find_char = '\n';
  s21_size_t n = 13;

  ck_assert_ptr_eq(memchr(str, find_char, n), s21_memchr(str, find_char, n));
}
END_TEST

START_TEST(test_9) {
  const void* str = "\tHello World\0\n";
  int find_char = '\t';
  s21_size_t n = 14;

  ck_assert_ptr_eq(memchr(str, find_char, n), s21_memchr(str, find_char, n));
}
END_TEST

START_TEST(test_10) {
  const void* str = "Hello world\0";
  int find_char = '\0';
  s21_size_t n = 12;

  ck_assert_ptr_eq(memchr(str, find_char, n), s21_memchr(str, find_char, n));
}
END_TEST

TCase* memchr_get_tests(void) {
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
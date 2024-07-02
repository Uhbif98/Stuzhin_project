#include <check.h>
#include <limits.h>

#include "../s21_string.h"

START_TEST(symb_in_str_test_1) {
  const void* str = "Hello world";
  const void* find_str = "wd";
  char* res_expected = strpbrk(str, find_str);
  char* res_s21_func = s21_strpbrk(str, find_str);
  ck_assert_ptr_eq(res_expected, res_s21_func);
}
END_TEST

START_TEST(symb_in_str_test_2) {
  const void* str = "Hello world";
  const void* find_str = "wdH";
  char* res_expected = strpbrk(str, find_str);
  char* res_s21_func = s21_strpbrk(str, find_str);
  ck_assert_ptr_eq(res_expected, res_s21_func);
}
END_TEST

START_TEST(symb_in_str_test_3) {
  const void* str = "Hello\0 world";
  const void* find_str = "wd";
  char* res_expected = strpbrk(str, find_str);
  char* res_s21_func = s21_strpbrk(str, find_str);
  ck_assert_ptr_eq(res_expected, res_s21_func);
}
END_TEST

START_TEST(symb_in_str_test_4) {
  const void* str = "Hello\n world";
  const void* find_str = "abcd";
  char* res_expected = strpbrk(str, find_str);
  char* res_s21_func = s21_strpbrk(str, find_str);
  ck_assert_ptr_eq(res_expected, res_s21_func);
}
END_TEST

START_TEST(no_symb_in_str_test_1) {
  const void* str = "Hello\0 world";
  const void* find_str = "abc123";
  char* res_expected = strpbrk(str, find_str);
  char* res_s21_func = s21_strpbrk(str, find_str);
  ck_assert_ptr_eq(res_expected, res_s21_func);
}
END_TEST

START_TEST(no_symb_in_empty_str_test_1) {
  const void* str = "";
  const void* find_str = "abc123";
  char* res_expected = strpbrk(str, find_str);
  char* res_s21_func = s21_strpbrk(str, find_str);
  ck_assert_ptr_eq(res_expected, res_s21_func);
}
END_TEST

START_TEST(no_symb_in_empty_str_test_2) {
  const void* str = "\0";
  const void* find_str = "abc123";
  char* res_expected = strpbrk(str, find_str);
  char* res_s21_func = s21_strpbrk(str, find_str);
  ck_assert_ptr_eq(res_expected, res_s21_func);
}
END_TEST

START_TEST(empty_symb_in_empty_str_test_1) {
  const void* str = "";
  const void* find_str = "";
  char* res_expected = strpbrk(str, find_str);
  char* res_s21_func = s21_strpbrk(str, find_str);
  ck_assert_ptr_eq(res_expected, res_s21_func);
}
END_TEST

START_TEST(empty_symb_in_str_test_1) {
  const void* str = "Hello\t world";
  const void* find_str = "";
  char* res_expected = strpbrk(str, find_str);
  char* res_s21_func = s21_strpbrk(str, find_str);
  ck_assert_ptr_eq(res_expected, res_s21_func);
}
END_TEST

START_TEST(nonprintable_symb_in_str_test_1) {
  const void* str = "Hello\t\x03\x04\x05 world\n";
  const void* find_str = "\t\n\x04";
  char* res_expected = strpbrk(str, find_str);
  char* res_s21_func = s21_strpbrk(str, find_str);
  ck_assert_ptr_eq(res_expected, res_s21_func);
}
END_TEST

START_TEST(nonprintable_symb_in_str_test_2) {
  const void* str = "Hello\t\x03\x04\x05 world\n";
  const void* find_str = "\x04\x05";
  char* res_expected = strpbrk(str, find_str);
  char* res_s21_func = s21_strpbrk(str, find_str);
  ck_assert_ptr_eq(res_expected, res_s21_func);
}
END_TEST

TCase* strbprk_get_tests(void) {
  TCase* test_cases = tcase_create("test_cases");

  tcase_add_test(test_cases, symb_in_str_test_1);
  tcase_add_test(test_cases, symb_in_str_test_2);
  tcase_add_test(test_cases, symb_in_str_test_3);
  tcase_add_test(test_cases, symb_in_str_test_4);
  tcase_add_test(test_cases, no_symb_in_str_test_1);
  tcase_add_test(test_cases, no_symb_in_empty_str_test_1);
  tcase_add_test(test_cases, no_symb_in_empty_str_test_2);
  tcase_add_test(test_cases, empty_symb_in_empty_str_test_1);
  tcase_add_test(test_cases, empty_symb_in_str_test_1);
  tcase_add_test(test_cases, nonprintable_symb_in_str_test_1);
  tcase_add_test(test_cases, nonprintable_symb_in_str_test_2);

  return test_cases;
}
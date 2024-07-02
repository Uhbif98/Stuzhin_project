#include <check.h>
#include <limits.h>

#include "../s21_string.h"

START_TEST(zero_len) {
  const void* str = "";
  ck_assert_int_eq(strlen(str), s21_strlen(str));
}
END_TEST

START_TEST(zero_len_srats_with_end_string) {
  const void* str = "\0Hello125\t\nWorld";
  ck_assert_int_eq(strlen(str), s21_strlen(str));
}
END_TEST

START_TEST(len_test_with_slash) {
  const void* str = "Hello125\t\nWorld";
  ck_assert_int_eq(strlen(str), s21_strlen(str));
}
END_TEST

START_TEST(len_non_printable_symbols) {
  const void* str = "\x03\x04\x05";
  ck_assert_int_eq(strlen(str), s21_strlen(str));
}
END_TEST

START_TEST(len_end_sting_in_middle) {
  const void* str = "Hello125\t\0World";
  ck_assert_int_eq(strlen(str), s21_strlen(str));
}
END_TEST

START_TEST(len_end_sting_in_end) {
  const void* str = "Hello125\tWorld\0";
  ck_assert_int_eq(strlen(str), s21_strlen(str));
}
END_TEST

START_TEST(len_mass_0_in_middle) {
  const char str[] = {'H', 'e', 'l', 'l', 'o', '\0', ' ',
                      'W', 'o', 'r', 'l', 'd', '!'};
  ck_assert_int_eq(strlen(str), s21_strlen(str));
}
END_TEST

START_TEST(len_mass_starts_0) {
  const char str[] = {'\0', 'H', 'e', 'l', 'l', 'o', ' ',
                      'W',  'o', 'r', 'l', 'd', '!'};
  ck_assert_int_eq(strlen(str), s21_strlen(str));
}
END_TEST

START_TEST(len_mass_ends_0) {
  const char str[] = {'H', 'e', 'l', 'l', 'o', ' ', 'W',
                      'o', 'r', 'l', 'd', '!', '\0'};
  ck_assert_int_eq(strlen(str), s21_strlen(str));
}
END_TEST

START_TEST(len_one_space) {
  const void* str = " ";
  ck_assert_int_eq(strlen(str), s21_strlen(str));
}
END_TEST

TCase* strlen_get_tests(void) {
  TCase* test_cases = tcase_create("test_cases");

  tcase_add_test(test_cases, zero_len);
  tcase_add_test(test_cases, zero_len_srats_with_end_string);
  tcase_add_test(test_cases, len_test_with_slash);
  tcase_add_test(test_cases, len_non_printable_symbols);
  tcase_add_test(test_cases, len_end_sting_in_middle);
  tcase_add_test(test_cases, len_end_sting_in_end);
  tcase_add_test(test_cases, len_mass_0_in_middle);
  tcase_add_test(test_cases, len_mass_starts_0);
  tcase_add_test(test_cases, len_mass_ends_0);
  tcase_add_test(test_cases, len_one_space);

  return test_cases;
}
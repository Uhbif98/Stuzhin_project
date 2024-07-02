#include <check.h>
#include <ctype.h>
#include <limits.h>

#include "../s21_string.h"

START_TEST(test_to_upper_1) {
  const char *str = "hello world";
  char *s21_result = s21_to_upper(str);
  char *original_copy = malloc(strlen(str) + 1);
  if (original_copy) {
    for (size_t i = 0; i < strlen(str); i++) {
      original_copy[i] = toupper((unsigned char)str[i]);
    }
    original_copy[strlen(str)] = '\0';
  }
  ck_assert_str_eq(original_copy, s21_result);
  if (s21_result) free(s21_result);
  if (original_copy) free(original_copy);
}
END_TEST

START_TEST(test_to_upper_2) {
  const char *str = "hello\0 world";
  char *s21_result = s21_to_upper(str);
  char *original_copy = malloc(strlen(str) + 1);
  if (original_copy) {
    for (size_t i = 0; i < strlen(str); i++) {
      original_copy[i] = toupper((unsigned char)str[i]);
    }
    original_copy[strlen(str)] = '\0';
  }
  ck_assert_str_eq(original_copy, s21_result);
  if (s21_result) free(s21_result);
  if (original_copy) free(original_copy);
}
END_TEST

START_TEST(test_to_upper_3) {
  const char *str = "HELLO WORLD";
  char *s21_result = s21_to_upper(str);
  char *original_copy = malloc(strlen(str) + 1);
  if (original_copy) {
    for (size_t i = 0; i < strlen(str); i++) {
      original_copy[i] = toupper((unsigned char)str[i]);
    }
    original_copy[strlen(str)] = '\0';
  }
  ck_assert_str_eq(original_copy, s21_result);
  if (s21_result) free(s21_result);
  if (original_copy) free(original_copy);
}
END_TEST

START_TEST(test_to_upper_russian_syms) {
  const char *str = "абвгдеЁЖ";
  char *s21_result = s21_to_upper(str);
  char *original_copy = malloc(strlen(str) + 1);
  if (original_copy) {
    for (size_t i = 0; i < strlen(str); i++) {
      original_copy[i] = toupper((unsigned char)str[i]);
    }
    original_copy[strlen(str)] = '\0';
  }
  ck_assert_str_eq(original_copy, s21_result);
  if (s21_result) free(s21_result);
  if (original_copy) free(original_copy);
}
END_TEST

START_TEST(test_to_upper_only_spaces) {
  const char *str = "   ";
  char *s21_result = s21_to_upper(str);
  char *original_copy = malloc(strlen(str) + 1);
  if (original_copy) {
    for (size_t i = 0; i < strlen(str); i++) {
      original_copy[i] = toupper((unsigned char)str[i]);
    }
    original_copy[strlen(str)] = '\0';
  }
  ck_assert_str_eq(original_copy, s21_result);
  if (s21_result) free(s21_result);
  if (original_copy) free(original_copy);
}
END_TEST

START_TEST(test_to_upper_with_tab) {
  const char *str = "hello\t\t world\n";
  char *s21_result = s21_to_upper(str);
  char *original_copy = malloc(strlen(str) + 1);
  if (original_copy) {
    for (size_t i = 0; i < strlen(str); i++) {
      original_copy[i] = toupper((unsigned char)str[i]);
    }
    original_copy[strlen(str)] = '\0';
  }
  ck_assert_str_eq(original_copy, s21_result);
  if (s21_result) free(s21_result);
  if (original_copy) free(original_copy);
}
END_TEST

START_TEST(test_to_upper_with_non_printable_syms) {
  const char *str = "hello\x03\x04\x05 world\n";
  char *s21_result = s21_to_upper(str);
  char *original_copy = malloc(strlen(str) + 1);
  if (original_copy) {
    for (size_t i = 0; i < strlen(str); i++) {
      original_copy[i] = toupper((unsigned char)str[i]);
    }
    original_copy[strlen(str)] = '\0';
  }
  ck_assert_str_eq(original_copy, s21_result);
  if (s21_result) free(s21_result);
  if (original_copy) free(original_copy);
}
END_TEST

START_TEST(test_to_upper_non_alpha) {
  const char *str = "12345!@#$%";
  char *s21_result = s21_to_upper(str);
  char *original_copy = malloc(strlen(str) + 1);
  if (original_copy) {
    for (size_t i = 0; i < strlen(str); i++) {
      original_copy[i] = toupper((unsigned char)str[i]);
    }
    original_copy[strlen(str)] = '\0';
  }
  ck_assert_str_eq(original_copy, s21_result);
  if (s21_result) free(s21_result);
  if (original_copy) free(original_copy);
}
END_TEST

START_TEST(test_to_upper_empty_str) {
  const char *str = "";
  char *s21_result = s21_to_upper(str);
  char *original_copy = malloc(strlen(str) + 1);
  if (original_copy) {
    original_copy[strlen(str)] = '\0';
  }
  ck_assert_str_eq(original_copy, s21_result);
  if (s21_result) free(s21_result);
  if (original_copy) free(original_copy);
}
END_TEST

START_TEST(test_to_upper_null) {
  char *s21_result = s21_to_upper(NULL);
  ck_assert_ptr_eq(s21_result, NULL);
  if (s21_result) free(s21_result);
}
END_TEST

START_TEST(test_to_upper_long_string) {
  char long_string[10000];
  memset(long_string, 'a', sizeof(long_string) - 1);
  long_string[sizeof(long_string) - 1] = '\0';
  char *s21_result = s21_to_upper(long_string);

  char expected_result[10000];
  memset(expected_result, 'A', sizeof(expected_result) - 1);
  expected_result[sizeof(expected_result) - 1] = '\0';

  ck_assert_msg(strcmp(s21_result, expected_result) == 0,
                "The to_upper function did not convert the string correctly.");

  free(s21_result);
}
END_TEST

TCase *to_upper_get_tests(void) {
  TCase *test_cases = tcase_create("test_cases");

  tcase_add_test(test_cases, test_to_upper_1);
  tcase_add_test(test_cases, test_to_upper_2);
  tcase_add_test(test_cases, test_to_upper_3);
  tcase_add_test(test_cases, test_to_upper_russian_syms);
  tcase_add_test(test_cases, test_to_upper_only_spaces);
  tcase_add_test(test_cases, test_to_upper_with_tab);
  tcase_add_test(test_cases, test_to_upper_non_alpha);
  tcase_add_test(test_cases, test_to_upper_empty_str);
  tcase_add_test(test_cases, test_to_upper_null);
  tcase_add_test(test_cases, test_to_upper_with_non_printable_syms);
  tcase_add_test(test_cases, test_to_upper_long_string);

  return test_cases;
}

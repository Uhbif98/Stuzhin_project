#include <check.h>
#include <ctype.h>
#include <limits.h>

#include "../s21_string.h"

START_TEST(test_to_lower_1) {
  const char *str = "HELLO WORLD";
  char *s21_result = s21_to_lower(str);
  char *original_copy = malloc(strlen(str) + 1);

  if (original_copy) {
    for (size_t i = 0; i < strlen(str); i++) {
      original_copy[i] = tolower((unsigned char)str[i]);
    }
    original_copy[strlen(str)] = '\0';
  }
  ck_assert_str_eq(original_copy, s21_result);
  if (s21_result) free(s21_result);
  if (original_copy) free(original_copy);
}
END_TEST

START_TEST(test_to_lower_2) {
  const char *str = "HELLO\0 WORLD";
  char *s21_result = s21_to_lower(str);
  // char *original_copy = strdup(str);
  // for (size_t i = 0; i < strlen(original_copy); i++) {
  //   original_copy[i] = tolower(original_copy[i]);
  // }
  char *original_copy = malloc(strlen(str) + 1);
  if (original_copy) {
    for (size_t i = 0; i < strlen(str); i++) {
      original_copy[i] = tolower((unsigned char)str[i]);
    }
    original_copy[strlen(str)] = '\0';
  }
  ck_assert_str_eq(original_copy, s21_result);
  if (s21_result) free(s21_result);
  if (original_copy) free(original_copy);
}
END_TEST

START_TEST(test_to_lower_3) {
  const char *str = "HELLO WORLD";
  char *s21_result = s21_to_lower(str);
  char *original_copy = malloc(strlen(str) + 1);
  if (original_copy) {
    for (size_t i = 0; i < strlen(str); i++) {
      original_copy[i] = tolower((unsigned char)str[i]);
    }
    original_copy[strlen(str)] = '\0';
  }
  ck_assert_str_eq(original_copy, s21_result);
  if (s21_result) free(s21_result);
  if (original_copy) free(original_copy);
}
END_TEST

START_TEST(test_to_lower_russian_syms) {
  const char *str = "АБВГдеЁЖ";
  char *s21_result = s21_to_lower(str);
  char *original_copy = malloc(strlen(str) + 1);
  if (original_copy) {
    for (size_t i = 0; i < strlen(str); i++) {
      original_copy[i] = tolower((unsigned char)str[i]);
    }
    original_copy[strlen(str)] = '\0';
  }
  ck_assert_str_eq(original_copy, s21_result);
  if (s21_result) free(s21_result);
  if (original_copy) free(original_copy);
}
END_TEST

START_TEST(test_to_lower_only_spaces) {
  const char *str = "   ";
  char *s21_result = s21_to_lower(str);
  char *original_copy = malloc(strlen(str) + 1);
  if (original_copy) {
    for (size_t i = 0; i < strlen(str); i++) {
      original_copy[i] = tolower((unsigned char)str[i]);
    }
    original_copy[strlen(str)] = '\0';
  }
  ck_assert_str_eq(original_copy, s21_result);
  if (s21_result) free(s21_result);
  if (original_copy) free(original_copy);
}
END_TEST

START_TEST(test_to_lower_with_tab) {
  const char *str = "HELLO\t\t WORLD\n";
  char *s21_result = s21_to_lower(str);
  char *original_copy = malloc(strlen(str) + 1);
  if (original_copy) {
    for (size_t i = 0; i < strlen(str); i++) {
      original_copy[i] = tolower((unsigned char)str[i]);
    }
    original_copy[strlen(str)] = '\0';
  }
  ck_assert_str_eq(original_copy, s21_result);
  if (s21_result) free(s21_result);
  if (original_copy) free(original_copy);
}
END_TEST

START_TEST(test_to_lower_with_non_printable_syms) {
  const char *str = "HELLO\x03\x04\x05 WORLD\n";
  char *s21_result = s21_to_lower(str);
  char *original_copy = malloc(strlen(str) + 1);
  if (original_copy) {
    for (size_t i = 0; i < strlen(str); i++) {
      original_copy[i] = tolower((unsigned char)str[i]);
    }
    original_copy[strlen(str)] = '\0';
  }
  ck_assert_str_eq(original_copy, s21_result);
  if (s21_result) free(s21_result);
  if (original_copy) free(original_copy);
}
END_TEST

START_TEST(test_to_lower_non_alpha) {
  const char *str = "12345!@#$%";
  char *s21_result = s21_to_lower(str);
  char *original_copy = malloc(strlen(str) + 1);
  if (original_copy) {
    for (size_t i = 0; i < strlen(str); i++) {
      original_copy[i] = tolower((unsigned char)str[i]);
    }
    original_copy[strlen(str)] = '\0';
  }
  ck_assert_str_eq(original_copy, s21_result);
  if (s21_result) free(s21_result);
  if (original_copy) free(original_copy);
}
END_TEST

START_TEST(test_to_lower_empty_str) {
  const char *str = "";
  char *s21_result = s21_to_lower(str);
  char *original_copy = malloc(strlen(str) + 1);
  if (original_copy) {
    original_copy[strlen(str)] = '\0';
  }
  ck_assert_str_eq(original_copy, s21_result);
  if (s21_result) free(s21_result);
  if (original_copy) free(original_copy);
}
END_TEST

START_TEST(test_to_lower_null) {
  char *s21_result = s21_to_lower(NULL);
  ck_assert_ptr_eq(s21_result, NULL);
  if (s21_result) free(s21_result);
}
END_TEST

START_TEST(test_to_lower_long_string) {
  char long_string[10000];
  memset(long_string, 'A', sizeof(long_string) - 1);
  long_string[sizeof(long_string) - 1] = '\0';
  char *s21_result = s21_to_lower(long_string);

  char expected_result[10000];
  memset(expected_result, 'a', sizeof(expected_result) - 1);
  expected_result[sizeof(expected_result) - 1] = '\0';

  ck_assert_msg(strcmp(s21_result, expected_result) == 0,
                "The to_lower function did not convert the string correctly.");

  free(s21_result);
}
END_TEST

TCase *to_lower_get_tests(void) {
  TCase *test_cases = tcase_create("test_cases");

  tcase_add_test(test_cases, test_to_lower_1);
  tcase_add_test(test_cases, test_to_lower_2);
  tcase_add_test(test_cases, test_to_lower_3);
  tcase_add_test(test_cases, test_to_lower_russian_syms);
  tcase_add_test(test_cases, test_to_lower_only_spaces);
  tcase_add_test(test_cases, test_to_lower_with_tab);
  tcase_add_test(test_cases, test_to_lower_non_alpha);
  tcase_add_test(test_cases, test_to_lower_empty_str);
  tcase_add_test(test_cases, test_to_lower_null);
  tcase_add_test(test_cases, test_to_lower_with_non_printable_syms);
  tcase_add_test(test_cases, test_to_lower_long_string);

  return test_cases;
}

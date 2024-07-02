#include <check.h>
#include <limits.h>

#include "../s21_string.h"

START_TEST(test_1) {
  char str[100] = "AaBbCc1234@^!";
  char str2[100] = "AaBbCc1234@^!";

  ck_assert_str_eq(s21_memset(str, '2', 2), memset(str2, '2', 2));
}
END_TEST

START_TEST(test_2) {
  char str[100] = "Aa$BbCc1234@^!";
  char str2[100] = "Aa$BbCc1234@^!";

  ck_assert_str_eq(s21_memset(str, '$', 4), memset(str2, '$', 4));
}
END_TEST

START_TEST(test_3) {
  char str[100] = "AaBbCc\0 1234@^!";
  char str2[100] = "AaBbCc\0 1234@^!";

  ck_assert_str_eq(s21_memset(str, '\0', 2), memset(str2, '\0', 2));
}
END_TEST

START_TEST(test_4) {
  char str[100] = "AaBbCc1234@^!";
  char str2[100] = "AaBbCc1234@^!";

  ck_assert_str_eq(s21_memset(str, '@', 1), memset(str2, '@', 1));
}
END_TEST

START_TEST(test_5) {
  char str[100] = "AaBbCc \n 1234@^!";
  char str2[100] = "AaBbCc \n 1234@^!";

  ck_assert_str_eq(s21_memset(str, '\n', 2), memset(str2, '\n', 2));
}
END_TEST

START_TEST(test_6) {
  char str[100] = "AaBbCc 1234@^!";
  char str2[100] = "AaBbCc 1234@^!";

  ck_assert_str_eq(s21_memset(str, ' ', 3), memset(str2, ' ', 3));
}
END_TEST

START_TEST(test_7) {
  char str[100] = "AaBb \t Cc1234@^!";
  char str2[100] = "AaBb \t Cc1234@^!";

  ck_assert_str_eq(s21_memset(str, 'C', 1), memset(str2, 'C', 1));
}
END_TEST

START_TEST(test_8) {
  char str[100] = "AaBbCc\n -_- \n 1234@^!";
  char str2[100] = "AaBbCc\n -_- \n 1234@^!";

  ck_assert_str_eq(s21_memset(str, '^', 2), memset(str2, '^', 2));
}
END_TEST

START_TEST(test_9) {
  char str[100] = "AaBbC \0 c1234@^!";
  char str2[100] = "AaBbC \0 c1234@^!";

  ck_assert_str_eq(s21_memset(str, '!', 5), memset(str2, '!', 5));
}
END_TEST

START_TEST(test_10) {
  char str[100] = "AaBbCc1234@^!";
  char str2[100] = "AaBbCc1234@^!";

  ck_assert_str_eq(s21_memset(str, str[2], 13), memset(str2, str2[2], 13));
}
END_TEST

TCase* memset_get_tests(void) {
  TCase* test_cases = tcase_create("test_memset");

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
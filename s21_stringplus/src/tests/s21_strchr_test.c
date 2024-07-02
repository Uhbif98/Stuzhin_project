#include <check.h>
#include <limits.h>

#include "../s21_string.h"

START_TEST(strchr_test1) {
  char *str = "Good Man";
  ck_assert_str_eq(strchr(str, 'a'), s21_strchr(str, 'a'));
}
END_TEST

START_TEST(strchr_test2) {
  char *str = "kjwOAdnbzqbEXMsakWaWIqW";
  ck_assert_str_eq(strchr(str, 'M'), s21_strchr(str, 'M'));
}
END_TEST

START_TEST(strchr_test3) {
  char *str = "Good Man";
  ck_assert_ptr_eq(strchr(str, ' '), s21_strchr(str, ' '));
}
END_TEST

START_TEST(strchr_test4) {
  char *str = "Good Man";
  ck_assert_ptr_eq(strchr(str, '\0'), s21_strchr(str, '\0'));
}
END_TEST

START_TEST(strchr_test5) {
  char *str = "Good \n Man";
  ck_assert_ptr_eq(strchr(str, '\n'), s21_strchr(str, '\n'));
}
END_TEST

START_TEST(strchr_test6) {
  char *str = "Что будет, если год не есть сахар?";
  ck_assert_ptr_eq(strchr(str, ','), s21_strchr(str, ','));
}
END_TEST

START_TEST(strchr_test7) {
  char *str = "Что будет, если год не есть сахар?";
  ck_assert_ptr_eq(strchr(str, '?'), s21_strchr(str, '?'));
}
END_TEST

START_TEST(strchr_test8) {
  char *str = "Что будет,\0 если год не есть сахар?";
  ck_assert_ptr_eq(strchr(str, '?'), s21_strchr(str, '?'));
}
END_TEST

START_TEST(strchr_test9) {
  char *str = "qw&\0?";
  ck_assert_ptr_eq(strchr(str, '?'), s21_strchr(str, '?'));
}
END_TEST

START_TEST(strchr_test10) {
  char *str = "\0";
  ck_assert_str_eq(strchr(str, '\0'), s21_strchr(str, '\0'));
}
END_TEST

START_TEST(strchr_test11) {
  char *str = "\0ew";
  ck_assert_ptr_eq(strchr(str, 'e'), s21_strchr(str, 'e'));
}
END_TEST

START_TEST(strchr_test12) {
  char *str =
      "Check is a simple and minimalistic unit \ttesting framework for C. It’s "
      "easy to learn and easy to install.";
  ck_assert_ptr_eq(strchr(str, '\t'), s21_strchr(str, '\t'));
}
END_TEST

START_TEST(strchr_test13) {
  char *str =
      "Check is a simple and minimalistic unit \ttesting framework for C. It’s "
      "easy to learn and easy to install.";
  ck_assert_str_eq(strchr(str, '\t'), s21_strchr(str, '\t'));
}
END_TEST

START_TEST(strchr_test14) {
  char *str =
      "Check is a simple and minimalistic unit \ttesting framework for C. It’s "
      "easy to learn and easy to install.";
  ck_assert_str_eq(strchr(str, '.'), s21_strchr(str, '.'));
}
END_TEST

START_TEST(strchr_test15) {
  char *str =
      "Check is a simple and minimalistic unit \ttesting framework for C. It’s "
      "easy to learn and easy to install.";
  ck_assert_ptr_eq(strchr(str, '.'), s21_strchr(str, '.'));
}
END_TEST

START_TEST(strchr_test16) {
  char *str =
      "Check is a simple and minimalistic unit \ttesting framework for C. It’s "
      "easy to learn and easy to install.";
  ck_assert_ptr_eq(strchr(str, 0), s21_strchr(str, 0));
}
END_TEST

START_TEST(strchr_test17) {
  char *str =
      "Check is a simple and minimalistic unit \ttesting framework for C. It’s "
      "easy to learn\n and easy to install.";
  ck_assert_ptr_eq(strchr(str, '\n'), s21_strchr(str, '\n'));
}
END_TEST

START_TEST(strchr_test18) {
  char *str =
      "Check is a simple and minimalistic unit \ttesting framework for C. It’s "
      "easy to learn\n and easy to install.";
  ck_assert_str_eq(strchr(str, '\n'), s21_strchr(str, '\n'));
}
END_TEST

START_TEST(strchr_test19) {
  char *str =
      "Check is a simple and minimalistic unit \ttesting framework for C. It’s "
      "easy to learn\n and easy to install.";
  ck_assert_ptr_eq(strchr(str, '\n'), s21_strchr(str, '\n'));
}
END_TEST

START_TEST(strchr_test20) {
  char *str =
      "Check is a simple and minimalistic unit \ttesting framework for C. It’s "
      "easy to learn\n and easy to install.";
  ck_assert_ptr_eq(strchr(str, '\n'), s21_strchr(str, '\n'));
}
END_TEST

START_TEST(strchr_test21) {
  char *str =
      "Check is a simple and minimalistic unit \ttesting framework for C. It’s "
      "easy to learn and easy to install.";
  ck_assert_ptr_eq(strchr(str, 255), s21_strchr(str, 255));
}
END_TEST

TCase *strchr_get_tests(void) {
  TCase *test = tcase_create("test_1");

  tcase_add_test(test, strchr_test1);
  tcase_add_test(test, strchr_test2);
  tcase_add_test(test, strchr_test3);
  tcase_add_test(test, strchr_test4);
  tcase_add_test(test, strchr_test5);
  tcase_add_test(test, strchr_test6);
  tcase_add_test(test, strchr_test7);
  tcase_add_test(test, strchr_test8);
  tcase_add_test(test, strchr_test9);
  tcase_add_test(test, strchr_test10);
  tcase_add_test(test, strchr_test11);
  tcase_add_test(test, strchr_test12);
  tcase_add_test(test, strchr_test13);
  tcase_add_test(test, strchr_test14);
  tcase_add_test(test, strchr_test15);
  tcase_add_test(test, strchr_test16);
  tcase_add_test(test, strchr_test17);
  tcase_add_test(test, strchr_test18);
  tcase_add_test(test, strchr_test19);
  tcase_add_test(test, strchr_test20);
  tcase_add_test(test, strchr_test21);

  return test;
}
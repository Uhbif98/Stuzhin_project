#include <check.h>
#include <limits.h>

#include "../s21_string.h"

START_TEST(strrchr_test1) {
  char *str = "Practise reading with your classmates in live group classes";
  ck_assert_str_eq(strrchr(str, 's'), s21_strrchr(str, 's'));
}
END_TEST

START_TEST(strrchr_test2) {
  char *str = "kjwOAdnbzqbEXMsakWaWIqw";
  ck_assert_str_eq(strrchr(str, 'w'), s21_strrchr(str, 'w'));
}
END_TEST

START_TEST(strrchr_test3) {
  char *str = "              ";
  ck_assert_ptr_eq(strrchr(str, ' '), s21_strrchr(str, ' '));
}
END_TEST

START_TEST(strrchr_test4) {
  char *str = "Good Man\0nnnnnnnnnn\0nnn";
  ck_assert_ptr_eq(strrchr(str, '\0'), s21_strrchr(str, '\0'));
}
END_TEST

START_TEST(strrchr_test5) {
  char *str = "Go\nod \n Man";
  ck_assert_ptr_eq(strrchr(str, '\n'), s21_strrchr(str, '\n'));
}
END_TEST

START_TEST(strrchr_test6) {
  char *str = "Что будет, если год не есть, сахар?";
  ck_assert_ptr_eq(strrchr(str, ','), s21_strrchr(str, ','));
}
END_TEST

START_TEST(strrchr_test7) {
  char *str = "Что будет, если год не есть сахар?";
  ck_assert_ptr_eq(strrchr(str, '?'), s21_strrchr(str, '?'));
}
END_TEST

START_TEST(strrchr_test8) {
  char *str = "Что будет,\0 если год не есть сахар?";
  ck_assert_ptr_eq(strrchr(str, '?'), s21_strrchr(str, '?'));
}
END_TEST

START_TEST(strrchr_test9) {
  char *str = "qw&\0?";
  ck_assert_ptr_eq(strrchr(str, '?'), s21_strrchr(str, '?'));
}
END_TEST

START_TEST(strrchr_test10) {
  char *str = "\0";
  ck_assert_str_eq(strrchr(str, '\0'), s21_strrchr(str, '\0'));
}
END_TEST

START_TEST(strrchr_test11) {
  char *str = "\0ewe";
  ck_assert_ptr_eq(strrchr(str, 'e'), s21_strrchr(str, 'e'));
}
END_TEST

START_TEST(strrchr_test12) {
  char *str =
      "Check is a simple and minimalistic unit \ttesting framework for C. It’s "
      "easy to learn and easy to\t install.";
  ck_assert_ptr_eq(strrchr(str, '\t'), s21_strrchr(str, '\t'));
}
END_TEST

START_TEST(strrchr_test13) {
  char *str =
      "\tCheck is a simple and minimalistic unit \ttesting framework for C. "
      "It’s "
      "easy to learn and easy to install.\t";
  ck_assert_str_eq(strrchr(str, '\t'), s21_strrchr(str, '\t'));
}
END_TEST

START_TEST(strrchr_test14) {
  char *str =
      "Check \tis a simple \nand minimalistic unit \ttesting framework for C. "
      "It’s "
      "easy to learn and easy to install.";
  ck_assert_str_eq(strrchr(str, '\n'), s21_strrchr(str, '\n'));
}
END_TEST

START_TEST(strrchr_test15) {
  char *str =
      "Check is a simple and minimalistic unit. \tTesting framework for C. "
      "It’s "
      "easy to learn and easy to install.";
  ck_assert_ptr_eq(strrchr(str, '.'), s21_strrchr(str, '.'));
}
END_TEST

START_TEST(strrchr_test16) {
  char *str =
      "Check is a simple and minimalistic unit \ttesting framework for C. It’s "
      "easy to learn and easy to install.";
  ck_assert_ptr_eq(strrchr(str, 0), s21_strrchr(str, 0));
}
END_TEST

START_TEST(strrchr_test17) {
  char *str =
      "Check is a simple and minimalistic unit \ttesting framework for C. It’s "
      "easy to learn\n and easy to install.\n\n\n";
  ck_assert_ptr_eq(strrchr(str, '\n'), s21_strrchr(str, '\n'));
}
END_TEST

START_TEST(strrchr_test18) {
  char *str =
      "Check is a simple and minimalistic unit \ttesting framework for C. It’s "
      "easy to learn\n and easy to install.";
  ck_assert_str_eq(strrchr(str, '\n'), s21_strrchr(str, '\n'));
}
END_TEST

START_TEST(strrchr_test19) {
  char *str =
      "Check is a simple and minimalistic unit \ttesting framework for C. It’s "
      "easy to learn\n and easy to install.";
  ck_assert_ptr_eq(strrchr(str, '\n'), s21_strrchr(str, '\n'));
}
END_TEST

START_TEST(strrchr_test20) {
  char *str =
      "Check is a simple and minimalistic unit \ttesting framework for C. It’s "
      "easy to learn\n and easy to install.";
  ck_assert_ptr_eq(strrchr(str, '\n'), s21_strrchr(str, '\n'));
}
END_TEST

START_TEST(strrchr_test21) {
  char *str =
      "Check is a simple and minimalistic unit \ttesting framework for C. It’s "
      "easy to learn and easy to install.";
  ck_assert_ptr_eq(strrchr(str, 255), s21_strrchr(str, 255));
}
END_TEST

START_TEST(strrchr_test22) {
  char *str = "Check is a simple and minimalistic";
  void *s = NULL;
  ck_assert_ptr_eq(s21_strrchr(str, '!'), s);
}
END_TEST

TCase *strrchr_get_tests(void) {
  TCase *test = tcase_create("test_1");

  tcase_add_test(test, strrchr_test1);
  tcase_add_test(test, strrchr_test2);
  tcase_add_test(test, strrchr_test3);
  tcase_add_test(test, strrchr_test4);
  tcase_add_test(test, strrchr_test5);
  tcase_add_test(test, strrchr_test6);
  tcase_add_test(test, strrchr_test7);
  tcase_add_test(test, strrchr_test8);
  tcase_add_test(test, strrchr_test9);
  tcase_add_test(test, strrchr_test10);
  tcase_add_test(test, strrchr_test11);
  tcase_add_test(test, strrchr_test12);
  tcase_add_test(test, strrchr_test13);
  tcase_add_test(test, strrchr_test14);
  tcase_add_test(test, strrchr_test15);
  tcase_add_test(test, strrchr_test16);
  tcase_add_test(test, strrchr_test17);
  tcase_add_test(test, strrchr_test18);
  tcase_add_test(test, strrchr_test19);
  tcase_add_test(test, strrchr_test20);
  tcase_add_test(test, strrchr_test21);
  tcase_add_test(test, strrchr_test22);

  return test;
}
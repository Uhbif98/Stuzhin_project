#include <check.h>

#include "../s21_string.h"

START_TEST(strncat_test1) {
  char str[40] = {0};
  char str2[40] = {0};
  strcpy(str, "Hello ");
  strcpy(str2, "world ");
  s21_size_t n = 5;
  ck_assert_str_eq(strncat(str, str2, n), s21_strncat(str, str2, n));
}
END_TEST

START_TEST(strncat_test2) {
  char str[40] = {0};
  char str2[40] = {0};
  strcpy(str, "Hello ");
  strcpy(str2, "world ");
  s21_size_t n = 20;
  ck_assert_str_eq(strncat(str, str2, n), s21_strncat(str, str2, n));
}
END_TEST

START_TEST(strncat_test3) {
  char str[40] = {0};
  char str2[40] = {0};
  strcpy(str, "He\0llo ");
  strcpy(str2, "world ");
  s21_size_t n = 5;
  ck_assert_str_eq(strncat(str, str2, n), s21_strncat(str, str2, n));
}
END_TEST

START_TEST(strncat_test4) {
  char str[40] = {0};
  char str2[40] = {0};
  strcpy(str, "\n \n \t ");
  strcpy(str2, "world ");
  s21_size_t n = 5;
  ck_assert_str_eq(strncat(str, str2, n), s21_strncat(str, str2, n));
}
END_TEST

START_TEST(strncat_test5) {
  char str[40] = {0};
  char str2[40] = {0};
  strcpy(str, "Hello\t ");
  strcpy(str2, "wo\nrld ");
  s21_size_t n = 10;
  ck_assert_str_eq(strncat(str, str2, n), s21_strncat(str, str2, n));
}
END_TEST

START_TEST(strncat_test6) {
  char str[40] = {0};
  char str2[40] = {0};
  strcpy(str, "\0 ");
  strcpy(str2, "world ");
  s21_size_t n = 5;
  ck_assert_str_eq(strncat(str, str2, n), s21_strncat(str, str2, n));
}
END_TEST

START_TEST(strncat_test7) {
  char str[40] = {0};
  char str2[40] = {0};
  strcpy(str, "Hello\t ");
  strcpy(str2, "wo\nrld ");
  s21_size_t n = 8;
  ck_assert_pstr_eq(strncat(str, str2, n), s21_strncat(str, str2, n));
}
END_TEST

START_TEST(strncat_test8) {
  char str[40] = {0};
  char str2[40] = {0};
  strcpy(str, "Hello ");
  strcpy(str2, "world ");
  s21_size_t n = 5;
  ck_assert_pstr_eq(strncat(str, str2, n), s21_strncat(str, str2, n));
}
END_TEST

START_TEST(strncat_test9) {
  char str[40] = {0};
  char str2[40] = {0};
  strcpy(str, "Hello ");
  strcpy(str2, "\0 ");
  s21_size_t n = 0;
  ck_assert_str_eq(strncat(str, str2, n), s21_strncat(str, str2, n));
}
END_TEST

START_TEST(strncat_test10) {
  char str[40] = {0};
  char *str2 = "\n";
  str[0] = '\0';
  s21_size_t n = 10;
  ck_assert_pstr_eq(strncat(str, str2, n), s21_strncat(str, str2, n));
}
END_TEST

START_TEST(strncat_test11) {
  char str[40] = {0};
  char *str2 = "\0\0\0\0\0";
  str[0] = '\0';
  s21_size_t n = 4;
  ck_assert_str_eq(strncat(str, str2, n), s21_strncat(str, str2, n));
}
END_TEST

START_TEST(strncat_test12) {
  char str[40] = {0};
  strcpy(str, "Welcom ");
  char *str_pattern = (char *)malloc(5 * sizeof(char));
  for (int i = 0; i < 5; *(str_pattern + i) = -120 - i, i++)
    ;
  str_pattern[4] = '\0';
  s21_size_t n = 10;
  ck_assert_str_eq(strncat(str, str_pattern, n),
                   s21_strncat(str, str_pattern, n));
  free(str_pattern);
}
END_TEST

START_TEST(strncat_test13) {
  char str[40] = {0};
  strcpy(str, "Welcom ");
  char *str_pattern = (char *)malloc(5 * sizeof(char));
  for (int i = 0; i < 5; *(str_pattern + i) = 14320 - i, i++)
    ;
  str_pattern[4] = '\0';
  s21_size_t n = 5;
  ck_assert_str_eq(strncat(str, str_pattern, n),
                   s21_strncat(str, str_pattern, n));
  free(str_pattern);
}
END_TEST

START_TEST(strncat_test14) {
  char str[500] = {0};
  char *str2 = "\t345\nfgb\0ksdlf";
  strcpy(str,
         "Check that a double precision floating point number is finite; i.e. "
         "is not +infinity, -infinity, or \"Not a Number\" (NaN)");
  s21_size_t n = 15;
  ck_assert_str_eq(strncat(str, str2, n), s21_strncat(str, str2, n));
}
END_TEST

START_TEST(strncat_test15) {
  char str[500] = {0};
  char *str2 = "!@#$%^&*()";
  strcpy(str, "1234567890-=+ ");
  s21_size_t n = 10;
  ck_assert_str_eq(strncat(str, str2, n), s21_strncat(str, str2, n));
}
END_TEST

START_TEST(strncat_test16) {
  char str[500] = {0};
  char *str2 = "\t345\nfgb\t\t\tksdlf";
  strcpy(str,
         "\tCheck that a double precision floating point number is finite; "
         "i.e. is not +infinity, -infinity, or Not a Number (NaN)");
  s21_size_t n = 40;
  ck_assert_str_eq(strncat(str, str2, n), s21_strncat(str, str2, n));
}
END_TEST

START_TEST(strncat_test17) {
  char str[500] = {0};
  char *str2 = "And this";
  strcpy(str, "that ");
  s21_size_t n = strlen(str2);
  ck_assert_str_eq(strncat(str, str2, n), s21_strncat(str, str2, n));
}
END_TEST

START_TEST(strncat_test18) {
  char str[500] = {0};
  char *str2 =
      "And this is what makes for dangerous territory. Just because teenagers "
      "feels that they are invincible, \0does not mean they are.If your teen "
      "is having rectal bleeding, it needs to be investigated as soon as "
      "possible. You need a definitive diagnosis in order to ensure that you "
      "are not dealing with a more serious issue.\0";
  strcpy(str,
         "\tCheck that a double precision floating point number is finite; "
         "i.e. is not +infinity, -infinity, or Not a Number (NaN)");
  s21_size_t n = strlen(str2);
  ck_assert_str_eq(strncat(str, str2, n), s21_strncat(str, str2, n));
}
END_TEST

START_TEST(strncat_test19) {
  char str[500] = {0};
  char *str2 = "And this";
  strcpy(str, "that ");
  s21_size_t n = 20;
  ck_assert_str_eq(strncat(str, str2, n), s21_strncat(str, str2, n));
}
END_TEST

TCase *strncat_get_tests(void) {
  TCase *test = tcase_create("test_strncat");

  tcase_add_test(test, strncat_test1);
  tcase_add_test(test, strncat_test2);
  tcase_add_test(test, strncat_test3);
  tcase_add_test(test, strncat_test4);
  tcase_add_test(test, strncat_test5);
  tcase_add_test(test, strncat_test6);
  tcase_add_test(test, strncat_test7);
  tcase_add_test(test, strncat_test8);
  tcase_add_test(test, strncat_test9);
  tcase_add_test(test, strncat_test10);
  tcase_add_test(test, strncat_test11);
  tcase_add_test(test, strncat_test12);
  tcase_add_test(test, strncat_test13);
  tcase_add_test(test, strncat_test14);
  tcase_add_test(test, strncat_test15);
  tcase_add_test(test, strncat_test16);
  tcase_add_test(test, strncat_test17);
  tcase_add_test(test, strncat_test18);
  tcase_add_test(test, strncat_test19);

  return test;
}
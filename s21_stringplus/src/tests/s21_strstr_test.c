#include <check.h>

#include "../s21_string.h"

START_TEST(strstr_test1) {
  const char *str_se =
      "Practise reading with your classmates in live group classes";
  const char *str_pattern = "live group classes";
  ck_assert_ptr_eq(strstr(str_se, str_pattern),
                   s21_strstr(str_se, str_pattern));
}
END_TEST

START_TEST(strstr_test2) {
  const char *str_se = "\0";
  const char *str_pattern = "live group classes";
  ck_assert_ptr_eq(strstr(str_se, str_pattern),
                   s21_strstr(str_se, str_pattern));
}
END_TEST

START_TEST(strstr_test3) {
  const char *str_se =
      "Practise reading with your classmates in live group classes";
  const char *str_pattern = "\0";
  ck_assert_ptr_eq(strstr(str_se, str_pattern),
                   s21_strstr(str_se, str_pattern));
}
END_TEST

START_TEST(strstr_test4) {
  const char *str_se =
      "Practise reading with your classmates in live group classes";
  const char *str_pattern = "\n";
  ck_assert_ptr_eq(strstr(str_se, str_pattern),
                   s21_strstr(str_se, str_pattern));
}
END_TEST

START_TEST(strstr_test5) {
  const char *str_se =
      "Practise reading with your classmates in live\n group classes";
  const char *str_pattern = "\n group classes";
  ck_assert_ptr_eq(strstr(str_se, str_pattern),
                   s21_strstr(str_se, str_pattern));
}
END_TEST

START_TEST(strstr_test6) {
  const char *str_se =
      "Practise \n reading with your classmates in live group classes";
  const char *str_pattern = "live group classes";
  ck_assert_ptr_eq(strstr(str_se, str_pattern),
                   s21_strstr(str_se, str_pattern));
}
END_TEST

START_TEST(strstr_test7) {
  const char *str_se =
      "Practise \treading with your classmates in live group classes";
  const char *str_pattern = "live group classes";
  ck_assert_ptr_eq(strstr(str_se, str_pattern),
                   s21_strstr(str_se, str_pattern));
}
END_TEST

START_TEST(strstr_test8) {
  const char *str_se =
      "Practise reading with your classmates in live group\t classes";
  const char *str_pattern = "live group\t classes";
  ck_assert_ptr_eq(strstr(str_se, str_pattern),
                   s21_strstr(str_se, str_pattern));
}
END_TEST

START_TEST(strstr_test9) {
  const char *str_se =
      "Practise reading with your classmates in\0 live group classes";
  const char *str_pattern = "live group classes";
  ck_assert_ptr_eq(strstr(str_se, str_pattern),
                   s21_strstr(str_se, str_pattern));
}
END_TEST

START_TEST(strstr_test10) {
  const char *str_se =
      "Practise reading with, your classmates in live group classes";
  const char *str_pattern = ", ";
  ck_assert_ptr_eq(strstr(str_se, str_pattern),
                   s21_strstr(str_se, str_pattern));
}
END_TEST

START_TEST(strstr_test11) {
  const char *str_se =
      "Practise reading with your classmates in live group classes";
  char *str_pattern = "901";
  ck_assert_ptr_eq(NULL, s21_strstr(str_se, str_pattern));
}
END_TEST

START_TEST(strstr_test12) {
  const char *str_se =
      "Practise reading with your classmates in live group classes";
  const char *str_pattern = "es";
  ck_assert_ptr_eq(strstr(str_se, str_pattern),
                   s21_strstr(str_se, str_pattern));
}
END_TEST

START_TEST(strstr_test13) {
  const char *str_se = "\n\n\n\n\t\t\t\t\0\n\n\n\t";
  const char *str_pattern = "\n\n\t";
  ck_assert_ptr_eq(strstr(str_se, str_pattern),
                   s21_strstr(str_se, str_pattern));
}
END_TEST

START_TEST(strstr_test14) {
  const char *str_se = "\n\n\n\n\t\t\t\t\0\n\n123\n\t";
  const char *str_pattern = "123\n\t";
  ck_assert_ptr_eq(NULL, s21_strstr(str_se, str_pattern));
  ;
}
END_TEST

START_TEST(strstr_test15) {
  const char *str_se =
      "Practise reading with your classmates in live group classes";
  const char *str_pattern = "es";
  ck_assert_ptr_eq(strstr(str_se, str_pattern),
                   s21_strstr(str_se, str_pattern));
}
END_TEST

START_TEST(strstr_test16) {
  const char *str_se =
      "Practise reading with your classmates in live group classes";
  const char *str_pattern = " ";
  ck_assert_ptr_eq(strstr(str_se, str_pattern),
                   s21_strstr(str_se, str_pattern));
}
END_TEST

START_TEST(strstr_test17) {
  const char *str_se =
      "Practise reading with your classmates in live group classes";
  const char *str_pattern = "";
  ck_assert_ptr_eq(strstr(str_se, str_pattern),
                   s21_strstr(str_se, str_pattern));
}
END_TEST

START_TEST(strstr_test18) {
  const char *str_se = "%%!@#$%%%%%%$!@#$%";
  const char *str_pattern = "!@#$%";
  ck_assert_ptr_eq(strstr(str_se, str_pattern),
                   s21_strstr(str_se, str_pattern));
}
END_TEST

START_TEST(strstr_test19) {
  const char *str_se =
      "Practise reading with your classmates in live group classes";
  const char *str_pattern = "smat";
  ck_assert_ptr_eq(strstr(str_se, str_pattern),
                   s21_strstr(str_se, str_pattern));
}
END_TEST

START_TEST(strstr_test20) {
  const char *str_se =
      "Practise reading with your classmates in live group classes";
  char *str_pattern = (char *)malloc(5 * sizeof(char));
  for (int i = 0; i < 5; *(str_pattern + i) = -120 - i, i++)
    ;
  str_pattern[4] = '\0';
  ck_assert_ptr_eq(NULL, s21_strstr(str_se, str_pattern));
  free(str_pattern);
}
END_TEST

START_TEST(strstr_test21) {
  const char *str_se =
      "Practise reading with your classmates in live group classes";
  char *str_pattern = (char *)malloc(5 * sizeof(char));
  for (int i = 0; i < 5; *(str_pattern + i) = -120 - i, i++)
    ;
  str_pattern[4] = '\0';
  ck_assert_ptr_eq(strstr(str_se, str_pattern),
                   s21_strstr(str_se, str_pattern));
  free(str_pattern);
}
END_TEST

START_TEST(strstr_test22) {
  const char *str_se =
      "Practise reading with your classmates in live group classes";
  char *str_pattern = (char *)malloc(5 * sizeof(char));
  for (int i = 0; i < 5; *(str_pattern + i) = 3432 + i, i++)
    ;
  str_pattern[4] = '\0';
  ck_assert_ptr_eq(strstr(str_se, str_pattern),
                   s21_strstr(str_se, str_pattern));
  free(str_pattern);
}
END_TEST

START_TEST(strstr_test23) {
  const char *str_se =
      "Practise reading with your classmates in live group classes";
  char *str_pattern = (char *)malloc(5 * sizeof(char));
  for (int i = 0; i < 5; *(str_pattern + i) = 3432 + i, i++)
    ;
  str_pattern[4] = '\0';
  ck_assert_ptr_eq(strstr(str_pattern, str_se),
                   s21_strstr(str_pattern, str_se));
  free(str_pattern);
}
END_TEST

START_TEST(strstr_test24) {
  char *str_pattern = (char *)malloc(5 * sizeof(char));
  for (int i = 0; i < 5; *(str_pattern + i) = 3432 + i, i++)
    ;
  str_pattern[4] = '\0';
  ck_assert_ptr_eq(strstr(str_pattern, str_pattern),
                   s21_strstr(str_pattern, str_pattern));
  free(str_pattern);
}
END_TEST

START_TEST(strstr_test25) {
  char *str_pattern = (char *)malloc(5 * sizeof(char));
  for (int i = 0; i < 5; *(str_pattern + i) = -120 - i, i++)
    ;
  str_pattern[4] = '\0';
  ck_assert_ptr_eq(strstr(str_pattern, str_pattern),
                   s21_strstr(str_pattern, str_pattern));
  free(str_pattern);
}
END_TEST

TCase *strstr_get_tests(void) {
  TCase *test = tcase_create("test_strstr");

  tcase_add_test(test, strstr_test1);
  tcase_add_test(test, strstr_test2);
  tcase_add_test(test, strstr_test3);
  tcase_add_test(test, strstr_test4);
  tcase_add_test(test, strstr_test5);
  tcase_add_test(test, strstr_test6);
  tcase_add_test(test, strstr_test7);
  tcase_add_test(test, strstr_test8);
  tcase_add_test(test, strstr_test9);
  tcase_add_test(test, strstr_test10);
  tcase_add_test(test, strstr_test11);
  tcase_add_test(test, strstr_test12);
  tcase_add_test(test, strstr_test13);
  tcase_add_test(test, strstr_test14);
  tcase_add_test(test, strstr_test15);
  tcase_add_test(test, strstr_test16);
  tcase_add_test(test, strstr_test17);
  tcase_add_test(test, strstr_test18);
  tcase_add_test(test, strstr_test19);
  tcase_add_test(test, strstr_test20);
  tcase_add_test(test, strstr_test21);
  tcase_add_test(test, strstr_test22);
  tcase_add_test(test, strstr_test23);
  tcase_add_test(test, strstr_test24);
  tcase_add_test(test, strstr_test25);

  return test;
}
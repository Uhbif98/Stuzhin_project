#include <check.h>
#include <limits.h>

#include "../s21_string.h"

START_TEST(test_1) {
  char str[50] = "aaa bBb, 234.EaF";
  char str2[50] = "aaa bBb, 234.EaF";

  ck_assert_pstr_eq(s21_strtok(str, " .,"), strtok(str2, " .,"));
}
END_TEST

START_TEST(test_2) {
  char str[50] = "\t \n 3233 fsdf \0";
  char str2[50] = "\t \n 3233 fsdf \0";

  ck_assert_pstr_eq(s21_strtok(str, "fs"), strtok(str2, "fs"));
}
END_TEST

START_TEST(test_3) {
  char str[50] = "\t \n 3233 fsdf \0";
  char str2[50] = "\t \n 3233 fsdf \0";

  ck_assert_pstr_eq(s21_strtok(str, "\0"), strtok(str2, "\0"));
}
END_TEST

START_TEST(test_4) {
  char str[50] = "\0 @ , fFf -_- 14";
  char str2[50] = "\0 @ , fFf -_- 14";

  ck_assert_pstr_eq(s21_strtok(str, ","), strtok(str2, ","));
}
END_TEST

START_TEST(test_5) {
  char str[50] = "Who the HELL do You think I am?";
  char str2[50] = "Who the HELL do You think I am?";

  ck_assert_pstr_eq(s21_strtok(str, "?"), strtok(str2, "?"));
}
END_TEST

START_TEST(test_6) {
  char str[50] = "";
  char str2[50] = "";

  ck_assert_pstr_eq(s21_strtok(str, ""), strtok(str2, ""));
}
END_TEST

START_TEST(test_7) {
  char str[50] = "  ";
  char str2[50] = "  ";

  ck_assert_pstr_eq(s21_strtok(str, " "), strtok(str2, " "));
}
END_TEST

START_TEST(test_8) {
  char str[50] = "Who the HELL do You think I am?";
  char str2[50] = "Who the HELL do You think I am?";

  ck_assert_pstr_eq(s21_strtok(str, "5"), strtok(str2, "5"));
}
END_TEST

START_TEST(test_9) {
  char str[50] = "Who the HELL d\no You think I am?";
  char str2[50] = "Who the HELL d\no You think I am?";

  ck_assert_pstr_eq(s21_strtok(str, "\n"), strtok(str2, "\n"));
}
END_TEST

START_TEST(test_10) {
  char str[50] = "Who the HE@LL do You/think I am?";
  char str2[50] = "Who the HE@LL do You/think I am?";

  ck_assert_pstr_eq(s21_strtok(str, "/"), strtok(str2, "/"));
}
END_TEST

TCase* strtok_get_tests(void) {
  TCase* test_cases = tcase_create("test_strtok");

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
#include <check.h>
#include <limits.h>

#include "../s21_string.h"

START_TEST(test_strncpy_1) {
  char one[50] = "";
  char two[50] = "";

  ck_assert_str_eq(s21_strncpy(one, "", 1), strncpy(two, "", 1));
}
END_TEST

START_TEST(test_strncpy_2) {
  char one[50] = "";
  char two[50] = "";

  ck_assert_str_eq(s21_strncpy(one, "TEST?", 6), strncpy(two, "TEST?", 6));
}
END_TEST

START_TEST(test_strncpy_3) {
  char one[50] = "";
  char two[50] = "";

  ck_assert_str_eq(s21_strncpy(one, "HellO", 6), strncpy(two, "HellO", 6));
}
END_TEST

START_TEST(test_strncpy_4) {
  char one[50] = "";
  char two[50] = "";

  ck_assert_str_eq(s21_strncpy(one, "", 2), strncpy(two, "", 2));
}
END_TEST

START_TEST(test_strncpy_5) {
  char one[50] = "";
  char two[50] = "";

  ck_assert_str_eq(s21_strncpy(one, "HellO WoRlD", 12),
                   strncpy(two, "HellO WoRlD", 12));
}
END_TEST

START_TEST(test_strncpy_6) {
  char one[50] = "";
  char two[50] = "";

  ck_assert_str_eq(s21_strncpy(one, "Hel32o", 7), strncpy(two, "Hel32o", 7));
}
END_TEST

START_TEST(test_strncpy_7) {
  char one[50] = "";
  char two[50] = "";

  ck_assert_str_eq(s21_strncpy(one, "\n", 2), strncpy(two, "\n", 2));
}
END_TEST

START_TEST(test_strncpy_8) {
  char one[50] = "";
  char two[50] = "";

  ck_assert_str_eq(s21_strncpy(one, "$ : ^M ^O ^I", 13),
                   strncpy(two, "$ : ^M ^O ^I", 13));
}
END_TEST

START_TEST(test_strncpy_9) {
  char one[50] = "";
  char two[50] = "";

  ck_assert_str_eq(s21_strncpy(one, "\t", 2), strncpy(two, "\t", 2));
}
END_TEST

START_TEST(test_strncpy_10) {
  char one[50] = "";
  char two[50] = "";

  ck_assert_str_eq(s21_strncpy(one, "\0", 2), strncpy(two, "\0", 2));
}
END_TEST

TCase* strncpy_get_tests(void) {
  TCase* test_cases = tcase_create("test_strncpy");

  tcase_add_test(test_cases, test_strncpy_1);
  tcase_add_test(test_cases, test_strncpy_2);
  tcase_add_test(test_cases, test_strncpy_3);
  tcase_add_test(test_cases, test_strncpy_4);
  tcase_add_test(test_cases, test_strncpy_5);
  tcase_add_test(test_cases, test_strncpy_6);
  tcase_add_test(test_cases, test_strncpy_7);
  tcase_add_test(test_cases, test_strncpy_8);
  tcase_add_test(test_cases, test_strncpy_9);
  tcase_add_test(test_cases, test_strncpy_10);

  return test_cases;
}
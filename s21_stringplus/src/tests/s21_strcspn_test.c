#include <check.h>
#include <limits.h>

#include "../s21_string.h"

START_TEST(test_1) {
  ck_assert_msg(s21_strcspn("fvgdfg", "e") == strcspn("fvgdfg", "e"),
                "FAILURE!");
}
END_TEST

START_TEST(test_2) {
  ck_assert_msg(s21_strcspn("\0ff", "qe2") == strcspn("\0ff", "qe2"),
                "FAILURE!");
}
END_TEST

START_TEST(test_3) {
  ck_assert_msg(s21_strcspn(" ", " ") == strcspn(" ", " "), "FAILURE!");
}
END_TEST

START_TEST(test_4) {
  ck_assert_msg(s21_strcspn("qe2", "\0ff") == strcspn("qe2", "\0ff"),
                "FAILURE!");
}
END_TEST

START_TEST(test_5) {
  ck_assert_msg(s21_strcspn("", "") == strcspn("", ""), "FAILURE!");
}
END_TEST

START_TEST(test_6) {
  ck_assert_msg(
      s21_strcspn("\n \0 \t $6&^*", "ba") == strcspn("\n \0 \t $6&^*", "ba"),
      "FAILURE!");
}
END_TEST

START_TEST(test_7) {
  ck_assert_msg(s21_strcspn("aa", "aa") == strcspn("aa", "aa"), "FAILURE!");
}
END_TEST

START_TEST(test_8) {
  ck_assert_msg(s21_strcspn("(-_-)945", "f") == strcspn("(-_-)945", "f"),
                "FAILURE!");
}
END_TEST

START_TEST(test_9) {
  ck_assert_msg(s21_strcspn("abC \n De", "4") == strcspn("abC \n De", "4"),
                "FAILURE!");
}
END_TEST

START_TEST(test_10) {
  ck_assert_msg(
      s21_strcspn("11111111", "hello") == strcspn("11111111", "hello"),
      "FAILURE!");
}
END_TEST

TCase* strcspn_get_tests(void) {
  TCase* test_cases = tcase_create("test_strcspn");

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
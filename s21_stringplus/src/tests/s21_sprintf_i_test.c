#include <check.h>
#include <limits.h>
#include <locale.h>

#include "../s21_string.h"

START_TEST(test_1) {
  char str[100] = {0};
  char str2[100] = {0};

  char* format = "%i";
  int x = 30;

  int result_one = s21_sprintf(str, format, x);
  int result_two = sprintf(str2, format, x);

  ck_assert_int_eq(result_one, result_two);
  ck_assert_pstr_eq(str, str2);
}
END_TEST

START_TEST(test_2) {
  char str[100] = {0};
  char str2[100] = {0};

  char* format = "%i %.5i %0i % i";

  int x = 0x3435;
  int x_2 = 0035;

  int result_one = s21_sprintf(str, format, x, x_2, x, x_2);
  int result_two = sprintf(str2, format, x, x_2, x, x_2);

  ck_assert_int_eq(result_one, result_two);
  ck_assert_pstr_eq(str, str2);
}
END_TEST

START_TEST(test_3) {
  char str[100] = {0};
  char str2[100] = {0};

  char* format = "%+i %-i %-+i %+-i %+5i";

  int x = 0;
  int x_2 = 00;
  int x_3 = 0x000;

  int result_one = s21_sprintf(str, format, x, x_2, x_3, x, x);
  int result_two = sprintf(str2, format, x, x_2, x_3, x, x);

  ck_assert_int_eq(result_one, result_two);
  ck_assert_pstr_eq(str, str2);
}
END_TEST

START_TEST(test_4) {
  char str[100] = {0};
  char str2[100] = {0};

  char* format = "%i %0i %.5i";

  int x = 53748533;

  int result_one = s21_sprintf(str, format, x, x, x);
  int result_two = sprintf(str2, format, x, x, x);

  ck_assert_int_eq(result_one, result_two);
  ck_assert_pstr_eq(str, str2);
}
END_TEST

START_TEST(test_5) {
  char str[100] = {0};
  char str2[100] = {0};

  char* format = "%i %c %s %5i";

  int x = 0x0032903;
  char sign = '@';
  char* string = "320fsd";
  int x_2 = 035;

  int result_one = s21_sprintf(str, format, x, sign, string, x_2);
  int result_two = sprintf(str2, format, x, sign, string, x_2);

  ck_assert_int_eq(result_one, result_two);
  ck_assert_pstr_eq(str, str2);
}
END_TEST

START_TEST(test_6) {
  char str[100] = {0};
  char str2[100] = {0};

  char* format = "%i %s %.5i";

  int x = 00234353432;
  char* string = "";

  int result_one = s21_sprintf(str, format, x, string, x);
  int result_two = sprintf(str2, format, x, string, x);

  ck_assert_int_eq(result_one, result_two);
  ck_assert_pstr_eq(str, str2);
}
END_TEST

TCase* sprintf_i_get_tests(void) {
  TCase* test_cases = tcase_create("test_sprintf_i");

  tcase_add_test(test_cases, test_1);
  tcase_add_test(test_cases, test_2);
  tcase_add_test(test_cases, test_3);
  tcase_add_test(test_cases, test_4);
  tcase_add_test(test_cases, test_5);
  tcase_add_test(test_cases, test_6);

  return test_cases;
}
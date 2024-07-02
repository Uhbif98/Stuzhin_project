#include <check.h>
#include <limits.h>
#include <locale.h>

#include "../s21_string.h"

START_TEST(test_1) {
  char str[100] = {0};
  char str2[100] = {0};

  char x = 'c';

  char* format = "%-10c";

  int result_one = s21_sprintf(str, format, x);
  int result_two = sprintf(str2, format, x);

  ck_assert_int_eq(result_one, result_two);
  ck_assert_pstr_eq(str, str2);
}
END_TEST

START_TEST(test_2) {
  char str[100] = {0};
  char str2[100] = {0};

  char x = 'A';

  char* format = "%.10c";

  int result_one = s21_sprintf(str, format, x);
  int result_two = sprintf(str2, format, x);

  ck_assert_int_eq(result_one, result_two);
  ck_assert_pstr_eq(str, str2);
}
END_TEST

START_TEST(test_3) {
  char str[100] = {0};
  char str2[100] = {0};

  setlocale(LC_ALL, "");

  wchar_t x = L'П';

  char* format = "%.010c";

  int result_one = s21_sprintf(str, format, x);
  int result_two = sprintf(str2, format, x);

  ck_assert_int_eq(result_one, result_two);
  ck_assert_pstr_eq(str, str2);
}
END_TEST

START_TEST(test_4) {
  char str[100] = {0};
  char str2[100] = {0};

  char x = '\0';

  char* format = "%c";

  int result_one = s21_sprintf(str, format, x);
  int result_two = sprintf(str2, format, x);

  ck_assert_int_eq(result_one, result_two);
  ck_assert_pstr_eq(str, str2);
}
END_TEST

START_TEST(test_5) {
  char str[100] = {0};
  char str2[100] = {0};

  wchar_t x = L'好';

  char* format = "%+4c %c";

  int result_one = s21_sprintf(str, format, x, x);
  int result_two = sprintf(str2, format, x, x);

  ck_assert_int_eq(result_one, result_two);
  ck_assert_pstr_eq(str, str2);
}
END_TEST

START_TEST(test_6) {
  char str[100] = {0};
  char str2[100] = {0};

  wchar_t x = L'🍺';

  char* format = "%c";

  int result_one = s21_sprintf(str, format, x);
  int result_two = sprintf(str2, format, x);

  ck_assert_int_eq(result_one, result_two);
  ck_assert_pstr_eq(str, str2);
}
END_TEST

START_TEST(test_7) {
  char str[100] = {0};
  char str2[100] = {0};

  char x = ' ';

  char* format = "%0c";

  int result_one = s21_sprintf(str, format, x);
  int result_two = sprintf(str2, format, x);

  ck_assert_int_eq(result_one, result_two);
  ck_assert_pstr_eq(str, str2);
}
END_TEST

START_TEST(test_8) {
  char str[100] = {0};
  char str2[100] = {0};

  wchar_t x = L' ';

  char* format = "%c";

  int result_one = s21_sprintf(str, format, x);
  int result_two = sprintf(str2, format, x);

  ck_assert_int_eq(result_one, result_two);
  ck_assert_pstr_eq(str, str2);
}
END_TEST

START_TEST(test_9) {
  char str[100] = {0};
  char str2[100] = {0};

  wchar_t x = L'.';

  char* format = "%c";

  int result_one = s21_sprintf(str, format, x);
  int result_two = sprintf(str2, format, x);

  ck_assert_int_eq(result_one, result_two);
  ck_assert_pstr_eq(str, str2);
}
END_TEST

START_TEST(test_10) {
  char str[100] = {0};
  char str2[100] = {0};

  char x = '\0';

  char* format = "%c";

  int result_one = s21_sprintf(str, format, x);
  int result_two = sprintf(str2, format, x);

  ck_assert_int_eq(result_one, result_two);
  ck_assert_pstr_eq(str, str2);
}
END_TEST

START_TEST(test_11) {
  char str[100] = {0};
  char str2[100] = {0};

  wchar_t x = L'\t';

  char* format = "%.3c";

  int result_one = s21_sprintf(str, format, x);
  int result_two = sprintf(str2, format, x);

  ck_assert_int_eq(result_one, result_two);
  ck_assert_pstr_eq(str, str2);
}
END_TEST

START_TEST(test_12) {
  char str[100] = {0};
  char str2[100] = {0};

  char x = '\t';

  char* format = "%-c";

  int result_one = s21_sprintf(str, format, x);
  int result_two = sprintf(str2, format, x);

  ck_assert_int_eq(result_one, result_two);
  ck_assert_pstr_eq(str, str2);
}
END_TEST

START_TEST(test_13) {
  char str[100] = {0};
  char str2[100] = {0};

  char x = '\n';

  char* format = "%5c";

  int result_one = s21_sprintf(str, format, x);
  int result_two = sprintf(str2, format, x);

  ck_assert_int_eq(result_one, result_two);
  ck_assert_pstr_eq(str, str2);
}

START_TEST(test_14) {
  char str[100] = {0};
  char str2[100] = {0};

  wchar_t x = L'\t';

  char* format = "%-c";

  int result_one = s21_sprintf(str, format, x);
  int result_two = sprintf(str2, format, x);

  ck_assert_int_eq(result_one, result_two);
  ck_assert_pstr_eq(str, str2);
}
END_TEST

START_TEST(test_15) {
  char str[100] = {0};
  char str2[100] = {0};

  wchar_t x = L'\n';

  char* format = "%5c";

  int result_one = s21_sprintf(str, format, x);
  int result_two = sprintf(str2, format, x);

  ck_assert_int_eq(result_one, result_two);
  ck_assert_pstr_eq(str, str2);
}
END_TEST

START_TEST(test_16) {
  char str[100] = {0};
  char str2[100] = {0};

  wchar_t x = '\0';

  char* format = "%c";

  int result_one = s21_sprintf(str, format, x);
  int result_two = sprintf(str2, format, x);

  ck_assert_int_eq(result_one, result_two);
  ck_assert_pstr_eq(str, str2);
}
END_TEST

START_TEST(test_17) {
  char str[100] = {0};
  char str2[100] = {0};

  char x = '5';

  char* format = "%c";

  int result_one = s21_sprintf(str, format, x);
  int result_two = sprintf(str2, format, x);

  ck_assert_int_eq(result_one, result_two);
  ck_assert_pstr_eq(str, str2);
}
END_TEST

START_TEST(test_18) {
  char str[100] = {0};
  char str2[100] = {0};

  wchar_t x = L'🍺';
  char x_1 = '<';

  char* format = "%c %c %.03c";

  int result_one = s21_sprintf(str, format, x, x_1, x);
  int result_two = sprintf(str2, format, x, x_1, x);

  ck_assert_int_eq(result_one, result_two);
  ck_assert_pstr_eq(str, str2);
}
END_TEST

START_TEST(test_19) {
  char str[100] = {0};
  char str2[100] = {0};

  char x = '?';

  char* format = "%c %c";

  int result_one = s21_sprintf(str, format, x, x);
  int result_two = sprintf(str2, format, x, x);

  ck_assert_int_eq(result_one, result_two);
  ck_assert_pstr_eq(str, str2);
}
END_TEST

START_TEST(test_20) {
  char str[100] = {0};
  char str2[100] = {0};
  int width = 2;
  int exact = 3;
  char x = '?';

  char* format = "%*c %.*c";

  int result_one = s21_sprintf(str, format, width, x, exact, x);
  int result_two = sprintf(str2, format, width, x, exact, x);

  ck_assert_int_eq(result_one, result_two);
  ck_assert_pstr_eq(str, str2);
}
END_TEST

START_TEST(test_21) {
  char str[100] = {0};
  char str2[100] = {0};
  char x = '?';

  char* format = "%06c % c";

  int result_one = s21_sprintf(str, format, x, x);
  int result_two = sprintf(str2, format, x, x);

  ck_assert_int_eq(result_one, result_two);
  ck_assert_pstr_eq(str, str2);
}
END_TEST

START_TEST(test_22) {
  char str[100] = {0};
  char str2[100] = {0};
  char x = '?';

  char* format = "%6c %15c";

  int result_one = s21_sprintf(str, format, x, x);
  int result_two = sprintf(str2, format, x, x);

  ck_assert_int_eq(result_one, result_two);
  ck_assert_pstr_eq(str, str2);
}
END_TEST

TCase* sprintf_c_get_tests(void) {
  TCase* test_cases = tcase_create("test_sprintf_c");

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
  tcase_add_test(test_cases, test_11);
  tcase_add_test(test_cases, test_12);
  tcase_add_test(test_cases, test_13);
  tcase_add_test(test_cases, test_14);
  tcase_add_test(test_cases, test_15);
  tcase_add_test(test_cases, test_16);
  tcase_add_test(test_cases, test_17);
  tcase_add_test(test_cases, test_18);
  tcase_add_test(test_cases, test_19);
  tcase_add_test(test_cases, test_20);
  tcase_add_test(test_cases, test_21);
  tcase_add_test(test_cases, test_22);

  return test_cases;
}

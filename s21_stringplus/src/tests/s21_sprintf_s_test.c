#include <check.h>
#include <limits.h>
#include <locale.h>

#include "../s21_string.h"

START_TEST(test_1) {
  char str[100] = {0};
  char str2[100] = {0};

  char* x = "Привет";

  char* format = "%s";

  int result_one = s21_sprintf(str, format, x);
  int result_two = sprintf(str2, format, x);

  ck_assert_int_eq(result_one, result_two);
  ck_assert_pstr_eq(str, str2);
}
END_TEST

START_TEST(test_2) {
  char str[100] = {0};
  char str2[100] = {0};

  setlocale(LC_ALL, "");
  wchar_t* x = L"ПрИвЕт,.;";
  char* format = "%ls %s %%s %-+s %.10s";

  int result_one = s21_sprintf(str, format, x, x, x, x);
  int result_two = sprintf(str2, format, x, x, x, x);

  ck_assert_int_eq(result_one, result_two);
  ck_assert_pstr_eq(str, str2);
}
END_TEST

START_TEST(test_3) {
  char str[100];
  char str2[100];

  char* x = "Привет,.";
  char* format = "%ls %2s %%s %-+s %.10s";

  int result_one = s21_sprintf(str, format, x, x, x, x);
  int result_two = sprintf(str2, format, x, x, x, x);

  ck_assert_int_eq(result_one, result_two);
  ck_assert_pstr_eq(str, str2);
}
END_TEST

START_TEST(test_4) {
  char str[100] = {0};
  char str2[100] = {0};

  wchar_t* x = L"🍺";
  char* format = "%.0s";

  int result_one = s21_sprintf(str, format, x);
  int result_two = sprintf(str2, format, x);

  ck_assert_int_eq(result_one, result_two);
  ck_assert_pstr_eq(str, str2);
}
END_TEST

START_TEST(test_5) {
  char str[100] = {0};
  char str2[100] = {0};

  wchar_t* x = L"🍺";
  char* format = "%.3s %.3ls %+.3s %+-4s";

  int result_one = s21_sprintf(str, format, x, x, x, x);
  int result_two = sprintf(str2, format, x, x, x, x);

  ck_assert_int_eq(result_one, result_two);
  ck_assert_pstr_eq(str, str2);
}
END_TEST

START_TEST(test_6) {
  char str[1024] = {0};
  char str2[1024] = {0};

  setlocale(LC_ALL, "");

  wchar_t* x = L"好 好 好";
  wchar_t x_2 = L'好';
  wchar_t* x_3 = L"好";

  char* format = "%c %s %c %s %03s %04s %5c %+-3c";

  int result_one = s21_sprintf(str, format, x_2, x, x_2, x_3, x, x, x_2, x_2);
  int result_two = sprintf(str2, format, x_2, x, x_2, x_3, x, x, x_2, x_2);

  ck_assert_int_eq(result_one, result_two);
  ck_assert_pstr_eq(str, str2);
}
END_TEST

START_TEST(test_7) {
  char str[100] = {0};
  char str2[100] = {0};

  wchar_t* x = L" ";
  char* format = "%ls %s %c %3ls";

  int result_one = s21_sprintf(str, format, x, x, 'g', x);
  int result_two = sprintf(str2, format, x, x, 'g', x);

  ck_assert_int_eq(result_one, result_two);
  ck_assert_pstr_eq(str, str2);
}
END_TEST

START_TEST(test_8) {
  char str[100] = {0};
  char str2[100] = {0};

  wchar_t* x = L"🍺🍺🍺 🍺  23rsdf23^@ 🍺";
  char* format = "%ls %s";

  int result_one = s21_sprintf(str, format, x, x);
  int result_two = sprintf(str2, format, x, x);

  ck_assert_int_eq(result_one, result_two);
  ck_assert_pstr_eq(str, str2);
}
END_TEST

START_TEST(test_9) {
  char str[100] = {0};
  char str2[100] = {0};

  char* x = "";
  char* format = "%s %ls";

  int result_one = s21_sprintf(str, format, x, x);
  int result_two = sprintf(str2, format, x, x);

  ck_assert_int_eq(result_one, result_two);
  ck_assert_pstr_eq(str, str2);
}
END_TEST

START_TEST(test_10) {
  char str[100] = {0};
  char str2[100] = {0};

  setlocale(LC_ALL, "");

  wchar_t* x = L"";
  char* format = "%s %ls";

  int result_one = s21_sprintf(str, format, x, x);
  int result_two = sprintf(str2, format, x, x);

  ck_assert_int_eq(result_one, result_two);
  ck_assert_pstr_eq(str, str2);
}
END_TEST

START_TEST(test_11) {
  char str[100] = {0};
  char str2[100] = {0};

  wchar_t* x = L"";
  char* format = "%s %ls";

  int result_one = s21_sprintf(str, format, x, x);
  int result_two = sprintf(str2, format, x, x);

  ck_assert_int_eq(result_one, result_two);
  ck_assert_pstr_eq(str, str2);
}
END_TEST

START_TEST(test_12) {
  char str[100] = {0};
  char str2[100] = {0};

  setlocale(LC_ALL, "");

  wchar_t* x = L" asd а";
  char* format = "%s %ls";

  int result_one = s21_sprintf(str, format, x, x);
  int result_two = sprintf(str2, format, x, x);

  ck_assert_int_eq(result_one, result_two);
  ck_assert_pstr_eq(str, str2);
}
END_TEST

START_TEST(test_13) {
  char str[100] = {0};
  char str2[100] = {0};

  setlocale(LC_ALL, "");

  wchar_t* x = L"🍺";
  char* format = "%.3s %.3ls %+.3s %+-4s";

  int result_one = s21_sprintf(str, format, x, x, x, x);
  int result_two = sprintf(str2, format, x, x, x, x);

  ck_assert_int_eq(result_one, result_two);
  ck_assert_pstr_eq(str, str2);
}
END_TEST

START_TEST(test_14) {
  char str[250];
  char str2[250];

  char* x = "абвгд123)))";
  char* format =
      "%3s %.3s %3.3s %33.3s %3.33s %33.33s % s %ls %3ls %.3ls %3.3ls %33.3ls "
      "%3.33ls %33.33ls";

  int result_one =
      s21_sprintf(str, format, x, x, x, x, x, x, x, x, x, x, x, x, x, x);
  int result_two =
      sprintf(str2, format, x, x, x, x, x, x, x, x, x, x, x, x, x, x);

  ck_assert_int_eq(result_one, result_two);
  ck_assert_pstr_eq(str, str2);
}
END_TEST

TCase* sprintf_s_get_tests(void) {
  TCase* test_cases = tcase_create("test_sprintf_s");

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

  return test_cases;
}

#include <check.h>
#include <limits.h>
#include <locale.h>

#include "../s21_string.h"

START_TEST(test_1) {
  char str[100] = {0};
  char str2[100] = {0};

  char* format = "%f";
  float x = -30.54345;

  int result_one = s21_sprintf(str, format, x);
  int result_two = sprintf(str2, format, x);

  ck_assert_float_eq(result_one, result_two);
  ck_assert_pstr_eq(str, str2);
}
END_TEST

START_TEST(test_2) {
  char str[100] = {0};
  char str2[100] = {0};

  char* format = "%.3f %lf %%f %%.5f";

  float x_1 = 43.23345;
  double x_2 = 23.554323429439;

  int result_one = s21_sprintf(str, format, x_1, x_2);
  int result_two = sprintf(str2, format, x_1, x_2);

  ck_assert_double_eq(result_one, result_two);
  ck_assert_pstr_eq(str, str2);
}
END_TEST

START_TEST(test_3) {
  char str[100] = {0};
  char str2[100] = {0};

  char* format = "%+3lf %-2lf %+-4lf %05lf %.5lf";

  double x = -32.534245;

  int resultOne = s21_sprintf(str, format, x, x, x, x, x);
  int resultTwo = sprintf(str2, format, x, x, x, x, x);

  ck_assert_double_eq(resultOne, resultTwo);
  ck_assert_pstr_eq(str, str2);
}
END_TEST

START_TEST(test_4) {
  char str[100] = {0};
  char str2[100] = {0};

  char* format = "%lf %.3lf %03lf";

  double x = 0;

  int resultOne = s21_sprintf(str, format, x, x, x);
  int resultTwo = sprintf(str2, format, x, x, x);

  ck_assert_double_eq(resultOne, resultTwo);
  ck_assert_pstr_eq(str, str2);
}
END_TEST

START_TEST(test_5) {
  char str[100] = {0};
  char str2[100] = {0};

  char* format = "%lf %lf";

  double x_1 = 0.00;
  double x_2 = -0.00;

  int resultOne = s21_sprintf(str, format, x_1, x_2);
  int resultTwo = sprintf(str2, format, x_1, x_2);

  ck_assert_double_eq(resultOne, resultTwo);
  ck_assert_pstr_eq(str, str2);
}
END_TEST

START_TEST(test_6) {
  char str[100] = {0};
  char str2[100] = {0};

  char* format = "% lf % f %% ";

  double x = -35.3435;

  int resultOne = s21_sprintf(str, format, x, x);
  int resultTwo = sprintf(str2, format, x, x);

  ck_assert_double_eq(resultOne, resultTwo);
  ck_assert_pstr_eq(str, str2);
}
END_TEST

START_TEST(test_7) {
  char str[100] = {0};
  char str2[100] = {0};

  char* format = "%+lf % -f %#f ";

  double x = 0.00005;

  int resultOne = s21_sprintf(str, format, x, x, x);
  int resultTwo = sprintf(str2, format, x, x, x);

  ck_assert_double_eq(resultOne, resultTwo);
  ck_assert_pstr_eq(str, str2);
}
END_TEST

START_TEST(test_8) {
  char str[100] = {0};
  char str2[100] = {0};

  char* format = "%+lf % -f %#f ";

  double x = -0.00005;

  int resultOne = s21_sprintf(str, format, x, x, x);
  int resultTwo = sprintf(str2, format, x, x, x);

  ck_assert_double_eq(resultOne, resultTwo);
  ck_assert_pstr_eq(str, str2);
}
END_TEST

START_TEST(test_9) {
  char str[100] = {0};
  char str2[100] = {0};

  char* format = "%3f %.3f %3.3f ";

  double x = 834.23572835723;

  int resultOne = s21_sprintf(str, format, x, x, x);
  int resultTwo = sprintf(str2, format, x, x, x);

  ck_assert_double_eq(resultOne, resultTwo);
  ck_assert_pstr_eq(str, str2);
}
END_TEST

START_TEST(test_10) {
  char str[512] = {0};
  char str2[512] = {0};

  char* format =
      "  %- #+33f %+ f %-+ #f %- #+73f %+ f %-+ #f %- #+f %+ f %-+ #.10f %- "
      "#+f %+ f %-+ #10.10f %- #+f %+ 3f %-+ #f";

  double x = 999.5;
  double x1 = 999.9;
  double x2 = 999.1;
  double x3 = -999.9;
  double x4 = -999.5;

  int resultOne = s21_sprintf(str, format, x, x, x, x1, x1, x1, x2, x2, x2, x3,
                              x3, x3, x4, x4, x4);
  int resultTwo = sprintf(str2, format, x, x, x, x1, x1, x1, x2, x2, x2, x3, x3,
                          x3, x4, x4, x4);

  ck_assert_int_eq(resultOne, resultTwo);
  ck_assert_pstr_eq(str, str2);
}
END_TEST

START_TEST(test_11) {
  char str[30] = {0};
  char str2[30] = {0};

  char* format = "%f";

  float x = 999.5;
  int zero = 0;

  int resultOne = s21_sprintf(str, format, x / zero);
  int resultTwo = sprintf(str2, format, x / zero);

  ck_assert_int_eq(resultOne, resultTwo);
  ck_assert_pstr_eq(str, str2);
}
END_TEST

START_TEST(test_12) {
  char str[30] = {0};
  char str2[30] = {0};

  char* format = "%f";

  float x = -999.5;
  int zero = 0;

  int resultOne = s21_sprintf(str, format, x / zero);
  int resultTwo = sprintf(str2, format, x / zero);

  ck_assert_int_eq(resultOne, resultTwo);
  ck_assert_pstr_eq(str, str2);
}
END_TEST

START_TEST(test_13) {
  char str[30] = {0};
  char str2[30] = {0};

  char* format = "%f";

  float x = -999.5e-308;

  int resultOne = s21_sprintf(str, format, x);
  int resultTwo = sprintf(str2, format, x);

  ck_assert_int_eq(resultOne, resultTwo);
  ck_assert_pstr_eq(str, str2);
}
END_TEST

START_TEST(test_14) {
  char str[30] = {0};
  char str2[30] = {0};

  char* format = "%f";

  float x = 999.5e+303;

  int resultOne = s21_sprintf(str, format, x);
  int resultTwo = sprintf(str2, format, x);

  ck_assert_int_eq(resultOne, resultTwo);
  ck_assert_pstr_eq(str, str2);
}
END_TEST

START_TEST(test_15) {
  char str[30] = {0};
  char str2[30] = {0};

  char* format = "%f";

  float x = 0.005e+308;

  int resultOne = s21_sprintf(str, format, x);
  int resultTwo = sprintf(str2, format, x);

  ck_assert_int_eq(resultOne, resultTwo);
  ck_assert_pstr_eq(str, str2);
}
END_TEST

START_TEST(test_16) {
  char str[30] = {0};
  char str2[30] = {0};

  char* format = "%f";

  float x = 0.005e-308;

  int resultOne = s21_sprintf(str, format, x);
  int resultTwo = sprintf(str2, format, x);

  ck_assert_int_eq(resultOne, resultTwo);
  ck_assert_pstr_eq(str, str2);
}
END_TEST

START_TEST(test_17) {
  char str[30] = {0};
  char str2[30] = {0};

  char* format = "%f";

  float x = -0.005e+308;

  int resultOne = s21_sprintf(str, format, x);
  int resultTwo = sprintf(str2, format, x);

  ck_assert_int_eq(resultOne, resultTwo);
  ck_assert_pstr_eq(str, str2);
}
END_TEST

START_TEST(test_18) {
  char str[30] = {0};
  char str2[30] = {0};

  char* format = "%f";

  float x = -0.005e-308;

  int resultOne = s21_sprintf(str, format, x);
  int resultTwo = sprintf(str2, format, x);

  ck_assert_int_eq(resultOne, resultTwo);
  ck_assert_pstr_eq(str, str2);
}
END_TEST

START_TEST(test_19) {
  char str[30] = {0};
  char str2[30] = {0};

  int width = 2;
  int exact = 3;
  char* format = "%*.*f";

  float x = -0.005e-308;

  int resultOne = s21_sprintf(str, format, width, exact, x);
  int resultTwo = sprintf(str2, format, width, exact, x);

  ck_assert_int_eq(resultOne, resultTwo);
  ck_assert_pstr_eq(str, str2);
}
END_TEST

TCase* sprintf_f_get_tests(void) {
  TCase* test_cases = tcase_create("test_sprintf_f");

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

  return test_cases;
}

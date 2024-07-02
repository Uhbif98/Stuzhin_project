#include <check.h>
#include <limits.h>

#include "../s21_string.h"

START_TEST(test_01) {
  char str[100] = {0};
  char str2[100] = {0};

  char* format = "%e";
  float x = -30.54345;

  int result_one = s21_sprintf(str, format, x);
  int result_two = sprintf(str2, format, x);

  ck_assert_int_eq(result_one, result_two);
  ck_assert_pstr_eq(str, str2);
}
END_TEST

START_TEST(test_02) {
  char str[100] = {0};
  char str2[100] = {0};

  char* format = "%.2e % e %+e %-e %+-e %-+e";
  float x = 25.435;

  int result_one = s21_sprintf(str, format, x, x, x, x, x, x);
  int result_two = sprintf(str2, format, x, x, x, x, x, x);

  ck_assert_int_eq(result_one, result_two);
  ck_assert_pstr_eq(str, str2);
}
END_TEST

START_TEST(test_03) {
  char str[100] = {0};
  char str2[100] = {0};

  char* format = "%e %e %c %05e";
  float x = 0;
  char sign = 'a';

  int result_one = s21_sprintf(str, format, x, x, sign, x);
  int result_two = sprintf(str2, format, x, x, sign, x);

  ck_assert_int_eq(result_one, result_two);
  ck_assert_pstr_eq(str, str2);
}
END_TEST

START_TEST(test_04) {
  char str[100] = {0};
  char str2[100] = {0};

  char* format = "%e %e %e";
  float x = -0.00;

  int result_one = s21_sprintf(str, format, x, x, x);
  int result_two = sprintf(str2, format, x, x, x);

  ck_assert_int_eq(result_one, result_two);
  ck_assert_pstr_eq(str, str2);
}
END_TEST

START_TEST(test_05) {
  char str[100] = {0};
  char str2[100] = {0};

  char* format = "%e %e %e";
  float x = 0.0;

  int result_one = s21_sprintf(str, format, x, x, x);
  int result_two = sprintf(str2, format, x, x, x);

  ck_assert_int_eq(result_one, result_two);
  ck_assert_pstr_eq(str, str2);
}
END_TEST

START_TEST(test_06) {
  char str[100] = {0};
  char str2[100] = {0};

  char* format = "%05e % 5e";
  float x = 34.5435434;

  int result_one = s21_sprintf(str, format, x, x);
  int result_two = sprintf(str2, format, x, x);

  ck_assert_int_eq(result_one, result_two);
  ck_assert_pstr_eq(str, str2);
}
END_TEST

START_TEST(test_07) {
  char str[100] = {0};
  char str2[100] = {0};

  char* format = "%E";
  float x = -30.54345;

  int result_one = s21_sprintf(str, format, x);
  int result_two = sprintf(str2, format, x);

  ck_assert_int_eq(result_one, result_two);
  ck_assert_pstr_eq(str, str2);
}
END_TEST

START_TEST(test_08) {
  char str[100] = {0};
  char str2[100] = {0};

  char* format = "%.2E % E %+E %-E %+-E %-+E";
  float x = 25.435;

  int result_one = s21_sprintf(str, format, x, x, x, x, x, x);
  int result_two = sprintf(str2, format, x, x, x, x, x, x);

  ck_assert_int_eq(result_one, result_two);
  ck_assert_pstr_eq(str, str2);
}
END_TEST

START_TEST(test_09) {
  char str[100] = {0};
  char str2[100] = {0};

  char* format = "%E %E %c %05E";
  float x = 0;
  char sign = 'a';

  int result_one = s21_sprintf(str, format, x, x, sign, x);
  int result_two = sprintf(str2, format, x, x, sign, x);

  ck_assert_int_eq(result_one, result_two);
  ck_assert_pstr_eq(str, str2);
}
END_TEST

START_TEST(test_010) {
  char str[100] = {0};
  char str2[100] = {0};

  char* format = "%E %e %E";
  float x = -0.00;

  int result_one = s21_sprintf(str, format, x, x, x);
  int result_two = sprintf(str2, format, x, x, x);

  ck_assert_int_eq(result_one, result_two);
  ck_assert_pstr_eq(str, str2);
}
END_TEST

START_TEST(test_011) {
  char str[100] = {0};
  char str2[100] = {0};

  char* format = "%e %E %e";
  float x = 0.0;

  int result_one = s21_sprintf(str, format, x, x, x);
  int result_two = sprintf(str2, format, x, x, x);

  ck_assert_int_eq(result_one, result_two);
  ck_assert_pstr_eq(str, str2);
}
END_TEST

START_TEST(test_012) {
  char str[100] = {0};
  char str2[100] = {0};

  char* format = "%05E % 5E";
  float x = 34.5435434;

  int result_one = s21_sprintf(str, format, x, x);
  int result_two = sprintf(str2, format, x, x);

  ck_assert_int_eq(result_one, result_two);
  ck_assert_pstr_eq(str, str2);
}
END_TEST

START_TEST(test_1) {
  char str[100] = {0};
  char str2[100] = {0};

  char* format = "%e";
  float x = -23.54375E-11;

  int result_one = s21_sprintf(str, format, x);
  int result_two = sprintf(str2, format, x);

  ck_assert_float_eq(result_one, result_two);
  ck_assert_pstr_eq(str, str2);
}
END_TEST

START_TEST(test_2) {
  char str[100] = {0};
  char str2[100] = {0};

  char* format = "%.3e %le %e %.5e";

  float x_1 = 13.23345e-21;
  double x_2 = 73.554323429439;

  int result_one = s21_sprintf(str, format, x_1, x_2, x_1, x_1);
  int result_two = sprintf(str2, format, x_1, x_2, x_1, x_1);

  ck_assert_double_eq(result_one, result_two);
  ck_assert_pstr_eq(str, str2);
}
END_TEST

START_TEST(test_3) {
  char str[100] = {0};
  char str2[100] = {0};

  char* format = "%+3le %-2le %+-4le %05le %.5le";

  double x = -52.534245e-1;

  int resultOne = s21_sprintf(str, format, x, x, x, x, x);
  int resultTwo = sprintf(str2, format, x, x, x, x, x);

  ck_assert_double_eq(resultOne, resultTwo);
  ck_assert_pstr_eq(str, str2);
}
END_TEST

START_TEST(test_4) {
  char str[100] = {0};
  char str2[100] = {0};

  char* format = "%le %.3le %03le";

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

  char* format = "%le %le";

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

  char* format = "% le % e %% ";

  double x = -75.3435;

  int resultOne = s21_sprintf(str, format, x, x);
  int resultTwo = sprintf(str2, format, x, x);

  ck_assert_double_eq(resultOne, resultTwo);
  ck_assert_pstr_eq(str, str2);
}
END_TEST

START_TEST(test_7) {
  char str[100] = {0};
  char str2[100] = {0};

  char* format = "%+le % -e %#e ";

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

  char* format = "%+le % -e %#e ";

  double x = -0.00005e+5;

  int resultOne = s21_sprintf(str, format, x, x, x);
  int resultTwo = sprintf(str2, format, x, x, x);

  ck_assert_double_eq(resultOne, resultTwo);
  ck_assert_pstr_eq(str, str2);
}
END_TEST

START_TEST(test_9) {
  char str[100] = {0};
  char str2[100] = {0};

  char* format = "%3e %.3e %3.3e ";

  double x = 734.23572835723;

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
      "  %- #+33e %+ e %-+ #e %- #+73e %+ e %-+ #e %- #+e %+ e %-+ #.10e %- "
      "#+f %+ e %-+ #10.10e %- #+e %+ 3e %-+ #e";

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

  char* format = "%e";

  float x = 999.5;
  int b = 3;

  int resultOne = s21_sprintf(str, format, x / b);
  int resultTwo = sprintf(str2, format, x / b);

  ck_assert_int_eq(resultOne, resultTwo);
  ck_assert_pstr_eq(str, str2);
}
END_TEST

START_TEST(test_12) {
  char str[30] = {0};
  char str2[30] = {0};

  char* format = "%e";

  float x = -999.5;
  int abc = 3;

  int resultOne = s21_sprintf(str, format, x / abc);
  int resultTwo = sprintf(str2, format, x / abc);

  ck_assert_int_eq(resultOne, resultTwo);
  ck_assert_pstr_eq(str, str2);
}
END_TEST

START_TEST(test_13) {
  char str[30] = {0};
  char str2[30] = {0};

  char* format = "%e";

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

  char* format = "%e";

  float x = 999.5e+10;

  int resultOne = s21_sprintf(str, format, x);
  int resultTwo = sprintf(str2, format, x);

  ck_assert_int_eq(resultOne, resultTwo);
  ck_assert_pstr_eq(str, str2);
}
END_TEST

START_TEST(test_15) {
  char str[30] = {0};
  char str2[30] = {0};

  char* format = "%e";

  float x = 0.005e+10;

  int resultOne = s21_sprintf(str, format, x);
  int resultTwo = sprintf(str2, format, x);

  ck_assert_int_eq(resultOne, resultTwo);
  ck_assert_pstr_eq(str, str2);
}
END_TEST

START_TEST(test_16) {
  char str[30] = {0};
  char str2[30] = {0};

  char* format = "%e";

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

  char* format = "%e";

  float x = -0.005e+10;

  int resultOne = s21_sprintf(str, format, x);
  int resultTwo = sprintf(str2, format, x);

  ck_assert_int_eq(resultOne, resultTwo);
  ck_assert_pstr_eq(str, str2);
}
END_TEST

START_TEST(test_18) {
  char str[30] = {0};
  char str2[30] = {0};

  char* format = "%e";

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
  char* format = "%*.*e";

  float x = -0.005e-308;

  int resultOne = s21_sprintf(str, format, width, exact, x);
  int resultTwo = sprintf(str2, format, width, exact, x);

  ck_assert_int_eq(resultOne, resultTwo);
  ck_assert_pstr_eq(str, str2);
}
END_TEST

START_TEST(test_20) {
  char str[30] = {0};
  char str2[30] = {0};

  char* format = "%E";

  float x = -999.5E-308;

  int resultOne = s21_sprintf(str, format, x);
  int resultTwo = sprintf(str2, format, x);

  ck_assert_int_eq(resultOne, resultTwo);
  ck_assert_pstr_eq(str, str2);
}
END_TEST

START_TEST(test_21) {
  char str[30] = {0};
  char str2[30] = {0};

  int width = 2;
  int exact = 3;
  char* format = "%*.*E";

  float x = -0.005E-308;

  int resultOne = s21_sprintf(str, format, width, exact, x);
  int resultTwo = sprintf(str2, format, width, exact, x);

  ck_assert_int_eq(resultOne, resultTwo);
  ck_assert_pstr_eq(str, str2);
}
END_TEST

START_TEST(test_22) {
  char str[100] = {0};
  char str2[100] = {0};

  char* format = "%+lE % -E %#E ";

  double x = -0.00005;

  int resultOne = s21_sprintf(str, format, x, x, x);
  int resultTwo = sprintf(str2, format, x, x, x);

  ck_assert_double_eq(resultOne, resultTwo);
  ck_assert_pstr_eq(str, str2);
}
END_TEST

START_TEST(test_23) {
  char str[100] = {0};
  char str2[100] = {0};

  char* format = "%3E %.3E %3.3E ";

  double x = 734.2357E-21;

  int resultOne = s21_sprintf(str, format, x, x, x);
  int resultTwo = sprintf(str2, format, x, x, x);

  ck_assert_double_eq(resultOne, resultTwo);
  ck_assert_pstr_eq(str, str2);
}
END_TEST

START_TEST(test_24) {
  char str[512] = {0};
  char str2[512] = {0};

  char* format =
      "  %- #+33E %+ E %-+ #E %- #+73E %+ E %-+ #E %- #+E %+ E %-+ #.10E %- "
      "#+f %+ E %-+ #10.10E %- #+E %+ 3E %-+ #E";

  double x = 999.5E-5;
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

START_TEST(test_25) {
  char str[30] = {0};
  char str2[30] = {0};

  char* format = "%E";

  float x = 999.5;
  int abc = 3;

  int resultOne = s21_sprintf(str, format, x / abc);
  int resultTwo = sprintf(str2, format, x / abc);

  ck_assert_int_eq(resultOne, resultTwo);
  ck_assert_pstr_eq(str, str2);
}
END_TEST

START_TEST(test_26) {
  char str[30] = {0};
  char str2[30] = {0};

  char* format = "%E";

  float x = -999.5e-10;
  int abc = 3;

  int resultOne = s21_sprintf(str, format, x / abc);
  int resultTwo = sprintf(str2, format, x / abc);

  ck_assert_int_eq(resultOne, resultTwo);
  ck_assert_pstr_eq(str, str2);
}
END_TEST

START_TEST(test_27) {
  char str[30] = {0};
  char str2[30] = {0};

  char* format = "%E";

  float x = -999.5E-10;

  int resultOne = s21_sprintf(str, format, x);
  int resultTwo = sprintf(str2, format, x);

  ck_assert_int_eq(resultOne, resultTwo);
  ck_assert_pstr_eq(str, str2);
}
END_TEST

START_TEST(test_28) {
  char str[30] = {0};
  char str2[30] = {0};

  char* format = "%E";

  float x = 999.5e+10;

  int resultOne = s21_sprintf(str, format, x);
  int resultTwo = sprintf(str2, format, x);

  ck_assert_int_eq(resultOne, resultTwo);
  ck_assert_pstr_eq(str, str2);
}
END_TEST

TCase* sprintf_eE_get_tests(void) {
  TCase* test_cases = tcase_create("test_sprintf_e");

  tcase_add_test(test_cases, test_01);
  tcase_add_test(test_cases, test_02);
  tcase_add_test(test_cases, test_03);
  tcase_add_test(test_cases, test_04);
  tcase_add_test(test_cases, test_05);
  tcase_add_test(test_cases, test_06);
  tcase_add_test(test_cases, test_07);
  tcase_add_test(test_cases, test_08);
  tcase_add_test(test_cases, test_09);
  tcase_add_test(test_cases, test_010);
  tcase_add_test(test_cases, test_011);
  tcase_add_test(test_cases, test_012);

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
  tcase_add_test(test_cases, test_23);
  tcase_add_test(test_cases, test_24);
  tcase_add_test(test_cases, test_25);
  tcase_add_test(test_cases, test_26);
  tcase_add_test(test_cases, test_27);
  tcase_add_test(test_cases, test_28);

  return test_cases;
}
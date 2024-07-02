#include <check.h>
#include <limits.h>
#include <locale.h>

#include "../s21_string.h"

START_TEST(test_1) {
  char str[50] = {0};
  char str2[50] = {0};

  int x1[2] = {0}, x2[2] = {0};

  char* format = "3sddfgdg %n fsdf%nfdsdl";

  int result_one = s21_sprintf(str, format, &x1[0], &x1[1]);
  int result_two = sprintf(str2, format, &x2[0], &x2[1]);

  ck_assert_int_eq(result_one, result_two);
  ck_assert_pstr_eq(str, str2);
  for (int i = 0; i < 2; i++) {
    ck_assert_int_eq(x1[i], x2[i]);
  }
}
END_TEST

START_TEST(test_2) {
  char str[50] = {0};
  char str2[50] = {0};

  int x1[2] = {0}, x2[2] = {0};

  char* format = "jfs %n Hello %c nfsej %n";
  char x_3 = 'b';

  int result_one = s21_sprintf(str, format, &x1[0], x_3, &x1[1]);
  int result_two = sprintf(str2, format, &x2[0], x_3, &x2[1]);

  ck_assert_int_eq(result_one, result_two);
  ck_assert_pstr_eq(str, str2);
  for (int i = 0; i < 2; i++) {
    ck_assert_int_eq(x1[i], x2[i]);
  }
}
END_TEST

START_TEST(test_3) {
  char str[10] = {0};
  char str2[10] = {0};

  int x = 5;
  int x_2 = 5;

  char* format = "%n";

  int result_one = s21_sprintf(str, format, &x);
  int result_two = sprintf(str2, format, &x_2);

  ck_assert_int_eq(result_one, result_two);
  ck_assert_int_eq(x, x_2);
  ck_assert_pstr_eq(str, str2);
}
END_TEST

START_TEST(test_4) {
  char str[50] = {0};
  char str2[50] = {0};

  int x1[3] = {0}, x2[3] = {0};
  char* letter = "BBBee324";

  char* format = "Hello %.3n wo%n  %ls nrld %+-4n";

  int result_one = s21_sprintf(str, format, &x1[0], &x1[1], letter, &x1[2]);
  int result_two = sprintf(str2, format, &x2[0], &x2[1], letter, &x2[2]);

  ck_assert_int_eq(result_one, result_two);
  ck_assert_pstr_eq(str, str2);
  for (int i = 0; i < 3; i++) {
    ck_assert_int_eq(x1[i], x2[i]);
  }
}
END_TEST

START_TEST(test_5) {
  char str[250] = {0};
  char str2[250] = {0};

  int x1[3] = {0}, x2[3] = {0};
  double number = 34.5555;
  double number_2 = -43.55;

  char* format = "Hello % n wo%lfrold \t \n %03n ! %lf %n";

  int result_one =
      s21_sprintf(str, format, &x1[0], number, &x1[1], number_2, &x1[2]);
  int result_two =
      sprintf(str2, format, &x2[0], number, &x2[1], number_2, &x2[2]);

  ck_assert_int_eq(result_one, result_two);
  ck_assert_pstr_eq(str, str2);
  for (int i = 0; i < 3; i++) {
    ck_assert_int_eq(x1[i], x2[i]);
  }
}
END_TEST

START_TEST(test_6) {
  char str[100] = {0};
  char str2[100] = {0};

  int x1[3] = {0}, x2[3] = {0};

  char* format = "Hel% +5nlo wo%5nrld aga \0 i%nn";

  int result_one = s21_sprintf(str, format, &x1[0], &x1[1], &x1[2]);
  int result_two = sprintf(str2, format, &x2[0], &x2[1], &x2[2]);

  ck_assert_int_eq(result_one, result_two);
  ck_assert_pstr_eq(str, str2);
  for (int i = 0; i < 3; i++) {
    ck_assert_int_eq(x1[i], x2[i]);
  }
}
END_TEST

START_TEST(test_7) {
  char str[100] = {0};
  char str2[100] = {0};

  int x1[3] = {0}, x2[3] = {0};

  char* format = "Hel% +5nlo wo%5nrld aga \0 i%nn";

  int result_one = s21_sprintf(str, format, &x1[0], &x1[1], &x1[2]);
  int result_two = sprintf(str2, format, &x2[0], &x2[1], &x2[2]);

  ck_assert_int_eq(result_one, result_two);
  ck_assert_pstr_eq(str, str2);
  for (int i = 0; i < 3; i++) {
    ck_assert_int_eq(x1[i], x2[i]);
  }
}
END_TEST

START_TEST(test_8) {
  char str[100] = {0};
  char str2[100] = {0};

  int x1[3] = {0}, x2[3] = {0};

  char* format = "Hel% +5nlo wo%5nrld aga \0 i%nn";

  int result_one = s21_sprintf(str, format, &x1[0], &x1[1], &x1[2]);
  int result_two = sprintf(str2, format, &x2[0], &x2[1], &x2[2]);

  ck_assert_int_eq(result_one, result_two);
  ck_assert_pstr_eq(str, str2);
  for (int i = 0; i < 3; i++) {
    ck_assert_int_eq(x1[i], x2[i]);
  }
}
END_TEST

TCase* sprintf_n_get_tests(void) {
  TCase* test_cases = tcase_create("test_sprintf_n");

  tcase_add_test(test_cases, test_1);
  tcase_add_test(test_cases, test_2);
  tcase_add_test(test_cases, test_3);
  tcase_add_test(test_cases, test_4);
  tcase_add_test(test_cases, test_5);
  tcase_add_test(test_cases, test_6);
  tcase_add_test(test_cases, test_7);
  tcase_add_test(test_cases, test_8);

  return test_cases;
}
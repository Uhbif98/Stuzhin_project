#include <check.h>
#include <limits.h>

#include "../s21_string.h"

START_TEST(sscanf_s_test_1) {
  const void* str = "  abcde 123";
  const void* format = "%s";

  char s21_vars[10] = {0};
  char lib_vars[10] = {0};

  int s21_res = s21_sscanf(str, format, s21_vars);
  int lib_res = sscanf(str, format, lib_vars);

  ck_assert_int_eq(s21_res, lib_res);
  ck_assert_str_eq(s21_vars, lib_vars);
}
END_TEST

START_TEST(sscanf_s_test_2) {
  const void* str = "  абвгд 123";
  const void* format = "%s";

  char s21_vars[30] = {0};
  char lib_vars[30] = {0};

  int s21_res = s21_sscanf(str, format, s21_vars);
  int lib_res = sscanf(str, format, lib_vars);

  ck_assert_int_eq(s21_res, lib_res);
  ck_assert_str_eq(s21_vars, lib_vars);
}
END_TEST

START_TEST(sscanf_s_test_3) {
  const void* str = "  абвгд 123";
  const void* format = "%1s";

  char s21_vars[10] = {0};
  char lib_vars[10] = {0};

  int s21_res = s21_sscanf(str, format, s21_vars);
  int lib_res = sscanf(str, format, lib_vars);

  ck_assert_int_eq(s21_res, lib_res);
  ck_assert_str_eq(s21_vars, lib_vars);
}
END_TEST

START_TEST(sscanf_s_test_4) {
  const void* str = "  абвгд 123asd";
  const void* format = "%15s";

  char s21_vars[16] = {0};
  char lib_vars[16] = {0};

  int s21_res = s21_sscanf(str, format, s21_vars);
  int lib_res = sscanf(str, format, lib_vars);

  ck_assert_int_eq(s21_res, lib_res);
  ck_assert_str_eq(s21_vars, lib_vars);
}
END_TEST

START_TEST(sscanf_s_test_5) {
  const void* str = " abcojetiosdhtoiweoiuthsdjfkahtaehrtokajdfklg";
  const void* format = "%s";

  char s21_vars[100] = {0};
  char lib_vars[100] = {0};

  int s21_res = s21_sscanf(str, format, s21_vars);
  int lib_res = sscanf(str, format, lib_vars);

  ck_assert_int_eq(s21_res, lib_res);
  ck_assert_str_eq(s21_vars, lib_vars);
}
END_TEST

START_TEST(sscanf_s_test_6) {
  const void* str = " abcojetiosdhtoiweoiuthsdjfkahtaehrtokajdfklg";
  const void* format = "%5s %s";

  char s21_vars[15] = {0}, s21_vars1[100] = {0};
  char lib_vars[15] = {0}, lib_vars1[100] = {0};

  int s21_res = s21_sscanf(str, format, s21_vars, s21_vars1);
  int lib_res = sscanf(str, format, lib_vars, lib_vars1);

  ck_assert_int_eq(s21_res, lib_res);
  ck_assert_str_eq(s21_vars, lib_vars);
  ck_assert_str_eq(s21_vars1, lib_vars1);
}
END_TEST

START_TEST(sscanf_s_test_7) {
  const void* str = " abcojetiosdhtoiweoiuthsdjfkahtaehrtokajdfklg";
  const void* format = "%s %5s";

  char s21_vars[100] = {0}, s21_vars1[15] = {0};
  char lib_vars[100] = {0}, lib_vars1[15] = {0};

  int s21_res = s21_sscanf(str, format, s21_vars, s21_vars1);
  int lib_res = sscanf(str, format, lib_vars, lib_vars1);

  ck_assert_int_eq(s21_res, lib_res);
  ck_assert_str_eq(s21_vars, lib_vars);
  ck_assert_str_eq(s21_vars1, lib_vars1);
}
END_TEST

START_TEST(sscanf_s_test_8) {
  const void* str = " шфцкршыво25823!%№;68asd   ";
  const void* format = "%s %s";

  char s21_vars[100] = {0}, s21_vars1[100] = {0};
  char lib_vars[100] = {0}, lib_vars1[100] = {0};

  int s21_res = s21_sscanf(str, format, s21_vars, s21_vars1);
  int lib_res = sscanf(str, format, lib_vars, lib_vars1);

  ck_assert_int_eq(s21_res, lib_res);
  ck_assert_str_eq(s21_vars, lib_vars);
  ck_assert_str_eq(s21_vars1, lib_vars1);
}
END_TEST

START_TEST(sscanf_s_test_9) {
  const void* str = "jsadjhasduas asdsad asd";
  const void* format = "%*3s %3s";

  char s21_vars[100] = {0}, s21_vars1[100] = {0};
  char lib_vars[100] = {0}, lib_vars1[100] = {0};

  int s21_res = s21_sscanf(str, format, s21_vars, s21_vars1);
  int lib_res = sscanf(str, format, lib_vars, lib_vars1);

  ck_assert_int_eq(s21_res, lib_res);
  ck_assert_str_eq(s21_vars, lib_vars);
  ck_assert_str_eq(s21_vars1, lib_vars1);
}
END_TEST

START_TEST(sscanf_s_test_10) {
  const void* str = "jsadjhasduas asdsad asd";
  const void* format = "%3s %*3s";

  char s21_vars[100] = {0}, s21_vars1[100] = {0};
  char lib_vars[100] = {0}, lib_vars1[100] = {0};

  int s21_res = s21_sscanf(str, format, s21_vars, s21_vars1);
  int lib_res = sscanf(str, format, lib_vars, lib_vars1);

  ck_assert_int_eq(s21_res, lib_res);
  ck_assert_str_eq(s21_vars, lib_vars);
  ck_assert_str_eq(s21_vars1, lib_vars1);
}
END_TEST

START_TEST(sscanf_s_test_11) {
  const void* str = "jsadjhasduas asdsad asd";
  const void* format = "%*3s %*3s";

  char s21_vars[100] = {0}, s21_vars1[100] = {0};
  char lib_vars[100] = {0}, lib_vars1[100] = {0};

  int s21_res = s21_sscanf(str, format, s21_vars, s21_vars1);
  int lib_res = sscanf(str, format, lib_vars, lib_vars1);

  ck_assert_int_eq(s21_res, lib_res);
  ck_assert_str_eq(s21_vars, lib_vars);
  ck_assert_str_eq(s21_vars1, lib_vars1);
}
END_TEST

START_TEST(sscanf_s_test_12) {
  const void* str = "jsadjhasduas asdsad asd";
  const void* format = "%*s %*s";

  char s21_vars[100] = {0}, s21_vars1[100] = {0};
  char lib_vars[100] = {0}, lib_vars1[100] = {0};

  int s21_res = s21_sscanf(str, format, s21_vars, s21_vars1);
  int lib_res = sscanf(str, format, lib_vars, lib_vars1);

  ck_assert_int_eq(s21_res, lib_res);
  ck_assert_str_eq(s21_vars, lib_vars);
  ck_assert_str_eq(s21_vars1, lib_vars1);
}
END_TEST

START_TEST(sscanf_s_test_13) {
  const void* str = "jsadjhasduas asdsad asd";
  const void* format = "%s %*s";

  char s21_vars[100] = {0}, s21_vars1[100] = {0};
  char lib_vars[100] = {0}, lib_vars1[100] = {0};

  int s21_res = s21_sscanf(str, format, s21_vars, s21_vars1);
  int lib_res = sscanf(str, format, lib_vars, lib_vars1);

  ck_assert_int_eq(s21_res, lib_res);
  ck_assert_str_eq(s21_vars, lib_vars);
  ck_assert_str_eq(s21_vars1, lib_vars1);
}
END_TEST

START_TEST(sscanf_s_test_14) {
  const void* str = "jsadjhasduas asdsad asd";
  const void* format = "%*s %s";

  char s21_vars[100] = {0}, s21_vars1[100] = {0};
  char lib_vars[100] = {0}, lib_vars1[100] = {0};

  int s21_res = s21_sscanf(str, format, s21_vars, s21_vars1);
  int lib_res = sscanf(str, format, lib_vars, lib_vars1);

  ck_assert_int_eq(s21_res, lib_res);
  ck_assert_str_eq(s21_vars, lib_vars);
  ck_assert_str_eq(s21_vars1, lib_vars1);
}
END_TEST

TCase* sscanf_s_get_tests(void) {
  TCase* test_cases = tcase_create("sscanf_s_cases");

  tcase_add_test(test_cases, sscanf_s_test_1);
  tcase_add_test(test_cases, sscanf_s_test_2);
  tcase_add_test(test_cases, sscanf_s_test_3);
  tcase_add_test(test_cases, sscanf_s_test_4);
  tcase_add_test(test_cases, sscanf_s_test_5);
  tcase_add_test(test_cases, sscanf_s_test_6);
  tcase_add_test(test_cases, sscanf_s_test_7);
  tcase_add_test(test_cases, sscanf_s_test_8);
  tcase_add_test(test_cases, sscanf_s_test_9);
  tcase_add_test(test_cases, sscanf_s_test_10);
  tcase_add_test(test_cases, sscanf_s_test_11);
  tcase_add_test(test_cases, sscanf_s_test_12);
  tcase_add_test(test_cases, sscanf_s_test_13);
  tcase_add_test(test_cases, sscanf_s_test_14);

  return test_cases;
}
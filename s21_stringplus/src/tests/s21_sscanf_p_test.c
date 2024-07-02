#include <check.h>
#include <limits.h>

#include "../s21_string.h"

START_TEST(sscanf_p_test_1) {
  const void* str = "0x7ffdbb9c5f40";
  const void* format = "%p";

  int* s21_vars = s21_NULL;
  int* lib_vars = s21_NULL;

  int s21_res = s21_sscanf(str, format, &s21_vars);
  int lib_res = sscanf(str, format, &lib_vars);

  ck_assert_int_eq(s21_res, lib_res);
  for (int i = 0; i < 1; i++) {
    ck_assert_ptr_eq(s21_vars, lib_vars);
  }
}
END_TEST

START_TEST(sscanf_p_test_2) {
  const void* str = " 0x3 abc";
  const void* format = "%p abc";

  void* s21_vars = s21_NULL;
  void* lib_vars = s21_NULL;

  int s21_res = s21_sscanf(str, format, &s21_vars);
  int lib_res = sscanf(str, format, &lib_vars);

  ck_assert_int_eq(s21_res, lib_res);
  for (int i = 0; i < 1; i++) {
    ck_assert_ptr_eq(s21_vars, lib_vars);
  }
}
END_TEST

START_TEST(sscanf_p_test_3) {
  const void* str = " 0x";
  const void* format = "%p";

  void* s21_vars = s21_NULL;
  void* lib_vars = s21_NULL;

  int s21_res = s21_sscanf(str, format, &s21_vars);
  int lib_res = sscanf(str, format, &lib_vars);

  ck_assert_int_eq(s21_res, lib_res);
  for (int i = 0; i < 1; i++) {
    ck_assert_ptr_eq(s21_vars, lib_vars);
  }
}
END_TEST

START_TEST(sscanf_p_test_4) {
  const void* str = " 0";
  const void* format = "%p";

  void* s21_vars = s21_NULL;
  void* lib_vars = s21_NULL;

  int s21_res = s21_sscanf(str, format, &s21_vars);
  int lib_res = sscanf(str, format, &lib_vars);

  ck_assert_int_eq(s21_res, lib_res);
  for (int i = 0; i < 1; i++) {
    ck_assert_ptr_eq(s21_vars, lib_vars);
  }
}
END_TEST

START_TEST(sscanf_p_test_5) {
  const void* str = " ";
  const void* format = "%p";

  void* s21_vars = s21_NULL;
  void* lib_vars = s21_NULL;

  int s21_res = s21_sscanf(str, format, &s21_vars);
  int lib_res = sscanf(str, format, &lib_vars);

  ck_assert_int_eq(s21_res, lib_res);
  for (int i = 0; i < 1; i++) {
    ck_assert_ptr_eq(s21_vars, lib_vars);
  }
}
END_TEST

START_TEST(sscanf_p_test_6) {
  const void* str = "";
  const void* format = "%p";

  void* s21_vars = s21_NULL;
  void* lib_vars = s21_NULL;

  int s21_res = s21_sscanf(str, format, &s21_vars);
  int lib_res = sscanf(str, format, &lib_vars);

  ck_assert_int_eq(s21_res, lib_res);
  for (int i = 0; i < 1; i++) {
    ck_assert_ptr_eq(s21_vars, lib_vars);
  }
}
END_TEST

START_TEST(sscanf_p_test_7) {
  const void* str = "NULL";
  const void* format = "%p";

  void* s21_vars = s21_NULL;
  void* lib_vars = s21_NULL;

  int s21_res = s21_sscanf(str, format, &s21_vars);
  int lib_res = sscanf(str, format, &lib_vars);

  ck_assert_int_eq(s21_res, lib_res);
  for (int i = 0; i < 1; i++) {
    ck_assert_ptr_eq(s21_vars, lib_vars);
  }
}
END_TEST

START_TEST(sscanf_p_test_8) {
  const void* str = " 0x3aAaAa ";
  const void* format = "%p";

  void* s21_vars = s21_NULL;
  void* lib_vars = s21_NULL;

  int s21_res = s21_sscanf(str, format, &s21_vars);
  int lib_res = sscanf(str, format, &lib_vars);

  ck_assert_int_eq(s21_res, lib_res);
  for (int i = 0; i < 1; i++) {
    ck_assert_ptr_eq(s21_vars, lib_vars);
  }
}
END_TEST

START_TEST(sscanf_p_test_9) {
  const void* str = " 0X3aAaAa ";
  const void* format = "%p";

  void* s21_vars = s21_NULL;
  void* lib_vars = s21_NULL;

  int s21_res = s21_sscanf(str, format, &s21_vars);
  int lib_res = sscanf(str, format, &lib_vars);

  ck_assert_int_eq(s21_res, lib_res);
  for (int i = 0; i < 1; i++) {
    ck_assert_ptr_eq(s21_vars, lib_vars);
  }
}
END_TEST

START_TEST(sscanf_p_test_10) {
  const void* str = " 0XFFFFFFFFFFFFFFFFFFF";
  const void* format = "%p";

  void* s21_vars = s21_NULL;
  void* lib_vars = s21_NULL;

  int s21_res = s21_sscanf(str, format, &s21_vars);
  int lib_res = sscanf(str, format, &lib_vars);

  ck_assert_int_eq(s21_res, lib_res);
  for (int i = 0; i < 1; i++) {
    ck_assert_ptr_eq(s21_vars, lib_vars);
  }
}
END_TEST

TCase* sscanf_p_get_tests(void) {
  TCase* test_cases = tcase_create("sscanf_p_cases");

  tcase_add_test(test_cases, sscanf_p_test_1);
  tcase_add_test(test_cases, sscanf_p_test_2);
  tcase_add_test(test_cases, sscanf_p_test_3);
  tcase_add_test(test_cases, sscanf_p_test_4);
  tcase_add_test(test_cases, sscanf_p_test_5);
  tcase_add_test(test_cases, sscanf_p_test_6);
  tcase_add_test(test_cases, sscanf_p_test_7);
  tcase_add_test(test_cases, sscanf_p_test_8);
  tcase_add_test(test_cases, sscanf_p_test_9);
  tcase_add_test(test_cases, sscanf_p_test_10);

  return test_cases;
}
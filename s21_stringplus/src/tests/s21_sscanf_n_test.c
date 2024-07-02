#include <check.h>
#include <limits.h>

#include "../s21_string.h"

START_TEST(sscanf_n_test_1) {
  const void* str = "abc    %";
  const void* format = "abc %%%n";

  int s21_vars[1] = {-1};
  int lib_vars[1] = {-1};

  int s21_res = s21_sscanf(str, format, &s21_vars[0]);
  int lib_res = sscanf(str, format, &lib_vars[0]);

  ck_assert_int_eq(s21_res, lib_res);
  for (int i = 0; i < 1; i++) {
    ck_assert_int_eq(s21_vars[i], lib_vars[i]);
  }
}
END_TEST

START_TEST(sscanf_n_test_2) {
  const void* str =
      "%nabcабв 123                                                           "
      "%";
  const void* format = "%nabcабв 123 %%%n%n%n";

  int s21_vars[4] = {-1};
  int lib_vars[4] = {-1};

  int s21_res = s21_sscanf(str, format, &s21_vars[0], &s21_vars[1],
                           &s21_vars[2], &s21_vars[3]);
  int lib_res = sscanf(str, format, &lib_vars[0], &lib_vars[1], &lib_vars[2],
                       &lib_vars[3]);

  ck_assert_int_eq(s21_res, lib_res);
  for (int i = 0; i < 4; i++) {
    ck_assert_int_eq(s21_vars[i], lib_vars[i]);
  }
}
END_TEST

START_TEST(sscanf_n_test_3) {
  const void* str =
      "abcабв 123                                                           %";
  const void* format = "%nabcабв 123 %%%n%n%n";

  int s21_vars[4] = {-1};
  int lib_vars[4] = {-1};

  int s21_res = s21_sscanf(str, format, &s21_vars[0], &s21_vars[1],
                           &s21_vars[2], &s21_vars[3]);
  int lib_res = sscanf(str, format, &lib_vars[0], &lib_vars[1], &lib_vars[2],
                       &lib_vars[3]);

  ck_assert_int_eq(s21_res, lib_res);
  for (int i = 0; i < 4; i++) {
    ck_assert_int_eq(s21_vars[i], lib_vars[i]);
  }
}
END_TEST

START_TEST(sscanf_n_test_4) {
  const void* str = "abcабв 634634 0x3abc 0x333 ";
  const void* format = "%nabcабв %d%n %x%n %o%n%n%n%n";

  int s21_vars[7] = {-1};
  int lib_vars[7] = {-1};
  int tmp = 0;
  unsigned int tmp1 = 0, tmp2 = 0;

  int s21_res = s21_sscanf(str, format, &s21_vars[0], &tmp, &s21_vars[1], &tmp1,
                           &s21_vars[2], &tmp2, &s21_vars[3], &s21_vars[4],
                           &s21_vars[5], &s21_vars[6]);
  int lib_res =
      sscanf(str, format, &lib_vars[0], &tmp, &lib_vars[1], &tmp1, &lib_vars[2],
             &tmp2, &lib_vars[3], &lib_vars[4], &lib_vars[5], &lib_vars[6]);

  ck_assert_int_eq(s21_res, lib_res);
  for (int i = 0; i < 7; i++) {
    ck_assert_int_eq(s21_vars[i], lib_vars[i]);
  }
}
END_TEST

START_TEST(sscanf_n_test_5) {
  const void* str = "hasdjsahdjahsdjas";
  const void* format = "%n%3s%n%c%n";

  int s21_vars[3] = {-1};
  int lib_vars[3] = {-1};
  char tmp[10] = {0};
  char tmp1 = 0;

  int s21_res = s21_sscanf(str, format, &s21_vars[0], tmp, &s21_vars[1], &tmp1,
                           &s21_vars[2]);
  int lib_res =
      sscanf(str, format, &lib_vars[0], tmp, &lib_vars[1], &tmp1, &lib_vars[2]);

  ck_assert_int_eq(s21_res, lib_res);
  for (int i = 0; i < 3; i++) {
    ck_assert_int_eq(s21_vars[i], lib_vars[i]);
  }
}
END_TEST

START_TEST(sscanf_n_test_6) {
  const void* str = "hasdjsahdjahsdjas";
  const void* format = "%*n%3s%n%c%*n";

  int s21_vars[3] = {-1};
  int lib_vars[3] = {-1};
  char tmp[10] = {0};
  char tmp1 = 0;

  int s21_res = s21_sscanf(str, format, &s21_vars[0], tmp, &s21_vars[1], &tmp1,
                           &s21_vars[2]);
  int lib_res =
      sscanf(str, format, &lib_vars[0], tmp, &lib_vars[1], &tmp1, &lib_vars[2]);

  ck_assert_int_eq(s21_res, lib_res);
  for (int i = 0; i < 3; i++) {
    ck_assert_int_eq(s21_vars[i], lib_vars[i]);
  }
}
END_TEST

START_TEST(sscanf_n_test_7) {
  const void* str = "hasdjsahdjahsdjas";
  const void* format = "%*n%3s%*n%c%*n";

  int s21_vars[3] = {-1};
  int lib_vars[3] = {-1};
  char tmp[10] = {0};
  char tmp1 = 0;

  int s21_res = s21_sscanf(str, format, &s21_vars[0], tmp, &s21_vars[1], &tmp1,
                           &s21_vars[2]);
  int lib_res =
      sscanf(str, format, &lib_vars[0], tmp, &lib_vars[1], &tmp1, &lib_vars[2]);

  ck_assert_int_eq(s21_res, lib_res);
  for (int i = 0; i < 3; i++) {
    ck_assert_int_eq(s21_vars[i], lib_vars[i]);
  }
}
END_TEST

START_TEST(sscanf_n_test_8) {
  const void* str = "hasdjsahdjahsdjas";
  const void* format = "%*n%*n%3s%c%n";

  int s21_vars[3] = {-1};
  int lib_vars[3] = {-1};
  char tmp[10] = {0};
  char tmp1 = 0;

  int s21_res = s21_sscanf(str, format, &s21_vars[0], tmp, &s21_vars[1], &tmp1,
                           &s21_vars[2]);
  int lib_res =
      sscanf(str, format, &lib_vars[0], tmp, &lib_vars[1], &tmp1, &lib_vars[2]);

  ck_assert_int_eq(s21_res, lib_res);
  for (int i = 0; i < 3; i++) {
    ck_assert_int_eq(s21_vars[i], lib_vars[i]);
  }
}
END_TEST

START_TEST(sscanf_n_test_9) {
  const void* str = "hasdjsahdjahsdjas";
  const void* format = "%n%n%3s%c%*n";

  int s21_vars[3] = {-1};
  int lib_vars[3] = {-1};
  char tmp[10] = {0};
  char tmp1 = 0;

  int s21_res = s21_sscanf(str, format, &s21_vars[0], tmp, &s21_vars[1], &tmp1,
                           &s21_vars[2]);
  int lib_res =
      sscanf(str, format, &lib_vars[0], tmp, &lib_vars[1], &tmp1, &lib_vars[2]);

  ck_assert_int_eq(s21_res, lib_res);
  for (int i = 0; i < 3; i++) {
    ck_assert_int_eq(s21_vars[i], lib_vars[i]);
  }
}
END_TEST

TCase* sscanf_n_get_tests(void) {
  TCase* test_cases = tcase_create("sscanf_n_cases");

  tcase_add_test(test_cases, sscanf_n_test_1);
  tcase_add_test(test_cases, sscanf_n_test_2);
  tcase_add_test(test_cases, sscanf_n_test_3);
  tcase_add_test(test_cases, sscanf_n_test_4);
  tcase_add_test(test_cases, sscanf_n_test_4);
  tcase_add_test(test_cases, sscanf_n_test_5);
  tcase_add_test(test_cases, sscanf_n_test_6);
  tcase_add_test(test_cases, sscanf_n_test_7);
  tcase_add_test(test_cases, sscanf_n_test_8);
  tcase_add_test(test_cases, sscanf_n_test_9);

  return test_cases;
}
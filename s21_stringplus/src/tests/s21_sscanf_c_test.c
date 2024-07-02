#include <check.h>
#include <limits.h>

#include "../s21_string.h"

START_TEST(sscanf_c_test_1) {
  const void* str = " b!ь        35";
  const void* format = "%c%c%c%c        3%c";

  char s21_vars[5] = {0};
  char lib_vars[5] = {0};

  int s21_res = s21_sscanf(str, format, &s21_vars[0], &s21_vars[1],
                           &s21_vars[2], &s21_vars[3], &s21_vars[4]);
  int lib_res = sscanf(str, format, &lib_vars[0], &lib_vars[1], &lib_vars[2],
                       &lib_vars[3], &lib_vars[4]);

  ck_assert_int_eq(s21_res, lib_res);
  for (int i = 0; i < 5; i++) {
    ck_assert_int_eq(s21_vars[i], lib_vars[i]);
  }
}
END_TEST

START_TEST(sscanf_c_test_2) {
  const void* str = "яs3! ";
  const void* format = "%c%c%c%c%c%c%c%c";

  char s21_vars[8] = {0};
  char lib_vars[8] = {0};

  int s21_res = s21_sscanf(str, format, &s21_vars[0], &s21_vars[1],
                           &s21_vars[2], &s21_vars[3], &s21_vars[4],
                           &s21_vars[5], &s21_vars[6], &s21_vars[7]);
  int lib_res = sscanf(str, format, &lib_vars[0], &lib_vars[1], &lib_vars[2],
                       &lib_vars[3], &lib_vars[4], &lib_vars[5], &lib_vars[6],
                       &lib_vars[7]);

  ck_assert_int_eq(s21_res, lib_res);
  for (int i = 0; i < 8; i++) {
    ck_assert_int_eq(s21_vars[i], lib_vars[i]);
  }
}
END_TEST

START_TEST(sscanf_c_test_3) {
  const void* str = "яs3! ";
  const void* format = "%c";

  char s21_vars[1] = {0};
  char lib_vars[1] = {0};

  int s21_res = s21_sscanf(str, format, &s21_vars[0]);
  int lib_res = sscanf(str, format, &lib_vars[0]);

  ck_assert_int_eq(s21_res, lib_res);
  for (int i = 0; i < 1; i++) {
    ck_assert_int_eq(s21_vars[i], lib_vars[i]);
  }
}
END_TEST

START_TEST(sscanf_c_test_4) {
  const void* str = "3 a b c4576333";
  const void* format = " %c4576%c";

  char s21_vars[2] = {0};
  char lib_vars[2] = {0};

  int s21_res = s21_sscanf(str, format, &s21_vars[0], &s21_vars[1]);
  int lib_res = sscanf(str, format, &lib_vars[0], &lib_vars[1]);

  ck_assert_int_eq(s21_res, lib_res);
  for (int i = 0; i < 2; i++) {
    ck_assert_int_eq(s21_vars[i], lib_vars[i]);
  }
}
END_TEST

START_TEST(sscanf_c_test_5) {
  const void* str = "яs3! ";
  const void* format = "%0c %1c %c";

  char s21_vars[3] = {0};
  char lib_vars[3] = {0};

  int s21_res =
      s21_sscanf(str, format, &s21_vars[0], &s21_vars[1], &s21_vars[2]);
  int lib_res = sscanf(str, format, &lib_vars[0], &lib_vars[1], &lib_vars[2]);

  ck_assert_int_eq(s21_res, lib_res);
  for (int i = 0; i < 3; i++) {
    ck_assert_int_eq(s21_vars[i], lib_vars[i]);
  }
}
END_TEST

START_TEST(sscanf_c_test_6) {
  const void* str = "абвгде";
  const void* format = "%c%c%c";

  char s21_vars[3] = {0};
  char lib_vars[3] = {0};

  int s21_res =
      s21_sscanf(str, format, &s21_vars[0], &s21_vars[1], &s21_vars[2]);
  int lib_res = sscanf(str, format, &lib_vars[0], &lib_vars[1], &lib_vars[2]);

  ck_assert_int_eq(s21_res, lib_res);
  for (int i = 0; i < 3; i++) {
    ck_assert_int_eq(s21_vars[i], lib_vars[i]);
  }
}
END_TEST

START_TEST(sscanf_c_test_7) {
  const void* str = "абвгде";
  const void* format = "%0c%0c%0c";

  char s21_vars[3] = {0};
  char lib_vars[3] = {0};

  int s21_res =
      s21_sscanf(str, format, &s21_vars[0], &s21_vars[1], &s21_vars[2]);
  int lib_res = sscanf(str, format, &lib_vars[0], &lib_vars[1], &lib_vars[2]);

  ck_assert_int_eq(s21_res, lib_res);
  for (int i = 0; i < 3; i++) {
    ck_assert_int_eq(s21_vars[i], lib_vars[i]);
  }
}
END_TEST

START_TEST(sscanf_c_test_8) {
  const void* str = "abcde";
  const void* format = "%c%c%c";

  char s21_vars[3] = {0};
  char lib_vars[3] = {0};

  int s21_res =
      s21_sscanf(str, format, &s21_vars[0], &s21_vars[1], &s21_vars[2]);
  int lib_res = sscanf(str, format, &lib_vars[0], &lib_vars[1], &lib_vars[2]);

  ck_assert_int_eq(s21_res, lib_res);
  for (int i = 0; i < 3; i++) {
    ck_assert_int_eq(s21_vars[i], lib_vars[i]);
  }
}
END_TEST

START_TEST(sscanf_c_test_9) {
  const void* str = "abcde";
  const void* format = "%0c%0c%0c";

  char s21_vars[3] = {0};
  char lib_vars[3] = {0};

  int s21_res =
      s21_sscanf(str, format, &s21_vars[0], &s21_vars[1], &s21_vars[2]);
  int lib_res = sscanf(str, format, &lib_vars[0], &lib_vars[1], &lib_vars[2]);

  ck_assert_int_eq(s21_res, lib_res);
  for (int i = 0; i < 3; i++) {
    ck_assert_int_eq(s21_vars[i], lib_vars[i]);
  }
}
END_TEST

START_TEST(sscanf_c_test_10) {
  const void* str = "%a%bc";
  const void* format = "%%%c%c%c";

  char s21_vars[3] = {0};
  char lib_vars[3] = {0};

  int s21_res =
      s21_sscanf(str, format, &s21_vars[0], &s21_vars[1], &s21_vars[2]);
  int lib_res = sscanf(str, format, &lib_vars[0], &lib_vars[1], &lib_vars[2]);

  ck_assert_int_eq(s21_res, lib_res);
  for (int i = 0; i < 3; i++) {
    ck_assert_int_eq(s21_vars[i], lib_vars[i]);
  }
}
END_TEST

START_TEST(sscanf_c_test_11) {
  const void* str = "    %  % %                     a1b2c3";
  const void* format = " %% %% %% %c1%c2%c3";

  char s21_vars[3] = {0};
  char lib_vars[3] = {0};

  int s21_res =
      s21_sscanf(str, format, &s21_vars[0], &s21_vars[1], &s21_vars[2]);
  int lib_res = sscanf(str, format, &lib_vars[0], &lib_vars[1], &lib_vars[2]);

  ck_assert_int_eq(s21_res, lib_res);
  for (int i = 0; i < 3; i++) {
    ck_assert_int_eq(s21_vars[i], lib_vars[i]);
  }
}
END_TEST

START_TEST(sscanf_c_test_12) {
  const void* str = "abcde";
  const void* format = "%*c%c%*c";

  char s21_vars[3] = {0};
  char lib_vars[3] = {0};

  int s21_res =
      s21_sscanf(str, format, &s21_vars[0], &s21_vars[1], &s21_vars[2]);
  int lib_res = sscanf(str, format, &lib_vars[0], &lib_vars[1], &lib_vars[2]);

  ck_assert_int_eq(s21_res, lib_res);
  for (int i = 0; i < 3; i++) {
    ck_assert_int_eq(s21_vars[i], lib_vars[i]);
  }
}
END_TEST

START_TEST(sscanf_c_test_13) {
  const void* str = "abcde";
  const void* format = "%c%*c%c";

  char s21_vars[3] = {0};
  char lib_vars[3] = {0};

  int s21_res =
      s21_sscanf(str, format, &s21_vars[0], &s21_vars[1], &s21_vars[2]);
  int lib_res = sscanf(str, format, &lib_vars[0], &lib_vars[1], &lib_vars[2]);

  ck_assert_int_eq(s21_res, lib_res);
  for (int i = 0; i < 3; i++) {
    ck_assert_int_eq(s21_vars[i], lib_vars[i]);
  }
}
END_TEST

START_TEST(sscanf_c_test_14) {
  const void* str = "abcde";
  const void* format = "%*c%*c%*c";

  char s21_vars[3] = {0};
  char lib_vars[3] = {0};

  int s21_res =
      s21_sscanf(str, format, &s21_vars[0], &s21_vars[1], &s21_vars[2]);
  int lib_res = sscanf(str, format, &lib_vars[0], &lib_vars[1], &lib_vars[2]);

  ck_assert_int_eq(s21_res, lib_res);
  for (int i = 0; i < 3; i++) {
    ck_assert_int_eq(s21_vars[i], lib_vars[i]);
  }
}
END_TEST

START_TEST(sscanf_c_test_15) {
  const void* str = "аабвгд";
  const void* format = "%c%*c%*c%c";

  char s21_vars[4] = {0};
  char lib_vars[4] = {0};

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

TCase* sscanf_c_get_tests(void) {
  TCase* test_cases = tcase_create("sscanf_c_cases");

  tcase_add_test(test_cases, sscanf_c_test_1);
  tcase_add_test(test_cases, sscanf_c_test_2);
  tcase_add_test(test_cases, sscanf_c_test_3);
  tcase_add_test(test_cases, sscanf_c_test_4);
  tcase_add_test(test_cases, sscanf_c_test_5);
  tcase_add_test(test_cases, sscanf_c_test_6);
  tcase_add_test(test_cases, sscanf_c_test_7);
  tcase_add_test(test_cases, sscanf_c_test_8);
  tcase_add_test(test_cases, sscanf_c_test_9);
  tcase_add_test(test_cases, sscanf_c_test_10);
  tcase_add_test(test_cases, sscanf_c_test_11);
  tcase_add_test(test_cases, sscanf_c_test_12);
  tcase_add_test(test_cases, sscanf_c_test_13);
  tcase_add_test(test_cases, sscanf_c_test_14);
  tcase_add_test(test_cases, sscanf_c_test_15);

  return test_cases;
}
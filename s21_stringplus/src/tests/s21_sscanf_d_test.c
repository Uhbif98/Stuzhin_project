#include <check.h>
#include <limits.h>

#include "../s21_string.h"

START_TEST(sscanf_d_test_1) {
  const void* str = "    3 45                                   -3  1 3 5";
  const void* format = " %d%d    %d";

  int s21_vars[3] = {-1};
  int lib_vars[3] = {-1};

  int s21_res =
      s21_sscanf(str, format, &s21_vars[0], &s21_vars[1], &s21_vars[2]);
  int lib_res = sscanf(str, format, &lib_vars[0], &lib_vars[1], &lib_vars[2]);

  ck_assert_int_eq(s21_res, lib_res);
  for (int i = 0; i < 3; i++) {
    ck_assert_int_eq(s21_vars[i], lib_vars[i]);
  }
}
END_TEST

START_TEST(sscanf_d_test_2) {
  const void* str = "346    343645      333";
  const void* format = "%d%d%d";

  int s21_vars[3] = {-1};
  int lib_vars[3] = {-1};

  int s21_res =
      s21_sscanf(str, format, &s21_vars[0], &s21_vars[1], &s21_vars[2]);
  int lib_res = sscanf(str, format, &lib_vars[0], &lib_vars[1], &lib_vars[2]);

  ck_assert_int_eq(s21_res, lib_res);
  for (int i = 0; i < 3; i++) {
    ck_assert_int_eq(s21_vars[i], lib_vars[i]);
  }
}
END_TEST

START_TEST(sscanf_d_test_3) {
  const void* str = "3e46.55a535333    3b43645      3a33";
  const void* format = "%d%d%d";

  int s21_vars[3] = {-1};
  int lib_vars[3] = {-1};

  int s21_res =
      s21_sscanf(str, format, &s21_vars[0], &s21_vars[1], &s21_vars[2]);
  int lib_res = sscanf(str, format, &lib_vars[0], &lib_vars[1], &lib_vars[2]);

  ck_assert_int_eq(s21_res, lib_res);
  for (int i = 0; i < 3; i++) {
    ck_assert_int_eq(s21_vars[i], lib_vars[i]);
  }
}
END_TEST

START_TEST(sscanf_d_test_4) {
  const void* str = " a 3 a b c";
  const void* format = "%d%d%d";

  int s21_vars[3] = {-1};
  int lib_vars[3] = {-1};

  int s21_res =
      s21_sscanf(str, format, &s21_vars[0], &s21_vars[1], &s21_vars[2]);
  int lib_res = sscanf(str, format, &lib_vars[0], &lib_vars[1], &lib_vars[2]);

  ck_assert_int_eq(s21_res, lib_res);
  for (int i = 0; i < 3; i++) {
    ck_assert_int_eq(s21_vars[i], lib_vars[i]);
  }
}
END_TEST

START_TEST(sscanf_d_test_5) {
  const void* str = "3";
  const void* format = "   %d    %d     %d";

  int s21_vars[3] = {-1};
  int lib_vars[3] = {-1};

  int s21_res =
      s21_sscanf(str, format, &s21_vars[0], &s21_vars[1], &s21_vars[2]);
  int lib_res = sscanf(str, format, &lib_vars[0], &lib_vars[1], &lib_vars[2]);

  ck_assert_int_eq(s21_res, lib_res);
  for (int i = 0; i < 3; i++) {
    ck_assert_int_eq(s21_vars[i], lib_vars[i]);
  }
}
END_TEST

START_TEST(sscanf_d_test_6) {
  const void* str = ".3.5.3";
  const void* format = "   %d    %d     %d";

  int s21_vars[3] = {-1};
  int lib_vars[3] = {-1};

  int s21_res =
      s21_sscanf(str, format, &s21_vars[0], &s21_vars[1], &s21_vars[2]);
  int lib_res = sscanf(str, format, &lib_vars[0], &lib_vars[1], &lib_vars[2]);

  ck_assert_int_eq(s21_res, lib_res);
  for (int i = 0; i < 3; i++) {
    ck_assert_int_eq(s21_vars[i], lib_vars[i]);
  }
}
END_TEST

START_TEST(sscanf_d_test_7) {
  const void* str = "+73 -74 --75 ++76 + - ++ -- 555";
  const void* format = "   %d    %d     %d %d %d";

  int s21_vars[5] = {-1};
  int lib_vars[5] = {-1};

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

START_TEST(sscanf_d_test_8) {
  const void* str = "abc        3-5-7+6+11";
  const void* format = "abc %d-%d%d+%d%d";

  int s21_vars[5] = {-1};
  int lib_vars[5] = {-1};

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

START_TEST(sscanf_d_test_9) {
  const void* str = "abc        3-5-7+6+11";
  const void* format = "abc %d-%d%d+%d%d %d%d %d    %d%d";

  int s21_vars[10] = {-1};
  int lib_vars[10] = {-1};

  int s21_res =
      s21_sscanf(str, format, &s21_vars[0], &s21_vars[1], &s21_vars[2],
                 &s21_vars[3], &s21_vars[4], &s21_vars[5], &s21_vars[6],
                 &s21_vars[7], &s21_vars[8], &s21_vars[9]);
  int lib_res = sscanf(str, format, &lib_vars[0], &lib_vars[1], &lib_vars[2],
                       &lib_vars[3], &lib_vars[4], &lib_vars[5], &lib_vars[6],
                       &lib_vars[7], &lib_vars[8], &lib_vars[9]);

  ck_assert_int_eq(s21_res, lib_res);
  for (int i = 0; i < 10; i++) {
    ck_assert_int_eq(s21_vars[i], lib_vars[i]);
  }
}
END_TEST

START_TEST(sscanf_d_test_10) {
  const void* str = "3 3A A A3A";
  const void* format = "%d %d %d %d";

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

START_TEST(sscanf_d_test_11) {
  const void* str = "37385 33 3";
  const void* format = "%d3%d";

  int s21_vars[2] = {-1};
  int lib_vars[2] = {-1};

  int s21_res = s21_sscanf(str, format, &s21_vars[0], &s21_vars[1]);
  int lib_res = sscanf(str, format, &lib_vars[0], &lib_vars[1]);

  ck_assert_int_eq(s21_res, lib_res);
  for (int i = 0; i < 2; i++) {
    ck_assert_int_eq(s21_vars[i], lib_vars[i]);
  }
}
END_TEST

START_TEST(sscanf_d_test_12) {
  const void* str = "37385 3      3 3";
  const void* format = "%d 3%d 3";

  int s21_vars[2] = {-1};
  int lib_vars[2] = {-1};

  int s21_res = s21_sscanf(str, format, &s21_vars[0], &s21_vars[1]);
  int lib_res = sscanf(str, format, &lib_vars[0], &lib_vars[1]);

  ck_assert_int_eq(s21_res, lib_res);
  for (int i = 0; i < 2; i++) {
    ck_assert_int_eq(s21_vars[i], lib_vars[i]);
  }
}
END_TEST

START_TEST(sscanf_d_test_13) {
  const void* str = "37385 3      3 3";
  const void* format = "%4d5 3%d 3";

  int s21_vars[2] = {-1};
  int lib_vars[2] = {-1};

  int s21_res = s21_sscanf(str, format, &s21_vars[0], &s21_vars[1]);
  int lib_res = sscanf(str, format, &lib_vars[0], &lib_vars[1]);

  ck_assert_int_eq(s21_res, lib_res);
  for (int i = 0; i < 2; i++) {
    ck_assert_int_eq(s21_vars[i], lib_vars[i]);
  }
}
END_TEST

START_TEST(sscanf_d_test_14) {
  const void* str = "37385 3      3 3";
  const void* format = "%5d5 3%d 3";

  int s21_vars[2] = {-1};
  int lib_vars[2] = {-1};

  int s21_res = s21_sscanf(str, format, &s21_vars[0], &s21_vars[1]);
  int lib_res = sscanf(str, format, &lib_vars[0], &lib_vars[1]);

  ck_assert_int_eq(s21_res, lib_res);
  for (int i = 0; i < 2; i++) {
    ck_assert_int_eq(s21_vars[i], lib_vars[i]);
  }
}
END_TEST

START_TEST(sscanf_d_test_15) {
  const void* str = "123456789";
  const void* format = "%3d %3d %3d %73d";

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

START_TEST(sscanf_d_test_16) {
  const void* str = "3Abc333 5+3+";
  const void* format = "    %3dAbc %   %7d+%3d%73d";

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

START_TEST(sscanf_d_test_17) {
  const void* str = "++3Abc333 5+3+";
  const void* format = "    %3dAbc %   %7d+%3d%73d";

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

START_TEST(sscanf_d_test_18) {
  const void* str = "-1 675333 -675333 3487634786333";
  const void* format = " %hd %hd %hd %hd";

  short int s21_vars[4] = {-1};
  short int lib_vars[4] = {-1};

  int s21_res = s21_sscanf(str, format, &s21_vars[0], &s21_vars[1],
                           &s21_vars[2], &s21_vars[3]);
  int lib_res = sscanf(str, format, &lib_vars[0], &lib_vars[1], &lib_vars[2],
                       &lib_vars[3]);

  ck_assert_int_eq(s21_res, lib_res);
  for (int i = 0; i < 4; i++) {
    ck_assert_msg(s21_vars[i] == lib_vars[i], "Error");
  }
}
END_TEST

START_TEST(sscanf_d_test_19) {
  const void* str = "-1 675333 -675333 3487634786333";
  const void* format = " %ld %ld %ld %ld";

  long int s21_vars[4] = {-1};
  long int lib_vars[4] = {-1};

  int s21_res = s21_sscanf(str, format, &s21_vars[0], &s21_vars[1],
                           &s21_vars[2], &s21_vars[3]);
  int lib_res = sscanf(str, format, &lib_vars[0], &lib_vars[1], &lib_vars[2],
                       &lib_vars[3]);

  ck_assert_int_eq(s21_res, lib_res);
  for (int i = 0; i < 4; i++) {
    ck_assert_msg(s21_vars[i] == lib_vars[i], "Error");
  }
}
END_TEST

START_TEST(sscanf_d_test_20) {
  const void* str =
      "-1 675333 -675333 3487634786333 259823289356238756237562387532";
  const void* format = " %Ld %Ld %Ld %Ld %10Ld";

  long long s21_vars[5] = {-1};
  long long lib_vars[5] = {-1};

  int s21_res = s21_sscanf(str, format, &s21_vars[0], &s21_vars[1],
                           &s21_vars[2], &s21_vars[3], &s21_vars[4]);
  int lib_res = sscanf(str, format, &lib_vars[0], &lib_vars[1], &lib_vars[2],
                       &lib_vars[3], &lib_vars[4]);

  ck_assert_int_eq(s21_res, lib_res);
  for (int i = 0; i < 5; i++) {
    ck_assert_msg(s21_vars[i] == lib_vars[i], "Error");
  }
}
END_TEST

START_TEST(sscanf_d_test_21) {
  const void* str = "82365 375 2353275 327563 3857";
  const void* format = " %Ld %*Ld %Ld %Ld %*3Ld";

  long long s21_vars[5] = {-1};
  long long lib_vars[5] = {-1};

  int s21_res = s21_sscanf(str, format, &s21_vars[0], &s21_vars[1],
                           &s21_vars[2], &s21_vars[3], &s21_vars[4]);
  int lib_res = sscanf(str, format, &lib_vars[0], &lib_vars[1], &lib_vars[2],
                       &lib_vars[3], &lib_vars[4]);

  ck_assert_int_eq(s21_res, lib_res);
  for (int i = 0; i < 5; i++) {
    ck_assert_msg(s21_vars[i] == lib_vars[i], "Error");
  }
}
END_TEST

START_TEST(sscanf_d_test_22) {
  const void* str = "82365457 375 2353275 327563";
  const void* format = " %*3d %d %d %d %3d";

  int s21_vars[5] = {-1};
  int lib_vars[5] = {-1};

  int s21_res = s21_sscanf(str, format, &s21_vars[0], &s21_vars[1],
                           &s21_vars[2], &s21_vars[3], &s21_vars[4]);
  int lib_res = sscanf(str, format, &lib_vars[0], &lib_vars[1], &lib_vars[2],
                       &lib_vars[3], &lib_vars[4]);

  ck_assert_int_eq(s21_res, lib_res);
  for (int i = 0; i < 5; i++) {
    ck_assert_msg(s21_vars[i] == lib_vars[i], "Error");
  }
}
END_TEST

START_TEST(sscanf_d_test_23) {
  const void* str = "82365457";
  const void* format = " %*1d %1d %*1d %1d %*1d";

  int s21_vars[5] = {-1};
  int lib_vars[5] = {-1};

  int s21_res = s21_sscanf(str, format, &s21_vars[0], &s21_vars[1],
                           &s21_vars[2], &s21_vars[3], &s21_vars[4]);
  int lib_res = sscanf(str, format, &lib_vars[0], &lib_vars[1], &lib_vars[2],
                       &lib_vars[3], &lib_vars[4]);

  ck_assert_int_eq(s21_res, lib_res);
  for (int i = 0; i < 5; i++) {
    ck_assert_msg(s21_vars[i] == lib_vars[i], "Error");
  }
}
END_TEST

START_TEST(sscanf_d_test_24) {
  const void* str = "-1 -2 -3 -4 -5";
  const void* format = " %*d %d %*d %d %*d";

  int s21_vars[5] = {-1};
  int lib_vars[5] = {-1};

  int s21_res = s21_sscanf(str, format, &s21_vars[0], &s21_vars[1],
                           &s21_vars[2], &s21_vars[3], &s21_vars[4]);
  int lib_res = sscanf(str, format, &lib_vars[0], &lib_vars[1], &lib_vars[2],
                       &lib_vars[3], &lib_vars[4]);

  ck_assert_int_eq(s21_res, lib_res);
  for (int i = 0; i < 5; i++) {
    ck_assert_msg(s21_vars[i] == lib_vars[i], "Error");
  }
}
END_TEST

START_TEST(sscanf_d_test_25) {
  const void* str = "NAN nan NAN nan NAN";
  const void* format = " %*d %d %*d %d %*d";

  int s21_vars[5] = {-1};
  int lib_vars[5] = {-1};

  int s21_res = s21_sscanf(str, format, &s21_vars[0], &s21_vars[1],
                           &s21_vars[2], &s21_vars[3], &s21_vars[4]);
  int lib_res = sscanf(str, format, &lib_vars[0], &lib_vars[1], &lib_vars[2],
                       &lib_vars[3], &lib_vars[4]);

  ck_assert_int_eq(s21_res, lib_res);
  for (int i = 0; i < 5; i++) {
    ck_assert_msg(s21_vars[i] == lib_vars[i], "Error");
  }
}
END_TEST

START_TEST(sscanf_d_test_26) {
  const void* str = "NAN nan NAN nan NAN";
  const void* format = " %*d %d %*d %d %*d";

  int s21_vars[5] = {-1};
  int lib_vars[5] = {-1};

  int s21_res = s21_sscanf(str, format, &s21_vars[0], &s21_vars[1],
                           &s21_vars[2], &s21_vars[3], &s21_vars[4]);
  int lib_res = sscanf(str, format, &lib_vars[0], &lib_vars[1], &lib_vars[2],
                       &lib_vars[3], &lib_vars[4]);

  ck_assert_int_eq(s21_res, lib_res);
  for (int i = 0; i < 5; i++) {
    ck_assert_msg(s21_vars[i] == lib_vars[i], "Error");
  }
}
END_TEST

START_TEST(sscanf_d_test_27) {
  const void* str = "123123";
  const void* format = "%1d   %1d";

  int s21_vars[2] = {-1};
  int lib_vars[2] = {-1};

  int s21_res = s21_sscanf(str, format, &s21_vars[0], &s21_vars[1]);
  int lib_res = sscanf(str, format, &lib_vars[0], &lib_vars[1]);

  ck_assert_int_eq(s21_res, lib_res);
  for (int i = 0; i < 2; i++) {
    ck_assert_msg(s21_vars[i] == lib_vars[i], "Error");
  }
}
END_TEST

TCase* sscanf_d_get_tests(void) {
  TCase* test_cases = tcase_create("sscanf_d_cases");

  tcase_add_test(test_cases, sscanf_d_test_1);
  tcase_add_test(test_cases, sscanf_d_test_2);
  tcase_add_test(test_cases, sscanf_d_test_3);
  tcase_add_test(test_cases, sscanf_d_test_4);
  tcase_add_test(test_cases, sscanf_d_test_5);
  tcase_add_test(test_cases, sscanf_d_test_6);
  tcase_add_test(test_cases, sscanf_d_test_7);
  tcase_add_test(test_cases, sscanf_d_test_8);
  tcase_add_test(test_cases, sscanf_d_test_9);
  tcase_add_test(test_cases, sscanf_d_test_10);
  tcase_add_test(test_cases, sscanf_d_test_11);
  tcase_add_test(test_cases, sscanf_d_test_12);
  tcase_add_test(test_cases, sscanf_d_test_13);
  tcase_add_test(test_cases, sscanf_d_test_14);
  tcase_add_test(test_cases, sscanf_d_test_15);
  tcase_add_test(test_cases, sscanf_d_test_16);
  tcase_add_test(test_cases, sscanf_d_test_17);
  tcase_add_test(test_cases, sscanf_d_test_18);
  tcase_add_test(test_cases, sscanf_d_test_19);
  tcase_add_test(test_cases, sscanf_d_test_20);
  tcase_add_test(test_cases, sscanf_d_test_21);
  tcase_add_test(test_cases, sscanf_d_test_22);
  tcase_add_test(test_cases, sscanf_d_test_23);
  tcase_add_test(test_cases, sscanf_d_test_24);
  tcase_add_test(test_cases, sscanf_d_test_25);
  tcase_add_test(test_cases, sscanf_d_test_26);
  tcase_add_test(test_cases, sscanf_d_test_27);

  return test_cases;
}
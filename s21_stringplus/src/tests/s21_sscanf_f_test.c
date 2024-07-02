#include <check.h>
#include <limits.h>

#include "../s21_string.h"

START_TEST(sscanf_f_test_1) {
  const void* str = "3.125 3 3,125";
  const void* format = " %f%f%f";

  float s21_vars[3] = {-1};
  float lib_vars[3] = {-1};

  int s21_res =
      s21_sscanf(str, format, &s21_vars[0], &s21_vars[1], &s21_vars[2]);
  int lib_res = sscanf(str, format, &lib_vars[0], &lib_vars[1], &lib_vars[2]);

  ck_assert_int_eq(s21_res, lib_res);
  for (int i = 0; i < 3; i++) {
    ck_assert_float_eq(s21_vars[i], lib_vars[i]);
  }
}
END_TEST

START_TEST(sscanf_f_test_2) {
  const void* str = "364.12543 3423 3354,164325";
  const void* format = " %5f %5f %5f ";

  float s21_vars[3] = {-1};
  float lib_vars[3] = {-1};

  int s21_res =
      s21_sscanf(str, format, &s21_vars[0], &s21_vars[1], &s21_vars[2]);
  int lib_res = sscanf(str, format, &lib_vars[0], &lib_vars[1], &lib_vars[2]);

  ck_assert_int_eq(s21_res, lib_res);
  for (int i = 0; i < 3; i++) {
    ck_assert_float_eq(s21_vars[i], lib_vars[i]);
  }
}
END_TEST

START_TEST(sscanf_f_test_3) {
  const void* str = "-364.12543 -3423 -3354,164325";
  const void* format = " %5f %5f %5f ";

  float s21_vars[3] = {-1};
  float lib_vars[3] = {-1};

  int s21_res =
      s21_sscanf(str, format, &s21_vars[0], &s21_vars[1], &s21_vars[2]);
  int lib_res = sscanf(str, format, &lib_vars[0], &lib_vars[1], &lib_vars[2]);

  ck_assert_int_eq(s21_res, lib_res);
  for (int i = 0; i < 3; i++) {
    ck_assert_float_eq(s21_vars[i], lib_vars[i]);
  }
}
END_TEST

START_TEST(sscanf_f_test_4) {
  const void* str = "3643463464.12543 -34236436346 -3643463464.12543";
  const void* format = " %lf %lf %lf ";

  double s21_vars[3] = {-1};
  double lib_vars[3] = {-1};

  int s21_res =
      s21_sscanf(str, format, &s21_vars[0], &s21_vars[1], &s21_vars[2]);
  int lib_res = sscanf(str, format, &lib_vars[0], &lib_vars[1], &lib_vars[2]);

  ck_assert_int_eq(s21_res, lib_res);
  for (int i = 0; i < 3; i++) {
    ck_assert_double_eq(s21_vars[i], lib_vars[i]);
  }
}
END_TEST

START_TEST(sscanf_f_test_5) {
  const void* str = "3643463464.12543 -34236436346 -3643463464.12543";
  const void* format = " %Lf %Lf %Lf ";

  long double s21_vars[3] = {-1};
  long double lib_vars[3] = {-1};

  int s21_res =
      s21_sscanf(str, format, &s21_vars[0], &s21_vars[1], &s21_vars[2]);
  int lib_res = sscanf(str, format, &lib_vars[0], &lib_vars[1], &lib_vars[2]);

  ck_assert_int_eq(s21_res, lib_res);
  for (int i = 0; i < 3; i++) {
    ck_assert_ldouble_eq(s21_vars[i], lib_vars[i]);
  }
}
END_TEST

START_TEST(sscanf_f_test_6) {
  const void* str = "333.23857e+3 -1234567e-3 67532e3";
  const void* format = " %f %f %f ";

  float s21_vars[3] = {-1};
  float lib_vars[3] = {-1};

  int s21_res =
      s21_sscanf(str, format, &s21_vars[0], &s21_vars[1], &s21_vars[2]);
  int lib_res = sscanf(str, format, &lib_vars[0], &lib_vars[1], &lib_vars[2]);

  ck_assert_int_eq(s21_res, lib_res);
  for (int i = 0; i < 3; i++) {
    ck_assert_float_eq(s21_vars[i], lib_vars[i]);
  }
}
END_TEST

START_TEST(sscanf_f_test_7) {
  const void* str = ".23857e+3 .e3 e3";
  const void* format = " %f %f %f ";

  float s21_vars[3] = {-1};
  float lib_vars[3] = {-1};

  int s21_res =
      s21_sscanf(str, format, &s21_vars[0], &s21_vars[1], &s21_vars[2]);
  int lib_res = sscanf(str, format, &lib_vars[0], &lib_vars[1], &lib_vars[2]);

  ck_assert_int_eq(s21_res, lib_res);
  for (int i = 0; i < 3; i++) {
    ck_assert_float_eq(s21_vars[i], lib_vars[i]);
  }
}
END_TEST

START_TEST(sscanf_f_test_8) {
  const void* str = ".e-3 -.333e-3 123.123e0000000000000000003";
  const void* format = " %f %f %f ";

  float s21_vars[3] = {-1};
  float lib_vars[3] = {-1};

  int s21_res =
      s21_sscanf(str, format, &s21_vars[0], &s21_vars[1], &s21_vars[2]);
  int lib_res = sscanf(str, format, &lib_vars[0], &lib_vars[1], &lib_vars[2]);

  ck_assert_int_eq(s21_res, lib_res);
  for (int i = 0; i < 3; i++) {
    ck_assert_float_eq(s21_vars[i], lib_vars[i]);
  }
}
END_TEST

START_TEST(sscanf_f_test_9) {
  const void* str = "123E3 777e+007 123-E3";
  const void* format = " %f %f %f ";

  float s21_vars[3] = {-1};
  float lib_vars[3] = {-1};

  int s21_res =
      s21_sscanf(str, format, &s21_vars[0], &s21_vars[1], &s21_vars[2]);
  int lib_res = sscanf(str, format, &lib_vars[0], &lib_vars[1], &lib_vars[2]);

  ck_assert_int_eq(s21_res, lib_res);
  for (int i = 0; i < 3; i++) {
    ck_assert_float_eq(s21_vars[i], lib_vars[i]);
  }
}
END_TEST

START_TEST(sscanf_f_test_10) {
  const void* str = ".3 63468.34834e+5 63468.34834e-5";
  const void* format = " %f %4f %1f ";

  float s21_vars[3] = {-1};
  float lib_vars[3] = {-1};

  int s21_res =
      s21_sscanf(str, format, &s21_vars[0], &s21_vars[1], &s21_vars[2]);
  int lib_res = sscanf(str, format, &lib_vars[0], &lib_vars[1], &lib_vars[2]);

  ck_assert_int_eq(s21_res, lib_res);
  for (int i = 0; i < 3; i++) {
    ck_assert_float_eq(s21_vars[i], lib_vars[i]);
  }
}
END_TEST

START_TEST(sscanf_f_test_11) {
  const void* str = "-3e+3.3+3";
  const void* format = " %f %f %1f ";

  float s21_vars[3] = {-1};
  float lib_vars[3] = {-1};

  int s21_res =
      s21_sscanf(str, format, &s21_vars[0], &s21_vars[1], &s21_vars[2]);
  int lib_res = sscanf(str, format, &lib_vars[0], &lib_vars[1], &lib_vars[2]);

  ck_assert_int_eq(s21_res, lib_res);
  for (int i = 0; i < 3; i++) {
    ck_assert_float_eq(s21_vars[i], lib_vars[i]);
  }
}
END_TEST

START_TEST(sscanf_f_test_12) {
  const void* str = "-36436e+10.36456+3435345";
  const void* format = " %Lf %Lf %1Lf ";

  long double s21_vars[3] = {-1};
  long double lib_vars[3] = {-1};

  int s21_res =
      s21_sscanf(str, format, &s21_vars[0], &s21_vars[1], &s21_vars[2]);
  int lib_res = sscanf(str, format, &lib_vars[0], &lib_vars[1], &lib_vars[2]);

  ck_assert_int_eq(s21_res, lib_res);
  for (int i = 0; i < 3; i++) {
    ck_assert_double_eq(s21_vars[i], lib_vars[i]);
  }
}
END_TEST

START_TEST(sscanf_f_test_13) {
  const void* str = "-36436e+10.36456+3435345";
  const void* format = " %*Lf %Lf %*1Lf ";

  long double s21_vars[3] = {-1};
  long double lib_vars[3] = {-1};

  int s21_res =
      s21_sscanf(str, format, &s21_vars[0], &s21_vars[1], &s21_vars[2]);
  int lib_res = sscanf(str, format, &lib_vars[0], &lib_vars[1], &lib_vars[2]);

  ck_assert_int_eq(s21_res, lib_res);
  for (int i = 0; i < 3; i++) {
    ck_assert_double_eq(s21_vars[i], lib_vars[i]);
  }
}
END_TEST

START_TEST(sscanf_f_test_14) {
  const void* str = "-36436e+10.36456+3435345";
  const void* format = " %Lf %*Lf %0Lf ";

  long double s21_vars[3] = {-1};
  long double lib_vars[3] = {-1};

  int s21_res =
      s21_sscanf(str, format, &s21_vars[0], &s21_vars[1], &s21_vars[2]);
  int lib_res = sscanf(str, format, &lib_vars[0], &lib_vars[1], &lib_vars[2]);

  ck_assert_int_eq(s21_res, lib_res);
  for (int i = 0; i < 3; i++) {
    ck_assert_ldouble_eq(s21_vars[i], lib_vars[i]);
  }
}
END_TEST

START_TEST(sscanf_f_test_15) {
  const void* str = "123.456 789.0333333333 777";
  const void* format = "%f %*f %*0f";

  float s21_vars[3] = {-1};
  float lib_vars[3] = {-1};

  int s21_res =
      s21_sscanf(str, format, &s21_vars[0], &s21_vars[1], &s21_vars[2]);
  int lib_res = sscanf(str, format, &lib_vars[0], &lib_vars[1], &lib_vars[2]);

  ck_assert_int_eq(s21_res, lib_res);
  for (int i = 0; i < 3; i++) {
    ck_assert_float_eq(s21_vars[i], lib_vars[i]);
  }
}
END_TEST

START_TEST(sscanf_f_test_16) {
  const void* str = "NAN nan NAN";
  const void* format = "%f%f%f";

  float s21_vars[3] = {-1};
  float lib_vars[3] = {-1};

  int s21_res =
      s21_sscanf(str, format, &s21_vars[0], &s21_vars[1], &s21_vars[2]);
  int lib_res = sscanf(str, format, &lib_vars[0], &lib_vars[1], &lib_vars[2]);

  ck_assert_int_eq(s21_res, lib_res);
  for (int i = 0; i < 3; i++) {
    ck_assert_int_eq(isnan(s21_vars[i]), isnan(lib_vars[i]));
  }
}
END_TEST

START_TEST(sscanf_f_test_17) {
  const void* str = "nif nif naf naf";
  const void* format = "%f%f%f";

  float s21_vars[3] = {-1};
  float lib_vars[3] = {-1};

  int s21_res =
      s21_sscanf(str, format, &s21_vars[0], &s21_vars[1], &s21_vars[2]);
  int lib_res = sscanf(str, format, &lib_vars[0], &lib_vars[1], &lib_vars[2]);

  ck_assert_int_eq(s21_res, lib_res);
  for (int i = 0; i < 3; i++) {
    ck_assert_float_eq(s21_vars[i], lib_vars[i]);
  }
}
END_TEST

START_TEST(sscanf_f_test_18) {
  const void* str = "1.23e-308";
  const void* format = "%f";

  float s21_vars[1] = {-1};
  float lib_vars[1] = {-1};

  int s21_res = s21_sscanf(str, format, &s21_vars[0]);
  int lib_res = sscanf(str, format, &lib_vars[0]);

  ck_assert_int_eq(s21_res, lib_res);
  for (int i = 0; i < 1; i++) {
    ck_assert_float_eq(s21_vars[i], lib_vars[i]);
  }
}
END_TEST

START_TEST(sscanf_f_test_19) {
  const void* str = "1.23e+308";
  const void* format = "%f";

  float s21_vars[1] = {-1};
  float lib_vars[1] = {-1};

  int s21_res = s21_sscanf(str, format, &s21_vars[0]);
  int lib_res = sscanf(str, format, &lib_vars[0]);

  ck_assert_int_eq(s21_res, lib_res);
  for (int i = 0; i < 1; i++) {
    ck_assert_float_eq(s21_vars[i], lib_vars[i]);
  }
}
END_TEST

START_TEST(sscanf_f_test_20) {
  const void* str = "1.23e+308";
  const void* format = "%e";

  float s21_vars[1] = {-1};
  float lib_vars[1] = {-1};

  int s21_res = s21_sscanf(str, format, &s21_vars[0]);
  int lib_res = sscanf(str, format, &lib_vars[0]);

  ck_assert_int_eq(s21_res, lib_res);
  for (int i = 0; i < 1; i++) {
    ck_assert_float_eq(s21_vars[i], lib_vars[i]);
  }
}
END_TEST

START_TEST(sscanf_f_test_21) {
  const void* str = "1.23e-308";
  const void* format = "%e";

  float s21_vars[1] = {-1};
  float lib_vars[1] = {-1};

  int s21_res = s21_sscanf(str, format, &s21_vars[0]);
  int lib_res = sscanf(str, format, &lib_vars[0]);

  ck_assert_int_eq(s21_res, lib_res);
  for (int i = 0; i < 1; i++) {
    ck_assert_float_eq(s21_vars[i], lib_vars[i]);
  }
}
END_TEST

START_TEST(sscanf_f_test_22) {
  const void* str = "1.23E-308";
  const void* format = "%e";

  float s21_vars[1] = {-1};
  float lib_vars[1] = {-1};

  int s21_res = s21_sscanf(str, format, &s21_vars[0]);
  int lib_res = sscanf(str, format, &lib_vars[0]);

  ck_assert_int_eq(s21_res, lib_res);
  for (int i = 0; i < 1; i++) {
    ck_assert_float_eq(s21_vars[i], lib_vars[i]);
  }
}
END_TEST

START_TEST(sscanf_f_test_23) {
  const void* str = "1.23E308";
  const void* format = "%e";

  float s21_vars[1] = {-1};
  float lib_vars[1] = {-1};

  int s21_res = s21_sscanf(str, format, &s21_vars[0]);
  int lib_res = sscanf(str, format, &lib_vars[0]);

  ck_assert_int_eq(s21_res, lib_res);
  for (int i = 0; i < 1; i++) {
    ck_assert_float_eq(s21_vars[i], lib_vars[i]);
  }
}
END_TEST

START_TEST(sscanf_f_test_24) {
  const void* str = "1.23E308";
  const void* format = "%g";

  float s21_vars[1] = {-1};
  float lib_vars[1] = {-1};

  int s21_res = s21_sscanf(str, format, &s21_vars[0]);
  int lib_res = sscanf(str, format, &lib_vars[0]);

  ck_assert_int_eq(s21_res, lib_res);
  for (int i = 0; i < 1; i++) {
    ck_assert_float_eq(s21_vars[i], lib_vars[i]);
  }
}
END_TEST

START_TEST(sscanf_f_test_25) {
  const void* str = "1.23E308";
  const void* format = "%G";

  float s21_vars[1] = {-1};
  float lib_vars[1] = {-1};

  int s21_res = s21_sscanf(str, format, &s21_vars[0]);
  int lib_res = sscanf(str, format, &lib_vars[0]);

  ck_assert_int_eq(s21_res, lib_res);
  for (int i = 0; i < 1; i++) {
    ck_assert_float_eq(s21_vars[i], lib_vars[i]);
  }
}
END_TEST

START_TEST(sscanf_f_test_26) {
  const void* str = "-1.23e-308";
  const void* format = "%g";

  float s21_vars[1] = {-1};
  float lib_vars[1] = {-1};

  int s21_res = s21_sscanf(str, format, &s21_vars[0]);
  int lib_res = sscanf(str, format, &lib_vars[0]);

  ck_assert_int_eq(s21_res, lib_res);
  for (int i = 0; i < 1; i++) {
    ck_assert_float_eq(s21_vars[i], lib_vars[i]);
  }
}
END_TEST

START_TEST(sscanf_f_test_27) {
  const void* str = "-1.23e+308";
  const void* format = "%g";

  float s21_vars[1] = {-1};
  float lib_vars[1] = {-1};

  int s21_res = s21_sscanf(str, format, &s21_vars[0]);
  int lib_res = sscanf(str, format, &lib_vars[0]);

  ck_assert_int_eq(s21_res, lib_res);
  for (int i = 0; i < 1; i++) {
    ck_assert_float_eq(s21_vars[i], lib_vars[i]);
  }
}
END_TEST

START_TEST(sscanf_f_test_28) {
  const void* str = "-1.23e+11";
  const void* format = "%lf";

  double s21_vars[1] = {0};
  double lib_vars[1] = {0};

  int s21_res = s21_sscanf(str, format, &s21_vars[0]);
  int lib_res = sscanf(str, format, &lib_vars[0]);

  ck_assert_int_eq(s21_res, lib_res);
  for (int i = 0; i < 1; i++) {
    ck_assert_double_eq(s21_vars[i], lib_vars[i]);
  }
}
END_TEST

START_TEST(sscanf_f_test_29) {
  const void* str = "1.23e-11";
  const void* format = "%lf";

  double s21_vars[1] = {-1};
  double lib_vars[1] = {-1};

  int s21_res = s21_sscanf(str, format, &s21_vars[0]);
  int lib_res = sscanf(str, format, &lib_vars[0]);

  ck_assert_int_eq(s21_res, lib_res);
  for (int i = 0; i < 1; i++) {
    ck_assert_float_eq(s21_vars[i], lib_vars[i]);
  }
}
END_TEST

START_TEST(sscanf_f_test_30) {
  const void* str = "1.23e-11";
  const void* format = "%Lf";

  long double s21_vars[1] = {-1};
  long double lib_vars[1] = {-1};

  int s21_res = s21_sscanf(str, format, &s21_vars[0]);
  int lib_res = sscanf(str, format, &lib_vars[0]);

  ck_assert_int_eq(s21_res, lib_res);
  for (int i = 0; i < 1; i++) {
    ck_assert_float_eq(s21_vars[i], lib_vars[i]);
  }
}
END_TEST

START_TEST(sscanf_f_test_31) {
  const void* str = "1.23e+11";
  const void* format = "%Lf";

  long double s21_vars[1] = {-1};
  long double lib_vars[1] = {-1};

  int s21_res = s21_sscanf(str, format, &s21_vars[0]);
  int lib_res = sscanf(str, format, &lib_vars[0]);

  ck_assert_int_eq(s21_res, lib_res);
  for (int i = 0; i < 1; i++) {
    ck_assert_double_eq(s21_vars[i], lib_vars[i]);
  }
}
END_TEST

START_TEST(sscanf_f_test_32) {
  const void* str = "INF";
  const void* format = "%Lf";

  long double s21_vars[1] = {-1};
  long double lib_vars[1] = {-1};

  int s21_res = s21_sscanf(str, format, &s21_vars[0]);
  int lib_res = sscanf(str, format, &lib_vars[0]);

  ck_assert_int_eq(s21_res, lib_res);
  for (int i = 0; i < 1; i++) {
    ck_assert_int_eq(isinf(s21_vars[i]), isinf(lib_vars[i]));
  }
}
END_TEST

START_TEST(sscanf_f_test_33) {
  const void* str = "NAN";
  const void* format = "%Lf";

  long double s21_vars[1] = {-1};
  long double lib_vars[1] = {-1};

  int s21_res = s21_sscanf(str, format, &s21_vars[0]);
  int lib_res = sscanf(str, format, &lib_vars[0]);

  ck_assert_int_eq(s21_res, lib_res);
  for (int i = 0; i < 1; i++) {
    ck_assert_int_eq(isnan(s21_vars[i]), isnan(lib_vars[i]));
  }
}
END_TEST

START_TEST(sscanf_f_test_34) {
  const void* str = "999.9";
  const void* format = "%lf";

  double s21_vars[1] = {-1};
  double lib_vars[1] = {-1};

  int s21_res = s21_sscanf(str, format, &s21_vars[0]);
  int lib_res = sscanf(str, format, &lib_vars[0]);

  ck_assert_int_eq(s21_res, lib_res);
  for (int i = 0; i < 1; i++) {
    ck_assert_int_eq(isnan(s21_vars[i]), isnan(lib_vars[i]));
  }
}
END_TEST

START_TEST(sscanf_f_test_35) {
  const void* str = "999.1";
  const void* format = "%lf";

  double s21_vars[1] = {-1};
  double lib_vars[1] = {-1};

  int s21_res = s21_sscanf(str, format, &s21_vars[0]);
  int lib_res = sscanf(str, format, &lib_vars[0]);

  ck_assert_int_eq(s21_res, lib_res);
  for (int i = 0; i < 1; i++) {
    ck_assert_int_eq(isnan(s21_vars[i]), isnan(lib_vars[i]));
  }
}
END_TEST

TCase* sscanf_f_get_tests(void) {
  TCase* test_cases = tcase_create("sscanf_f_cases");

  tcase_add_test(test_cases, sscanf_f_test_1);
  tcase_add_test(test_cases, sscanf_f_test_2);
  tcase_add_test(test_cases, sscanf_f_test_3);
  tcase_add_test(test_cases, sscanf_f_test_4);
  tcase_add_test(test_cases, sscanf_f_test_5);
  tcase_add_test(test_cases, sscanf_f_test_6);
  tcase_add_test(test_cases, sscanf_f_test_7);
  tcase_add_test(test_cases, sscanf_f_test_8);
  tcase_add_test(test_cases, sscanf_f_test_9);
  tcase_add_test(test_cases, sscanf_f_test_10);
  tcase_add_test(test_cases, sscanf_f_test_11);
  tcase_add_test(test_cases, sscanf_f_test_12);
  tcase_add_test(test_cases, sscanf_f_test_13);
  tcase_add_test(test_cases, sscanf_f_test_14);
  tcase_add_test(test_cases, sscanf_f_test_15);
  tcase_add_test(test_cases, sscanf_f_test_16);
  tcase_add_test(test_cases, sscanf_f_test_17);
  tcase_add_test(test_cases, sscanf_f_test_18);
  tcase_add_test(test_cases, sscanf_f_test_19);
  tcase_add_test(test_cases, sscanf_f_test_20);
  tcase_add_test(test_cases, sscanf_f_test_21);
  tcase_add_test(test_cases, sscanf_f_test_22);
  tcase_add_test(test_cases, sscanf_f_test_23);
  tcase_add_test(test_cases, sscanf_f_test_24);
  tcase_add_test(test_cases, sscanf_f_test_25);
  tcase_add_test(test_cases, sscanf_f_test_26);
  tcase_add_test(test_cases, sscanf_f_test_27);
  tcase_add_test(test_cases, sscanf_f_test_28);
  tcase_add_test(test_cases, sscanf_f_test_29);
  tcase_add_test(test_cases, sscanf_f_test_30);
  tcase_add_test(test_cases, sscanf_f_test_31);
  tcase_add_test(test_cases, sscanf_f_test_32);
  tcase_add_test(test_cases, sscanf_f_test_33);
  tcase_add_test(test_cases, sscanf_f_test_34);
  tcase_add_test(test_cases, sscanf_f_test_35);

  return test_cases;
}
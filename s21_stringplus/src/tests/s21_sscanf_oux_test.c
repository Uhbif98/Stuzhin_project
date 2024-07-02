#include <check.h>
#include <limits.h>

#include "../s21_string.h"

START_TEST(sscanf_oux_test_1) {
  const void* str = "0xabc 0XABC 0xABC 0Xabc";
  const void* format = " %x %x %x %x";

  unsigned int s21_vars[4] = {-1};
  unsigned int lib_vars[4] = {-1};

  int s21_res = s21_sscanf(str, format, &s21_vars[0], &s21_vars[1],
                           &s21_vars[2], &s21_vars[3]);
  int lib_res = sscanf(str, format, &lib_vars[0], &lib_vars[1], &lib_vars[2],
                       &lib_vars[3]);

  ck_assert_int_eq(s21_res, lib_res);
  for (int i = 0; i < 4; i++) {
    ck_assert_uint_eq(s21_vars[i], lib_vars[i]);
  }
}
END_TEST

START_TEST(sscanf_oux_test_2) {
  const void* str = "0xabc 0XABC 0xABC 0Xabc";
  const void* format = " %X %X %X %X";

  unsigned int s21_vars[4] = {-1};
  unsigned int lib_vars[4] = {-1};

  int s21_res = s21_sscanf(str, format, &s21_vars[0], &s21_vars[1],
                           &s21_vars[2], &s21_vars[3]);
  int lib_res = sscanf(str, format, &lib_vars[0], &lib_vars[1], &lib_vars[2],
                       &lib_vars[3]);

  ck_assert_int_eq(s21_res, lib_res);
  for (int i = 0; i < 4; i++) {
    ck_assert_uint_eq(s21_vars[i], lib_vars[i]);
  }
}
END_TEST

START_TEST(sscanf_oux_test_3) {
  const void* str = "-0xabc -0XABC -0xABC -0Xabc";
  const void* format = " %x %x %x %x";

  unsigned int s21_vars[4] = {-1};
  unsigned int lib_vars[4] = {-1};

  int s21_res = s21_sscanf(str, format, &s21_vars[0], &s21_vars[1],
                           &s21_vars[2], &s21_vars[3]);
  int lib_res = sscanf(str, format, &lib_vars[0], &lib_vars[1], &lib_vars[2],
                       &lib_vars[3]);

  ck_assert_int_eq(s21_res, lib_res);
  for (int i = 0; i < 4; i++) {
    ck_assert_uint_eq(s21_vars[i], lib_vars[i]);
  }
}
END_TEST

START_TEST(sscanf_oux_test_4) {
  const void* str = "063454 00 0 12345";
  const void* format = " %o %o %o %o";

  unsigned int s21_vars[4] = {-1};
  unsigned int lib_vars[4] = {-1};

  int s21_res = s21_sscanf(str, format, &s21_vars[0], &s21_vars[1],
                           &s21_vars[2], &s21_vars[3]);
  int lib_res = sscanf(str, format, &lib_vars[0], &lib_vars[1], &lib_vars[2],
                       &lib_vars[3]);

  ck_assert_int_eq(s21_res, lib_res);
  for (int i = 0; i < 4; i++) {
    ck_assert_uint_eq(s21_vars[i], lib_vars[i]);
  }
}
END_TEST

START_TEST(sscanf_oux_test_5) {
  const void* str = "-063454 -00 -0 -12345";
  const void* format = " %o %o %o %o";

  unsigned int s21_vars[4] = {-1};
  unsigned int lib_vars[4] = {-1};

  int s21_res = s21_sscanf(str, format, &s21_vars[0], &s21_vars[1],
                           &s21_vars[2], &s21_vars[3]);
  int lib_res = sscanf(str, format, &lib_vars[0], &lib_vars[1], &lib_vars[2],
                       &lib_vars[3]);

  ck_assert_int_eq(s21_res, lib_res);
  for (int i = 0; i < 4; i++) {
    ck_assert_uint_eq(s21_vars[i], lib_vars[i]);
  }
}
END_TEST

START_TEST(sscanf_oux_test_6) {
  const void* str = "72635 72365723 0 333";
  const void* format = " %u %u %u %u";

  unsigned int s21_vars[4] = {-1};
  unsigned int lib_vars[4] = {-1};

  int s21_res = s21_sscanf(str, format, &s21_vars[0], &s21_vars[1],
                           &s21_vars[2], &s21_vars[3]);
  int lib_res = sscanf(str, format, &lib_vars[0], &lib_vars[1], &lib_vars[2],
                       &lib_vars[3]);

  ck_assert_int_eq(s21_res, lib_res);
  for (int i = 0; i < 4; i++) {
    ck_assert_uint_eq(s21_vars[i], lib_vars[i]);
  }
}
END_TEST

START_TEST(sscanf_oux_test_7) {
  const void* str = "-72635 -72365723 -0 -333";
  const void* format = " %u %u %u %u";

  unsigned int s21_vars[4] = {-1};
  unsigned int lib_vars[4] = {-1};

  int s21_res = s21_sscanf(str, format, &s21_vars[0], &s21_vars[1],
                           &s21_vars[2], &s21_vars[3]);
  int lib_res = sscanf(str, format, &lib_vars[0], &lib_vars[1], &lib_vars[2],
                       &lib_vars[3]);

  ck_assert_int_eq(s21_res, lib_res);
  for (int i = 0; i < 4; i++) {
    ck_assert_uint_eq(s21_vars[i], lib_vars[i]);
  }
}
END_TEST

START_TEST(sscanf_oux_test_8) {
  const void* str = "AAA";
  const void* format = "%x";

  unsigned int s21_vars[1] = {-1};
  unsigned int lib_vars[1] = {-1};

  int s21_res = s21_sscanf(str, format, &s21_vars[0]);
  int lib_res = sscanf(str, format, &lib_vars[0]);

  ck_assert_int_eq(s21_res, lib_res);
  for (int i = 0; i < 1; i++) {
    ck_assert_uint_eq(s21_vars[i], lib_vars[i]);
  }
}
END_TEST

START_TEST(sscanf_oux_test_9) {
  const void* str = "3AAA";
  const void* format = "%x";

  unsigned int s21_vars[1] = {-1};
  unsigned int lib_vars[1] = {-1};

  int s21_res = s21_sscanf(str, format, &s21_vars[0]);
  int lib_res = sscanf(str, format, &lib_vars[0]);

  ck_assert_int_eq(s21_res, lib_res);
  for (int i = 0; i < 1; i++) {
    ck_assert_uint_eq(s21_vars[i], lib_vars[i]);
  }
}
END_TEST

START_TEST(sscanf_oux_test_10) {
  const void* str = "0AAA";
  const void* format = "%x";

  unsigned int s21_vars[1] = {-1};
  unsigned int lib_vars[1] = {-1};

  int s21_res = s21_sscanf(str, format, &s21_vars[0]);
  int lib_res = sscanf(str, format, &lib_vars[0]);

  ck_assert_int_eq(s21_res, lib_res);
  for (int i = 0; i < 1; i++) {
    ck_assert_uint_eq(s21_vars[i], lib_vars[i]);
  }
}
END_TEST

START_TEST(sscanf_oux_test_11) {
  const void* str = "+000AAA";
  const void* format = "%x";

  unsigned int s21_vars[1] = {-1};
  unsigned int lib_vars[1] = {-1};

  int s21_res = s21_sscanf(str, format, &s21_vars[0]);
  int lib_res = sscanf(str, format, &lib_vars[0]);

  ck_assert_int_eq(s21_res, lib_res);
  for (int i = 0; i < 1; i++) {
    ck_assert_uint_eq(s21_vars[i], lib_vars[i]);
  }
}
END_TEST

START_TEST(sscanf_oux_test_12) {
  const void* str = "0x15AI";
  const void* format = "%x";

  unsigned int s21_vars[1] = {-1};
  unsigned int lib_vars[1] = {-1};

  int s21_res = s21_sscanf(str, format, &s21_vars[0]);
  int lib_res = sscanf(str, format, &lib_vars[0]);

  ck_assert_int_eq(s21_res, lib_res);
  for (int i = 0; i < 1; i++) {
    ck_assert_uint_eq(s21_vars[i], lib_vars[i]);
  }
}
END_TEST

START_TEST(sscanf_oux_test_13) {
  const void* str = "0x15A";
  const void* format = "%o";

  unsigned int s21_vars[1] = {-1};
  unsigned int lib_vars[1] = {-1};

  int s21_res = s21_sscanf(str, format, &s21_vars[0]);
  int lib_res = sscanf(str, format, &lib_vars[0]);

  ck_assert_int_eq(s21_res, lib_res);
  for (int i = 0; i < 1; i++) {
    ck_assert_uint_eq(s21_vars[i], lib_vars[i]);
  }
}
END_TEST

START_TEST(sscanf_oux_test_14) {
  const void* str = "015A";
  const void* format = "%o";

  unsigned int s21_vars[1] = {-1};
  unsigned int lib_vars[1] = {-1};

  int s21_res = s21_sscanf(str, format, &s21_vars[0]);
  int lib_res = sscanf(str, format, &lib_vars[0]);

  ck_assert_int_eq(s21_res, lib_res);
  for (int i = 0; i < 1; i++) {
    ck_assert_uint_eq(s21_vars[i], lib_vars[i]);
  }
}
END_TEST

START_TEST(sscanf_oux_test_15) {
  const void* str = "015";
  const void* format = "%o";

  unsigned int s21_vars[1] = {-1};
  unsigned int lib_vars[1] = {-1};

  int s21_res = s21_sscanf(str, format, &s21_vars[0]);
  int lib_res = sscanf(str, format, &lib_vars[0]);

  ck_assert_int_eq(s21_res, lib_res);
  for (int i = 0; i < 1; i++) {
    ck_assert_uint_eq(s21_vars[i], lib_vars[i]);
  }
}
END_TEST

START_TEST(sscanf_oux_test_16) {
  const void* str = "15";
  const void* format = "%o";

  unsigned int s21_vars[1] = {-1};
  unsigned int lib_vars[1] = {-1};

  int s21_res = s21_sscanf(str, format, &s21_vars[0]);
  int lib_res = sscanf(str, format, &lib_vars[0]);

  ck_assert_int_eq(s21_res, lib_res);
  for (int i = 0; i < 1; i++) {
    ck_assert_uint_eq(s21_vars[i], lib_vars[i]);
  }
}
END_TEST

START_TEST(sscanf_oux_test_17) {
  const void* str = "-15";
  const void* format = "%o";

  unsigned int s21_vars[1] = {-1};
  unsigned int lib_vars[1] = {-1};

  int s21_res = s21_sscanf(str, format, &s21_vars[0]);
  int lib_res = sscanf(str, format, &lib_vars[0]);

  ck_assert_int_eq(s21_res, lib_res);
  for (int i = 0; i < 1; i++) {
    ck_assert_uint_eq(s21_vars[i], lib_vars[i]);
  }
}
END_TEST

START_TEST(sscanf_oux_test_18) {
  const void* str = "0x3a";
  const void* format = "%u";

  unsigned int s21_vars[1] = {-1};
  unsigned int lib_vars[1] = {-1};

  int s21_res = s21_sscanf(str, format, &s21_vars[0]);
  int lib_res = sscanf(str, format, &lib_vars[0]);

  ck_assert_int_eq(s21_res, lib_res);
  for (int i = 0; i < 1; i++) {
    ck_assert_uint_eq(s21_vars[i], lib_vars[i]);
  }
}
END_TEST

START_TEST(sscanf_oux_test_19) {
  const void* str = "0333";
  const void* format = "%u";

  unsigned int s21_vars[1] = {-1};
  unsigned int lib_vars[1] = {-1};

  int s21_res = s21_sscanf(str, format, &s21_vars[0]);
  int lib_res = sscanf(str, format, &lib_vars[0]);

  ck_assert_int_eq(s21_res, lib_res);
  for (int i = 0; i < 1; i++) {
    ck_assert_uint_eq(s21_vars[i], lib_vars[i]);
  }
}
END_TEST

START_TEST(sscanf_oux_test_20) {
  const void* str = "333";
  const void* format = "%u";

  unsigned int s21_vars[1] = {-1};
  unsigned int lib_vars[1] = {-1};

  int s21_res = s21_sscanf(str, format, &s21_vars[0]);
  int lib_res = sscanf(str, format, &lib_vars[0]);

  ck_assert_int_eq(s21_res, lib_res);
  for (int i = 0; i < 1; i++) {
    ck_assert_uint_eq(s21_vars[i], lib_vars[i]);
  }
}
END_TEST

START_TEST(sscanf_oux_test_21) {
  const void* str = "00000000333";
  const void* format = "%u";

  unsigned int s21_vars[1] = {-1};
  unsigned int lib_vars[1] = {-1};

  int s21_res = s21_sscanf(str, format, &s21_vars[0]);
  int lib_res = sscanf(str, format, &lib_vars[0]);

  ck_assert_int_eq(s21_res, lib_res);
  for (int i = 0; i < 1; i++) {
    ck_assert_uint_eq(s21_vars[i], lib_vars[i]);
  }
}
END_TEST

START_TEST(sscanf_oux_test_22) {
  const void* str = "0xFFFFFFFFFFFFFF";
  const void* format = "%hx";

  unsigned short int s21_vars[1] = {-1};
  unsigned short int lib_vars[1] = {-1};

  int s21_res = s21_sscanf(str, format, &s21_vars[0]);
  int lib_res = sscanf(str, format, &lib_vars[0]);

  ck_assert_int_eq(s21_res, lib_res);
  for (int i = 0; i < 1; i++) {
    ck_assert_msg(s21_vars[i] == lib_vars[i], "Error");
  }
}
END_TEST

START_TEST(sscanf_oux_test_23) {
  const void* str = "0777777777773337777777";
  const void* format = "%ho";

  unsigned short int s21_vars[1] = {-1};
  unsigned short int lib_vars[1] = {-1};

  int s21_res = s21_sscanf(str, format, &s21_vars[0]);
  int lib_res = sscanf(str, format, &lib_vars[0]);

  ck_assert_int_eq(s21_res, lib_res);
  for (int i = 0; i < 1; i++) {
    ck_assert_msg(s21_vars[i] == lib_vars[i], "Error");
  }
}
END_TEST

START_TEST(sscanf_oux_test_24) {
  const void* str = "835673956395";
  const void* format = "%hu";

  unsigned short int s21_vars[1] = {-1};
  unsigned short int lib_vars[1] = {-1};

  int s21_res = s21_sscanf(str, format, &s21_vars[0]);
  int lib_res = sscanf(str, format, &lib_vars[0]);

  ck_assert_int_eq(s21_res, lib_res);
  for (int i = 0; i < 1; i++) {
    ck_assert_msg(s21_vars[i] == lib_vars[i], "Error");
  }
}
END_TEST

START_TEST(sscanf_oux_test_25) {
  const void* str = "0777777777773337777777 835673956395 0xFFFFFFFFFFFFFF";
  const void* format = "%lo %lu %lx";

  unsigned long int s21_vars[3] = {-1};
  unsigned long int lib_vars[3] = {-1};

  int s21_res =
      s21_sscanf(str, format, &s21_vars[0], &s21_vars[1], &s21_vars[2]);
  int lib_res = sscanf(str, format, &lib_vars[0], &lib_vars[1], &lib_vars[2]);

  ck_assert_int_eq(s21_res, lib_res);
  for (int i = 0; i < 3; i++) {
    ck_assert_msg(s21_vars[i] == lib_vars[i], "Error");
  }
}
END_TEST

START_TEST(sscanf_oux_test_26) {
  const void* str = "0777777777773337777777 835673956395 0xFFFFFFFFFFFFFF";
  const void* format = "%Lo %Lu %Lx";

  unsigned long long s21_vars[3] = {-1};
  unsigned long long lib_vars[3] = {-1};

  int s21_res =
      s21_sscanf(str, format, &s21_vars[0], &s21_vars[1], &s21_vars[2]);
  int lib_res = sscanf(str, format, &lib_vars[0], &lib_vars[1], &lib_vars[2]);

  ck_assert_int_eq(s21_res, lib_res);
  for (int i = 0; i < 3; i++) {
    ck_assert_msg(s21_vars[i] == lib_vars[i], "Error");
  }
}
END_TEST

START_TEST(sscanf_oux_test_27) {
  const void* str = "835673956395";
  const void* format = "%u";

  unsigned int s21_vars[1] = {-1};
  unsigned int lib_vars[1] = {-1};

  int s21_res = s21_sscanf(str, format, &s21_vars[0]);
  int lib_res = sscanf(str, format, &lib_vars[0]);

  ck_assert_int_eq(s21_res, lib_res);
  for (int i = 0; i < 1; i++) {
    ck_assert_msg(s21_vars[i] == lib_vars[i], "Error");
  }
}
END_TEST

START_TEST(sscanf_oux_test_28) {
  const void* str = "835673956395";
  const void* format = "%hu";

  unsigned short int s21_vars[1] = {-1};
  unsigned short int lib_vars[1] = {-1};

  int s21_res = s21_sscanf(str, format, &s21_vars[0]);
  int lib_res = sscanf(str, format, &lib_vars[0]);

  ck_assert_int_eq(s21_res, lib_res);
  for (int i = 0; i < 1; i++) {
    ck_assert_msg(s21_vars[i] == lib_vars[i], "Error");
  }
}
END_TEST

START_TEST(sscanf_oux_test_29) {
  const void* str = "835673956395";
  const void* format = "%*3u %*u %u";

  unsigned int s21_vars[3] = {-1};
  unsigned int lib_vars[3] = {-1};

  int s21_res =
      s21_sscanf(str, format, &s21_vars[0], &s21_vars[1], &s21_vars[2]);

  int lib_res = sscanf(str, format, &lib_vars[0], &lib_vars[1], &lib_vars[2]);

  ck_assert_int_eq(s21_res, lib_res);
  for (int i = 0; i < 3; i++) {
    ck_assert_msg(s21_vars[i] == lib_vars[i], "Error");
  }
}
END_TEST

START_TEST(sscanf_oux_test_30) {
  const void* str = "835673956395";
  const void* format = "%3u %u %*u";

  unsigned int s21_vars[3] = {-1};
  unsigned int lib_vars[3] = {-1};

  int s21_res =
      s21_sscanf(str, format, &s21_vars[0], &s21_vars[1], &s21_vars[2]);
  int lib_res = sscanf(str, format, &lib_vars[0], &lib_vars[1], &lib_vars[2]);

  ck_assert_int_eq(s21_res, lib_res);
  for (int i = 0; i < 3; i++) {
    ck_assert_msg(s21_vars[i] == lib_vars[i], "Error");
  }
}
END_TEST

TCase* sscanf_oux_get_tests(void) {
  TCase* test_cases = tcase_create("sscanf_oux_cases");

  tcase_add_test(test_cases, sscanf_oux_test_1);
  tcase_add_test(test_cases, sscanf_oux_test_2);
  tcase_add_test(test_cases, sscanf_oux_test_3);
  tcase_add_test(test_cases, sscanf_oux_test_4);
  tcase_add_test(test_cases, sscanf_oux_test_5);
  tcase_add_test(test_cases, sscanf_oux_test_6);
  tcase_add_test(test_cases, sscanf_oux_test_7);
  tcase_add_test(test_cases, sscanf_oux_test_8);
  tcase_add_test(test_cases, sscanf_oux_test_9);
  tcase_add_test(test_cases, sscanf_oux_test_10);
  tcase_add_test(test_cases, sscanf_oux_test_11);
  tcase_add_test(test_cases, sscanf_oux_test_12);
  tcase_add_test(test_cases, sscanf_oux_test_13);
  tcase_add_test(test_cases, sscanf_oux_test_14);
  tcase_add_test(test_cases, sscanf_oux_test_15);
  tcase_add_test(test_cases, sscanf_oux_test_16);
  tcase_add_test(test_cases, sscanf_oux_test_17);
  tcase_add_test(test_cases, sscanf_oux_test_18);
  tcase_add_test(test_cases, sscanf_oux_test_19);
  tcase_add_test(test_cases, sscanf_oux_test_20);
  tcase_add_test(test_cases, sscanf_oux_test_21);
  tcase_add_test(test_cases, sscanf_oux_test_22);
  tcase_add_test(test_cases, sscanf_oux_test_23);
  tcase_add_test(test_cases, sscanf_oux_test_24);
  tcase_add_test(test_cases, sscanf_oux_test_25);
  tcase_add_test(test_cases, sscanf_oux_test_26);
  tcase_add_test(test_cases, sscanf_oux_test_27);
  tcase_add_test(test_cases, sscanf_oux_test_28);
  tcase_add_test(test_cases, sscanf_oux_test_29);
  tcase_add_test(test_cases, sscanf_oux_test_30);

  return test_cases;
}
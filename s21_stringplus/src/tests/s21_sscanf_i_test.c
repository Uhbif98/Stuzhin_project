#include <check.h>
#include <limits.h>

#include "../s21_string.h"

START_TEST(sscanf_i_test_1) {
  const void* str = " 531 07346 0030687 00073330 0x3AA 0X3AA 0xA 0XA 0A A";
  const void* format = " %i %i %i %i %i %i %i %i %i %i";

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

START_TEST(sscanf_i_test_2) {
  const void* str =
      " -531 -07346 -0030687 -00073330 -0x3AA -0X3AA -0xA -0XA -0A -A";
  const void* format = " %i %i %i %i %i %i %i %i %i %i";

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

START_TEST(sscanf_i_test_3) {
  const void* str = " +8436 -7364 +-5837 -+76845 333";
  const void* format = " %i %i %i %i %i";

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

START_TEST(sscanf_i_test_4) {
  const void* str =
      " 052303 004387 0007436 000 0 +08436 -07364 +-05837 -+076845 0333";
  const void* format = " %i %i %i %i %i %i %i %i %i %i";

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

START_TEST(sscanf_i_test_5) {
  const void* str = " 0x52303 0x04387 0x0F7436 0x00 0x 0 x";
  const void* format = " %i %i %i %i %i %i";

  int s21_vars[6] = {-1};
  int lib_vars[6] = {-1};

  int s21_res =
      s21_sscanf(str, format, &s21_vars[0], &s21_vars[1], &s21_vars[2],
                 &s21_vars[3], &s21_vars[4], &s21_vars[5]);
  int lib_res = sscanf(str, format, &lib_vars[0], &lib_vars[1], &lib_vars[2],
                       &lib_vars[3], &lib_vars[4], &lib_vars[5]);

  ck_assert_int_eq(s21_res, lib_res);
  for (int i = 0; i < 6; i++) {
    ck_assert_int_eq(s21_vars[i], lib_vars[i]);
  }
}
END_TEST

START_TEST(sscanf_i_test_6) {
  const void* str = " 0X52a03 0X04B7 0X007C36 0X00 0X 0 X";
  const void* format = " %i %i %i %i %i %i";

  int s21_vars[6] = {-1};
  int lib_vars[6] = {-1};

  int s21_res =
      s21_sscanf(str, format, &s21_vars[0], &s21_vars[1], &s21_vars[2],
                 &s21_vars[3], &s21_vars[4], &s21_vars[5]);
  int lib_res = sscanf(str, format, &lib_vars[0], &lib_vars[1], &lib_vars[2],
                       &lib_vars[3], &lib_vars[4], &lib_vars[5]);

  ck_assert_int_eq(s21_res, lib_res);
  for (int i = 0; i < 6; i++) {
    ck_assert_int_eq(s21_vars[i], lib_vars[i]);
  }
}
END_TEST

START_TEST(sscanf_i_test_7) {
  const void* str = " -0X52Bc3 -0X0BA87 -0X0ab436 -0X00 -0X -0 -X";
  const void* format = " %i %i %i %i %i %i";

  int s21_vars[6] = {-1};
  int lib_vars[6] = {-1};

  int s21_res =
      s21_sscanf(str, format, &s21_vars[0], &s21_vars[1], &s21_vars[2],
                 &s21_vars[3], &s21_vars[4], &s21_vars[5]);
  int lib_res = sscanf(str, format, &lib_vars[0], &lib_vars[1], &lib_vars[2],
                       &lib_vars[3], &lib_vars[4], &lib_vars[5]);

  ck_assert_int_eq(s21_res, lib_res);
  for (int i = 0; i < 6; i++) {
    ck_assert_int_eq(s21_vars[i], lib_vars[i]);
  }
}
END_TEST

START_TEST(sscanf_i_test_8) {
  const void* str = " 0xfff 0xqwerty";
  const void* format = " %i %i";

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

START_TEST(sscanf_i_test_9) {
  const void* str = " 0333 03169";
  const void* format = " %i %i";

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

START_TEST(sscanf_i_test_10) {
  const void* str = " 00000310369";
  const void* format = " %i";

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

START_TEST(sscanf_i_test_11) {
  const void* str = "3 34678374 957453 753 5734";
  const void* format = " %3i %0i %1i %3i %100i";

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

START_TEST(sscanf_i_test_12) {
  const void* str = "0375657 00723572 000784333 000754534";
  const void* format = " %3i %4i %5i %1i";

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

START_TEST(sscanf_i_test_13) {
  const void* str = "0x375657 0x0723572 0x00784333 0x00754534";
  const void* format = " %3i %4i %5i %1i";

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

START_TEST(sscanf_i_test_14) {
  const void* str = "0x3x57325 x235333";
  const void* format = " %i %i";

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

START_TEST(sscanf_i_test_15) {
  const void* str = " 0AxAA57325 x0x0x3ABCDEF";
  const void* format = " %i %i";

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

START_TEST(sscanf_i_test_16) {
  const void* str = " 0XA1B2C3 0XA 0X0 -0XABC";
  const void* format = " %hi %hi %hi %hi";

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

START_TEST(sscanf_i_test_17) {
  const void* str = " 01546 03 00 -058236";
  const void* format = " %hi %hi %hi %hi";

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

START_TEST(sscanf_i_test_18) {
  const void* str = " 1546 3 0 -58236";
  const void* format = " %hi %hi %hi %hi";

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

START_TEST(sscanf_i_test_19) {
  const void* str = " 0XA1B2C3 0XA 0X0 -0XABC";
  const void* format = " %li %li %li %li";

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

START_TEST(sscanf_i_test_20) {
  const void* str = " 01546 03 00 -058236";
  const void* format = " %li %li %li %li";

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

START_TEST(sscanf_i_test_21) {
  const void* str = " 1546 3 0 -58236";
  const void* format = " %li %li %li %li";

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

START_TEST(sscanf_i_test_22) {
  const void* str = " 0XA1B2C3 0XA 0X0 -0XABC";
  const void* format = " %Li %Li %Li %Li";

  long long s21_vars[4] = {-1};
  long long lib_vars[4] = {-1};

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

START_TEST(sscanf_i_test_23) {
  const void* str = " 01546 03 00 -058236";
  const void* format = " %Li %Li %Li %Li";

  long long s21_vars[4] = {-1};
  long long lib_vars[4] = {-1};

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

START_TEST(sscanf_i_test_24) {
  const void* str = " 1546 3 0 -58236";
  const void* format = " %Li %Li %Li %Li";

  long long s21_vars[4] = {-1};
  long long lib_vars[4] = {-1};

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

START_TEST(sscanf_i_test_25) {
  const void* str = " 1546 3 0 -58236";
  const void* format = " %*Li %Li %*Li %Li";

  long long s21_vars[4] = {-1};
  long long lib_vars[4] = {-1};

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

START_TEST(sscanf_i_test_26) {
  const void* str = " 01546 0x3AAA 123 -58236";
  const void* format = " %Li %*Li %*Li %*Li";

  long long s21_vars[4] = {-1};
  long long lib_vars[4] = {-1};

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

START_TEST(sscanf_i_test_27) {
  const void* str = " 0X1546a 0x3AAAaaa 123 -58236";
  const void* format = " %*Li %Li %Li %Li";

  long long s21_vars[4] = {-1};
  long long lib_vars[4] = {-1};

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

TCase* sscanf_i_get_tests(void) {
  TCase* test_cases = tcase_create("sscanf_i_cases");

  tcase_add_test(test_cases, sscanf_i_test_1);
  tcase_add_test(test_cases, sscanf_i_test_2);
  tcase_add_test(test_cases, sscanf_i_test_3);
  tcase_add_test(test_cases, sscanf_i_test_4);
  tcase_add_test(test_cases, sscanf_i_test_5);
  tcase_add_test(test_cases, sscanf_i_test_6);
  tcase_add_test(test_cases, sscanf_i_test_7);
  tcase_add_test(test_cases, sscanf_i_test_8);
  tcase_add_test(test_cases, sscanf_i_test_9);
  tcase_add_test(test_cases, sscanf_i_test_10);
  tcase_add_test(test_cases, sscanf_i_test_11);
  tcase_add_test(test_cases, sscanf_i_test_12);
  tcase_add_test(test_cases, sscanf_i_test_13);
  tcase_add_test(test_cases, sscanf_i_test_14);
  tcase_add_test(test_cases, sscanf_i_test_15);
  tcase_add_test(test_cases, sscanf_i_test_16);
  tcase_add_test(test_cases, sscanf_i_test_17);
  tcase_add_test(test_cases, sscanf_i_test_18);
  tcase_add_test(test_cases, sscanf_i_test_19);
  tcase_add_test(test_cases, sscanf_i_test_20);
  tcase_add_test(test_cases, sscanf_i_test_21);
  tcase_add_test(test_cases, sscanf_i_test_22);
  tcase_add_test(test_cases, sscanf_i_test_23);
  tcase_add_test(test_cases, sscanf_i_test_24);
  tcase_add_test(test_cases, sscanf_i_test_25);
  tcase_add_test(test_cases, sscanf_i_test_26);
  tcase_add_test(test_cases, sscanf_i_test_27);

  return test_cases;
}
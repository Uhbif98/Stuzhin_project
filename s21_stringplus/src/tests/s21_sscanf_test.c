#include <check.h>
#include <limits.h>

#include "../s21_string.h"

START_TEST(sscanf_test_1) {
  const void* str =
      "abc % a 123 123.456 0123 123 0x123abc 0333 333 0x333abc 0X333abc "
      "0XABCDEF text_text_text )";
  const void* format = "abc %% %c %d %f %i %i %i %n %o %u %x %X %p %s )";

  char c1 = 0, c2 = 0;
  int d1 = 0, d2 = 0;
  float f1 = 0, f2 = 0;
  int i1[3] = {0}, i2[3] = {0};
  int n1 = 0, n2 = 0;
  unsigned int oux1[4] = {0}, oux2[4] = {0};
  void* p1 = 0;
  void* p2 = 0;
  char s1[100] = {0}, s2[100] = {0};

  int s21_res =
      s21_sscanf(str, format, &c1, &d1, &f1, &i1[0], &i1[1], &i1[2], &n1,
                 &oux1[0], &oux1[1], &oux1[2], &oux1[3], &p1, s1);
  int lib_res = sscanf(str, format, &c2, &d2, &f2, &i2[0], &i2[1], &i2[2], &n2,
                       &oux2[0], &oux2[1], &oux2[2], &oux2[3], &p2, s2);

  ck_assert_int_eq(s21_res, lib_res);

  ck_assert_int_eq(c1, c2);
  ck_assert_int_eq(d1, d2);
  ck_assert_float_eq(f1, f2);
  ck_assert_int_eq(i1[0], i2[0]);
  ck_assert_int_eq(i1[1], i2[1]);
  ck_assert_int_eq(i1[2], i2[2]);
  ck_assert_int_eq(n1, n2);
  ck_assert_uint_eq(oux1[0], oux2[0]);
  ck_assert_uint_eq(oux1[1], oux2[1]);
  ck_assert_uint_eq(oux1[2], oux2[2]);
  ck_assert_uint_eq(oux1[3], oux2[3]);
  ck_assert_ptr_eq(p1, p2);
  ck_assert_pstr_eq(s1, s2);
}
END_TEST

START_TEST(sscanf_test_2) {
  const void* str =
      "abc % a 123 123.456 0123 123 0x123abc 0333 333 0x333abc 0X333abc "
      "0XABCDEF text_text_text";
  const void* format =
      "abc %% %*c %*d %*f %*i %*i %*i %*n %*o %*u %*x %*X %*p %*s";

  char c1 = 0, c2 = 0;
  int d1 = 0, d2 = 0;
  float f1 = 0, f2 = 0;
  int i1[3] = {0}, i2[3] = {0};
  int n1 = 0, n2 = 0;
  unsigned int oux1[4] = {0}, oux2[4] = {0};
  void* p1 = 0;
  void* p2 = 0;
  char s1[100] = {0}, s2[100] = {0};

  int s21_res =
      s21_sscanf(str, format, &c1, &d1, &f1, &i1[0], &i1[1], &i1[2], &n1,
                 &oux1[0], &oux1[1], &oux1[2], &oux1[3], &p1, s1);
  int lib_res = sscanf(str, format, &c2, &d2, &f2, &i2[0], &i2[1], &i2[2], &n2,
                       &oux2[0], &oux2[1], &oux2[2], &oux2[3], &p2, s2);

  ck_assert_int_eq(s21_res, lib_res);

  ck_assert_int_eq(c1, c2);
  ck_assert_int_eq(d1, d2);
  ck_assert_float_eq(f1, f2);
  ck_assert_int_eq(i1[0], i2[0]);
  ck_assert_int_eq(i1[1], i2[1]);
  ck_assert_int_eq(i1[2], i2[2]);
  ck_assert_int_eq(n1, n2);
  ck_assert_uint_eq(oux1[0], oux2[0]);
  ck_assert_uint_eq(oux1[1], oux2[1]);
  ck_assert_uint_eq(oux1[2], oux2[2]);
  ck_assert_uint_eq(oux1[3], oux2[3]);
  ck_assert_ptr_eq(p1, p2);
  ck_assert_pstr_eq(s1, s2);
}
END_TEST

START_TEST(sscanf_test_3) {
  const void* str =
      "a 123 123.456 0123 123 0x123abc 0333 333 0x333abc 0X333abc 0XABCDEF "
      "text_text_text";
  const void* format = "%c%d%f%i%i%i%n%o%u%x%X%p%s";

  char c1 = 0, c2 = 0;
  int d1 = 0, d2 = 0;
  float f1 = 0, f2 = 0;
  int i1[3] = {0}, i2[3] = {0};
  int n1 = 0, n2 = 0;
  unsigned int oux1[4] = {0}, oux2[4] = {0};
  void* p1 = 0;
  void* p2 = 0;
  char s1[100] = {0}, s2[100] = {0};

  int s21_res =
      s21_sscanf(str, format, &c1, &d1, &f1, &i1[0], &i1[1], &i1[2], &n1,
                 &oux1[0], &oux1[1], &oux1[2], &oux1[3], &p1, s1);
  int lib_res = sscanf(str, format, &c2, &d2, &f2, &i2[0], &i2[1], &i2[2], &n2,
                       &oux2[0], &oux2[1], &oux2[2], &oux2[3], &p2, s2);

  ck_assert_int_eq(s21_res, lib_res);

  ck_assert_int_eq(c1, c2);
  ck_assert_int_eq(d1, d2);
  ck_assert_float_eq(f1, f2);
  ck_assert_int_eq(i1[0], i2[0]);
  ck_assert_int_eq(i1[1], i2[1]);
  ck_assert_int_eq(i1[2], i2[2]);
  ck_assert_int_eq(n1, n2);
  ck_assert_uint_eq(oux1[0], oux2[0]);
  ck_assert_uint_eq(oux1[1], oux2[1]);
  ck_assert_uint_eq(oux1[2], oux2[2]);
  ck_assert_uint_eq(oux1[3], oux2[3]);
  ck_assert_ptr_eq(p1, p2);
  ck_assert_pstr_eq(s1, s2);
}
END_TEST

TCase* sscanf_get_tests(void) {
  TCase* test_cases = tcase_create("sscanf_cases");

  tcase_add_test(test_cases, sscanf_test_1);
  tcase_add_test(test_cases, sscanf_test_2);
  tcase_add_test(test_cases, sscanf_test_3);

  return test_cases;
}
#include <check.h>
#include <limits.h>

#include "../s21_string.h"

START_TEST(test_x_flags) {
  char s21_result[100];
  char original_result[100];

  unsigned int val = 12345;
  int a = s21_sprintf(s21_result, "%x", val);
  int b = sprintf(original_result, "%x", val);
  ck_assert_str_eq(s21_result, original_result);
  ck_assert_int_eq(a, b);

  a = s21_sprintf(s21_result, "%#x", val);
  b = sprintf(original_result, "%#x", val);
  ck_assert_str_eq(s21_result, original_result);
  ck_assert_int_eq(a, b);

  a = s21_sprintf(s21_result, "%010x", val);
  b = sprintf(original_result, "%010x", val);
  ck_assert_str_eq(s21_result, original_result);
  ck_assert_int_eq(a, b);

  a = s21_sprintf(s21_result, "%-10x", val);
  b = sprintf(original_result, "%-10x", val);
  ck_assert_str_eq(s21_result, original_result);
  ck_assert_int_eq(a, b);
}
END_TEST

START_TEST(test_x_width) {
  char s21_result[100];
  char original_result[100];
  unsigned int val = 12345;

  int a = s21_sprintf(s21_result, "%10x", val);
  int b = sprintf(original_result, "%10x", val);
  ck_assert_str_eq(s21_result, original_result);
  ck_assert_int_eq(a, b);
}
END_TEST

START_TEST(test_x_accuracy) {
  char s21_result[100];
  char original_result[100];
  unsigned int val = 12345;
  int a = s21_sprintf(s21_result, "%.5x", val);
  int b = sprintf(original_result, "%.5x", val);
  ck_assert_str_eq(s21_result, original_result);
  ck_assert_int_eq(a, b);
}
END_TEST

START_TEST(test_x_width_accuracy) {
  char s21_result[100];
  char original_result[100];
  unsigned int val = 12345;
  int a = s21_sprintf(s21_result, "%10.5x", val);
  int b = sprintf(original_result, "%10.5x", val);
  ck_assert_str_eq(s21_result, original_result);
  ck_assert_int_eq(a, b);
}
END_TEST

START_TEST(test_x_flag_0_width) {
  char s21_result[100];
  char original_result[100];
  unsigned int val = 12345;
  int a = s21_sprintf(s21_result, "%10.5x", val);
  int b = sprintf(original_result, "%10.5x", val);
  ck_assert_str_eq(s21_result, original_result);
  ck_assert_int_eq(a, b);
}
END_TEST

START_TEST(test_x_length_l) {
  char s21_result[100];
  char original_result[100];
  unsigned long int lval = 123456789;
  int a = s21_sprintf(s21_result, "%lx", lval);
  int b = sprintf(original_result, "%lx", lval);
  ck_assert_str_eq(s21_result, original_result);
  ck_assert_int_eq(a, b);

  unsigned long int lvalue = 0xFFFFFFFF;
  a = s21_sprintf(s21_result, "%lX", lvalue);
  b = sprintf(original_result, "%lX", lvalue);
  ck_assert_str_eq(s21_result, original_result);
  ck_assert_int_eq(a, b);
}
END_TEST

START_TEST(test_x_length_h) {
  char s21_result[100];
  char original_result[100];
  unsigned short int hval = 12345;
  int a = s21_sprintf(s21_result, "%hx", hval);
  int b = sprintf(original_result, "%hx", hval);
  ck_assert_str_eq(s21_result, original_result);
  ck_assert_int_eq(a, b);
}
END_TEST

START_TEST(test_X_flags) {
  char s21_result[100];
  char original_result[100];
  unsigned int val = 12345;

  int a = s21_sprintf(s21_result, "%X", val);
  int b = sprintf(original_result, "%X", val);
  ck_assert_str_eq(s21_result, original_result);
  ck_assert_int_eq(a, b);

  a = s21_sprintf(s21_result, "%#X", val);
  b = sprintf(original_result, "%#X", val);
  ck_assert_str_eq(s21_result, original_result);
  ck_assert_int_eq(a, b);

  a = s21_sprintf(s21_result, "%010X", val);
  b = sprintf(original_result, "%010X", val);
  ck_assert_str_eq(s21_result, original_result);
  ck_assert_int_eq(a, b);

  a = s21_sprintf(s21_result, "%-10X", val);
  b = sprintf(original_result, "%-10X", val);
  ck_assert_str_eq(s21_result, original_result);
  ck_assert_int_eq(a, b);
}
END_TEST

START_TEST(test_X_width) {
  char s21_result[100];
  char original_result[100];

  unsigned int val = 12345;
  int a = s21_sprintf(s21_result, "%10X", val);
  int b = sprintf(original_result, "%10X", val);
  ck_assert_str_eq(s21_result, original_result);
  ck_assert_int_eq(a, b);
}
END_TEST

START_TEST(test_X_accuracy) {
  char s21_result[100];
  char original_result[100];

  unsigned int val = 12345;
  int a = s21_sprintf(s21_result, "%.5X", val);
  int b = sprintf(original_result, "%.5X", val);
  ck_assert_str_eq(s21_result, original_result);
  ck_assert_int_eq(a, b);
}
END_TEST

START_TEST(test_X_accuracy_width) {
  char s21_result[100];
  char original_result[100];

  unsigned int val = 12345;
  int a = s21_sprintf(s21_result, "%10.5X", val);
  int b = sprintf(original_result, "%10.5X", val);
  ck_assert_str_eq(s21_result, original_result);
  ck_assert_int_eq(a, b);
}
END_TEST

START_TEST(test_X_length) {
  char s21_result[100];
  char original_result[100];

  unsigned long int lval = 123456789;
  unsigned short int hval = 12345;
  int a = s21_sprintf(s21_result, "%lX", lval);
  int b = sprintf(original_result, "%lX", lval);
  ck_assert_str_eq(s21_result, original_result);
  ck_assert_int_eq(a, b);

  a = s21_sprintf(s21_result, "%hX", hval);
  b = sprintf(original_result, "%hX", hval);
  ck_assert_str_eq(s21_result, original_result);
  ck_assert_int_eq(a, b);

  unsigned long int lvalue = 0xFFFFFFFF;
  a = s21_sprintf(s21_result, "%lX", lvalue);
  b = sprintf(original_result, "%lX", lvalue);
  ck_assert_str_eq(s21_result, original_result);
  ck_assert_int_eq(a, b);

  unsigned short int hvalue = 0xFFFF;
  a = s21_sprintf(s21_result, "%hX", hvalue);
  b = sprintf(original_result, "%hX", hvalue);
  ck_assert_str_eq(s21_result, original_result);
  ck_assert_int_eq(a, b);
}
END_TEST

START_TEST(test_x_combination) {
  char s21_result[100];
  char original_result[100];

  int int_val = 255;
  unsigned int hex_val = 0xFF;
  int a = s21_sprintf(s21_result, "%d %x", int_val, hex_val);
  int b = sprintf(original_result, "%d %x", int_val, hex_val);
  ck_assert_str_eq(s21_result, original_result);
  ck_assert_int_eq(a, b);

  double float_val = 123.456;
  a = s21_sprintf(s21_result, "%f %x", float_val, hex_val);
  b = sprintf(original_result, "%f %x", float_val, hex_val);
  ck_assert_str_eq(s21_result, original_result);
  ck_assert_int_eq(a, b);

  const char *str_val = "Test";
  a = s21_sprintf(s21_result, "%s %x", str_val, hex_val);
  b = sprintf(original_result, "%s %x", str_val, hex_val);
  ck_assert_str_eq(s21_result, original_result);
  ck_assert_int_eq(a, b);

  char char_val = 'A';
  a = s21_sprintf(s21_result, "%c %x", char_val, hex_val);
  b = sprintf(original_result, "%c %x", char_val, hex_val);
  ck_assert_str_eq(s21_result, original_result);
  ck_assert_int_eq(a, b);

  a = s21_sprintf(s21_result, "%#x", hex_val);
  b = sprintf(original_result, "%#x", hex_val);
  ck_assert_str_eq(s21_result, original_result);
  ck_assert_int_eq(a, b);

  a = s21_sprintf(s21_result, "%0x", hex_val);
  b = sprintf(original_result, "%0x", hex_val);
  ck_assert_str_eq(s21_result, original_result);
  ck_assert_int_eq(a, b);

  a = s21_sprintf(s21_result, "%-x", hex_val);
  b = sprintf(original_result, "%-x", hex_val);
  ck_assert_str_eq(s21_result, original_result);
  ck_assert_int_eq(a, b);

  a = s21_sprintf(s21_result, "%10x", hex_val);
  b = sprintf(original_result, "%10x", hex_val);
  ck_assert_str_eq(s21_result, original_result);
  ck_assert_int_eq(a, b);

  a = s21_sprintf(s21_result, "%.5x", hex_val);
  b = sprintf(original_result, "%.5x", hex_val);
  ck_assert_str_eq(s21_result, original_result);
  ck_assert_int_eq(a, b);

  a = s21_sprintf(s21_result, "%10.5x", hex_val);
  b = sprintf(original_result, "%10.5x", hex_val);
  ck_assert_str_eq(s21_result, original_result);
  ck_assert_int_eq(a, b);

  a = s21_sprintf(s21_result, "%#10.5x", hex_val);
  b = sprintf(original_result, "%#10.5x", hex_val);
  ck_assert_str_eq(s21_result, original_result);
  ck_assert_int_eq(a, b);

  a = s21_sprintf(s21_result, "%#X", hex_val);
  b = sprintf(original_result, "%#X", hex_val);
  ck_assert_str_eq(s21_result, original_result);
  ck_assert_int_eq(a, b);

  a = s21_sprintf(s21_result, "%0X", hex_val);
  b = sprintf(original_result, "%0X", hex_val);
  ck_assert_str_eq(s21_result, original_result);
  ck_assert_int_eq(a, b);

  a = s21_sprintf(s21_result, "%-X", hex_val);
  b = sprintf(original_result, "%-X", hex_val);
  ck_assert_str_eq(s21_result, original_result);
  ck_assert_int_eq(a, b);

  a = s21_sprintf(s21_result, "%10X", hex_val);
  b = sprintf(original_result, "%10X", hex_val);
  ck_assert_str_eq(s21_result, original_result);
  ck_assert_int_eq(a, b);

  a = s21_sprintf(s21_result, "%.5X", hex_val);
  b = sprintf(original_result, "%.5X", hex_val);
  ck_assert_str_eq(s21_result, original_result);
  ck_assert_int_eq(a, b);

  a = s21_sprintf(s21_result, "%#10.5X", hex_val);
  b = sprintf(original_result, "%#10.5X", hex_val);
  ck_assert_str_eq(s21_result, original_result);
  ck_assert_int_eq(a, b);
}
END_TEST

START_TEST(test_x_specifier_load) {
  char s21_result[1000];
  char original_result[1000];

  unsigned long int large_val = 0xFFFFFFFFFFFFFFFF;
  int a = s21_sprintf(s21_result, "%lx", large_val);
  int b = sprintf(original_result, "%lx", large_val);
  ck_assert_str_eq(s21_result, original_result);
  ck_assert_int_eq(a, b);

  unsigned int small_val = 0x1;
  a = s21_sprintf(s21_result, "%x", small_val);
  b = sprintf(original_result, "%x", small_val);
  ck_assert_str_eq(s21_result, original_result);
  ck_assert_int_eq(a, b);

  unsigned int val = 0xFF;
  a = s21_sprintf(s21_result, "%x %x %x %x %x %x %x %x %x %x", val, val, val,
                  val, val, val, val, val, val, val);
  b = sprintf(original_result, "%x %x %x %x %x %x %x %x %x %x", val, val, val,
              val, val, val, val, val, val, val);
  ck_assert_str_eq(s21_result, original_result);
  ck_assert_int_eq(a, b);
}
END_TEST

START_TEST(test_x_specifier) {
  char s21_result[100];
  char original_result[100];

  unsigned int val = 0x1234abcd;

  int a = s21_sprintf(s21_result, "%#x", val);
  int b = sprintf(original_result, "%#x", val);
  ck_assert_pstr_eq(s21_result, original_result);
  ck_assert_int_eq(a, b);

  a = s21_sprintf(s21_result, "%#X", val);
  b = sprintf(original_result, "%#X", val);
  ck_assert_str_eq(s21_result, original_result);
  ck_assert_int_eq(a, b);

  a = s21_sprintf(s21_result, "%0x", val);
  b = sprintf(original_result, "%0x", val);
  ck_assert_str_eq(s21_result, original_result);
  ck_assert_int_eq(a, b);

  a = s21_sprintf(s21_result, "%0X", val);
  b = sprintf(original_result, "%0X", val);
  ck_assert_str_eq(s21_result, original_result);
  ck_assert_int_eq(a, b);

  a = s21_sprintf(s21_result, "%-x", val);
  b = sprintf(original_result, "%-x", val);
  ck_assert_str_eq(s21_result, original_result);
  ck_assert_int_eq(a, b);

  a = s21_sprintf(s21_result, "%-X", val);
  b = sprintf(original_result, "%-X", val);
  ck_assert_str_eq(s21_result, original_result);
  ck_assert_int_eq(a, b);

  a = s21_sprintf(s21_result, "%10x", val);
  b = sprintf(original_result, "%10x", val);
  ck_assert_str_eq(s21_result, original_result);
  ck_assert_int_eq(a, b);

  a = s21_sprintf(s21_result, "%10X", val);
  b = sprintf(original_result, "%10X", val);
  ck_assert_str_eq(s21_result, original_result);
  ck_assert_int_eq(a, b);

  a = s21_sprintf(s21_result, "%.5x", val);
  b = sprintf(original_result, "%.5x", val);
  ck_assert_str_eq(s21_result, original_result);
  ck_assert_int_eq(a, b);

  a = s21_sprintf(s21_result, "%.5X", val);
  b = sprintf(original_result, "%.5X", val);
  ck_assert_str_eq(s21_result, original_result);
  ck_assert_int_eq(a, b);

  a = s21_sprintf(s21_result, "%10.5x", val);
  b = sprintf(original_result, "%10.5x", val);
  ck_assert_str_eq(s21_result, original_result);
  ck_assert_int_eq(a, b);

  a = s21_sprintf(s21_result, "%10.5X", val);
  b = sprintf(original_result, "%10.5X", val);
  ck_assert_str_eq(s21_result, original_result);
  ck_assert_int_eq(a, b);

  a = s21_sprintf(s21_result, "%10.5x", val);
  b = sprintf(original_result, "%10.5x", val);
  ck_assert_str_eq(s21_result, original_result);
  ck_assert_int_eq(a, b);

  a = s21_sprintf(s21_result, "%10.5X", val);
  b = sprintf(original_result, "%10.5X", val);
  ck_assert_str_eq(s21_result, original_result);
  ck_assert_int_eq(a, b);

  a = s21_sprintf(s21_result, "%#3x %-2x %-4x %05x %.5x", val, val, val, val,
                  val);
  b = sprintf(original_result, "%#3x %-2x %-4x %05x %.5x", val, val, val, val,
              val);
  ck_assert_str_eq(s21_result, original_result);
  ck_assert_int_eq(a, b);

  a = s21_sprintf(s21_result, "%#3X %-2X %-4X %05X %.5X", val, val, val, val,
                  val);
  b = sprintf(original_result, "%#3X %-2X %-4X %05X %.5X", val, val, val, val,
              val);
  ck_assert_str_eq(s21_result, original_result);
  ck_assert_int_eq(a, b);
}
END_TEST

TCase *sprintf_xX_get_tests(void) {
  TCase *test_cases = tcase_create("test_sprintf_x");

  tcase_add_test(test_cases, test_x_flags);
  tcase_add_test(test_cases, test_x_width);
  tcase_add_test(test_cases, test_x_accuracy);
  tcase_add_test(test_cases, test_x_width_accuracy);

  tcase_add_test(test_cases, test_x_flag_0_width);
  tcase_add_test(test_cases, test_x_length_l);
  tcase_add_test(test_cases, test_x_length_h);
  tcase_add_test(test_cases, test_X_flags);
  tcase_add_test(test_cases, test_X_width);
  tcase_add_test(test_cases, test_X_accuracy);

  tcase_add_test(test_cases, test_X_accuracy_width);
  tcase_add_test(test_cases, test_X_length);
  tcase_add_test(test_cases, test_x_combination);
  tcase_add_test(test_cases, test_x_specifier_load);
  tcase_add_test(test_cases, test_x_specifier);

  return test_cases;
}

#include <check.h>
#include <limits.h>

#include "../s21_string.h"

START_TEST(test_1) {
  s21_size_t n = 2;
  char* str2 = calloc(n + 1, sizeof(char));
  char* str3 = calloc(n + 1, sizeof(char));
  if (str2 != s21_NULL && str3 != s21_NULL) {
    char* str = "\0";
    ck_assert_str_eq(s21_memcpy(str2, str, n), memcpy(str3, str, n));
  }

  if (str2 != s21_NULL) {
    free(str2);
  }
  if (str3 != s21_NULL) {
    free(str3);
  }
}
END_TEST

START_TEST(test_2) {
  s21_size_t n = 5;
  char* str2 = calloc(n + 1, sizeof(char));
  char* str3 = calloc(n + 1, sizeof(char));

  if (str2 != s21_NULL && str3 != s21_NULL) {
    char* str = "sfasg";
    ck_assert_str_eq(s21_memcpy(str2, str, n), memcpy(str3, str, n));
  }

  if (str2 != s21_NULL) {
    free(str2);
  }
  if (str3 != s21_NULL) {
    free(str3);
  }
}
END_TEST

START_TEST(test_3) {
  s21_size_t n = 2;
  char* str2 = calloc(n + 1, sizeof(char));
  char* str3 = calloc(n + 1, sizeof(char));

  if (str2 != s21_NULL && str3 != s21_NULL) {
    char* str = "\n";
    ck_assert_str_eq(s21_memcpy(str2, str, n), memcpy(str3, str, n));
  }

  if (str2 != s21_NULL) {
    free(str2);
  }
  if (str3 != s21_NULL) {
    free(str3);
  }
}
END_TEST

START_TEST(test_4) {
  s21_size_t n = 14;
  char* str2 = calloc(n + 1, sizeof(char));
  char* str3 = calloc(n + 1, sizeof(char));

  if (str2 != s21_NULL && str3 != s21_NULL) {
    char* str = "Hello\n World\n";
    ck_assert_str_eq(s21_memcpy(str2, str, n), memcpy(str3, str, n));
  }

  if (str2 != s21_NULL) {
    free(str2);
  }
  if (str3 != s21_NULL) {
    free(str3);
  }
}
END_TEST;

START_TEST(test_5) {
  s21_size_t n = 7;
  char* str2 = calloc(n + 1, sizeof(char));
  char* str3 = calloc(n + 1, sizeof(char));

  if (str2 != s21_NULL && str3 != s21_NULL) {
    char* str = "\t Hello";
    ck_assert_str_eq(s21_memcpy(str2, str, n), memcpy(str3, str, n));
  }

  if (str2 != s21_NULL) {
    free(str2);
  }
  if (str3 != s21_NULL) {
    free(str3);
  }
}
END_TEST

START_TEST(test_6) {
  s21_size_t n = 8;
  char* str2 = calloc(n + 1, sizeof(char));
  char* str3 = calloc(n + 1, sizeof(char));

  if (str2 != s21_NULL && str3 != s21_NULL) {
    char* str = "^fn\t dk\n";
    ck_assert_str_eq(s21_memcpy(str2, str, n), memcpy(str3, str, n));
  }

  if (str2 != s21_NULL) {
    free(str2);
  }
  if (str3 != s21_NULL) {
    free(str3);
  }
}
END_TEST

START_TEST(test_7) {
  s21_size_t n = 9;
  char* str2 = calloc(n + 1, sizeof(char));
  char* str3 = calloc(n + 1, sizeof(char));

  if (str2 != s21_NULL && str3 != s21_NULL) {
    char* str = "\0Hello\t \n";
    ck_assert_str_eq(s21_memcpy(str2, str, n), memcpy(str3, str, n));
  }

  if (str2 != s21_NULL) {
    free(str2);
  }
  if (str3 != s21_NULL) {
    free(str3);
  }
}
END_TEST;

START_TEST(test_8) {
  s21_size_t n = 7;
  char* str2 = calloc(n + 1, sizeof(char));
  char* str3 = calloc(n + 1, sizeof(char));

  if (str2 != s21_NULL && str3 != s21_NULL) {
    char* str = "\0Hello\t \n";
    ck_assert_str_eq(s21_memcpy(str2, str, n), memcpy(str3, str, n));
  }

  if (str2 != s21_NULL) {
    free(str2);
  }
  if (str3 != s21_NULL) {
    free(str3);
  }
}
END_TEST

START_TEST(test_9) {
  s21_size_t n = 8;
  char* str2 = calloc(n + 1, sizeof(char));
  char* str3 = calloc(n + 1, sizeof(char));

  if (str2 != s21_NULL && str3 != s21_NULL) {
    char* str = "\0^I\0 ^M\0";
    ck_assert_str_eq(s21_memcpy(str2, str, n), memcpy(str3, str, n));
  }
  if (str2 != s21_NULL) {
    free(str2);
  }
  if (str3 != s21_NULL) {
    free(str3);
  }
}
END_TEST

START_TEST(test_10) {
  s21_size_t n = 8;
  char* str2 = calloc(n + 1, sizeof(char));
  char* str3 = calloc(n + 1, sizeof(char));

  if (str2 != s21_NULL && str3 != s21_NULL) {
    char* str = "\n\t\0 fsfd";
    ck_assert_str_eq(s21_memcpy(str2, str, n), memcpy(str3, str, n));
  }

  if (str2 != s21_NULL) {
    free(str2);
  }
  if (str3 != s21_NULL) {
    free(str3);
  }
}
END_TEST

TCase* memcpy_get_tests(void) {
  TCase* test_cases = tcase_create("test_memcpy");

  tcase_add_test(test_cases, test_1);
  tcase_add_test(test_cases, test_2);
  tcase_add_test(test_cases, test_3);
  tcase_add_test(test_cases, test_4);
  tcase_add_test(test_cases, test_5);
  tcase_add_test(test_cases, test_6);
  tcase_add_test(test_cases, test_7);
  tcase_add_test(test_cases, test_8);
  tcase_add_test(test_cases, test_9);
  tcase_add_test(test_cases, test_10);

  return test_cases;
}
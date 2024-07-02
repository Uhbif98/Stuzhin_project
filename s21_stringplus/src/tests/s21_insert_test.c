#include <check.h>
#include <limits.h>

#include "../s21_string.h"

START_TEST(test_insert_at_start) {
  const char *src = "World";
  const char *str = "Hello ";
  size_t start_index = 0;
  char *result = s21_insert(src, str, start_index);
  char expected[] = "Hello World";

  ck_assert_str_eq(expected, result);
  if (result) free(result);
}
END_TEST

START_TEST(test_insert_at_end) {
  const char *src = "Hello ";
  const char *str = "World";
  size_t start_index = 6;
  char *result = s21_insert(src, str, start_index);
  char expected[] = "Hello World";

  ck_assert_str_eq(expected, result);
  if (result) free(result);
}
END_TEST

START_TEST(test_insert_at_midle) {
  const char *src = "Hello World!";
  const char *str = "big ";
  size_t start_index = 6;
  char *result = s21_insert(src, str, start_index);
  char expected[] = "Hello big World!";

  ck_assert_str_eq(expected, result);
  if (result) free(result);
}
END_TEST

START_TEST(test_insert_src_consist_non_printable_syms) {
  const char *src = "Hello\n World!";
  const char *str = "big ";
  size_t start_index = 6;
  char *result = s21_insert(src, str, start_index);
  char expected[] = "Hello\nbig  World!";

  ck_assert_str_eq(expected, result);
  if (result) free(result);
}
END_TEST

START_TEST(test_insert_after_end_string) {
  const char *src = "Hello\0 World!";
  const char *str = "big ";
  size_t start_index = 6;
  char *result = s21_insert(src, str, start_index);

  ck_assert_ptr_eq(NULL, result);
  if (result) free(result);
}
END_TEST

START_TEST(test_insert_null_str) {
  const char *src = "Hello World!";
  size_t start_index = 6;
  char *result = s21_insert(src, NULL, start_index);

  ck_assert_ptr_eq(NULL, result);
  if (result) free(result);
}
END_TEST

START_TEST(test_insert_in_null_src) {
  const char *str = "Hello";
  size_t start_index = 0;
  char *result = s21_insert(NULL, str, start_index);

  ck_assert_ptr_eq(NULL, result);
  if (result) free(result);
}
END_TEST

START_TEST(test_insert_index_more_len_src) {
  const char *src = "Hello ";
  const char *str = "World";
  size_t start_index = 8;
  char *result = s21_insert(src, str, start_index);

  ck_assert_ptr_eq(NULL, result);
  if (result) free(result);
}
END_TEST

START_TEST(test_insert_empty_str) {
  const char *src = "Hello ";
  const char *str = "";
  size_t start_index = 3;
  char *result = s21_insert(src, str, start_index);
  char expected[] = "Hello ";

  ck_assert_str_eq(expected, result);
  if (result) free(result);
}
END_TEST

START_TEST(test_insert_min_len_str) {
  const char *src = "Hello";
  const char *str = "!";
  size_t start_index = 5;
  char *result = s21_insert(src, str, start_index);
  char expected[] = "Hello!";

  ck_assert_str_eq(expected, result);
  if (result) free(result);
}
END_TEST

START_TEST(test_insert_long_string) {
  char *src = malloc(10001);
  if (src) {
    memset(src, 'a', 10000);
    src[10000] = '\0';
    const char *str = "INSERTED";
    size_t start_index = 5000;
    char *result = s21_insert(src, str, start_index);

    ck_assert_ptr_nonnull(result);
    if (result) {
      ck_assert_mem_eq(result + start_index, str, strlen(str));

      char *inserted_position = strstr(result, str);
      ck_assert_ptr_nonnull(inserted_position);

      // Проверка индекса начала вхождения строки "INSERTED"
      size_t inserted_index = inserted_position - result;
      ck_assert_uint_eq(inserted_index, start_index);

      free(result);
    }
    free(src);
  }
}
END_TEST

TCase *insert_get_tests(void) {
  TCase *test_cases = tcase_create("test_cases");

  tcase_add_test(test_cases, test_insert_at_start);
  tcase_add_test(test_cases, test_insert_at_end);
  tcase_add_test(test_cases, test_insert_at_midle);
  tcase_add_test(test_cases, test_insert_src_consist_non_printable_syms);
  tcase_add_test(test_cases, test_insert_after_end_string);
  tcase_add_test(test_cases, test_insert_null_str);
  tcase_add_test(test_cases, test_insert_in_null_src);
  tcase_add_test(test_cases, test_insert_index_more_len_src);
  tcase_add_test(test_cases, test_insert_empty_str);
  tcase_add_test(test_cases, test_insert_min_len_str);
  tcase_add_test(test_cases, test_insert_long_string);

  return test_cases;
}

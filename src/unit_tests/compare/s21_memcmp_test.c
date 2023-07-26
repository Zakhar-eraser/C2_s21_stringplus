#include "common_test.h"

START_TEST(same_str) {
  char *str1 = "Compare two blocks of memory";
  char *str2 = "Compare two blocks of memory";
  size_t n = strlen(str1);
  ck_assert_int_eq(s21_memcmp(str1, str2, n), memcmp(str1, str2, n));
}
END_TEST

START_TEST(non_same_str) {
  char *str1 = "Compare two blocks of memory";
  char *str2 = "Compares the first num bytes";
  size_t n = strlen(str1);
  ck_assert_int_eq(!!s21_memcmp(str1, str2, n), !!memcmp(str1, str2, n));
}
END_TEST

START_TEST(first_char) {
  char *str1 = "123456789";
  char *str2 = "012345678";
  size_t n = strlen(str1);
  ck_assert_int_eq(s21_memcmp(str1, str2, n), memcmp(str1, str2, n));
}
END_TEST

START_TEST(end_char) {
  char *str1 = "012345678";
  char *str2 = "123456789";
  size_t n = strlen(str1);
  ck_assert_int_eq(s21_memcmp(str1, str2, n), memcmp(str1, str2, n));
}
END_TEST

START_TEST(empty_str) {
  char *str1 = "";
  char *str2 = "";
  size_t n = strlen(str1);
  ck_assert_int_eq(s21_memcmp(str1, str2, n), memcmp(str1, str2, n));
}
END_TEST

Suite *s21_memcmp_suite() {
  Suite *s = suite_create("s21_memcmp");
  TCase *tc_core = tcase_create("Core");

  tcase_add_test(tc_core, same_str);
  tcase_add_test(tc_core, non_same_str);
  tcase_add_test(tc_core, first_char);
  tcase_add_test(tc_core, end_char);
  tcase_add_test(tc_core, empty_str);
  suite_add_tcase(s, tc_core);

  return s;
}

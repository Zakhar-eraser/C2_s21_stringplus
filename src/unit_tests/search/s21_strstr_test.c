#include "common_test.h"

START_TEST(match_start) {
  const char str1[] = "Returns a pointer to the first occurrence...";
  const char str2[] = "Returns a ";
  char *res1 = s21_strstr(str1, str2);
  char *res2 = strstr(str1, str2);
  ck_assert_ptr_eq(res1, res2);
  // output: Returns a pointer to the first occurrence...
}
END_TEST

START_TEST(match_end) {
  const char str1[] = "Returns a pointer to the first occurrence...";
  const char str2[] = "occurrence";
  char *res1 = s21_strstr(str1, str2);
  char *res2 = strstr(str1, str2);
  ck_assert_ptr_eq(res1, res2);
  // output: occurrence...
}
END_TEST

START_TEST(str2_null) {
  const char str1[] = "Returns a pointer to the first occurrence...";
  const char str2[] = "";
  char *res1 = s21_strstr(str1, str2);
  char *res2 = strstr(str1, str2);
  ck_assert_ptr_eq(res1, res2);
  // output: Returns a pointer to the first occurrence...
}
END_TEST

START_TEST(no_match) {
  const char str1[] = "Returns a pointer to the first occurrence...";
  const char str2[] = " th ";
  char *res1 = s21_strstr(str1, str2);
  char *res2 = strstr(str1, str2);
  ck_assert_ptr_eq(res1, res2);
  // output: (null)
}
END_TEST

START_TEST(one_char) {
  const char str1[] = "Returns a pointer to the first occurrence...";
  const char str2[] = "o";
  char *res1 = s21_strstr(str1, str2);
  char *res2 = strstr(str1, str2);
  ck_assert_ptr_eq(res1, res2);
  // output: ointer to the first occurrence...
}
END_TEST

START_TEST(extra_char_str2) {
  const char str1[] = "Returns a pointer to the first occurrence...";
  const char str2[] = "Returns a pointer to the first occurrence...!";
  char *res1 = s21_strstr(str1, str2);
  char *res2 = strstr(str1, str2);
  ck_assert_ptr_eq(res1, res2);
  // output: (null)
}
END_TEST

Suite *s21_strstr_suite() {
  Suite *s = suite_create("s21_strstr");
  TCase *s21_strstr = tcase_create("s21_strstrs");

  tcase_add_test(s21_strstr, match_start);
  tcase_add_test(s21_strstr, match_end);
  tcase_add_test(s21_strstr, str2_null);
  tcase_add_test(s21_strstr, no_match);
  tcase_add_test(s21_strstr, one_char);
  tcase_add_test(s21_strstr, extra_char_str2);
  suite_add_tcase(s, s21_strstr);

  return s;
}

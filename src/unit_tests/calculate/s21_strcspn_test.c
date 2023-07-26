#include "common_test.h"

START_TEST(str2_in_the_end_str1) {
  const char *str1 = "0123456789";
  const char *str2 = "987";
  ck_assert_int_eq(s21_strcspn(str1, str2), strcspn(str1, str2));
}
END_TEST

START_TEST(str2_in_the_start_str1) {
  const char *str1 = "0123456789";
  const char *str2 = "0";
  ck_assert_int_eq(s21_strcspn(str1, str2), strcspn(str1, str2));
}
END_TEST

START_TEST(str2_in_the_middle_str1) {
  const char *str1 = "0123456789";
  const char *str2 = "456";
  ck_assert_int_eq(s21_strcspn(str1, str2), strcspn(str1, str2));
}
END_TEST

START_TEST(null_string2) {
  const char *str1 = "0123456789";
  const char *str2 = "";
  ck_assert_int_eq(s21_strcspn(str1, str2), strcspn(str1, str2));
}
END_TEST

START_TEST(null_string1) {
  const char *str1 = "";
  const char *str2 = "123";
  ck_assert_int_eq(s21_strcspn(str1, str2), strcspn(str1, str2));
}
END_TEST

Suite *s21_strcspn_suite() {
  Suite *s = suite_create("s21_strcspn");
  TCase *tc_core = tcase_create("Core");

  tcase_add_test(tc_core, str2_in_the_end_str1);
  tcase_add_test(tc_core, str2_in_the_start_str1);
  tcase_add_test(tc_core, str2_in_the_middle_str1);
  tcase_add_test(tc_core, null_string2);
  tcase_add_test(tc_core, null_string1);
  suite_add_tcase(s, tc_core);

  return s;
}

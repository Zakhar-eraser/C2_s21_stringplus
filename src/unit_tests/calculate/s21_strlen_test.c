#include "common_test.h"

START_TEST(null_string) {
  const char *nullString = "";
  ck_assert_int_eq(s21_strlen(nullString), strlen(nullString));
}
END_TEST

START_TEST(one_char_string) {
  const char *oneChString = ".";
  ck_assert_int_eq(s21_strlen(oneChString), strlen(oneChString));
}
END_TEST

START_TEST(regular_string) {
  const char *regString =
      "Computes the length of the string str up to but not including the "
      "terminating null character.";
  ck_assert_int_eq(s21_strlen(regString), strlen(regString));
}
END_TEST

START_TEST(string_whith_end) {
  const char *endString =
      "Computes the length of the string str up to\0 but not including the "
      "terminating null character.";
  ck_assert_int_eq(s21_strlen(endString), strlen(endString));
}
END_TEST

START_TEST(string_whith_cr) {
  char *crString =
      "Computes the length of the string str up to\n but not including the "
      "terminating null character.";
  ck_assert_int_eq(s21_strlen(crString), strlen(crString));
}
END_TEST

START_TEST(string_whith_tab) {
  char *tabString =
      "Computes the length of the string str up to\t but not including the "
      "terminating null character.";
  ck_assert_int_eq(s21_strlen(tabString), strlen(tabString));
}
END_TEST

Suite *s21_strlen_suite() {
  Suite *s = suite_create("s21_strlen");
  TCase *tc_core = tcase_create("Core");

  tcase_add_test(tc_core, null_string);
  tcase_add_test(tc_core, one_char_string);
  tcase_add_test(tc_core, regular_string);
  tcase_add_test(tc_core, string_whith_end);
  tcase_add_test(tc_core, string_whith_cr);
  tcase_add_test(tc_core, string_whith_tab);

  suite_add_tcase(s, tc_core);
  return s;
}

#include "common_test.h"

START_TEST(trim_space) {
  char src[] = " abCdfgdsabBCba  ";
  char charToTrim[] = " ";
  char *res1 = s21_trim(src, charToTrim);
  char res2[] = "abCdfgdsabBCba";
  ck_assert_str_eq(res1, res2);
}
END_TEST

START_TEST(trim_chars) {
  char src[] = "abCdfgdsabBCba";
  char charsToTrim[] = "abC";
  char *res1 = s21_trim(src, charsToTrim);
  char res2[] = "dfgdsabB";
  ck_assert_str_eq(res1, res2);
}
END_TEST

START_TEST(trim_char) {
  char src[] = "aaACdfgdsabAaa";
  char charToTrim[] = "a";
  char *res1 = s21_trim(src, charToTrim);
  char res2[] = "ACdfgdsabA";
  ck_assert_str_eq(res1, res2);
}
END_TEST

START_TEST(no_trim) {
  char src[] = "aaACdfgdsabAaa";
  char charToTrim[] = "b";
  char *res1 = s21_trim(src, charToTrim);
  char res2[] = "aaACdfgdsabAaa";
  ck_assert_str_eq(res1, res2);
}
END_TEST

START_TEST(end_in_midle) {
  char src[] = "aaACdfg\0dsabAaa";
  char charToTrim[] = "agf";
  char *res1 = s21_trim(src, charToTrim);
  char res2[] = "ACd";
  ck_assert_str_eq(res1, res2);
}
END_TEST

Suite *s21_trim_suite() {
  Suite *s = suite_create("s21_trim");
  TCase *tc_core = tcase_create("Core");

  tcase_add_test(tc_core, trim_space);
  tcase_add_test(tc_core, trim_chars);
  tcase_add_test(tc_core, trim_char);
  tcase_add_test(tc_core, no_trim);
  tcase_add_test(tc_core, end_in_midle);
  suite_add_tcase(s, tc_core);

  return s;
}

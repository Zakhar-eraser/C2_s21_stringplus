#include "common_test.h"

START_TEST(add_space) {
  char *src = "WelcomeJacob";
  char *res1 = s21_insert(src, " ", 7);
  char *res2 = "Welcome Jacob";
  ck_assert_str_eq(res1, res2);
  free(res1);
}
END_TEST

START_TEST(add_word) {
  char *src = "WelcomeJacob";
  char *res1 = s21_insert(src, " here, ", 7);
  char *res2 = "Welcome here, Jacob";
  ck_assert_str_eq(res1, res2);
  free(res1);
}
END_TEST

START_TEST(add_char) {
  char *src = "25/55";
  char *res1 = s21_insert(src, "=", 4);
  char *res2 = "25/5=5";
  ck_assert_str_eq(res1, res2);
  free(res1);
}
END_TEST

START_TEST(start_pos) {
  char *src = "ello school 21!";
  char *res1 = s21_insert(src, "H", 0);
  char *res2 = "Hello school 21!";
  ck_assert_str_eq(res1, res2);
  free(res1);
}
END_TEST

START_TEST(end_pos) {
  char *src = "Hello school";
  s21_size_t pos = s21_strlen(src);
  char *res1 = s21_insert(src, " 21!", pos);
  char *res2 = "Hello school 21!";
  ck_assert_str_eq(res1, res2);
  free(res1);
}
END_TEST

START_TEST(empty_src) {
  char *src = "";
  char *res1 = s21_insert(src, "Hello school 21!", 0);
  char *res2 = "Hello school 21!";
  ck_assert_str_eq(res1, res2);
  free(res1);
}
END_TEST

START_TEST(empty) {
  char *src = "";
  char *res1 = s21_insert(src, "", 0);
  char *res2 = "";
  ck_assert_str_eq(res1, res2);
  free(res1);
}
END_TEST

START_TEST(empty_str) {
  char *src = "Hello school 21!";
  char *res1 = s21_insert(src, "", 3);
  char *res2 = "Hello school 21!";
  ck_assert_str_eq(res1, res2);
  free(res1);
}
END_TEST

Suite *s21_insert_suite() {
  Suite *s = suite_create("s21_insert");
  TCase *tc_core = tcase_create("Core");

  tcase_add_test(tc_core, add_space);
  tcase_add_test(tc_core, add_word);
  tcase_add_test(tc_core, add_char);
  tcase_add_test(tc_core, start_pos);
  tcase_add_test(tc_core, end_pos);
  tcase_add_test(tc_core, empty_src);
  tcase_add_test(tc_core, empty);
  tcase_add_test(tc_core, empty_str);
  suite_add_tcase(s, tc_core);

  return s;
}

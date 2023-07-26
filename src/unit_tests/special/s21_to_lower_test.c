#include "common_test.h"

START_TEST(all_upper) {
  char *src = "ASDFGTREWQ";
  char *res1 = s21_to_lower(src);
  char *res2 = "asdfgtrewq";
  ck_assert_str_eq(res1, res2);
}
END_TEST

START_TEST(part_upper) {
  char *src = "zXcFDsa";
  char *res1 = s21_to_lower(src);
  char *res2 = "zxcfdsa";
  ck_assert_str_eq(res1, res2);
}
END_TEST

START_TEST(whith_num) {
  char *src = "Q1wer3DF1";
  char *res1 = s21_to_lower(src);
  char *res2 = "q1wer3df1";
  ck_assert_str_eq(res1, res2);
}
END_TEST

START_TEST(whith_space) {
  char *src = "Q1we r3DF1";
  char *res1 = s21_to_lower(src);
  char *res2 = "q1we r3df1";
  ck_assert_str_eq(res1, res2);
}
END_TEST

Suite *s21_to_lower_suite() {
  Suite *s = suite_create("s21_to_lower");
  TCase *tc_core = tcase_create("Core");

  tcase_add_test(tc_core, all_upper);
  tcase_add_test(tc_core, part_upper);
  tcase_add_test(tc_core, whith_num);
  tcase_add_test(tc_core, whith_space);
  suite_add_tcase(s, tc_core);

  return s;
}

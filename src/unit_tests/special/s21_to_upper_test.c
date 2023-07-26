
#include "common_test.h"

START_TEST(all_lower) {
  char *src = "asdfgtrewq";
  char *res1 = s21_to_upper(src);
  char *res2 = "ASDFGTREWQ";
  ck_assert_str_eq(res1, res2);
}
END_TEST

START_TEST(part_lower) {
  char *src = "zXcFDsa";
  char *res1 = s21_to_upper(src);
  char *res2 = "ZXCFDSA";
  ck_assert_str_eq(res1, res2);
}
END_TEST

START_TEST(whith_num) {
  char *src = "Q1wer3DF1";
  char *res1 = s21_to_upper(src);
  char *res2 = "Q1WER3DF1";
  ck_assert_str_eq(res1, res2);
}
END_TEST

START_TEST(whith_space) {
  char *src = "Q1we r3DF1";
  char *res1 = s21_to_upper(src);
  char *res2 = "Q1WE R3DF1";
  ck_assert_str_eq(res1, res2);
}
END_TEST

Suite *s21_to_upper_suite() {
  Suite *s = suite_create("s21_to_upper");
  TCase *tc_core = tcase_create("Core");

  tcase_add_test(tc_core, all_lower);
  tcase_add_test(tc_core, part_lower);
  tcase_add_test(tc_core, whith_num);
  tcase_add_test(tc_core, whith_space);
  suite_add_tcase(s, tc_core);

  return s;
}

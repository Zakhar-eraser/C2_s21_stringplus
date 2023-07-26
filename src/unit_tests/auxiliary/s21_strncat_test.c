#include "common_test.h"

START_TEST(test_strncat_1) {
  char res1[100] = "string?";
  char str1[15] = " String!";
  char res2[100] = "string?";
  char str2[15] = " String!";
  for (int i = 0; i < 10; i++) {
    ck_assert_str_eq(s21_strncat(res1, str1, i), strncat(res2, str2, i));
  }
}
END_TEST

TCase *case_strncat_create(void) {
  TCase *case_strncat = tcase_create("TEST STRNCAT");
  tcase_add_test(case_strncat, test_strncat_1);
  return case_strncat;
}

Suite *s21_strncat_suite() {
  Suite *s = suite_create("s21_strncat");
  suite_add_tcase(s, case_strncat_create());
  return s;
}
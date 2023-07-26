#include "common_test.h"

START_TEST(test_strerror_1) {
  char *res1;
  char *res2;
  for (int i = 0; i <= 107; i++) {
    res1 = s21_strerror(i);
    res2 = strerror(i);
    ck_assert_str_eq(res1, res2);
  }
}

TCase *case_strerror_create(void) {
  TCase *case_strerror = tcase_create("TEST STRERROR");
  tcase_add_test(case_strerror, test_strerror_1);
  return case_strerror;
}

Suite *s21_strerror_suite() {
  Suite *s = suite_create("s21_strerror");
  suite_add_tcase(s, case_strerror_create());
  return s;
}
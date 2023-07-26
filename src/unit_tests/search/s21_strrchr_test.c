#include "common_test.h"

START_TEST(test_strrchr_1) {
  const char str[] = "This is a string for test strrchr from Jarlygri";
  char *res1;
  char *res2;
  for (int i = 0; i <= 127; i++) {
    res1 = s21_strrchr(str, i);
    res2 = strrchr(str, i);
    ck_assert_ptr_eq(res1, res2);
  }
}
END_TEST

TCase *case_strrchr_create(void) {
  TCase *case_strrchr = tcase_create("TEST STRRCHR");
  tcase_add_test(case_strrchr, test_strrchr_1);
  return case_strrchr;
}

Suite *s21_strrchr_suite() {
  Suite *s = suite_create("s21_strrchr");
  suite_add_tcase(s, case_strrchr_create());
  return s;
}
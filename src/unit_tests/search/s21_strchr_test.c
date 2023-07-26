#include "common_test.h"

START_TEST(test_strchr_1) {
  const char src[] = "This is a Jarlygri's Test fffor the strchr";
  char *res1;
  char *res2;
  for (int c = 'a'; c <= 'z'; c++) {
    res1 = s21_strchr(src, c);
    res2 = strchr(src, c);
    ck_assert_ptr_eq(res1, res2);
  }
}
END_TEST

START_TEST(test_strchr_2) {
  const char src[] = "This is a Jarlygri's Test fffor the strchr";
  char *res1;
  char *res2;
  for (int c = 0; c <= 127; c++) {
    res1 = s21_strchr(src, c);
    res2 = strchr(src, c);
    ck_assert_ptr_eq(res1, res2);
  }
}
END_TEST

TCase *case_strchr_create(void) {
  TCase *case_strchr = tcase_create("STRCHR TEST");
  tcase_add_test(case_strchr, test_strchr_1);
  tcase_add_test(case_strchr, test_strchr_2);
  return case_strchr;
}

Suite *s21_strchr_suite() {
  Suite *s = suite_create("s21_strchr");
  suite_add_tcase(s, case_strchr_create());
  return s;
}
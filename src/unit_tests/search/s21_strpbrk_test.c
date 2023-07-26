#include "common_test.h"

START_TEST(test_strpbrk_1) {
  const char str1[] = "This is Jarlygri's tesT For   STRpbrk :)";
  const char str2[] = "raJ";
  char *res1 = strpbrk(str1, str2);
  char *res2 = s21_strpbrk(str1, str2);
  ck_assert_ptr_eq(res1, res2);
}

START_TEST(test_strpbrk_2) {
  const char str1[] = "This is Jarlygri's tesT For   STRpbrk :)";
  const char str2[] = "Test";
  char *res1 = strpbrk(str1, str2);
  char *res2 = s21_strpbrk(str1, str2);
  ck_assert_ptr_eq(res1, res2);
}

START_TEST(test_strpbrk_3) {
  const char str1[] = "This is Jarlygri's tesT For   STRpbrk :)";
  const char str2[] = "tesF";
  char *res1 = strpbrk(str1, str2);
  char *res2 = s21_strpbrk(str1, str2);
  ck_assert_ptr_eq(res1, res2);
}

START_TEST(test_strpbrk_4) {
  const char str1[] = "This is Jarlygri's tesT For   STRpbrk :)";
  const char str2[] = "est:)";
  char *res1 = strpbrk(str1, str2);
  char *res2 = s21_strpbrk(str1, str2);
  ck_assert_ptr_eq(res1, res2);
}

START_TEST(test_strpbrk_5) {
  const char str1[] = "This is Jarlygri's tesT For   STRpbrk :)";
  const char str2[] = "abc";
  char *res1 = strpbrk(str1, str2);
  char *res2 = s21_strpbrk(str1, str2);
  ck_assert_ptr_eq(res1, res2);
}

START_TEST(test_strpbrk_6) {
  const char str1[] = "This is Jarlygri's tesT For   STRpbrk :)";
  const char str2[] = ")001:";
  char *res1 = strpbrk(str1, str2);
  char *res2 = s21_strpbrk(str1, str2);
  ck_assert_ptr_eq(res1, res2);
}

START_TEST(test_strpbrk_7) {
  const char str1[] = "This is Jarlygri's tesT For   STRpbrk :)";
  const char str2[] = " is";
  char *res1 = strpbrk(str1, str2);
  char *res2 = s21_strpbrk(str1, str2);
  ck_assert_ptr_eq(res1, res2);
}

TCase *case_strpbrk_create(void) {
  TCase *case_strpbrk = tcase_create("STRPBRK TEST");
  tcase_add_test(case_strpbrk, test_strpbrk_1);
  tcase_add_test(case_strpbrk, test_strpbrk_2);
  tcase_add_test(case_strpbrk, test_strpbrk_3);
  tcase_add_test(case_strpbrk, test_strpbrk_4);
  tcase_add_test(case_strpbrk, test_strpbrk_5);
  tcase_add_test(case_strpbrk, test_strpbrk_6);
  tcase_add_test(case_strpbrk, test_strpbrk_7);
  return case_strpbrk;
}

Suite *s21_strpbrk_suite() {
  Suite *s = suite_create("s21_strpbrk");
  suite_add_tcase(s, case_strpbrk_create());
  return s;
}
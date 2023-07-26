#include <stdio.h>

#include "common_test.h"

static void common_test(const char *str, size_t pos, char c, size_t n);

static const char *some_string = "fafsadfMMMFMWEFAAErrl;[[]'/";

START_TEST(test_memchr_1) {
  const char *src = "this   iss a Jarlygri's testtt for memchr";
  char symbol;
  s21_size_t n = 10;
  void *res1;
  void *res2;
  for (size_t i = 0; i < strlen(src); i++) {
    symbol = src[i];
    res1 = s21_memchr(src, symbol, n);
    res2 = memchr(src, symbol, n);
    ck_assert_ptr_eq(res1, res2);
  }
}
END_TEST

START_TEST(test_memchr_2) {
  const char *src = "this   iss a Jarlygri's testtt for memchr";
  char symbol;
  s21_size_t n = -3;
  void *res1;
  void *res2;
  for (size_t i = 0; i < strlen(src); i++) {
    symbol = src[i];
    res1 = s21_memchr(src, symbol, n);
    res2 = memchr(src, symbol, n);
    ck_assert_ptr_eq(res1, res2);
  }
}
END_TEST

START_TEST(test_memchr_3) {
  const char *src = "this   iss a Jarlygri's testtt for memchr";
  char symbol;
  s21_size_t n = 100;
  void *res1;
  void *res2;
  for (size_t i = 0; i < strlen(src); i++) {
    symbol = src[i];
    res1 = s21_memchr(src, symbol, n);
    res2 = memchr(src, symbol, n);
    ck_assert_ptr_eq(res1, res2);
  }
}
END_TEST

START_TEST(no_match_terminator) {
  common_test(some_string, 0, '\0', strlen(some_string));
}
END_TEST

START_TEST(no_match_just_no) {
  common_test(some_string, 0, '1', strlen(some_string));
}
END_TEST

START_TEST(no_match_n_small) { common_test(some_string, 0, 'M', 7); }
END_TEST

START_TEST(no_match_offset) {
  common_test(some_string, 5, 'a', strlen(some_string));
}
END_TEST

START_TEST(no_match_end_0) {
  common_test(some_string, strlen(some_string), '\0', 10);
}
END_TEST

START_TEST(no_match_end_1) {
  common_test(some_string, strlen(some_string), '0', 1);
}
END_TEST

static TCase *case_memchr_default() {
  TCase *case_memchr = tcase_create("DEFAULT");
  tcase_add_test(case_memchr, test_memchr_1);
  tcase_add_test(case_memchr, test_memchr_2);
  tcase_add_test(case_memchr, test_memchr_3);
  return case_memchr;
}

static TCase *case_memchar_no_match() {
  TCase *tc = tcase_create("NO MATCH");
  tcase_add_test(tc, no_match_terminator);
  tcase_add_test(tc, no_match_just_no);
  tcase_add_test(tc, no_match_n_small);
  tcase_add_test(tc, no_match_offset);
  tcase_add_test(tc, no_match_end_0);
  tcase_add_test(tc, no_match_end_1);
  return tc;
}

Suite *s21_memchr_suite() {
  Suite *s = suite_create("s21_memchr");
  suite_add_tcase(s, case_memchr_default());
  suite_add_tcase(s, case_memchar_no_match());
  return s;
}

static void common_test(const char *str, size_t pos, char c, size_t n) {
  void *r1 = s21_memchr(str + pos, c, n);
  void *r2 = memchr(str + pos, c, n);
  ck_assert_ptr_eq(r1, r2);
}
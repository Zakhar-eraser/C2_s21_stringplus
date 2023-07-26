#include "common_test.h"
const char src_str[40] = "123456678910";
static char dst_str1[100];
static char dst_str2[100];

static void common_test(const char *src, size_t n);

START_TEST(all_char) {
  char *src = "strncy() copies at...";
  size_t n = strlen(src);
  char *dest1 = (char *)malloc((n + 1) * sizeof(char));
  dest1[0] = '\0';
  char *dest2 = (char *)malloc((n + 1) * sizeof(char));
  dest2[0] = '\0';
  s21_strncpy(dest1, src, n);
  strncpy(dest2, src, n);
  ck_assert_mem_eq(dest1, dest2, n * sizeof(char));
  free(dest1);
  free(dest2);
}
END_TEST

START_TEST(part_char) {
  char *src = "strncy() copies at...";
  size_t n = strlen(src);
  char *dest1 = (char *)malloc((n + 1) * sizeof(char));
  dest1[0] = '\0';
  char *dest2 = (char *)malloc((n + 1) * sizeof(char));
  dest2[0] = '\0';
  s21_strncpy(dest1, src, 10);
  strncpy(dest2, src, 10);
  ck_assert_mem_eq(dest1, dest2, 10 * sizeof(char));
  free(dest1);
  free(dest2);
}
END_TEST

START_TEST(ovf) { common_test(src_str, 40); }
END_TEST

START_TEST(ovf_term) { common_test(src_str, strlen(src_str)); }
END_TEST

START_TEST(ovf_preterm) { common_test(src_str, strlen(src_str) - 1); }
END_TEST

START_TEST(ovf_overlap) {
  memset(dst_str1, 'A', 99);
  memset(dst_str2, 'A', 99);
  s21_strncpy(dst_str1, src_str + 5, 50);
  strncpy(dst_str2, src_str + 5, 50);
  ck_assert_str_eq(dst_str1, dst_str2);
  ck_assert_mem_eq(dst_str1, dst_str2, 60 * sizeof(char));
}
END_TEST

static TCase *s21_strncpy_core() {
  TCase *tc_core = tcase_create("CORE");
  tcase_add_test(tc_core, all_char);
  tcase_add_test(tc_core, part_char);
  return tc_core;
}

static TCase *s21_strncpy_ovf() {
  TCase *tc = tcase_create("OVF");
  tcase_add_test(tc, ovf);
  tcase_add_test(tc, ovf_preterm);
  tcase_add_test(tc, ovf_term);
  tcase_add_test(tc, ovf_overlap);
  return tc;
}

Suite *s21_strncpy_suite() {
  Suite *s = suite_create("s21_strncpy");
  suite_add_tcase(s, s21_strncpy_core());
  suite_add_tcase(s, s21_strncpy_ovf());
  return s;
}

static void common_test(const char *src, size_t n) {
  s21_strncpy(dst_str1, src, n);
  strncpy(dst_str2, src, n);
  ck_assert_str_eq(dst_str1, dst_str2);
  ck_assert_mem_eq(dst_str1, dst_str2, n * sizeof(char));
}

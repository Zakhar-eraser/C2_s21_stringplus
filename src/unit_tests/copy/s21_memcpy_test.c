#include "common_test.h"

START_TEST(all_char) {
  char *src = "The memcpy() declares in the header file <string.h>.";
  size_t n = strlen(src);
  char *dest1 = (char *)malloc((n + 1) * sizeof(char));
  dest1[0] = '\0';
  char *dest2 = (char *)malloc((n + 1) * sizeof(char));
  dest2[0] = '\0';
  s21_memcpy(dest1, src, n);
  memcpy(dest2, src, n);
  ck_assert_mem_eq(dest1, dest2, n * sizeof(char));
  free(dest1);
  free(dest2);
}
END_TEST

START_TEST(part_char) {
  char *src = "The memcpy() declares in the header file <string.h>.";
  size_t n = 10;
  char *dest1 = (char *)malloc((n + 1) * sizeof(char));
  dest1[0] = '\0';
  char *dest2 = (char *)malloc((n + 1) * sizeof(char));
  dest2[0] = '\0';
  s21_memcpy(dest1, src, n);
  memcpy(dest2, src, n);
  ck_assert_mem_eq(dest1, dest2, n * sizeof(char));
  free(dest1);
  free(dest2);
}
END_TEST

START_TEST(zero_char) {
  char *src = "The memcpy() declares in the header file <string.h>.";
  size_t n = strlen(src);
  char *dest1 = (char *)malloc((n + 1) * sizeof(char));
  dest1[0] = '\0';
  char *dest2 = (char *)malloc((n + 1) * sizeof(char));
  dest2[0] = '\0';
  s21_memcpy(dest1, src, 0);
  memcpy(dest2, src, 0);
  ck_assert_mem_eq(dest1, dest2, sizeof(char));
  free(dest1);
  free(dest2);
}
END_TEST

Suite *s21_memcpy_suite() {
  Suite *s = suite_create("s21_memcpy");
  TCase *tc_core = tcase_create("Core");

  tcase_add_test(tc_core, all_char);
  tcase_add_test(tc_core, part_char);
  tcase_add_test(tc_core, zero_char);
  suite_add_tcase(s, tc_core);

  return s;
}

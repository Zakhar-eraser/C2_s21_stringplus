#include "common_test.h"

START_TEST(first_test) {
  size_t len = 8;
  char str1[] = "memset() copies the character c...";
  char str2[] = "memset() copies the character c...";
  s21_memset(str1, '_', len);
  memset(str2, '_', len);
  ck_assert_mem_eq(str1, str2, len);
}

START_TEST(second_test) {
  size_t len = 18;
  char *str1 = (char *)malloc((len + 5) * sizeof(char));
  char *str2 = (char *)malloc((len + 5) * sizeof(char));
  s21_memset(str1, 'M', len);
  memset(str2, 'M', len);
  ck_assert_mem_eq(str1, str2, len);
  free(str1);
  free(str2);
}

START_TEST(register_change) {
  char str1[] = "memset() copies the character c...";
  char str2[] = "memset() copies the character c...";
  size_t len = 1;
  s21_memset(str1, 'M', len);
  memset(str2, 'M', len);
  ck_assert_mem_eq(str1, str2, len);
}

START_TEST(change_to_digit) {
  char str1[] = "memset() copies the character c...";
  char str2[] = "memset() copies the character c...";
  size_t len = 10;
  s21_memset(str1, '7', len);
  memset(str2, '7', len);
  ck_assert_mem_eq(str1, str2, len);
}

Suite *s21_memset_suite() {
  Suite *s = suite_create("s21_memset");
  TCase *tc_core = tcase_create("Core");

  tcase_add_test(tc_core, first_test);
  tcase_add_test(tc_core, second_test);
  tcase_add_test(tc_core, register_change);
  tcase_add_test(tc_core, change_to_digit);
  suite_add_tcase(s, tc_core);

  return s;
}

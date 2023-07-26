#include <check.h>

Suite *s21_memchr_suite();
Suite *s21_memcmp_suite();
Suite *s21_memcpy_suite();
Suite *s21_memset_suite();
Suite *s21_strncat_suite();
Suite *s21_strchr_suite();
Suite *s21_strncmp_suite();
Suite *s21_strncpy_suite();
Suite *s21_strcspn_suite();
Suite *s21_strerror_suite();
Suite *s21_strlen_suite();
Suite *s21_strpbrk_suite();
Suite *s21_strrchr_suite();
Suite *s21_strstr_suite();
Suite *s21_strtok_suite();
Suite *s21_sprintf_suite();
Suite *s21_insert_suite();
Suite *s21_to_lower_suite();
Suite *s21_to_upper_suite();
Suite *s21_trim_suite();

int main() {
  int result = 0;
  SRunner *runner = srunner_create(suite_create("s21_decimal"));
#ifdef S21_NOFORK
  srunner_set_fork_status(runner, CK_NOFORK);
#endif
  srunner_add_suite(runner, s21_memchr_suite());
  srunner_add_suite(runner, s21_memcmp_suite());
  srunner_add_suite(runner, s21_memcpy_suite());
  srunner_add_suite(runner, s21_memset_suite());
  srunner_add_suite(runner, s21_strncat_suite());
  srunner_add_suite(runner, s21_strchr_suite());
  srunner_add_suite(runner, s21_strncmp_suite());
  srunner_add_suite(runner, s21_strncpy_suite());
  srunner_add_suite(runner, s21_strcspn_suite());
  srunner_add_suite(runner, s21_strerror_suite());
  srunner_add_suite(runner, s21_strlen_suite());
  srunner_add_suite(runner, s21_strpbrk_suite());
  srunner_add_suite(runner, s21_strrchr_suite());
  srunner_add_suite(runner, s21_strstr_suite());
  srunner_add_suite(runner, s21_strtok_suite());
  srunner_add_suite(runner, s21_sprintf_suite());
  srunner_add_suite(runner, s21_insert_suite());
  srunner_add_suite(runner, s21_to_lower_suite());
  srunner_add_suite(runner, s21_to_upper_suite());
  srunner_add_suite(runner, s21_trim_suite());

  srunner_run_all(runner, CK_NORMAL);

  result = srunner_ntests_failed(runner) > 0;
  srunner_free(runner);
  return result;
}

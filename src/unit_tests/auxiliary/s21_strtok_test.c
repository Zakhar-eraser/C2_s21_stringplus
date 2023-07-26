#include "common_test.h"

static void common_test(const char *src, const char *delim1,
                        const char *delim2);

static const char *test_str = "one/two////three(four)five{six}";
static const char *empty_str = "";
static const char *only_delims = "//{/}({}))(";
static char src1[50];
static char src2[50];

START_TEST(same_delims) { common_test(test_str, "/(){}", "/(){}"); }
END_TEST

START_TEST(appended_delims) { common_test(test_str, "/()", "/(){}"); }
END_TEST

START_TEST(diff_delims) { common_test(test_str, "/()", "{}"); }
END_TEST

START_TEST(delim1_empty) { common_test(test_str, "", "{}"); }
END_TEST

START_TEST(delim2_empty) { common_test(test_str, "/()", ""); }
END_TEST

START_TEST(empty_delims) { common_test(test_str, "", ""); }
END_TEST

START_TEST(repeating_delims) {
  common_test(test_str, "/{}{}(//)", "/{}{}(//)");
}
END_TEST

START_TEST(empty_src_str) { common_test(empty_str, "/", "/"); }
END_TEST

START_TEST(empty_all) { common_test(empty_str, "", ""); }
END_TEST

START_TEST(delimeters_str) { common_test(only_delims, "/{(})", "/{)("); }
END_TEST

static TCase *core_case() {
  TCase *tc = tcase_create("CORE");
  tcase_add_test(tc, same_delims);
  tcase_add_test(tc, appended_delims);
  tcase_add_test(tc, diff_delims);
  tcase_add_test(tc, delim1_empty);
  tcase_add_test(tc, delim2_empty);
  tcase_add_test(tc, empty_delims);
  tcase_add_test(tc, repeating_delims);
  return tc;
}

static TCase *empty_str_case() {
  TCase *tc = tcase_create("EMPTY");
  tcase_add_test(tc, empty_src_str);
  tcase_add_test(tc, empty_all);
  return tc;
}

static TCase *delimeters_str_case() {
  TCase *tc = tcase_create("DELIMETERS STRING");
  tcase_add_test(tc, delimeters_str);
  return tc;
}

Suite *s21_strtok_suite() {
  Suite *s = suite_create("s21_strtok");
  suite_add_tcase(s, core_case());
  suite_add_tcase(s, empty_str_case());
  suite_add_tcase(s, delimeters_str_case());
  return s;
}

static void common_test(const char *src, const char *delim1,
                        const char *delim2) {
  memset(src1, 0, 50);
  memset(src2, 0, 50);
  strcpy(src1, src);
  strcpy(src2, src);
  char *my_strtok = s21_strtok(src1, delim1);
  char *origin_strtok = strtok(src2, delim1);
  while (origin_strtok != S21_NULL) {
    ck_assert_str_eq(my_strtok, origin_strtok);
    my_strtok = s21_strtok(S21_NULL, delim2);
    origin_strtok = strtok(S21_NULL, delim2);
  }
}
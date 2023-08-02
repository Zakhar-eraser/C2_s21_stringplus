#include "common_test.h"

static char orig_res[1000];
static char s21_res[1000];

static void common_test(int orig_count, int s21_count);

START_TEST(no_format_0) {
  common_test(sprintf(orig_res, "Some String"),
              s21_sprintf(s21_res, "Some String"));
}
END_TEST

START_TEST(c_format_single) {
  common_test(sprintf(orig_res, "prefix%csuffix", '_'),
              s21_sprintf(s21_res, "prefix%csuffix", '_'));
}
END_TEST

START_TEST(c_format_width_right) {
  common_test(sprintf(orig_res, "prefix%5c", '|'),
              s21_sprintf(s21_res, "prefix%5c", '|'));
}
END_TEST

START_TEST(c_format_width_left) {
  common_test(sprintf(orig_res, "%-5csuffix", '|'),
              s21_sprintf(s21_res, "%-5csuffix", '|'));
}
END_TEST

START_TEST(c_format_width_from_input) {
  common_test(sprintf(orig_res, "%-*csuffix", 5, '|'),
              s21_sprintf(s21_res, "%-*csuffix", 5, '|'));
}
END_TEST

START_TEST(c_format_multiple) {
  common_test(
      sprintf(orig_res, "1%-5c 2%*c 2%1c3 %-10cf", 'a', 3, '3', 'b', 'c'),
      s21_sprintf(s21_res, "1%-5c 2%*c 2%1c3 %-10cf", 'a', 3, '3', 'b', 'c'));
}
END_TEST

START_TEST(d_format_single_0) {
  common_test(sprintf(orig_res, "prefix%dsuffix", 102344),
              s21_sprintf(s21_res, "prefix%dsuffix", 102344));
}
END_TEST

START_TEST(d_format_single_1) {
  common_test(sprintf(orig_res, "prefix%dsuffix", 0),
              s21_sprintf(s21_res, "prefix%dsuffix", 0));
}
END_TEST

START_TEST(d_format_short) {
  common_test(sprintf(orig_res, "%hd", (short)65535),
              s21_sprintf(s21_res, "%hd", (short)65535));
}
END_TEST

START_TEST(d_format_char) {
  common_test(sprintf(orig_res, "%hhd", (char)255),
              s21_sprintf(s21_res, "%hhd", (char)255));
}
END_TEST

START_TEST(d_format_long) {
  common_test(sprintf(orig_res, "%ld", 9223372036854775807L),
              s21_sprintf(s21_res, "%ld", 9223372036854775807L));
}
END_TEST

START_TEST(d_format_long_long) {
  common_test(sprintf(orig_res, "%lld", 9223372036854775807LL),
              s21_sprintf(s21_res, "%lld", 9223372036854775807LL));
}
END_TEST

START_TEST(d_format_width_right_0) {
  common_test(sprintf(orig_res, "prefix%3d", -255),
              s21_sprintf(s21_res, "prefix%3d", -255));
}
END_TEST

START_TEST(d_format_zero_width) {
  common_test(sprintf(orig_res, "abc%05ddfc", 34),
              s21_sprintf(s21_res, "abc%05ddfc", 34));
}
END_TEST

START_TEST(d_format_zero_width_from_input) {
  common_test(sprintf(orig_res, "abc%0*ddfc", 5, 34),
              s21_sprintf(s21_res, "abc%0*ddfc", 5, 34));
}
END_TEST

START_TEST(d_format_offset_zero_width_0) {
  common_test(sprintf(orig_res, "abc%05ddfc", -34),
              s21_sprintf(s21_res, "abc%05ddfc", -34));
}
END_TEST

START_TEST(d_format_offset_zero_width_1) {
  common_test(sprintf(orig_res, "abc%+05ddfc", 34),
              s21_sprintf(s21_res, "abc%+05ddfc", 34));
}
END_TEST

START_TEST(d_format_width_right_1) {
  common_test(sprintf(orig_res, "prefix%5d", -255),
              s21_sprintf(s21_res, "prefix%5d", -255));
}
END_TEST

START_TEST(d_format_width_left_0) {
  common_test(sprintf(orig_res, "%-3dsuffix", -255),
              s21_sprintf(s21_res, "%-3dsuffix", -255));
}
END_TEST

START_TEST(d_format_width_left_1) {
  common_test(sprintf(orig_res, "%-5dsuffix", -255),
              s21_sprintf(s21_res, "%-5dsuffix", -255));
}
END_TEST

START_TEST(d_format_sign_space_0) {
  common_test(sprintf(orig_res, "% d", 255), s21_sprintf(s21_res, "% d", 255));
}
END_TEST

START_TEST(d_format_sign_space_1) {
  common_test(sprintf(orig_res, "% d", -255),
              s21_sprintf(s21_res, "% d", -255));
}
END_TEST

START_TEST(d_format_sign_plus_0) {
  common_test(sprintf(orig_res, "%+d", 255), s21_sprintf(s21_res, "%+d", 255));
}
END_TEST

START_TEST(d_format_sign_plus_1) {
  common_test(sprintf(orig_res, "%+d", 255), s21_sprintf(s21_res, "%+d", 255));
}
END_TEST

START_TEST(d_format_precision_0) {
  common_test(sprintf(orig_res, "%7.5d", -255),
              s21_sprintf(s21_res, "%7.5d", -255));
}
END_TEST

START_TEST(d_format_precision_from_input) {
  common_test(sprintf(orig_res, "%7.*d", 5, -255),
              s21_sprintf(s21_res, "%7.*d", 5, -255));
}
END_TEST

START_TEST(d_format_width_precision_from_input) {
  common_test(sprintf(orig_res, "%*.*d", 7, 5, -255),
              s21_sprintf(s21_res, "%*.*d", 7, 5, -255));
}
END_TEST

START_TEST(d_format_precision_1) {
  common_test(sprintf(orig_res, "%2.0d", -0),
              s21_sprintf(s21_res, "%2.0d", -0));
}
END_TEST

START_TEST(d_format_multiple) {
  common_test(
      sprintf(orig_res, "1%2.0dbn%+-7hhdrt% -7hd", -0, (char)127, (short)1023),
      s21_sprintf(s21_res, "1%2.0dbn%+-7hhdrt% -7hd", -0, (char)127,
                  (short)1023));
}
END_TEST

START_TEST(u_format_single_0) {
  common_test(sprintf(orig_res, "prefix%usuffix", 102344),
              s21_sprintf(s21_res, "prefix%usuffix", 102344));
}
END_TEST

START_TEST(u_format_single_1) {
  common_test(sprintf(orig_res, "prefix%usuffix", 0),
              s21_sprintf(s21_res, "prefix%usuffix", 0));
}
END_TEST

START_TEST(u_format_short) {
  common_test(sprintf(orig_res, "%hu", (short)65534),
              s21_sprintf(s21_res, "%hu", (short)65534));
}
END_TEST

START_TEST(u_format_char) {
  common_test(sprintf(orig_res, "%hhu", (char)255),
              s21_sprintf(s21_res, "%hhu", (char)255));
}
END_TEST

START_TEST(u_format_long) {
  common_test(sprintf(orig_res, "%lu", 18446744073709551615UL),
              s21_sprintf(s21_res, "%lu", 18446744073709551615UL));
}
END_TEST

START_TEST(u_format_long_long) {
  common_test(sprintf(orig_res, "%llu", 18446744073709551615ULL),
              s21_sprintf(s21_res, "%llu", 18446744073709551615ULL));
}
END_TEST

START_TEST(u_format_width_right_0) {
  common_test(sprintf(orig_res, "prefix%3u", 255),
              s21_sprintf(s21_res, "prefix%3u", 255));
}
END_TEST

START_TEST(u_format_width_right_1) {
  common_test(sprintf(orig_res, "prefix%5u", 255),
              s21_sprintf(s21_res, "prefix%5u", 255));
}
END_TEST

START_TEST(u_format_width_left_0) {
  common_test(sprintf(orig_res, "%-3usuffix", 255),
              s21_sprintf(s21_res, "%-3usuffix", 255));
}
END_TEST

START_TEST(u_format_width_left_1) {
  common_test(sprintf(orig_res, "%-5usuffix", 255),
              s21_sprintf(s21_res, "%-5usuffix", 255));
}
END_TEST

START_TEST(u_format_zero_width_from_input) {
  common_test(sprintf(orig_res, "%0*usuffix", 5, 255),
              s21_sprintf(s21_res, "%0*usuffix", 5, 255));
}
END_TEST

START_TEST(u_format_precision_0) {
  common_test(sprintf(orig_res, "%7.5u", 255),
              s21_sprintf(s21_res, "%7.5u", 255));
}
END_TEST

START_TEST(u_format_precision_1) {
  common_test(sprintf(orig_res, "%2.0u", 0), s21_sprintf(s21_res, "%2.0u", 0));
}
END_TEST

START_TEST(u_format_precision_from_input) {
  common_test(sprintf(orig_res, "%7.*u", 5, 255),
              s21_sprintf(s21_res, "%7.*u", 5, 255));
}
END_TEST

START_TEST(u_format_width_precision_from_input) {
  common_test(sprintf(orig_res, "%*.*u", 7, 5, 255),
              s21_sprintf(s21_res, "%*.*u", 7, 5, 255));
}
END_TEST

START_TEST(u_format_multiple) {
  common_test(
      sprintf(orig_res, "1%2.0ubn%-7hhurt%-7hu", 0, (char)127, (short)1023),
      s21_sprintf(s21_res, "1%2.0ubn%-7hhurt%-7hu", 0, (char)127, (short)1023));
}
END_TEST

// FLOAT

START_TEST(f_format_single_0) {
  common_test(sprintf(orig_res, "prefix%fsuffix", 102344.764743645),
              s21_sprintf(s21_res, "prefix%fsuffix", 102344.764743645));
}
END_TEST

START_TEST(f_format_single_1) {
  common_test(sprintf(orig_res, "prefix%fsuffix", 0.0),
              s21_sprintf(s21_res, "prefix%fsuffix", 0.0));
}
END_TEST

START_TEST(f_format_long) {
  common_test(sprintf(orig_res, "prefix%fsuffix", 102344.764743645123),
              s21_sprintf(s21_res, "prefix%fsuffix", 102344.764743645123));
}
END_TEST

START_TEST(f_format_width_right_0) {
  common_test(sprintf(orig_res, "prefix%3f", -3.2),
              s21_sprintf(s21_res, "prefix%3f", -3.2));
}
END_TEST

START_TEST(f_format_width_right_1) {
  common_test(sprintf(orig_res, "prefix%5f", -3.2),
              s21_sprintf(s21_res, "prefix%5f", -3.2));
}
END_TEST

START_TEST(f_format_width_left_0) {
  common_test(sprintf(orig_res, "%-3fsuffix", -3.2),
              s21_sprintf(s21_res, "%-3fsuffix", -3.2));
}
END_TEST

START_TEST(f_format_width_left_1) {
  common_test(sprintf(orig_res, "%-5fsuffix", -3.2),
              s21_sprintf(s21_res, "%-5fsuffix", -3.2));
}
END_TEST

START_TEST(f_format_zero_width) {
  common_test(sprintf(orig_res, "abc%05fdfc", 2.3),
              s21_sprintf(s21_res, "abc%05fdfc", 2.3));
}
END_TEST

START_TEST(f_format_zero_width_from_input) {
  common_test(sprintf(orig_res, "abc%0*fdfc", 5, 2.3),
              s21_sprintf(s21_res, "abc%0*fdfc", 5, 2.3));
}
END_TEST

START_TEST(f_format_zero_width_offset_0) {
  common_test(sprintf(orig_res, "abc%05fdfc", -2.3),
              s21_sprintf(s21_res, "abc%05fdfc", -2.3));
}
END_TEST

START_TEST(f_format_zero_width_offset_1) {
  common_test(sprintf(orig_res, "abc%0+7fdfc", 2.3),
              s21_sprintf(s21_res, "abc%0+7fdfc", 2.3));
}
END_TEST

START_TEST(f_format_sign_space_0) {
  common_test(sprintf(orig_res, "% f", 3.2), s21_sprintf(s21_res, "% f", 3.2));
}
END_TEST

START_TEST(f_format_sign_space_1) {
  common_test(sprintf(orig_res, "% f", -3.2),
              s21_sprintf(s21_res, "% f", -3.2));
}
END_TEST

START_TEST(f_format_sign_plus_0) {
  common_test(sprintf(orig_res, "%+f", 3.2), s21_sprintf(s21_res, "%+f", 3.2));
}
END_TEST

START_TEST(f_format_sign_plus_1) {
  common_test(sprintf(orig_res, "%+f", -3.2),
              s21_sprintf(s21_res, "%+f", -3.2));
}
END_TEST

START_TEST(f_format_precision_0) {
  common_test(sprintf(orig_res, "%7.4f", -2.55345),
              s21_sprintf(s21_res, "%7.4f", -2.55345));
}
END_TEST

START_TEST(f_format_precision_1) {
  common_test(sprintf(orig_res, "%7.4f", -2.553451),
              s21_sprintf(s21_res, "%7.4f", -2.553451));
}
END_TEST

START_TEST(f_format_precision_from_input) {
  common_test(sprintf(orig_res, "%7.*f", 4, -2.55345),
              s21_sprintf(s21_res, "%7.*f", 4, -2.55345));
}
END_TEST

START_TEST(f_format_width_precision_from_input) {
  common_test(sprintf(orig_res, "%*.*f", 7, 4, -2.55345),
              s21_sprintf(s21_res, "%*.*f", 7, 4, -2.55345));
}
END_TEST

START_TEST(f_format_precision_2) {
  common_test(sprintf(orig_res, "%7.4f", -2.55355),
              s21_sprintf(s21_res, "%7.4f", -2.55355));
}
END_TEST

START_TEST(f_format_nan_0) {
  common_test(sprintf(orig_res, "%7f", NAN), s21_sprintf(s21_res, "%7f", NAN));
}
END_TEST

START_TEST(f_format_nan_3) {
  common_test(sprintf(orig_res, "% 7f", NAN),
              s21_sprintf(s21_res, "% 7f", NAN));
}
END_TEST

START_TEST(f_format_inf_0) {
  common_test(sprintf(orig_res, "%7f", INFINITY),
              s21_sprintf(s21_res, "%7f", INFINITY));
}
END_TEST

START_TEST(f_format_inf_1) {
  common_test(sprintf(orig_res, "%+7f", INFINITY),
              s21_sprintf(s21_res, "%+7f", INFINITY));
}
END_TEST

START_TEST(f_format_inf_2) {
  common_test(sprintf(orig_res, "% 7f", INFINITY),
              s21_sprintf(s21_res, "% 7f", INFINITY));
}
END_TEST

START_TEST(f_format_inf_3) {
  common_test(sprintf(orig_res, "% 7f", -INFINITY),
              s21_sprintf(s21_res, "% 7f", -INFINITY));
}
END_TEST

START_TEST(f_format_multiple) {
  common_test(sprintf(orig_res, "123% -17Lf 456%+-12.1f %9.1f, %*f",
                      124532562623543532.L, 4325.46, NAN, 2, -INFINITY),
              s21_sprintf(s21_res, "123% -17Lf 456%+-12.1f %9.1f, %*f",
                          124532562623543532.L, 4325.46, NAN, 2, -INFINITY));
}
END_TEST

START_TEST(s_format_0) {
  common_test(sprintf(orig_res, "prefix%ssuffix", "_fix_"),
              s21_sprintf(s21_res, "prefix%ssuffix", "_fix_"));
}
END_TEST

START_TEST(s_format_1) {
  common_test(sprintf(orig_res, "prefix%20s", "_fix_"),
              s21_sprintf(s21_res, "prefix%20s", "_fix_"));
}
END_TEST

START_TEST(s_format_2) {
  common_test(sprintf(orig_res, "%-20ssuffix", "_fix_"),
              s21_sprintf(s21_res, "%-20ssuffix", "_fix_"));
}
END_TEST

START_TEST(e_format) {
  const char* format = "%e";
  common_test(sprintf(orig_res, format, 56000004.2),
              s21_sprintf(s21_res, format, 56000004.2));
}
END_TEST

START_TEST(e_format_zero) {
  const char* format = "%e";
  common_test(sprintf(orig_res, format, 0),
              s21_sprintf(s21_res, format, 0));
}
END_TEST

START_TEST(common) {
  common_test(sprintf(orig_res, "%-20ssuffix%-5hhu - % .10f, %4.0d", "_fix_",
                      (unsigned char)255, 12.3453235654956, 0),
              s21_sprintf(s21_res, "%-20ssuffix%-5hhu - % .10f, %4.0d", "_fix_",
                          (unsigned char)255, 12.3453235654956, 0));
}
END_TEST

Suite *s21_sprintf_suite() {
  Suite *s = suite_create("s21_sprintf");

  TCase *tc_no = tcase_create("NO FORMAT");
  tcase_add_test(tc_no, no_format_0);
  suite_add_tcase(s, tc_no);

  TCase *tc_c = tcase_create("C");
  tcase_add_test(tc_c, c_format_single);
  tcase_add_test(tc_c, c_format_width_right);
  tcase_add_test(tc_c, c_format_width_left);
  tcase_add_test(tc_c, c_format_width_from_input);
  tcase_add_test(tc_c, c_format_multiple);
  suite_add_tcase(s, tc_c);

  TCase *tc_d = tcase_create("D");
  tcase_add_test(tc_d, d_format_single_0);
  tcase_add_test(tc_d, d_format_single_1);
  tcase_add_test(tc_d, d_format_short);
  tcase_add_test(tc_d, d_format_char);
  tcase_add_test(tc_d, d_format_long);
  tcase_add_test(tc_d, d_format_long_long);
  tcase_add_test(tc_d, d_format_width_left_0);
  tcase_add_test(tc_d, d_format_width_left_1);
  tcase_add_test(tc_d, d_format_width_right_0);
  tcase_add_test(tc_d, d_format_width_right_1);
  tcase_add_test(tc_d, d_format_zero_width);
  tcase_add_test(tc_d, d_format_zero_width_from_input);
  tcase_add_test(tc_d, d_format_offset_zero_width_0);
  tcase_add_test(tc_d, d_format_offset_zero_width_1);
  tcase_add_test(tc_d, d_format_sign_space_0);
  tcase_add_test(tc_d, d_format_sign_space_1);
  tcase_add_test(tc_d, d_format_sign_plus_0);
  tcase_add_test(tc_d, d_format_sign_plus_1);
  tcase_add_test(tc_d, d_format_precision_0);
  tcase_add_test(tc_d, d_format_precision_1);
  tcase_add_test(tc_d, d_format_precision_from_input);
  tcase_add_test(tc_d, d_format_width_precision_from_input);
  tcase_add_test(tc_d, d_format_multiple);
  suite_add_tcase(s, tc_d);

  TCase *tc_u = tcase_create("U");
  tcase_add_test(tc_u, u_format_single_0);
  tcase_add_test(tc_u, u_format_single_1);
  tcase_add_test(tc_u, u_format_short);
  tcase_add_test(tc_u, u_format_char);
  tcase_add_test(tc_u, u_format_long);
  tcase_add_test(tc_u, u_format_long_long);
  tcase_add_test(tc_u, u_format_width_left_0);
  tcase_add_test(tc_u, u_format_width_left_1);
  tcase_add_test(tc_u, u_format_width_right_0);
  tcase_add_test(tc_u, u_format_width_right_1);
  tcase_add_test(tc_u, u_format_zero_width_from_input);
  tcase_add_test(tc_u, u_format_precision_0);
  tcase_add_test(tc_u, u_format_precision_1);
  tcase_add_test(tc_u, u_format_precision_from_input);
  tcase_add_test(tc_u, u_format_width_precision_from_input);
  tcase_add_test(tc_u, u_format_multiple);
  suite_add_tcase(s, tc_u);

  TCase *tc_f = tcase_create("F");
  tcase_add_test(tc_f, f_format_single_0);
  tcase_add_test(tc_f, f_format_single_1);
  tcase_add_test(tc_f, f_format_long);
  tcase_add_test(tc_f, f_format_width_right_0);
  tcase_add_test(tc_f, f_format_width_right_1);
  tcase_add_test(tc_f, f_format_width_left_0);
  tcase_add_test(tc_f, f_format_width_left_1);
  tcase_add_test(tc_f, f_format_zero_width);
  tcase_add_test(tc_f, f_format_zero_width_from_input);
  tcase_add_test(tc_f, f_format_zero_width_offset_0);
  tcase_add_test(tc_f, f_format_zero_width_offset_1);
  tcase_add_test(tc_f, f_format_sign_space_0);
  tcase_add_test(tc_f, f_format_sign_space_1);
  tcase_add_test(tc_f, f_format_sign_plus_0);
  tcase_add_test(tc_f, f_format_sign_plus_1);
  tcase_add_test(tc_f, f_format_precision_0);
  tcase_add_test(tc_f, f_format_precision_1);
  tcase_add_test(tc_f, f_format_precision_2);
  tcase_add_test(tc_f, f_format_precision_from_input);
  tcase_add_test(tc_f, f_format_width_precision_from_input);
  tcase_add_test(tc_f, f_format_nan_0);
  tcase_add_test(tc_f, f_format_nan_3);
  tcase_add_test(tc_f, f_format_inf_0);
  tcase_add_test(tc_f, f_format_inf_1);
  tcase_add_test(tc_f, f_format_inf_2);
  tcase_add_test(tc_f, f_format_inf_3);
  tcase_add_test(tc_f, f_format_multiple);
  suite_add_tcase(s, tc_f);

  TCase *tc_s = tcase_create("S");
  tcase_add_test(tc_s, s_format_0);
  tcase_add_test(tc_s, s_format_1);
  tcase_add_test(tc_s, s_format_2);
  suite_add_tcase(s, tc_s);

  TCase *tc_e = tcase_create("E");
  tcase_add_test(tc_e, e_format);
  tcase_add_test(tc_e, e_format_zero);
  suite_add_tcase(s, tc_e);

  TCase *tc_common = tcase_create("COMMON");
  tcase_add_test(tc_common, common);
  suite_add_tcase(s, tc_common);

  return s;
}

static void common_test(int orig_count, int s21_count) {
  ck_assert(orig_count == s21_count);
  ck_assert_str_eq(orig_res, s21_res);
}

#include "common.h"

const char *s21_read_int(const char *str, long double *result) {
  const char *adm_chars = "0123456789";
  *result = 0;
  for (; s21_strchr(adm_chars, *str); str++) {
    *result *= 10;
    *result += *str - '0';
  }
  return str;
}

int char_in_set(char a, const char *set) {
  int res = 0;
  for (int i = 0; set[i] && !res; i++) {
    if (set[i] == a) res = 1;
  }
  return res;
}

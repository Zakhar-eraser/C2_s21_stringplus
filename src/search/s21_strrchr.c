#include "common.h"

char *s21_strrchr(const char *str, int c) {
  char *res = S21_NULL;
  if (str != S21_NULL) {
    int len = s21_strlen(str);
    while (len && *(str + len) != c) {
      len--;
    }
    if (*(str + len) == c) res = (char *)(str + len);
  }
  return res;
}
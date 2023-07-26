#include "common.h"

void *s21_memchr(const void *str, int c, s21_size_t n) {
  void *res = S21_NULL;
  int i = 0;
  if (str != S21_NULL) {
    while (--n && *(char *)(str + i) != c && *(char *)(str + i) != '\0') {
      i++;
    }
    if (*(char *)(str + i) == c) res = (void *)(str + i);
  }
  return res;
}
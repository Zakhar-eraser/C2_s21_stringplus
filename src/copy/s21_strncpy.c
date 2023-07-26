#include "common.h"

char *s21_strncpy(char *dest, const char *src, s21_size_t n) {
  char *res = dest;
  while (n--) {
    *dest++ = *src;
    if (*src) src++;
  }
  return res;
}

// http://all-ht.ru/inf/prog/c/func/strncpy.html

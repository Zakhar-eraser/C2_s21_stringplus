#include "common.h"

void *s21_memset(void *str, int c, s21_size_t n) {
  char *dest = (char *)str;
  while (n--) {
    *(dest++) = c;
  }
  return str;
}

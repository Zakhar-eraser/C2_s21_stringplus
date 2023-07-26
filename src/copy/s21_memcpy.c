#include "common.h"

void *s21_memcpy(void *dest, const void *src, s21_size_t n) {
  char *goal = (char *)dest;
  const char *source = (const char *)src;
  while (n--) {
    *(goal++) = *(source++);
  }
  return dest;
}

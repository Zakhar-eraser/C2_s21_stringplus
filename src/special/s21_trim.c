#include <stdlib.h>

#include "common.h"

void *s21_trim(const char *src, const char *trim_chars) {
  char *res = S21_NULL;
  if (src && trim_chars) {
    s21_size_t start = 0;
    s21_size_t end = s21_strlen(src) - 1;
    // printf("start = %lld\nend = %lld\n", start, end);
    while (char_in_set(*(src + start), trim_chars)) start++;
    while (char_in_set(*(src + end), trim_chars)) end--;
    res = (char *)calloc(end - start + 1, sizeof(char));
    // printf("start = %lld\nend = %lld\n", start, end);
    if (res) {
      int k = 0;
      for (s21_size_t i = start; i <= end; i++) {
        res[k++] = src[i];
      }
      res[k] = '\0';
    }
  }
  return res;
}

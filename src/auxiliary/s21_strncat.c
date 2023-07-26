#include "common.h"

char *s21_strncat(char *dest, const char *src, s21_size_t n) {
  int len = s21_strlen(dest);
  int i = 0;
  while (n--) {
    *(dest + len) = *(src + i);
    len++;
    i++;
  }
  *(dest + len) = '\0';
  return dest;
}

// char *s21_strncat(char *dest, const char *src, s21_size_t n) {
//     s21_size_t i, j;
//     for (i = 0; dest[i] != '\0'; i++) {
//     }
//     for (j = 0; j < n; j++) {
//         dest[i+j] = src[j];
//     }
//     dest[i+j] = '\0';
//     return dest;
// }
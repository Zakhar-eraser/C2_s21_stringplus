#include "common.h"

char *s21_strchr(const char *str, int c) {
  char *res = S21_NULL;
  int i = 0;
  if (str != S21_NULL) {
    while (*(str + i) != c && *(str + i) != '\0') {
      i++;
    }
    if (*(str + i) == c) {
      res = (char *)(str + i);
    }
  }
  return res;
}
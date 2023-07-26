#include "common.h"

char *s21_strpbrk(const char *str1, const char *str2) {
  char *res = S21_NULL;
  int i = 0;
  int j;
  while (res == S21_NULL && *(str1 + i)) {
    j = 0;
    while (*(str2 + j) != '\0' && *(str2 + j) != *(str1 + i)) {
      j++;
    }
    if (*(str1 + i) == *(str2 + j)) res = (char *)(str1 + i);
    i++;
  }
  return res;
}
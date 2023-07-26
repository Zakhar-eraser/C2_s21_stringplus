#include "common.h"
int s21_memcmp(const void *str1, const void *str2, s21_size_t n) {
  unsigned char *cmp1 = (unsigned char *)str1;
  unsigned char *cmp2 = (unsigned char *)str2;
  int flag = 0;
  for (s21_size_t i = 0; i < n; i++) {
    if (cmp1[i] != cmp2[i]) {
      if (cmp1[i] < cmp2[i])
        flag = -1;
      else
        flag = 1;
      break;
    }
  }
  return flag;
}

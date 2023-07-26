#include "common.h"

int s21_strncmp(const char *str1, const char *str2, s21_size_t n) {
  int flag = 0;
  // if (str1 && str2 && n > 0) {
  for (s21_size_t i = 0; i < n; i++) {
    if (str1[i] != str2[i]) {
      flag = str1[i] - str2[i];
      break;
    }
  }
  //}
  return flag;
}

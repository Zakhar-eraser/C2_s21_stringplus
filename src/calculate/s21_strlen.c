#include "common.h"

s21_size_t s21_strlen(const char *str) {
  s21_size_t len = 0;
  if (str == S21_NULL) {
    len = -1;
  } else {
    for (; *(str + len); len++) {
    }
  }
  return len;
}

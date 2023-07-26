#include <stdlib.h>

#include "common.h"

void *s21_to_upper(const char *str) {
  s21_size_t len = s21_strlen(str);
  char *new_str = S21_NULL;
  new_str = (char *)malloc((len + 1) * sizeof(char));
  for (s21_size_t i = 0; i <= len; i++) {
    if (str[i] >= 'a' && str[i] <= 'z')
      new_str[i] = str[i] - 32;
    else
      new_str[i] = str[i];
  }
  return new_str;
}

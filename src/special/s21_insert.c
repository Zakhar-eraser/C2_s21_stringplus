#include "common.h"

void *s21_insert(const char *src, const char *str, s21_size_t start_index) {
  char *new_str = S21_NULL;
  if (src && str && start_index <= s21_strlen(src)) {
    s21_size_t src_len = s21_strlen(src);
    s21_size_t str_len = s21_strlen(str);
    new_str = (char *)malloc((src_len + str_len + 1) * sizeof(char));
    if (new_str) {
      s21_size_t n = 0;
      for (s21_size_t i = 0; i < start_index; i++) {
        new_str[n++] = src[i];
      }
      for (s21_size_t i = 0; i < str_len; i++) {
        new_str[n++] = str[i];
      }
      for (s21_size_t i = start_index; i <= src_len; i++) {
        new_str[n++] = src[i];
      }
    }
  }
  return new_str;
}

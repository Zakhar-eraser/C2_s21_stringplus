#include "common.h"

static char *current = S21_NULL;

char *s21_strtok(char *src, const char *delim) {
  char *res = S21_NULL;
  if (src != S21_NULL && *src) {
    res = src;
    if ((current = s21_strpbrk(src, delim))) *(current++) = '\0';
  } else if (src == S21_NULL && current) {
    res = current;
    for (; s21_strpbrk(res, delim) == res; res++)
      ;
    if ((current = s21_strpbrk(res, delim))) {
      *(current++) = '\0';
    } else if (!*res) {
      res = S21_NULL;
    }
  }
  return res;
}

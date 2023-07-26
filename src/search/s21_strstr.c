#include "common.h"

char *s21_strstr(const char *haystack, const char *needle) {
  char *res = S21_NULL;
  int len1 = s21_strlen(haystack);
  int len2 = s21_strlen(needle);
  if (len2 == 0) {
    res = (char *)haystack;
  } else if (len1 >= len2) {
    int i = 0;
    while (res == S21_NULL && (len1 - i) >= len2) {
      if (*(haystack + i) == *needle) {
        int j = 0;
        while (*(needle + j) != '\0' && *(haystack + i + j) == *(needle + j)) {
          j++;
        }
        if (j == len2) res = (char *)(haystack + i);
      }
      i++;
    }
  }
  return res;
}
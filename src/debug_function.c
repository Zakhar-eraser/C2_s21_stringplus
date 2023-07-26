#include <stdio.h>
#include <string.h>

#include "s21_string.h"

void tok(char *, char *);
void tok21(char *, char *);

int main(void) {
  char str1[5];  // = " tes1tsst teThis is a stringst stee0 ";
  char *str2 = S21_NULL;
  // printf("%s\n%s\n", str2, str1);
  printf("%s\n", (char *)s21_trim(str1, str2));
  return 0;
}

void tok(char *src, char *tok) {
  char *res = strtok(src, tok);
  while (res) {
    printf("%s\n", res);
    res = strtok(NULL, tok);
  }
}

void tok21(char *src, char *tok) {
  char *res = s21_strtok(src, tok);
  while (res) {
    printf("%s\n", res);
    res = s21_strtok(NULL, tok);
  }
}
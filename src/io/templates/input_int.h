#ifndef _SRC_IO_TEMPLATES_INPUT_INT_H_
#define _SRC_IO_TEMPLATES_INPUT_INT_H_
#define S21_SIGN
#define S21_ARG_1 long
#define S21_ARG_2 long long
#define S21_TYPE_1 long
#define S21_TYPE_2 long long
#include "input_int.c"
#undef S21_SIGN
#define S21_SIGN unsigned
#include "input_int.c"
#undef S21_TYPE_1
#undef S21_TYPE_2
#undef S21_ARG_1
#undef S21_ARG_2
#define S21_TYPE_1 short
#define S21_TYPE_2 char
#define S21_ARG_1 int
#define S21_ARG_2 int
#include "input_int.c"
#undef S21_SIGN
#define S21_SIGN
#include "input_int.c"
#endif  // _SRC_IO_TEMPLATES_INPUT_INT_H_
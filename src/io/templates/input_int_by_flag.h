#ifndef _SRC_IO_TEMPLATES_INPUT_INT_BY_FLAG_H_
#define _SRC_IO_TEMPLATES_INPUT_INT_BY_FLAG_H_
#include "input_int.h"
#undef S21_SIGN
#define S21_SIGN
#include "input_int_by_flag.c"
#undef S21_SIGN
#define S21_SIGN unsigned
#include "input_int_by_flag.c"
#endif  // _SRC_IO_TEMPLATES_INPUT_INT_BY_FLAG_H_
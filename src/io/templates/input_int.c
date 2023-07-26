#if defined(S21_SIGN) && defined(S21_TYPE_1) && defined(S21_ARG_1) && \
    defined(S21_ARG_2) && defined(S21_TYPE_2)
#define S21_CAT(S, T) s21_input_##S##_##T
#define S21_INPUT(S, T) S21_CAT(S, T)
#include <stdarg.h>

S21_SIGN long long S21_INPUT(S21_SIGN, S21_TYPE_1)(char width, va_list args) {
  S21_SIGN long long value;
  if (width == 2) {
    value = (S21_SIGN S21_TYPE_2)va_arg(args, S21_SIGN S21_ARG_2);
  } else {
    value = (S21_SIGN S21_TYPE_1)va_arg(args, S21_SIGN S21_ARG_1);
  }
  return value;
}
#endif
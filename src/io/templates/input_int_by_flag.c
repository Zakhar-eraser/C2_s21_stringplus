#if defined(S21_SIGN) && defined(S21_INPUT) && defined(S21_CAT)
#include <stdarg.h>
#define S21_CAT_BY_FLAG(S) s21_input_##S##_int
#define S21_INPUT_BY_FLAG(S) S21_CAT_BY_FLAG(S)

S21_SIGN long long S21_INPUT(S21_SIGN, short)(char, va_list);
S21_SIGN long long S21_INPUT(S21_SIGN, long)(char, va_list);

S21_SIGN long long S21_INPUT_BY_FLAG(S21_SIGN)(char short_l, char long_l,
                                               va_list args) {
  S21_SIGN long long value;
  if (short_l) {
    value = S21_INPUT(S21_SIGN, short)(short_l, args);
  } else if (long_l) {
    value = S21_INPUT(S21_SIGN, long)(long_l, args);
  } else {
    value = va_arg(args, int);
  }
  return value;
}
#endif
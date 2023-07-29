#include <math.h>
#include <stdarg.h>

#include "common.h"
#include "templates/input_int_by_flag.h"

typedef struct {
  int width;
  int precision;
  int counter;
  char width_filler;
  unsigned short plus_f : 1;
  unsigned short minus_f : 1;
  unsigned short space_f : 1;
  unsigned short zero_f : 1;
  unsigned short h_l : 2;
  unsigned short l_l : 2;
  unsigned short L_l : 1;
  unsigned short offset : 1;
} arg_info;

const char *s21_parse_flags(const char *format, arg_info *info);
const char *s21_parse_width(const char *format, arg_info *info);
const char *s21_parse_precision(const char *format, arg_info *info);
const char *s21_parse_length(const char *format, arg_info *info);
char *s21_insert_arg(char *str, char spec, arg_info *info, va_list args);

char *s21_print_int(char *str, long double integral, arg_info *info);
char *s21_print_float(char *str, long double floating, arg_info *info);
char *s21_print_char(char *str, int ch, arg_info *info);
char *s21_print_str(char *str, char *in_str, arg_info *info);

int s21_fill(char *str, char c, char right, char offset, int width,
             int counter);
long double s21_align_sign(char *str, long double value, arg_info *info);

int s21_int_to_str(char *str, long double value);
long double s21_frac_to_int(long double value, int precision);
void s21_inverse_str(char *str, int len);

char s21_set_double_length(const char **pformat);

void s21_rshift(char *begin, char *end, unsigned int n);

int s21_sprintf(char *str, const char *format, ...) {
  int count = 0;
  va_list args;
  va_start(args, format);
  int error = 0;
  for (; !error && *format; format++, str++) {
    if (*format == '%') {
      arg_info info = {0};
      info.width_filler = ' ';
      info.precision = -1;
      format = s21_parse_flags(format + 1, &info);
      format = s21_parse_width(format, &info);
      format = s21_parse_precision(format, &info);
      format = s21_parse_length(format, &info);
      str = s21_insert_arg(str, *format, &info, args);
      if (info.counter < 0) {
        error = 1;
      } else {
        count += info.counter;
      }
    } else {
      *str = *format;
      count++;
    }
  }
  *str = 0;
  va_end(args);
  str[count] = 0;
  if (error) count = -1;
  return count;
}

char *s21_insert_arg(char *str, char spec, arg_info *info, va_list args) {
  switch (spec) {
    case 'c':
      str = s21_print_char(str, va_arg(args, int), info);
      break;
    case 'd':
      str =
          s21_print_int(str, s21_input__int(info->h_l, info->l_l, args), info);
      break;
    case 'u':
      info->space_f = 0;
      info->plus_f = 0;
      str = s21_print_int(
          str, s21_input_unsigned_int(info->h_l, info->l_l, args), info);
      break;
    case 'f':
      if (info->precision == -1) info->precision = 6;
      if (info->L_l) {
        str = s21_print_float(str, va_arg(args, long double), info);
      } else {
        str = s21_print_float(str, va_arg(args, double), info);
      }
      break;
    case 's':
      str = s21_print_str(str, va_arg(args, char *), info);
      break;
    default:
      info->counter = -1;
      break;
  }
  return str;
}

char *s21_print_char(char *str, int ch, arg_info *info) {
  *str = (char)ch;
  info->counter = 1;
  info->counter +=
      s21_fill(str, ' ', info->minus_f, 0, info->width, info->counter);
  return str + info->counter - 1;
}

char *s21_print_int(char *str, long double integral, arg_info *info) {
  if (integral || info->precision) {
    integral = s21_align_sign(str, integral, info);
    info->counter += s21_int_to_str(str + info->offset, integral);
    if (info->precision > 0)
      info->counter +=
          s21_fill(str + info->offset, '0', 0, info->offset & info->zero_f,
                   info->precision, info->counter);
    info->counter += info->offset;
  }
  info->counter +=
      s21_fill(str, info->width_filler, info->minus_f,
               info->offset & info->zero_f, info->width, info->counter);
  return str + info->counter - 1;
}

long double s21_align_sign(char *str, long double value, arg_info *info) {
  if (signbit(value)) {
    *str = '-';
    value = -value;
    info->offset = 1;
  } else if (info->plus_f) {
    *str = '+';
    info->offset = 1;
  } else if (info->space_f) {
    *str = ' ';
    info->offset = 1;
  }
  return value;
}

char *s21_print_float(char *str, long double floating, arg_info *info) {
  floating = s21_align_sign(str + info->offset, floating, info);
  info->counter += info->offset;
  if (isnan(floating)) {
    s21_memcpy(str + info->counter, "nan", 3);
    info->counter += 3;
  } else if (isinf(floating)) {
    s21_memcpy(str + info->counter, "inf", 3);
    info->counter += 3;
  } else {
    long double integ, frac = modfl(floating, &integ);
    info->counter += s21_int_to_str(str + info->counter, integ) + 1;
    str[info->counter - 1] = '.';
    frac = s21_frac_to_int(frac, info->precision);
    s21_memset(str + info->counter, '0', info->precision);
    s21_int_to_str(str + info->counter, frac);
    info->counter += info->precision;
  }
  info->counter +=
      s21_fill(str, info->width_filler, info->minus_f,
               info->offset & info->zero_f, info->width, info->counter);
  return str + info->counter - 1;
}

char *s21_print_str(char *str, char *in_str, arg_info *info) {
  info->counter = (int)s21_strlen(in_str);
  s21_memcpy(str, in_str, info->counter);
  info->counter +=
      s21_fill(str, ' ', info->minus_f, 0, info->width, info->counter);
  return str + info->counter - 1;
}

int s21_int_to_str(char *str, long double value) {
  int count = 0;
  if (!value) {
    *str = '0';
    count = 1;
  } else {
    for (char *sstr = str; value; sstr++, count++) {
      long double unit = fmodl(value, 10);
      value = truncl(value / 10);
      *sstr = (char)unit + '0';
    }
    s21_inverse_str(str, count);
  }
  return count;
}

void s21_inverse_str(char *str, int len) {
  for (int i = 0; i < len / 2; i++) {
    char tmp = *(str + i);
    *(str + i) = *(str + len - 1 - i);
    *(str + len - 1 - i) = tmp;
  }
}

long double s21_frac_to_int(long double value, int precision) {
  value *= powl(10, precision);
  long double frac = modfl(value, &value);
  if (frac > 0.5L || (frac == 0.5L && ((int)fmodl(value, 10) % 2))) value += 1;
  return value;
}

int s21_fill(char *str, char c, char right, char offset, int width,
             int counter) {
  int shift = 0;
  if (width > counter) {
    shift = width - counter;
    if (right) {
      s21_memset(str + counter, c, shift);
    } else {
      s21_rshift(str + offset, str + counter, shift);
      s21_memset(str + offset, c, shift);
    }
  }
  return shift;
}

void s21_rshift(char *begin, char *end, unsigned int n) {
  for (unsigned int i = 0; i < n; i++, begin++, end++) {
    for (char *p = end; p != begin; p--) {
      *p = *(p - 1);
    }
  }
}

const char *s21_parse_length(const char *format, arg_info *info) {
  switch (*format) {
    case 'h':
      info->h_l = s21_set_double_length(&format);
      break;
    case 'l':
      info->l_l = s21_set_double_length(&format);
      break;
    case 'L':
      info->L_l = 1;
      format++;
      break;
  }
  return format;
}

char s21_set_double_length(const char **pformat) {
  char out = 1;
  if (*(*pformat + 1) == **pformat) {
    out = 2;
    *pformat += 1;
  }
  *pformat += 1;
  return out;
}

const char *s21_parse_precision(const char *format, arg_info *info) {
  if (*format == '.') {
    long double result;
    format = s21_read_int(format + 1, &result);
    info->precision = (s21_size_t)result;
  }
  return format;
}

const char *s21_parse_width(const char *format, arg_info *info) {
  long double result;
  format = s21_read_int(format, &result);
  info->width = (s21_size_t)result;
  return format;
}

const char *s21_parse_flags(const char *format, arg_info *info) {
  for (int exist = 1; exist; format++) {
    switch (*format) {
      case '-':
        info->minus_f = 1;
        break;
      case '+':
        info->plus_f = 1;
        break;
      case ' ':
        info->space_f = 1;
        break;
      case '0':
        info->zero_f = 1;
        break;
      default:
        exist = 0;
        format--;
        break;
    }
  }
  if (info->minus_f) info->zero_f = 0;
  if (info->zero_f) info->width_filler = '0';
  return format;
}

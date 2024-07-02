#include "common/digits_helper.h"
#include "common/va_helper.h"
#include "s21_string.h"

typedef struct {
  int is_left_justify;         // -
  int set_plus_sign;           // +
  int set_space_instead_sign;  // (space)
  int is_alt_form;             // #
  int set_zero_instead_space;  // 0

  int width;      // (number) or *
  int precision;  // .(number) or *
  char length;    // h l L
  char specifier;
} sprintf_flags_t;

sprintf_flags_t sprintf_parse_flags(const char* format, s21_size_t* curr_index);
void set_flag(sprintf_flags_t* flags, char curr_char);
void sprintf_set_width(sprintf_flags_t* flags, char curr_char);
void set_precision(sprintf_flags_t* flags, char curr_char);

long long int handle_specifiers(sprintf_flags_t flags, char* str);
long long int handle_specifier_c(sprintf_flags_t flags, char* str);
s21_size_t handle_specifier_di(sprintf_flags_t flags, char* str);
s21_size_t handle_specifier_e(sprintf_flags_t flags, char* str,
                              long double value);
s21_size_t handle_specifier_f(sprintf_flags_t flags, char* str,
                              long double value);
long long int handle_specifier_s(sprintf_flags_t flags, char* str);
s21_size_t handle_specifier_ouxp(sprintf_flags_t flags, char* str);
s21_size_t handle_specifier_g(sprintf_flags_t flags, char* str,
                              long double value);
s21_size_t handle_inf_nan(char* str, long double value, int is_upper);

int check_value_nan_inf(long double value);
void print_exp_value(sprintf_flags_t flags, char* str, s21_size_t* length,
                     exp_ld_t exp_data);
void print_exponent(sprintf_flags_t flags, char* str, s21_size_t* length,
                    exp_ld_t exp_data);
void set_ouxp_data(sprintf_flags_t* flags, unsigned long int* value, int* ss);
int set_ss_pre_data(sprintf_flags_t flags, char* str, s21_size_t* length,
                    int has_digits, int ss, int is_p);
void convert_ss_to_str(sprintf_flags_t flags, char* str, s21_size_t* length,
                       unsigned long int value, unsigned int ss);
char get_sign_by_flags(sprintf_flags_t flags, int is_greater_zero);

int s21_sprintf(char* str, const char* format, ...) {
  long long int str_index = 0;

  va_list ap;
  va_start(ap, format);
  set_va_list(&ap);

  s21_size_t format_length = s21_strlen(format);

  for (s21_size_t i = 0; i < format_length && str_index != -1; i++) {
    str[str_index] = '\0';
    if (format[i] == '%') {
      i++;
      sprintf_flags_t flags = sprintf_parse_flags(format, &i);

      if (flags.specifier == 'n') {
        *(int*)get_va_arg_ptr() = str_index;
      } else {
        long long int result_handle = handle_specifiers(flags, str + str_index);
        str_index += result_handle == -1 ? -str_index - 1 : result_handle;
      }
    } else {
      str[str_index++] = format[i];
    }

    if (str_index != -1) {
      str[str_index] = '\0';
    }
  }

  va_end(ap);

  return str_index;
}

sprintf_flags_t sprintf_parse_flags(const char* format,
                                    s21_size_t* curr_index) {
  sprintf_flags_t flags = {0};
  flags.precision = -1;

  // Get flags
  for (; s21_strchr("-+ #0", format[*curr_index]); (*curr_index)++) {
    set_flag(&flags, format[*curr_index]);
  }

  // Get width
  for (; s21_strchr("0123456789", format[*curr_index]); (*curr_index)++) {
    sprintf_set_width(&flags, format[*curr_index]);
  }
  if (format[*curr_index] == '*') {
    flags.width = get_va_arg_int();
    (*curr_index)++;
  }

  // Get .precision
  if (format[*curr_index] == '.') {
    flags.precision = 0;
    (*curr_index)++;
    for (; s21_strchr("0123456789", format[*curr_index]); (*curr_index)++) {
      set_precision(&flags, format[*curr_index]);
    }
    if (format[*curr_index] == '*') {
      flags.precision = get_va_arg_int();
      (*curr_index)++;
    }
  }

  // Get length
  if (s21_strchr("hlL", format[*curr_index])) {
    flags.length = format[(*curr_index)++];
  }

  // Get specifier
  flags.specifier = format[*curr_index];

  return flags;
}

void set_flag(sprintf_flags_t* flags, char curr_char) {
  if (curr_char == '-') {
    flags->is_left_justify = 1;
  } else if (curr_char == '+') {
    flags->set_plus_sign = 1;
  } else if (curr_char == ' ') {
    flags->set_space_instead_sign = 1;
  } else if (curr_char == '#') {
    flags->is_alt_form = 1;
  } else if (curr_char == '0') {
    flags->set_zero_instead_space = 1;
  }
}

void sprintf_set_width(sprintf_flags_t* flags, char curr_char) {
  if (curr_char >= '0' && curr_char <= '9') {
    flags->width *= 10;
    flags->width += curr_char - '0';
  }
}

void set_precision(sprintf_flags_t* flags, char curr_char) {
  if (curr_char == '*') {
    flags->precision = get_va_arg_int();
  } else if (curr_char >= '0' && curr_char <= '9') {
    flags->precision = flags->precision < 0 ? 0 : flags->precision;
    flags->precision *= 10;
    flags->precision += curr_char - '0';
  }
}

long long int handle_specifiers(sprintf_flags_t flags, char* str) {
  long long int length = 0;

  if (flags.specifier == '%') {
    str[length++] = '%';
  } else if (flags.specifier == 'c') {
    long long int result = handle_specifier_c(flags, str);
    length += result == -1 ? -length - 1 : result;
  } else if (s21_strchr("di", flags.specifier)) {
    length += handle_specifier_di(flags, str);
  } else if (s21_strchr("eE", flags.specifier)) {
    long double value = 0;
    if (flags.length == 'L') {
      value = get_va_arg_long_double();
    } else {
      value = get_va_arg_double();
    }
    length += check_value_nan_inf(value)
                  ? handle_inf_nan(str, value, flags.specifier == 'E')
                  : handle_specifier_e(flags, str, value);
  } else if (flags.specifier == 'f') {
    long double value = 0;
    if (flags.length == 'L') {
      value = get_va_arg_long_double();
    } else {
      value = get_va_arg_double();
    }
    length += check_value_nan_inf(value)
                  ? handle_inf_nan(str, value, 0)
                  : handle_specifier_f(flags, str, value);
  } else if (s21_strchr("gG", flags.specifier)) {
    long double value = 0;
    if (flags.length == 'L') {
      value = get_va_arg_long_double();
    } else {
      value = get_va_arg_double();
    }
    length += check_value_nan_inf(value)
                  ? handle_inf_nan(str, value, flags.specifier == 'G')
                  : handle_specifier_g(flags, str, value);
  } else if (flags.specifier == 's') {
    long long int result = handle_specifier_s(flags, str);
    length += result == -1 ? -length - 1 : result;

  } else if (s21_strchr("ouxXp", flags.specifier)) {
    length += handle_specifier_ouxp(flags, str);
  }

  return length;
}

long long int handle_specifier_c(sprintf_flags_t flags, char* str) {
  long long int length = 0;

  if (flags.length == 'l') {
    wchar_t wchar = get_va_arg_wchar();

    long long int result = (long long int)wcrtomb(str + length, wchar, NULL);
    if (result == -1) {
      str[length + 1] = '\0';
      length = -1;
    } else {
      length += result;
    }
  } else {
    str[length++] = get_va_arg_int();
  }

  if (length != -1) {
    str[length] = 0;

    s21_reverse(str);
    for (; length < flags.width && !flags.is_left_justify && length != -1;
         length++) {
      str[length] = ' ';
    }
    str[length] = 0;

    s21_reverse(str);
    for (; length < flags.width && flags.is_left_justify && length != -1;
         length++) {
      str[length] = ' ';
    }
    str[length] = 0;
  }
  return length;
}

s21_size_t handle_specifier_di(sprintf_flags_t flags, char* str) {
  s21_size_t length = 0;
  long int value = 0;
  int count_symbols = 0;

  flags.set_zero_instead_space =
      flags.set_zero_instead_space && flags.precision == -1;
  value = flags.length == 'l' ? get_va_arg_long_int() : get_va_arg_int();

  count_symbols = get_count_digits(value);
  flags.precision =
      flags.precision - count_symbols > 0 ? flags.precision - count_symbols : 0;
  count_symbols += flags.precision;

  char sign_char = get_sign_by_flags(flags, value >= 0 && 1.0 / value >= 0);
  count_symbols += sign_char != '\0';

  for (int i = 0; i < flags.width - count_symbols && !flags.is_left_justify &&
                  !flags.set_zero_instead_space;
       i++) {
    str[length++] = ' ';
  }

  if (sign_char != '\0') {
    str[length++] = sign_char;
  }

  for (int i = 0; (i < flags.width - count_symbols && !flags.is_left_justify &&
                   flags.set_zero_instead_space) ||
                  i < flags.precision;
       i++) {
    str[length++] = '0';
  }

  int count_digits = get_count_digits(value);
  long int reversed_value = reverse_digit(value);
  while (reversed_value > 0 || count_digits > 0) {
    str[length++] = reversed_value % 10 + '0';
    reversed_value /= 10;
    count_digits--;
  }

  for (int i = 0; i < flags.width - count_symbols && flags.is_left_justify;
       i++) {
    str[length++] = ' ';
  }

  return length;
}

s21_size_t handle_specifier_e(sprintf_flags_t flags, char* str,
                              long double value) {
  s21_size_t length = 0;
  int count_symbols = 0;
  exp_ld_t exp_data = get_exp_ld(value);

  count_symbols = 5;  // 0e+00
  flags.precision = flags.precision == -1 ? 6 : flags.precision;
  count_symbols +=
      flags.precision > 0 ? flags.precision + 1 : 0;  // дробные числа + (точка)
  count_symbols +=
      flags.precision == 0 && flags.is_alt_form ? 1 : 0;  // (точка)

  char sign_char = get_sign_by_flags(flags, value >= 0 && 1.0 / value >= 0);
  count_symbols += sign_char != '\0';

  for (int i = 0; i < flags.width - count_symbols && !flags.is_left_justify &&
                  !flags.set_zero_instead_space;
       i++) {
    str[length++] = ' ';
  }

  if (sign_char != '\0') {
    str[length++] = sign_char;
  }

  for (int i = 0; i < flags.width - count_symbols && !flags.is_left_justify &&
                  flags.set_zero_instead_space;
       i++) {
    str[length++] = '0';
  }

  str[length++] = flags.precision > 0 ? (int)exp_data.value + '0'
                                      : (int)round(exp_data.value) + '0';
  if (flags.precision > 0 || flags.is_alt_form) {
    str[length++] = '.';
  }

  // вывод дробной части
  print_exp_value(flags, str, &length, exp_data);
  // вывод экспоненты
  print_exponent(flags, str, &length, exp_data);

  for (int i = 0; i < flags.width - count_symbols && flags.is_left_justify;
       i++) {
    str[length++] = ' ';
  }

  return length;
}

void print_exp_value(sprintf_flags_t flags, char* str, s21_size_t* length,
                     exp_ld_t exp_data) {
  if (flags.precision > 0) {
    long val = (long)roundl(
        (exp_data.value - ((long)exp_data.value - (long)exp_data.value % 10)) *
        pow(10, flags.precision));
    int val_count_digits = get_count_digits(val) - 1;
    val = reverse_digit(val) / 10;  // отбрасываем первое число

    while (val_count_digits > 0 || flags.precision > 0) {
      str[(*length)++] = val % 10 + '0';
      val /= 10;
      val_count_digits--;
      flags.precision--;
    }
  }
}

void print_exponent(sprintf_flags_t flags, char* str, s21_size_t* length,
                    exp_ld_t exp_data) {
  str[(*length)++] = flags.specifier;
  str[(*length)++] = exp_data.exponent < 0 ? '-' : '+';

  // если экспонента это 1 число, то добавялем 0
  if (exp_data.exponent > -10 && exp_data.exponent < 10) {
    str[(*length)++] = '0';
    str[(*length)++] = abs(exp_data.exponent) + '0';
  } else {
    int count_digits = get_count_digits(exp_data.exponent);
    long reverse_value = reverse_digit(exp_data.exponent);

    while (reverse_value > 0) {
      str[(*length)++] = reverse_value % 10 + '0';
      reverse_value /= 10;
      count_digits--;
    }

    while (count_digits-- > 0) {
      str[(*length)++] = '0';
    }
  }
}

s21_size_t handle_specifier_f(sprintf_flags_t flags, char* str,
                              long double value) {
  s21_size_t length = 0;
  int count_symbols = get_count_digits(
      flags.precision == 0 ? (long)roundl(value) : (long)value);

  flags.precision = flags.precision == -1 ? 6 : flags.precision;
  count_symbols +=
      flags.precision > 0 ? flags.precision + 1 : 0;  // дробные числа + (точка)
  count_symbols +=
      flags.precision == 0 && flags.is_alt_form ? 1 : 0;  // (точка)

  char sign_char = get_sign_by_flags(flags, value >= 0 && 1.0 / value >= 0);
  count_symbols += sign_char != '\0';
  value *= value < 0 ? -1 : 1;

  for (int i = 0; i < flags.width - count_symbols && !flags.is_left_justify &&
                  !flags.set_zero_instead_space;
       i++) {
    str[length++] = ' ';
  }

  if (sign_char != '\0') {
    str[length++] = sign_char;
  }

  for (int i = 0; i < flags.width - count_symbols && !flags.is_left_justify &&
                  flags.set_zero_instead_space;
       i++) {
    str[length++] = '0';
  }

  length += s21_itos(str + length,
                     flags.precision == 0 ? (long)roundl(value) : (long)value);
  if (flags.precision > 0 || flags.is_alt_form) {
    str[length++] = '.';
  }

  // вывод дробной части
  if (flags.precision > 0) {
    long long int val =
        (long long int)((value - (long)value + 1) * powl(10, flags.precision) +
                        0.5);
    val = reverse_digit(val) / 10;

    while (val >= 10 || flags.precision > 0) {
      str[length++] = val % 10 + '0';
      val /= 10;
      flags.precision--;
    }
  }

  for (int i = 0; i < flags.width - count_symbols && flags.is_left_justify;
       i++) {
    str[length++] = ' ';
  }

  return length;
}

s21_size_t handle_inf_nan(char* str, long double value, int is_upper) {
  s21_size_t index = 0;

  int is_nan = isnan(value);
  int is_inf = isinf(value);

  if (is_nan || (is_inf && (value < 0 || 1.0 / value < 0))) {
    str[index++] = '-';
  }

  if (is_inf) {
    str[index++] = is_upper ? 'I' : 'i';
    str[index++] = is_upper ? 'N' : 'n';
    str[index++] = is_upper ? 'F' : 'f';
    str[index] = '\0';
  } else if (is_nan) {
    str[index++] = is_upper ? 'N' : 'n';
    str[index++] = is_upper ? 'A' : 'a';
    str[index++] = is_upper ? 'N' : 'n';
    str[index] = '\0';
  }

  return index;
}

int check_value_nan_inf(long double value) {
  return isnan(value) || isinf(value);
}

long long int handle_specifier_s(sprintf_flags_t flags, char* str) {
  long long int length = 0;

  if (flags.length == 'l') {
    wchar_t* wchar_str = get_va_arg_wchar_str();

    while (*wchar_str != L'\0' && length != -1 &&
           (flags.precision <= -1 || length < flags.precision)) {
      long long int result =
          (long long int)wcrtomb(str + length, *wchar_str, NULL);
      if (result == -1) {
        str[length] = '\0';
        length = -1;
      } else if (flags.precision <= -1 || length + result < flags.precision) {
        length += result;
        str[length] = '\0';
      } else {
        s21_memset(str + length, '\0', result);
      }
      wchar_str++;
    }
  } else {
    char* new_str = get_va_arg_str();

    while (*new_str && (flags.precision <= -1 || length < flags.precision)) {
      str[length++] = *new_str;
      new_str++;
    }
    str[length] = '\0';
  }

  if (length != -1) {
    str[length] = 0;
    s21_reverse(str);
    for (; length < flags.width && !flags.is_left_justify; length++) {
      str[length] = ' ';
    }
    str[length] = 0;

    s21_reverse(str);
    for (; length < flags.width && flags.is_left_justify; length++) {
      str[length] = ' ';
    }
    str[length] = 0;
  }

  return length;
}

s21_size_t handle_specifier_ouxp(sprintf_flags_t flags, char* str) {
  s21_size_t length = 0;
  unsigned long int value = 0;
  int count_symbols = 0, ss = 10, has_digits = 1, is_p = flags.specifier == 'p';

  flags.set_zero_instead_space =
      flags.set_zero_instead_space && flags.precision == -1;

  set_ouxp_data(&flags, &value, &ss);

  if (value == 0) {
    str[length++] = '0';
    has_digits = 0;
  }
  str[length] = 0;

  convert_ss_to_str(flags, str, &length, value, ss);

  count_symbols = (int)length;
  flags.precision =
      flags.precision - count_symbols > 0 ? flags.precision - count_symbols : 0;
  count_symbols += flags.precision;

  for (int i = 0; (i < flags.width - count_symbols && !flags.is_left_justify &&
                   flags.set_zero_instead_space) ||
                  i < flags.precision;
       i++) {
    str[length++] = '0';
  }

  count_symbols += set_ss_pre_data(flags, str, &length, has_digits, ss, is_p);

  for (int i = 0; i < flags.width - count_symbols && !flags.is_left_justify &&
                  !flags.set_zero_instead_space;
       i++) {
    str[length++] = ' ';
  }
  str[length] = 0;

  s21_reverse(str);

  for (int i = 0; i < flags.width - count_symbols && flags.is_left_justify;
       i++) {
    str[length++] = ' ';
  }

  return length;
}

void set_ouxp_data(sprintf_flags_t* flags, unsigned long int* value, int* ss) {
  if (flags->specifier == 'p') {
    *value = (unsigned long int)get_va_arg_ptr();
    flags->specifier = 'x';
    flags->is_alt_form = 1;
  } else {
    if (flags->length == 'l') {
      *value = get_va_arg_long_u_int();
    } else if (flags->length == 'h') {
      *value = (unsigned short int)get_va_arg_u_int();
    } else {
      *value = get_va_arg_u_int();
    }
  }

  if (flags->specifier == 'o') {
    *ss = 8;
  } else if (s21_strchr("xX", flags->specifier)) {
    *ss = 16;
  }
}

int set_ss_pre_data(sprintf_flags_t flags, char* str, s21_size_t* length,
                    int has_digits, int ss, int is_p) {
  int count_symbols = 0;

  if (flags.is_alt_form && has_digits) {
    if (ss == 16) {
      str[(*length)++] = flags.specifier;
      count_symbols++;
    }
    if ((ss == 8 && *length > 0 && str[(*length) - 1] != '0') || ss == 16) {
      str[(*length)++] = '0';
      count_symbols++;
    }
  }

  if (is_p) {
    if (flags.set_plus_sign) {
      str[(*length)++] = '+';
      count_symbols++;
    } else if (flags.set_space_instead_sign) {
      str[(*length)++] = ' ';
      count_symbols++;
    }
  }

  return count_symbols;
}

void convert_ss_to_str(sprintf_flags_t flags, char* str, s21_size_t* length,
                       unsigned long int value, unsigned int ss) {
  if (ss == 0) {
    return;
  }

  const char* ss_values = NUMBER_SYSTEM;

  while (value > 0) {
    char tmp_char = ss_values[value % ss];

    if (tmp_char >= 'A' && tmp_char <= 'F' && flags.specifier == 'x') {
      str[(*length)++] = tmp_char + 32;
    } else {
      str[(*length)++] = tmp_char;
    }

    value /= ss;
  }
  str[*length] = 0;
}

s21_size_t handle_specifier_g(sprintf_flags_t flags, char* str,
                              long double value) {
  s21_size_t length = 0;

  if (flags.precision == -1) {
    flags.precision = 6;
  } else if (flags.precision == 0) {
    flags.precision = 1;
  }

  float curr_plus = 0;
  if ((long long int)(value + 0.5) > (long long int)value) {
    curr_plus = 0.5;
  }
  exp_ld_t exp_data = get_exp_ld(value + curr_plus);

  if (exp_data.exponent < -4 || exp_data.exponent >= flags.precision) {
    flags.specifier = flags.specifier == 'g' ? 'e' : 'E';
    flags.precision =
        flags.is_alt_form
            ? flags.precision - 1
            : get_count_sign_digits(
                  roundl(exp_data.value * powl(10, flags.precision - 1)),
                  flags.precision - 1);
    length += handle_specifier_e(flags, str, value + curr_plus);
  } else {
    flags.specifier = 'f';

    int max_count_digits =
        flags.precision -
        get_count_digits(
            value);  // максимум знаков после запятой, которые можно взять

    long double abs_value = value < 0 ? value * -1 : value;
    long double rounded_value =
        roundl(abs_value * powl(10, max_count_digits)) /
        powl(10, max_count_digits);  // полностью округлённое число
    long long int fract_part_value =
        roundl((abs_value -
                ((long long int)abs_value - (long long int)abs_value % 10)) *
               powl(10, max_count_digits));  // только дробная часть

    max_count_digits =
        flags.precision - get_count_digits((long long int)rounded_value) < 0
            ? 0
            : flags.precision -
                  get_count_digits(
                      (long long int)
                          rounded_value);  // перерасчёт кол-ва дробных чисел
                                           // после округления
    flags.precision =
        flags.is_alt_form
            ? max_count_digits
            : get_count_sign_digits(fract_part_value, max_count_digits);

    length +=
        handle_specifier_f(flags, str, rounded_value * (value < 0 ? -1 : 1));
  }

  return length;
}

char get_sign_by_flags(sprintf_flags_t flags, int is_greater_zero) {
  char sign_char = '\0';

  if (is_greater_zero) {
    if (flags.set_plus_sign) {
      sign_char = '+';
    } else if (flags.set_space_instead_sign) {
      sign_char = ' ';
    }
  } else {
    sign_char = '-';
  }

  return sign_char;
}

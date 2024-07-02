#include "common/digits_helper.h"
#include "common/va_helper.h"
#include "s21_string.h"

#define SPACE_CHAR " \t\n\r\f\x0B"
#define DIGIT_CHAR "0123456789"

typedef struct {
  int suppress_assignment;  // *

  int width;    // (number)
  char length;  // h l L

  char specifier;
} sscanf_flags_t;

int s21_sscanf(const char* str, const char* format, ...);
sscanf_flags_t parse_flags(const char* format, long long int* curr_index);
void set_width(sscanf_flags_t* flags, char curr_char);
long long int get_value_by_specifier(sscanf_flags_t flags, const char* str,
                                     int* count_assignment);
long double handle_float(const char* str, long long int* str_index);
int set_float_value(sscanf_flags_t flags, long double value);
long long int get_integer_from_str(const char* str, long long int* str_index,
                                   int ss);
int set_integer_value(sscanf_flags_t flags, long long int value);
int set_ptr_value(sscanf_flags_t flags, unsigned long value);
long double get_fract_from_str(const char* str, long long int* str_index);
long long int get_exponent_from_str(const char* str, long long int* str_index);
int set_s(sscanf_flags_t flags, const char* str, long long int* str_index);
int set_c(sscanf_flags_t flags, const char* str, long long int* str_index);
void skip_empty_chars(const char* str, long long int* index);
int get_curr_ss(const char* str, long long int str_index);
int get_ss_by_char(char c);
int is_nan_inf(const char* str, long long int* str_index);
int is_space(char c);
int is_digit(char c);
int is_hex(char c);
int get_hex_value(char c);
int is_octal(char c);

int s21_sscanf(const char* str, const char* format, ...) {
  long long int str_index = 0, format_index = 0;
  int count_assignment = 0, is_error = 0, was_symb = 0;
  long long int format_length = s21_strlen(format);

  va_list ap;
  va_start(ap, format);
  set_va_list(&ap);

  while (format_index < format_length && !is_error) {
    if (is_space(format[format_index])) {
      skip_empty_chars(str, &str_index);
      skip_empty_chars(format, &format_index);
    } else if (format[format_index] == '%') {
      format_index++;
      sscanf_flags_t flags = parse_flags(format, &format_index);

      if (flags.specifier == 'n') {
        flags.suppress_assignment ? 0 : (*(int*)get_va_arg_ptr() = str_index);
      } else if (flags.specifier) {
        long long int result =
            get_value_by_specifier(flags, str + str_index, &count_assignment);

        is_error = result == -1;
        format_index = result == 0 ? format_length + 3 : format_index;
        was_symb = was_symb || result > 0;
        str_index += result;
      } else {
        is_error = 2;
      }
    } else if (str[str_index] != format[format_index]) {
      is_error = 2;
    } else {
      was_symb = 1;
      format_index++;
      str_index++;
    }
  }

  va_end(ap);
  return is_error == 1 && count_assignment == 0 ? -1 : count_assignment;
}

sscanf_flags_t parse_flags(const char* format, long long int* curr_index) {
  sscanf_flags_t flags = {0};

  // Get suppress assignment
  if (format[*curr_index] == '*') {
    flags.suppress_assignment = 1;
    (*curr_index)++;
  }

  // Get width
  for (; format[*curr_index] && s21_strchr("0123456789", format[*curr_index]);
       (*curr_index)++) {
    set_width(&flags, format[*curr_index]);
  }

  // Get length
  if (format[*curr_index] && s21_strchr("hlL", format[*curr_index])) {
    flags.length = format[(*curr_index)++];
  }

  // Get specifier
  if (format[*curr_index] &&
      s21_strchr("cdieEfgGousxXpn%", format[*curr_index])) {
    flags.specifier = format[(*curr_index)++];
  }

  return flags;
}

void set_width(sscanf_flags_t* flags, char curr_char) {
  if (curr_char >= '0' && curr_char <= '9') {
    flags->width *= 10;
    flags->width += curr_char - '0';
  }
}

long long int get_value_by_specifier(sscanf_flags_t flags, const char* str,
                                     int* count_assignment) {
  long long int str_index = 0;

  if (flags.specifier != 'c') {
    skip_empty_chars(str, &str_index);
    if (flags.specifier != 'f') {
      str_index =
          (!str[str_index] || is_space(str[str_index])) ? -1 : str_index;
    }
  }

  char* tmp = s21_NULL;
  long long int tmp_length = 0;
  if (str_index != -1) {
    tmp_length = flags.width == 0 || flags.width > (long long int)s21_strlen(
                                                       str + str_index)
                     ? (long long int)s21_strlen(str + str_index)
                     : flags.width;
    tmp = calloc(tmp_length + 1, sizeof(char));
  }

  if (tmp) {
    s21_strncpy(tmp, str + str_index, tmp_length);
    long long int new_index = 0;

    if (flags.specifier == '%') {
      str_index += str[str_index] == '%' ? 1 : -(str_index + 1);
    } else if (s21_strchr("feEgG", flags.specifier)) {
      long double value = handle_float(tmp, &new_index);
      *count_assignment += new_index > 0 ? set_float_value(flags, value) : 0;
      str_index += new_index > 0 ? new_index : 0;
    } else if (s21_strchr("diouxX", flags.specifier)) {
      long long int value = get_integer_from_str(
          tmp, &new_index, get_ss_by_char(flags.specifier));
      *count_assignment += new_index > 0 ? set_integer_value(flags, value) : 0;
      str_index += new_index > 0 ? new_index : 0;
    } else if (flags.specifier == 's') {
      *count_assignment += set_s(flags, tmp, &new_index);
      str_index += new_index;
    } else if (flags.specifier == 'c') {
      *count_assignment += set_c(flags, tmp, &new_index);
      str_index += new_index;
    } else if (flags.specifier == 'p') {
      unsigned long value = get_integer_from_str(tmp, &new_index, 16);
      *count_assignment += new_index > 0 ? set_ptr_value(flags, value) : 0;
      str_index += new_index > 0 ? new_index : 0;
    }
    free(tmp);
  }

  return str_index;
}

long double handle_float(const char* str, long long int* str_index) {
  long double value = 0;
  int sign = 1, has_digits = 0, is_end_read = 0;

  // получаем знак
  if (str[*str_index] == '+' || str[*str_index] == '-') {
    sign = str[*str_index] == '+' ? 1 : -1;
    (*str_index)++;
  }

  int nan_inf_info = is_nan_inf(str, str_index);
  is_end_read = nan_inf_info != 0;
  if (nan_inf_info == 1) {
    value = INFINITY;
  } else if (nan_inf_info == 2) {
    value = NAN;
  }

  // получаем целые числа
  if (!is_end_read) {
    has_digits = has_digits || (str[*str_index] && is_digit(str[*str_index]));
    value = get_integer_from_str(str, str_index, 10);
  }

  int has_dot = str[*str_index] == '.';
  *str_index += !is_end_read && has_dot ? 1 : 0;

  // получаем дробные числа
  if (!is_end_read && has_dot) {
    has_digits = has_digits || (str[*str_index] && is_digit(str[*str_index]));
    value += get_fract_from_str(str, str_index);
    // value += get_fract_from_str((const char*)str, str_index);
  }

  if (!is_end_read && !has_digits) {
    *str_index = -1;
    is_end_read = 1;
  }

  // получаем экспоненту
  if (!is_end_read) {
    long long int exponent = get_exponent_from_str(str, str_index);
    int e_sign = exponent >= 0 ? 1 : -1;
    exponent *= e_sign;  // замена abs
    for (; exponent > 0; exponent--) {
      value = e_sign > 0 ? value * 10 : value / 10;
    }
  }
  return value * sign;
}

// 0 - digit, 1 - is_inf, 2 - is_nan
int is_nan_inf(const char* str, long long int* str_index) {
  int result = 0;

  if ((str[*str_index] == 'I' || str[*str_index] == 'i') &&
      (str[*str_index + 1] == 'N' || str[*str_index + 1] == 'n') &&
      (str[*str_index + 2] == 'F' || str[*str_index + 2] == 'f')) {
    result = 1;
    *str_index += 3;
  } else if ((str[*str_index] == 'N' || str[*str_index] == 'n') &&
             (str[*str_index + 1] == 'A' || str[*str_index + 1] == 'a') &&
             (str[*str_index + 2] == 'N' || str[*str_index + 2] == 'n')) {
    result = 2;
    *str_index += 3;
  }

  return result;
}

int set_float_value(sscanf_flags_t flags, long double value) {
  if (flags.suppress_assignment) {
    return 0;
  }

  if (flags.length == 'L') {
    *(long double*)get_va_arg_ptr() = value;
  } else if (flags.length == 'l') {
    *(double*)get_va_arg_ptr() = value;
  } else {
    *(float*)get_va_arg_ptr() = value;
  }

  return 1;
}

long long int get_integer_from_str(const char* str, long long int* str_index,
                                   int ss) {
  long long int value = 0;
  int sign = 1, is_end_read = *str_index == -1;

  if ((str[*str_index] == '+' || str[*str_index] == '-') &&
      is_digit(str[*str_index + 1])) {
    sign = str[*str_index] == '+' ? 1 : -1;
    (*str_index)++;
  }

  if (ss == 0) {
    ss = get_curr_ss(str, *str_index);
  }

  if (ss == 8) {
    if (str[*str_index] == '0') {
      (*str_index)++;
    } else {
      is_end_read = 1;
    }
  } else if (ss == 16) {
    if (str[*str_index] == '0' &&
        (str[*str_index + 1] == 'X' || str[*str_index + 1] == 'x')) {
      (*str_index) += 2;
    } else {
      is_end_read = 1;
    }
  }
  is_end_read = is_end_read && (ss != 8 && ss != 10 && ss != 16);

  while (!is_end_read && str[*str_index]) {
    if (ss == 16 && (is_hex(str[*str_index]) || is_digit(str[*str_index]))) {
      value = value * ss + get_hex_value(str[*str_index]);
      (*str_index)++;
    } else if ((ss == 10 && is_digit(str[*str_index])) ||
               (ss == 8 && is_octal(str[*str_index]))) {
      value = value * ss + (str[*str_index] - '0');
      (*str_index)++;
    } else {
      is_end_read = 1;
    }
  }

  return value * sign;
}

int get_curr_ss(const char* str, long long int str_index) {
  int curr_ss = -1;

  if (str[str_index] == '0') {
    str_index++;
    if (str[str_index] == 'X' || str[str_index] == 'x') {
      curr_ss = 16;
    } else {
      curr_ss = 8;
    }
  } else if (str[str_index] && is_digit(str[str_index])) {
    curr_ss = 10;
  }

  return curr_ss;
}

int get_ss_by_char(char c) {
  int ss = 0;

  if (c == 'd' || c == 'u') {
    ss = 10;
  } else if (c == 'o') {
    ss = 8;
  } else if (c == 'X' || c == 'x') {
    ss = 16;
  }

  return ss;
}

int set_integer_value(sscanf_flags_t flags, long long int value) {
  if (flags.suppress_assignment) {
    return 0;
  }

  int is_unsigned = flags.specifier != 'd' && flags.specifier != 'i';

  if (flags.length == 'h') {
    if (is_unsigned) {
      *(unsigned short int*)get_va_arg_ptr() = value;
    } else {
      *(short int*)get_va_arg_ptr() = value;
    }
  } else if (flags.length == 'l') {
    if (is_unsigned) {
      *(unsigned long int*)get_va_arg_ptr() = value;
    } else {
      *(long int*)get_va_arg_ptr() = value;
    }
  } else if (flags.length == 'L') {
    if (is_unsigned) {
      *(unsigned long long*)get_va_arg_ptr() = value;
    } else {
      *(long long*)get_va_arg_ptr() = value;
    }
  } else {
    if (is_unsigned) {
      *(unsigned int*)get_va_arg_ptr() = value;
    } else {
      *(int*)get_va_arg_ptr() = value;
    }
  }

  return 1;
}

int set_ptr_value(sscanf_flags_t flags, unsigned long value) {
  if (flags.suppress_assignment) {
    return 0;
  }

  *(void**)get_va_arg_ptr() = (void*)value;

  return 1;
}

long double get_fract_from_str(const char* str, long long int* str_index) {
  if (*str_index == -1) {
    return 0;
  }

  long double value = 0;
  unsigned long long int curr_pow = 10;
  while (str[*str_index] && is_digit(str[*str_index])) {
    value += (long double)(str[*str_index] - '0') / curr_pow;

    curr_pow *= 10;
    (*str_index)++;
  }

  return value;
}

long long int get_exponent_from_str(const char* str, long long int* str_index) {
  long long int value = 0;
  int exponents_sign = 1, is_end_read = 0;

  is_end_read =
      str[*str_index] == 'e' || str[*str_index] == 'E' ? is_end_read : 1;
  if (!is_end_read) {
    (*str_index)++;
  }

  if (!is_end_read && (str[*str_index] == '+' || str[*str_index] == '-')) {
    exponents_sign = str[*str_index] == '+' ? 1 : -1;
    (*str_index)++;
  }

  while (!is_end_read && str[*str_index] && is_digit(str[*str_index])) {
    value = value * 10 + (str[*str_index] - '0');
    (*str_index)++;
  }

  return value * exponents_sign;
}

int set_s(sscanf_flags_t flags, const char* str, long long int* str_index) {
  char* curr_str = s21_NULL;
  int is_set_symbols = 0;
  if (!flags.suppress_assignment) {
    curr_str = (char*)get_va_arg_ptr();
  }

  s21_size_t curr_str_index = 0;
  while (str[*str_index] && !is_space(str[*str_index])) {
    if (!flags.suppress_assignment) {
      curr_str[curr_str_index++] = str[*str_index];
      curr_str[curr_str_index] = '\0';
      is_set_symbols = 1;
    }
    (*str_index)++;
  }

  return curr_str == s21_NULL || !is_set_symbols ? 0 : 1;
}

int set_c(sscanf_flags_t flags, const char* str, long long int* str_index) {
  char* curr_str = s21_NULL;
  int is_set_symbols = 0;
  if (!flags.suppress_assignment) {
    curr_str = (char*)get_va_arg_ptr();
  }

  flags.width = flags.width == 0 ? 1 : flags.width;
  while (str[*str_index] && *str_index < flags.width) {
    if (!flags.suppress_assignment && !is_set_symbols) {
      *curr_str = str[*str_index];
      curr_str++;
      is_set_symbols = 1;
    }
    (*str_index)++;
  }

  return curr_str == s21_NULL || !is_set_symbols ? 0 : 1;
}

void skip_empty_chars(const char* str, long long int* index) {
  while (str[*index] && is_space(str[*index])) {
    (*index)++;
  }
}

int is_space(char c) { return c && s21_strchr(SPACE_CHAR, c) != s21_NULL; }

int is_digit(char c) { return c && s21_strchr(DIGIT_CHAR, c) != s21_NULL; }

int is_hex(char c) { return (c >= 'a' && c <= 'f') || (c >= 'A' && c <= 'F'); }

int get_hex_value(char c) {
  int value = -1;

  if (is_digit(c)) {
    value = c - '0';
  } else if (is_hex(c)) {
    if (c <= 'F') {
      value = c - 'A' + 10;
    } else {
      value = c - 'a' + 10;
    }
  }

  return value;
}

int is_octal(char c) { return c >= '0' && c <= '7'; }

#include "va_helper.h"

void set_va_list(va_list* new_va) { get_va_list(new_va); }

va_list* get_va_list(va_list* new_va) {
  static va_list* va = NULL;

  if (new_va != NULL) {
    va = new_va;
  }

  return va;
}

int get_va_arg_int() { return va_arg(*get_va_list(NULL), int); }

unsigned int get_va_arg_u_int() {
  return va_arg(*get_va_list(NULL), unsigned int);
}

long int get_va_arg_long_int() { return va_arg(*get_va_list(NULL), long int); }

long unsigned int get_va_arg_long_u_int() {
  return va_arg(*get_va_list(NULL), long unsigned int);
}

double get_va_arg_double() { return va_arg(*get_va_list(NULL), double); }

long double get_va_arg_long_double() {
  return va_arg(*get_va_list(NULL), long double);
}

wchar_t get_va_arg_wchar() { return va_arg(*get_va_list(NULL), wchar_t); }

wchar_t* get_va_arg_wchar_str() { return va_arg(*get_va_list(NULL), wchar_t*); }

char* get_va_arg_str() { return va_arg(*get_va_list(NULL), char*); }

void* get_va_arg_ptr() { return va_arg(*get_va_list(NULL), void*); }
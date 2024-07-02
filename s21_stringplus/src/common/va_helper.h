#include <stdarg.h>
#include <wchar.h>

void set_va_list(va_list* new_va);
va_list* get_va_list(va_list* new_va);

int get_va_arg_int();
unsigned int get_va_arg_u_int();
long int get_va_arg_long_int();
long unsigned int get_va_arg_long_u_int();

double get_va_arg_double();
long double get_va_arg_long_double();

wchar_t get_va_arg_wchar();
wchar_t* get_va_arg_wchar_str();

char* get_va_arg_str();

void* get_va_arg_ptr();
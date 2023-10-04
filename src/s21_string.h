#ifndef S21_STRING_H
#define S21_STRING_H
#include <limits.h>
#include <stdarg.h>
#include <stdlib.h>

#include "math.h"
#include "s21_string_20_functions.h"
#include "stdbool.h"
#include "stdio.h"

#define s21_size_t unsigned long long
#define s21_NULL (void *)0
typedef struct flags {
  bool ms;
  bool pl;
  bool space;
  bool zero;
  bool grid;
} flags;
typedef struct {
  struct flags flag;
  int width;
  char length;
  int prec;
  char specifier;
} structSprintf;
void for_conv_e(long double a, int pres, structSprintf *opt_sprintf, char *line,
                int *k);
void exceptions(char *line, long double a, int *k);
void extra_zeros_end_of_line(char *rep, char *line, structSprintf *opt_sprintf,
                             int r);
void okrugl_for_g(long double *a);
void function_c(char *res, va_list args, structSprintf *opt_sprintf, int *p);
void conv_f_right_part(long long y_int, structSprintf *opt_sprintf,
                       char *float_part, char *line);
void reverse(char *str);
void if_bvery_bin_number(long double d, char *ep);
int length_of_num(long long y);
void for_conv_g(va_list args, char *line, structSprintf *opt_sprintf);
s21_size_t s21_strlen(const char *str);
int s21_sprintf(char *str, const char *format, ...);
void init_number(char **record, int *num);
void init_specifier(char **record, structSprintf *opt_sprintf);
void init_precision(char **record, structSprintf *opt_sprintf, va_list args);
void init_width(char **record, structSprintf *opt_sprintf, va_list args);
void init_flags(char **record, structSprintf *opt_sprintf);
void init_length(char **record, structSprintf *opt_sprintf);
void fill_structure(structSprintf *opt_sprintf);
void converter_x(char *res, va_list args, structSprintf *opt_sprintf, int *p);
char for_converter_x(unsigned long int a, structSprintf *opt_sprintf);
void init_res(char *res, structSprintf *opt_sprintf, va_list args, int *p);
void grid(char *line, int *k, structSprintf *opt_sprintf);
void nules_and_spaces(char *res, structSprintf *structSprintf, char *line,
                      bool ms, int *p);
void func_flags(int a, char *str1, char *line, int *k,
                structSprintf *opt_sprintf);
void system_16(unsigned long int a, char *line, int *k,
               structSprintf *opt_sprintf);
void system_8(unsigned long int a, char *line, int *k,
              structSprintf *opt_sprintf);
void num_in_length(unsigned long int *a, structSprintf *opt_sprintf);
void converter_g(char *res, va_list args, structSprintf *opt_sprintf, int *p);
bool for_converter_g(va_list args, char *line, structSprintf *opt_sprintf);
int func_spaces(char *str, structSprintf *opt_sprintf, char *line, bool g);
int func_float(structSprintf *opt_sprintf, long double a, long double y,
               long double d, char *res_str);
int num_before_point(structSprintf *opt_sprintf, long double a, char *res_str,
                     long double *result, int *kol_number);
void func_float_f(structSprintf *opt_sprintf, long double a, long double y,
                  long double d, char *res_str);
bool okrugleniye999(long double *a, structSprintf *opt_sprintf);
void converter_s(char *str, va_list args, structSprintf option, int *p);
void converter_u(char *str, va_list args, structSprintf option, int *p);
void converter_d_i(char *str, va_list args, structSprintf option, int *p);
void charArrayUnsigned(char *array, unsigned long int num, int amount);
int numberOfDigitsUnsigned(unsigned long int num);
int numberOfDigits(long int num);
bool checkSpace(structSprintf o, int amount, int numSign, int blank);
void initVal(int *prec, int *width, int *blank, int *nil, int *blankBegin,
             structSprintf o, int amount);
#endif  // S21_STRING_H

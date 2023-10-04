
#include "s21_string.h"

#include "stdarg.h"
#include "stdbool.h"

void function_c(char *res, va_list args, structSprintf *opt_sprintf, int *p) {
  char ch = (opt_sprintf->specifier != '%') ? (char)va_arg(args, int) : '%';
  int blank = opt_sprintf->width > 1 ? opt_sprintf->width - 1 : 0;
  int blankBegin = opt_sprintf->flag.ms ? 0 : blank;
  int blankEnd = opt_sprintf->flag.ms ? blank : 0;
  for (int i = 0; i < blankBegin; i++, *p = *p + 1)
    if (opt_sprintf->flag.zero)
      res[*p] = '0';
    else
      res[*p] = ' ';

  res[*p] = ch;
  *p = *p + 1;
  for (int i = 0; i < blankEnd; i++, *p = *p + 1) res[*p] = ' ';
}
int length_of_num(long long y) {
  int length = 0;
  while (y != 0) {
    length++;
    y = y / 10;
  }
  return length;
}
bool okrugleniye999(long double *a, structSprintf *opt_sprintf) {
  long double y, d;
  y = modfl(*a, &d);
  int t = 0;
  bool g = true;
  while (t++ < opt_sprintf->prec) {
    y *= 10;
  }
  t = 0;
  while (t++ < opt_sprintf->prec && g) {
    if ((long int)y % 10 != 9) g = false;
    y /= 10;
  }
  t = 1;
  long double p = 0.1;
  while (t < opt_sprintf->prec && g) {
    p = p / 10;
    t++;
  }
  if (g) *a = *a + p;
  return g;
}
void if_bvery_bin_number(long double d, char *ep) {
  int w = 0;
  bool b = false;
  long double right, left = 0;
  if (d > 18446744073709551615.0) {
    right = trunc(fmodl(d, 10000000000000));
    left = d / 10000000000000;
    b = true;
  } else {
    right = d;
  }
  for (int y = 1; (b) ? y <= 2 : y <= 1; y++) {
    if ((long int)right == 0) {
      ep[w++] = '0';
    } else {
      while ((long int)right != 0) {
        ep[w++] = (unsigned long long)right % 10 + '0';
        right = right / 10;
      }
    }
    right = left;
  }
  ep[w] = '\0';
}
void reverse(char *str) {
  int w = s21_strlen(str);
  for (int i = 0; i < w / 2; i++) {
    char temp = str[i];
    str[i] = str[w - i - 1];
    str[w - i - 1] = temp;
  }
}
void conv_f_right_part(long long y_int, structSprintf *opt_sprintf,
                       char *float_part, char *line) {
  int m = 0;
  if (opt_sprintf->prec != 0) {
    if (y_int != 0) {
      char rep_kep[128] = {'\0'};
      int t = length_of_num(y_int);
      for (; m < t; m++) {
        rep_kep[m] = (unsigned long int)(y_int % 10 + 0.05) + '0';
        y_int /= 10;
      }
      rep_kep[m] = '\0';
      reverse(rep_kep);
      s21_strcat(line, rep_kep);
    } else {
      if (y_int == 0) {
        for (; m < opt_sprintf->prec; m++) {
          float_part[m] = '0';
        }
        s21_strcat(line, float_part);
      }
    }
  }
}
bool for_converter_f(va_list args, char *line, structSprintf *opt_sprintf) {
  long double a;
  bool g = true;
  a = (opt_sprintf->length == 'L') ? va_arg(args, long double)
                                   : (double)va_arg(args, double);
  if (a < 0) g = false;
  a = (a < 0) ? a * -1 : a;
  if (a == INFINITY || a == NAN) {
    exceptions(line, a, 0);
  } else {
    bool t = okrugleniye999(&a, opt_sprintf);
    if (opt_sprintf->prec == 0) a = roundl(a);
    long double y = 0, d = 0, x = a;
    y = modfl(x, &d);
    char ep[50] = {'\0'};
    if_bvery_bin_number(d, ep);
    reverse(ep);
    s21_strcat(line, ep);
    for (int u = 0; u < opt_sprintf->prec; u++) {
      y *= 10;
    }
    if (opt_sprintf->prec != 0 || opt_sprintf->flag.grid) s21_strcat(line, ".");
    long long y_int;
    if (!t)
      y_int = roundl(y);
    else
      y_int = y;
    char float_part[51] = {'\0'};
    conv_f_right_part(y_int, opt_sprintf, float_part, line);
  }
  return g;
}
int func_spaces(char *str, structSprintf *opt_sprintf, char *line, bool g) {
  int spaces =
      (opt_sprintf->width != -1) ? opt_sprintf->width - s21_strlen(line) : 0;
  int i = 0;
  if (opt_sprintf->flag.space && !opt_sprintf->flag.pl && g) {
    str[i++] = ' ';
    spaces--;
  }
  if (!g && opt_sprintf->flag.zero) str[i++] = '-';
  if (opt_sprintf->flag.pl && g && opt_sprintf->flag.zero) str[i++] = '+';
  if (opt_sprintf->flag.pl || !g) spaces--;
  if (spaces > 0 && !opt_sprintf->flag.ms) {
    while (spaces > 0) {
      if (opt_sprintf->flag.zero)
        str[i++] = '0';
      else
        str[i++] = ' ';

      spaces--;
    }
  }
  if (!g && !opt_sprintf->flag.zero) str[i++] = '-';
  if (opt_sprintf->flag.pl && g && !opt_sprintf->flag.zero) str[i++] = '+';
  str[i] = '\0';
  return spaces;
}
void converter_g(char *res, va_list args, structSprintf *opt_sprintf, int *p) {
  opt_sprintf->prec = (opt_sprintf->prec == -1) ? 6 : opt_sprintf->prec;
  char line[1250] = {'\0'};
  char str[1250] = {'\0'};
  bool g = (opt_sprintf->specifier == 'f')
               ? for_converter_f(args, line, opt_sprintf)
               : for_converter_g(args, line, opt_sprintf);
  int spaces = func_spaces(str, opt_sprintf, line, g);
  for (int k = 0; str[k] != '\0'; k++) {
    res[*p] = str[k];
    *p = *p + 1;
  }
  for (int k = 0; line[k] != '\0'; k++) {
    res[*p] = line[k];
    *p = *p + 1;
  }
  if (spaces > 0 && opt_sprintf->flag.ms) {
    while (spaces-- > 0) {
      res[*p] = ' ';
      *p = *p + 1;
    }
  }
}
int s21_sprintf(char *str, const char *format, ...) {
  structSprintf opt_sprintf;
  fill_structure(&opt_sprintf);
  va_list args;
  va_start(args, format);
  char *record = s21_NULL;
  int return_size = -1;
  if (!!s21_strlen(format))
    record = (char *)calloc((s21_strlen(format) + 1), sizeof(char));
  if (record) {
    int p = 0;
    char res[2048] = {'\0'};
    char *ptr = record;
    s21_strcpy(record, format);
    while (*record != '\0') {
      if (*record == '%') {
        record++;
        init_flags(&record, &opt_sprintf);
        init_width(&record, &opt_sprintf, args);
        init_precision(&record, &opt_sprintf, args);
        init_length(&record, &opt_sprintf);
        init_specifier(&record, &opt_sprintf);
        init_res(res, &opt_sprintf, args, &p);
        fill_structure(&opt_sprintf);
      } else {
        while (*record != '%' && *record != '\0') {
          res[p] = *record;
          p++;
          record++;
        }
      }
    }
    res[p] = '\0';
    if (record != s21_NULL) record = ptr;
    return_size = (p == 0) ? 0 : p--;
    for (p = 0; res[p] != '\0'; p++) {
      *str = res[p];
      str++;
    }
    va_end(args);
    if (record != s21_NULL) free(record);
  }
  *str = '\0';
  return return_size;
}
void init_res(char *res, structSprintf *opt_sprintf, va_list args, int *p) {
  switch (opt_sprintf->specifier) {
    case 'd':
    case 'i':
      converter_d_i(res, args, *opt_sprintf, p);
      break;
    case 'u':
      converter_u(res, args, *opt_sprintf, p);
      break;
    case 'f':
      converter_g(res, args, opt_sprintf, p);
      break;
    case 'c':
    case '%':
      function_c(res, args, opt_sprintf, p);
      break;
    case 'g':
    case 'G':
      converter_g(res, args, opt_sprintf, p);
      break;
    case 'o':
    case 'x':
    case 'X':
      converter_x(res, args, opt_sprintf, p);
      break;
    case 's':
      converter_s(res, args, *opt_sprintf, p);
  }
}

void fill_structure(structSprintf *opt_sprintf) {
  opt_sprintf->width = -1;
  opt_sprintf->prec = -1;
  opt_sprintf->specifier = -1;
  opt_sprintf->length = -1;
  opt_sprintf->flag.ms = false;
  opt_sprintf->flag.pl = false;
  opt_sprintf->flag.space = false;
  opt_sprintf->flag.zero = false;
  opt_sprintf->flag.grid = false;
}
void init_flags(char **record, structSprintf *opt_sprintf) {
  while (**record == '-' || **record == '+' || **record == ' ' ||
         **record == '#' || **record == '0') {
    switch (**record) {
      case '-':
        opt_sprintf->flag.ms = true;
        break;
      case '+':
        opt_sprintf->flag.pl = true;
        break;
      case ' ':
        opt_sprintf->flag.space = true;
        break;
      case '0':
        opt_sprintf->flag.zero = true;
        break;
      case '#':
        opt_sprintf->flag.grid = true;
        break;
    }
    (*record)++;
  }
}

void grid(char *line, int *k, structSprintf *opt_sprintf) {
  if (opt_sprintf->flag.grid == true) {
    switch (opt_sprintf->specifier) {
      case 'x':
        line[*k] = '0';
        *k = *k + 1;
        line[*k] = 'x';
        break;
      case 'X':
        line[*k] = '0';
        *k = *k + 1;
        line[*k] = 'X';
        break;
      case 'o':
        line[*k] = '0';
        break;
    }
    *k = *k + 1;
  }
}
void func_flags(int a, char *str1, char *line, int *k,
                structSprintf *opt_sprintf) {
  if (opt_sprintf->flag.grid) {
    if (a != 0) {
      grid(line, k, opt_sprintf);
    }
  } else {
    if (opt_sprintf->flag.zero) {
      int s = (opt_sprintf->prec == -1) ? 0 : opt_sprintf->prec;
      int spaces = opt_sprintf->width - s - s21_strlen(str1);
      while (spaces > 0) {
        line[*k] = '0';
        *k = *k + 1;
        spaces--;
      }
    }
  }
}
void num_in_length(unsigned long int *a, structSprintf *opt_sprintf) {
  switch (opt_sprintf->length) {
    case 'h':
      *a = (unsigned short)*a;
      break;
    case 'l':
      *a = (unsigned long)*a;
      break;
    default:
      *a = (unsigned int)*a;
  }
}
void system_8(unsigned long int a, char *line, int *k,
              structSprintf *opt_sprintf) {
  char str1[50] = {'\0'};
  int i = 0;
  unsigned long int res = 9;
  int ost = 0;
  while (res >= 8) {
    res = a / 8;
    ost = a % 8;
    str1[i] = ost + '0';
    if (res < 8 && (res != 0 || ost != 0)) {
      i++;
      str1[i] = res + '0';
    }
    i++;
    a = res;
  }
  str1[i] = '\0';
  i--;
  func_flags(a, str1, line, k, opt_sprintf);
  int s = opt_sprintf->prec - s21_strlen(str1) - s21_strlen(line);
  for (int j = 0; s - j > 0; j++, *k = *k + 1) {
    line[*k] = '0';
  }
  for (; i >= 0; i--, *k = *k + 1) {
    line[*k] = str1[i];
  }
}
void system_16(unsigned long int a, char *line, int *k,
               structSprintf *opt_sprintf) {
  char str1[50] = {'\0'};
  int i = 0;
  unsigned long int res = 17;
  unsigned long int ost = 0;
  while (res >= 16) {
    res = a / 16;
    ost = a % 16;
    if (ost < 10)
      str1[i] = ost + '0';
    else
      str1[i] = for_converter_x(ost, opt_sprintf);
    if (res < 16 && (res != 0 || ost != 0)) {
      i++;
      if (res < 10)
        str1[i] = res + '0';
      else
        str1[i] = for_converter_x(res, opt_sprintf);
    }
    i++;
    a = res;
  }
  str1[i] = '\0';
  i--;
  func_flags(a, str1, line, k, opt_sprintf);
  int s = opt_sprintf->prec - s21_strlen(str1);
  for (int j = 0; s - j > 0; j++, *k = *k + 1) {
    line[*k] = '0';
  }
  for (; i >= 0; i--, *k = *k + 1) {
    line[*k] = str1[i];
  }
}
void converter_x(char *res, va_list args, structSprintf *opt_sprintf, int *p) {
  unsigned long int a = va_arg(args, unsigned long int);
  num_in_length(&a, opt_sprintf);
  char line[50] = {'\0'};
  int k = 0;
  if (a != 0 || opt_sprintf->prec != 0) {
    if (opt_sprintf->specifier == 'x' || opt_sprintf->specifier == 'X')
      system_16(a, line, &k, opt_sprintf);
    if (opt_sprintf->specifier == 'o') system_8(a, line, &k, opt_sprintf);
  }
  line[k] = '\0';
  nules_and_spaces(res, opt_sprintf, line, true, p);
  for (k = 0; line[k] != '\0'; k++) {
    res[*p] = line[k];
    *p = *p + 1;
  }
  nules_and_spaces(res, opt_sprintf, line, false, p);
}
void nules_and_spaces(char *res, structSprintf *opt_sprintf, char *line,
                      bool before, int *p) {
  int spaces = 0;
  if (opt_sprintf->width > 0 && opt_sprintf->prec > 0) {
    spaces = opt_sprintf->width - opt_sprintf->prec;
  } else {
    if (opt_sprintf->width > 0) spaces = opt_sprintf->width - s21_strlen(line);
  }
  int nules =
      (opt_sprintf->prec > 0) ? opt_sprintf->prec - s21_strlen(line) : 0;
  while (before && !opt_sprintf->flag.ms && spaces > 0) {
    res[*p] = ' ';
    *p = *p + 1;
    spaces--;
  }

  while (!before && opt_sprintf->flag.ms && spaces > 0) {
    res[*p] = ' ';
    *p = *p + 1;
    spaces--;
  }
  while (before && nules > 0) {
    res[*p] = '0';
    *p = *p + 1;
    nules--;
  }
}
char for_converter_x(unsigned long int a, structSprintf *structSprintf) {
  char ch = ' ';
  switch (a) {
    case 10:
      ch = (structSprintf->specifier == 'X') ? 'A' : 'a';
      break;
    case 11:
      ch = (structSprintf->specifier == 'X') ? 'B' : 'b';
      break;
    case 12:
      ch = (structSprintf->specifier == 'X') ? 'C' : 'c';
      break;
    case 13:
      ch = (structSprintf->specifier == 'X') ? 'D' : 'd';
      break;
    case 14:
      ch = (structSprintf->specifier == 'X') ? 'E' : 'e';
      break;
    case 15:
      ch = (structSprintf->specifier == 'X') ? 'F' : 'f';
      break;
  }
  return ch;
}

void init_width(char **record, structSprintf *opt_sprintf, va_list args) {
  int num = 0;
  if (**record == '*') {
    num = va_arg(args, int);
    (*record)++;
  } else {
    init_number(record, &num);
  }
  opt_sprintf->width = num;
}
void init_precision(char **record, structSprintf *opt_sprintf, va_list args) {
  int num = 0;
  if (**record == '.') {
    (*record)++;
    if (**record == '*') {
      num = va_arg(args, int);
      opt_sprintf->prec = num;
      (*record)++;
    } else {
      if (**record >= 48 && **record <= 57) {
        init_number(record, &num);
        opt_sprintf->prec = num;
      } else {
        opt_sprintf->prec = 0;
      }
    }
  }
}
void init_length(char **record, structSprintf *opt_sprintf) {
  if (**record == 'h' || **record == 'l' || **record == 'L') {
    opt_sprintf->length = **record;
    (*record)++;
  }
}
void init_specifier(char **record, structSprintf *opt_sprintf) {
  if (**record == 'c' || **record == 'd' || **record == 'i' ||
      **record == 'f' || **record == 's' || **record == 'u' ||
      **record == '%' || **record == 'g' || **record == 'G' ||
      **record == 'e' || **record == 'E' || **record == 'x' ||
      **record == 'X' || **record == 'o' || **record == 'n' ||
      **record == 'p') {
    opt_sprintf->specifier = **record;
    (*record)++;
  }
}

void init_number(char **record, int *num) {
  char number[30] = {'\0'};
  int i = 0;
  int k = 0;
  while (**record >= 48 && **record <= 57) {
    k = 1;
    number[i] = **record;
    i++;
    (*record)++;
  }
  number[i] = '\0';
  if (k == 1) {
    while (i != 0) {
      i--;
      *num = *num + (number[i] - '0') * k;
      k = k * 10;
    }
  }
}
void okrugl_for_g(long double *a) {
  if ((int)fmodl((*a * 10), 10) == 9 && (int)fmodl((*a * 100), 10) == 9 &&
      (int)fmodl((*a * 1000), 10) == 9 && (int)fmodl((*a * 10000), 10) == 9)
    *a = *a + 0.01;
}
void func_eksponenta(long double a, structSprintf *opt_sprintf, char *line,
                     int *k) {
  long double y = 0, d = 0;
  y = modfl(a, &d);
  int r = opt_sprintf->prec;
  if (opt_sprintf->prec == 0 || r == 1) {
    line[*k++] = (int)roundl(a) + '0';
    r--;
  } else {
    line[*k++] = (int)d + '0';
    r--;
  }
  char rep[80] = {'\0'};
  int u = 0;
  if (r > 0 || opt_sprintf->flag.grid) {
    y = y * 10;
    while (r > 0) {
      a = y;
      if (r == 1) {
        d = fmodl(roundl(a), 10);
      } else {
        y = modfl(a, &d);
        y = y * 10;
        okrugl_for_g(&y);
      }
      if (roundl(y) != 0 || d != 0 || opt_sprintf->flag.grid)
        rep[u++] = (int)d + '0';
      r--;
    }
  }
  rep[u] = '\0';
  extra_zeros_end_of_line(rep, line, opt_sprintf, r);
}
void extra_zeros_end_of_line(char *rep, char *line, structSprintf *opt_sprintf,
                             int r) {
  int u = s21_strlen(rep);
  int kol_ohne_nules = s21_strlen(rep) - 1;
  while (rep[u--] == '0' && u != -1 && !opt_sprintf->flag.grid) {
    kol_ohne_nules--;
  }
  u = 0;
  if (kol_ohne_nules > -1 || opt_sprintf->flag.grid) {
    s21_strcat(line, ".");
    s21_strncat(line, rep, kol_ohne_nules + 1);
  }
  while (opt_sprintf->flag.grid && r-- > 0) {
    s21_strcat(line, "0");
  }
}
void exceptions(char line[], long double a, int *k) {
  if (a == 0) s21_strcat(line, "0");
  if (a == INFINITY) s21_strcat(line, "inf");
  if (a == NAN) s21_strcat(line, "nan");
  *k = s21_strlen(line) + 1;
}
void for_conv_e(long double a, int pres, structSprintf *opt_sprintf, char *line,
                int *k) {
  while (a < 1) {
    a = a * 10;
  }
  while (a >= 10) {
    a = a / 10;
  }
  func_eksponenta(a, opt_sprintf, line, k);
  *k = s21_strlen(line);
  if (opt_sprintf->specifier == 'g') s21_strcat(line, "e");
  if (opt_sprintf->specifier == 'G') s21_strcat(line, "E");
  if (pres < 0)
    s21_strcat(line, "-");
  else
    s21_strcat(line, "+");
  pres = (pres < 0) ? (-1) * pres : pres;
  char tr[2] = "";
  tr[0] = pres / 10 + '0';
  tr[1] = '\0';
  s21_strcat(line, tr);
  tr[0] = (pres % 10) + '0';
  tr[1] = '\0';
  s21_strcat(line, tr);
  *k = s21_strlen(line);
}
bool for_converter_g(va_list args, char *line, structSprintf *opt_sprintf) {
  long double a;
  bool g = true;
  a = (opt_sprintf->length == 'L') ? va_arg(args, long double)
                                   : (double)va_arg(args, double);
  if (a < 0) g = false;
  int k = 0;
  a = (a < 0) ? a * -1 : a;
  if (a == 0 || a == INFINITY || a == NAN) {
    exceptions(line, a, &k);
  } else {
    okrugl_for_g(&a);
    long double y = 0, d = 0, x = a;
    int pres = 0;
    while (d <= 0 || d >= 10) {
      y = modfl(x, &d);
      if (d <= 0) {
        x = x * 10;
        pres--;
      } else {
        if (d >= 10) {
          x /= 10;
          pres++;
        }
      }
    }
    if ((opt_sprintf->prec > pres && pres >= -4) ||
        opt_sprintf->specifier == 'f') {
      k = func_float(opt_sprintf, a, y, d, line);
    } else {
      for_conv_e(a, pres, opt_sprintf, line, &k);
    }
  }
  return g;
}

int func_float(structSprintf *opt_sprintf, long double a, long double y,
               long double d, char *res_str) {
  long double result;
  int kol_number = opt_sprintf->prec;
  num_before_point(opt_sprintf, a, res_str, &result, &kol_number);
  char rep[150] = {'\0'};
  int u = 0;
  result = result * 10;
  y = result * 10, d = 0;
  while (kol_number > 0 &&
         (d != 0 || y != 0 || opt_sprintf->specifier == 'f')) {
    if (y != 0 && d != 0) result = y;
    if (kol_number == 1) {
      d = fmodl(roundl(result), 10);
    } else {
      y = modfl(result, &d);
      y = y * 10;
      if ((int)fmodl((y * 10), 10) == 9 && (int)fmodl((y * 100), 10) == 9 &&
          (int)fmodl((y * 1000), 10) == 9 && (int)fmodl((y * 10000), 10) == 9)
        y = y + 0.01;
    }
    if ((y != 0 && d != 0) || opt_sprintf->specifier == 'f')
      rep[u++] = ((int)d % 10) + '0';
    kol_number--;
  }
  rep[u] = '\0';
  int kol_ohne_nules = s21_strlen(rep) - 1;
  u--;
  while (u >= 0 && rep[u--] == '0' && u != -1 && !opt_sprintf->flag.grid) {
    kol_ohne_nules--;
  }
  u = 0;
  if (kol_ohne_nules > -1 || opt_sprintf->flag.grid) {
    s21_strcat(res_str, ".");
    s21_strncat(res_str, rep, kol_ohne_nules + 1);
  }
  while (opt_sprintf->flag.grid && kol_number > 0) {
    s21_strcat(res_str, "0");
    kol_number--;
  }
  int k = s21_strlen(res_str);
  return k;
}

int num_before_point(structSprintf *opt_sprintf, long double a, char *res_str,
                     long double *result, int *kol_number) {
  long double c = a;
  int num_before_point = 0;
  while (c >= 1) {
    *kol_number =
        (opt_sprintf->specifier == 'g' || opt_sprintf->specifier == 'G')
            ? *kol_number - 1
            : *kol_number;
    num_before_point++;
    c = c / 10;
  }
  int k = 0;
  *result = roundl(a * powl(10, *kol_number)) / powl(10, *kol_number);
  *result = (opt_sprintf->length == 'L') ? *result : (double)*result;
  if (*result >= 1) {
    *result = *result / pow(10, --num_before_point);
    res_str[k++] = truncl(*result) + '0';
    while (num_before_point-- != 0) {
      *result = *result * 10;
      res_str[k++] = truncl((int)*result % 10) + '0';
    }
  } else {
    res_str[k++] = '0';
  }
  return k;
}

void converter_d_i(char *str, va_list args, structSprintf o, int *p) {
  long int num = va_arg(args, long int);
  num = o.length == 'h' ? (short)num : o.length == 'l' ? num : (int)num;
  int amount = numberOfDigits(num);
  char *charNum;
  int sign = num < 0 ? -1 : 1;
  num *= sign;
  char array[2048] = {'\0'};
  charArrayUnsigned(array, num, amount);
  charNum = (num == LONG_MIN) ? "9223372036854775808" : array;
  int prec = 0, width = 0, blank = 0, nil = 0, blankBegin = 0;
  initVal(&prec, &width, &blank, &nil, &blankBegin, o, amount);
  nil = o.flag.zero ? nil + blankBegin : nil;
  if (o.flag.zero && o.width >= o.prec &&
      (o.flag.pl || o.flag.space || sign < 0))
    nil--;
  blankBegin = o.flag.zero ? 0 : blankBegin;
  int blankEnd = o.flag.ms ? blank : 0;
  int blankValue = o.flag.ms && (o.flag.pl || o.flag.space || sign < 0) ? 1 : 0;
  for (int i = 0; i < blankBegin - 1; i++, *p += 1) str[*p] = ' ';
  if (o.specifier != 'u' && o.flag.pl && sign > 0) {
    str[*p] = '+';
    *p += 1;
  }
  if (sign < 0) {
    str[*p] = '-';
    *p += 1;
  } else if (checkSpace(o, amount, sign, blank)) {
    str[*p] = ' ';
    *p += 1;
  }
  for (int i = blankBegin; i < nil + blankBegin; i++, *p += 1) str[*p] = '0';
  if (o.flag.zero && o.width >= o.prec &&
      (o.flag.pl || o.flag.space || sign < 0))
    nil++;
  if (num == 0 && o.prec == 0 && !o.flag.ms && !o.flag.pl && !o.flag.grid) {
    if (o.width > 0) {
      str[*p] = ' ';
      *p += 1;
    }
  } else {
    for (int i = nil + blankBegin; i < width - blankEnd; i++, *p += 1)
      str[*p] = charNum[i - nil - blankBegin];
  }
  for (int i = width - blankEnd; i < width - blankValue; i++, *p += 1)
    str[*p] = ' ';
}
void initVal(int *prec, int *width, int *blank, int *nil, int *blankBegin,
             structSprintf o, int amount) {
  *prec = o.prec > amount ? o.prec : amount;
  *width = o.width > *prec ? o.width : *prec;
  *blank = o.width > *prec ? o.width - *prec : 0;
  *nil = o.prec > amount ? o.prec - amount : 0;
  *blankBegin = o.flag.ms ? 0 : *blank;
}
bool checkSpace(structSprintf o, int amount, int sign, int blank) {
  return ((o.flag.space && !o.flag.pl && sign > 0) ||
          (blank != 0 && !o.flag.pl && !o.flag.ms && !o.flag.zero)) ||
         ((o.flag.pl || o.flag.space) && (o.width > o.prec) &&
          (o.width > amount));
}

void converter_u(char *str, va_list args, structSprintf o, int *p) {
  long long int num = va_arg(args, long long int);
  int amount = numberOfDigitsUnsigned(num);
  char *charNum;
  char array[2048] = {'\0'};
  charArrayUnsigned(array, num, amount);
  charNum = (num == LONG_MIN) ? "9223372036854775808" : array;
  int prec = o.prec > amount ? o.prec : amount;
  int width = o.width > prec ? o.width : prec;
  int blank = o.width > prec ? o.width - prec : 0;
  int nil = o.prec > amount ? o.prec - amount : 0;
  int blankBegin = o.flag.ms ? 0 : blank;
  nil = o.flag.zero ? nil + blankBegin : nil;
  if (o.flag.zero && o.width >= o.prec && (o.flag.pl || o.flag.space)) nil--;
  blankBegin = o.flag.zero ? 0 : blankBegin;
  int blankEnd = o.flag.ms ? blank : 0;
  int blankValue = o.flag.ms && (o.flag.pl || o.flag.space) ? 1 : 0;
  for (int i = 0; i < blankBegin - 1; i++, *p += 1) str[*p] = ' ';
  if (o.specifier != 'u' && o.flag.pl) {
    str[*p] = '+';
    *p += 1;
  }
  if ((blank != 0 && !o.flag.pl && !o.flag.ms && !o.flag.zero) ||
      (!o.flag.ms && (o.flag.pl || o.flag.space) && o.width > o.prec &&
       o.width > amount)) {
    str[*p] = ' ';
    *p += 1;
  }
  for (int i = blankBegin; i < nil + blankBegin; i++, *p += 1) str[*p] = '0';
  if (o.flag.zero && o.width >= o.prec && (o.flag.pl || o.flag.space)) nil++;
  if (num == 0 && o.prec == 0 && !o.flag.ms && !o.flag.pl && !o.flag.grid) {
    if (o.width > 0) {
      str[*p] = ' ';
      *p += 1;
    }
  } else {
    for (int i = nil + blankBegin; i < width - blankEnd; i++, *p += 1)
      str[*p] = charNum[i - nil - blankBegin];
  }
  for (int i = width - blankEnd; i < width - blankValue; i++, *p += 1)
    str[*p] = ' ';
  if ((o.flag.ms && (o.flag.pl || o.flag.space) && o.width > o.prec &&
       o.width > amount)) {
    str[*p] = ' ';
    *p += 1;
  }
}

void converter_s(char *str, va_list args, structSprintf o, int *p) {
  char *charArray;
  charArray = va_arg(args, char *);
  if (!charArray) charArray = "(null)";
  int size = 0;
  size = s21_strlen(charArray);
  size = o.prec < size && o.prec != -1 ? o.prec : size;
  int blank = o.width > size ? o.width - size : 0;
  int blankBegin = o.flag.ms ? 0 : blank;
  int zero = o.flag.zero && o.width - size > 0 ? o.width - size : 0;
  int blankEnd = o.flag.ms ? blank : 0;
  for (int i = 0; i < blankBegin - zero; i++) {
    str[*p] = ' ';
    *p += 1;
  }
  for (int i = 0; i < zero; i++) {
    str[*p] = '0';
    *p += 1;
  }
  for (int i = 0; i < size; i++) {
    str[*p] = charArray[i];
    *p += 1;
  }
  for (int i = 0; i < blankEnd - zero; i++) {
    str[*p] = ' ';
    *p += 1;
  }
}
void charArrayUnsigned(char *array, unsigned long int num, int amount) {
  for (int i = amount - 1; i >= 0; i--) {
    array[i] = (char)(num % 10 + '0');
    num /= 10;
  }
  array[amount] = '\0';
}
int numberOfDigitsUnsigned(unsigned long int num) {
  int count = 0;
  if (num == 0) count = 1;
  while (num != 0) {
    num /= 10;
    count++;
  }
  return count;
}
int numberOfDigits(long int num) {
  int count = 0;
  if (num == 0) count = 1;
  while (num != 0) {
    num /= 10;
    count++;
  }
  return count;
}

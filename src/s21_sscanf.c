#include "s21_sscanf.h"

int s21_sscanf(char *buf, char *format, ...) {
  int result = 0;
  char *str = s21_NULL;
  if (!!s21_strlen(buf)) str = malloc((s21_strlen(buf) + 1) * sizeof(char));
  if (!str || !(*buf))
    result = -1;
  else {
    int suc = 0, wid = 0, minus = 0, count = 0, br = 0;
    char *ptr = str;
    s21_strcpy(str, buf);
    Param form = {0};
    strInfo strinfo;
    char Specifiers[40] = {"cdieEfgGosuxXpnlLh*1234567890%\0"};
    strinfo.Success = &suc;
    strinfo.minus = &minus;
    strinfo.count = &count;
    form.width = &wid;
    va_list args;
    va_start(args, *format);
    while (1) {
      form.Error = form.continu = form.Type = form.Ignore = form.Format =
          noIgnore;
      *form.width = *strinfo.Success = *strinfo.minus = 0;
      parsing(&format, Specifiers, &form, &str, strinfo);
      if (form.continu == 1) continue;
      if (form.Error == 1) {
        if (result == 0) result = -1;
        br = 1;
      }
      if (!br) {
        s21_strcpy(strinfo.paramString, format);
        if (*form.width == 0) *form.width = -10;
        NEW(args, form, strinfo, &str);  // Запись в args значения из buf
        if (*strinfo.Success == 1) {
          result += 1;
        } else if (*strinfo.Success != -2) {
          if (*strinfo.Success == -1 && result == 0) {
            result = -1;
          }
          br = 1;
        }
        if (!br) {
          if (form.Ignore != -1 || form.Type == noIgnore || form.Char == '%')
            result -= 1;
          if (s21_strlen(format) == 0) br = 1;
        }
      }
      if (br == 1) break;
    }
    va_end(args);
    str = ptr;
    free(str);
  }
  return result;
}

int parsing(char **format, char *Spec, Param *form, char **str, strInfo value) {
  int result = 0, br = 0;
  SkipParsing(value, format, str);
  if (**format == '%') {
    *format += 1;
    for (int n = 0; Spec[n] != '\0'; n++) {
      if (**format == Spec[n]) {
        ParamInput(
            form,
            Spec[n]);  // тут мы определяем тип формы, которую нужно выполнить
        *format += 1;
        if (Spec[n] == 'l' || Spec[n] == 'L' || Spec[n] == 'h' ||
            Spec[n] == '*' || (Spec[n] >= '0' && Spec[n] <= '9')) {
          n = -1;
        } else
          break;
      }
    }
  } else if (s21_strlen(*format) == 0) {
  } else {
    while (s21_strlen(*format) != 0) {
      if (**format == ' ' || **format == '%') {
        form->continu = 1;
        br = 1;
      }
      if (!br) {
        if (**format != **str) {
          form->Error = 1;
          br = 1;
        }
        if (!br) {
          (*format)++;
          (*str)++;
          *value.count += 1;
        }
      }
      if (br == 1) break;
    }
  }
  if (form->Error == 1) result = noIgnore;
  return result;
}

void SkipParsing(strInfo value, char **format, char **str) {
  int isNotVisit = 0;
  if (**format == ' ' || (**format >= 7 && **format <= 13)) {
    isNotVisit = 1;
    while (**format == ' ' || (**format >= 7 && **format <= 13)) {
      (*format)++;
    }
  }
  if (isNotVisit == 1) {
    while (**str == ' ' || (**str >= 7 && **str <= 13)) {
      (*str)++;
      *value.count += 1;
    }
  }
}

void TypeCounter(va_list argv, strInfo value, char **str, Param form) {
  int x1 = 0;
  short x2 = 0;
  int8_t x3 = 0;
  if (s21_strstr(value.paramString, "%") == s21_NULL) TrashSkip(str, value);
  if (form.Format == 208) {
    value.Un = &x3;
    if (form.Ignore == noIgnore) {
      value.Un = va_arg(argv, int8_t *);
      *value.Un = *value.count;
    }
  } else if (form.Format == 104) {
    value.Short = &x2;
    if (form.Ignore == noIgnore) {
      value.Short = va_arg(argv, short *);
      *value.Short = *value.count;
    }
  } else {
    value.Decimal = &x1;
    if (form.Ignore == noIgnore) {
      value.Decimal = va_arg(argv, int *);
      *value.Decimal = *value.count;
    }
  }
  *value.Success = -2;
}

void TrashSkip(char **str, strInfo value) {
  while (**str == ' ') {
    *str += 1;
    *value.count += 1;
  }
}

void NEW(va_list argv, Param form, strInfo value, char **str) {
  if (form.Type == TypeOfInt) {
    TypeInt(argv, value, form, str);
  } else if (form.Type == TypeOfFloat) {
    TypeFloat(argv, value, form, str);
  } else if (form.Type == TypeOfChar) {
    TypeChar(argv, value, form, str);
  } else if (form.Type == TypeOfString) {
    TypeString(argv, value, form, str);
  } else if (form.Type == TypeOfPointer) {
    TypePointer(argv, value, form, str);
  } else if (form.Type == TypeOfCount) {
    TypeCounter(argv, value, str, form);
  }
}

void TypePointer(va_list argv, strInfo value, Param form, char **str) {
  long long int i = 0;
  value.Pointer = &i;
  char arr[17] = "\0";
  if (form.Ignore == noIgnore) value.Pointer = va_arg(argv, void *);
  int counter = 0, br = 0;
  TrashSkip(str, value);
  for (;;) {
    if ((s21_strlen(*str) > 3) && *(*str) == 'N' && *(*str + 1) == 'U' &&
        *(*str + 2) == 'L' && *(*str + 3) == 'L') {
      *value.Pointer = 0x0;
      for (int j = 0; j < 4; j++) {
        (*str)++;
        Plus(value, &counter);
      }
      br = 1;
    }
    if (!br) {
      if (((**str == '0' && (i == 0 || arr[0] == '-' || arr[0] == '+')) ||
           (**str == 'x' &&
            (counter == 1 ||
             (counter == 2 && i == 1 && (*arr == '-' || *arr == '+')))))) {
        Plus(value, &counter);
      } else if ((**str >= '0' && **str <= '9') ||
                 (**str >= 'a' && **str <= 'f') ||
                 (**str >= 'A' && **str <= 'F') || **str == '-' ||
                 **str == '+') {
        arr[i] = **str;
        i++;
        Plus(value, &counter);
        if (i == 17) {
          for (i = 0; i < 17; i++) arr[i] = 'f';
          br = 1;
        }
      } else {
        br = 1;
      }
      if (br == 1 || counter == *form.width || *(*str + 1) == '\0') break;
      *(str) += 1;
    }
  }
  arr[i] = '\0';
  *value.Success = 1;
  form.Type = 5;
  if ((i > 1 && *(arr + 1) >= '0') || (i == 0 && *arr >= '0') ||
      (i == 1 && *arr >= '0')) {
  } else {
    arr[0] = 0;
    arr[1] = '\0';
  }
  ParseInt(value, arr, form);
}

void Plus(strInfo value, int *counter) {
  *counter += 1;
  *value.count += 1;
}

void TypeString(va_list argv, strInfo value, Param form, char **str) {
  wchar_t X[150];
  char st[150];
  if (form.Format == 'l') {
    if (form.Ignore == noIgnore)
      value.wstring = va_arg(argv, wchar_t *);
    else
      value.wstring = X;
  } else {
    if (form.Ignore == noIgnore)
      value.String = va_arg(argv, char *);
    else
      value.String = st;
  }
  ParseString(str, value, form);
}

void ParseString(char **str, strInfo value, Param form) {
  int i = 0, count = 0, error = 0, br = 0;
  while (**str == ' ' || (**str >= 7 && **str <= 13)) {
    IncrementChar(str, &count, value);
  }
  for (;;) {
    if (**str == '\0' || **str == ' ' || (**str >= 7 && **str <= 13)) {
      if (i == 0) error = 1;
      if (form.Format == 'l') {
        value.wstring[i] = '\0';
      } else {
        value.String[i] = '\0';
      }
      br = 1;
    }
    if (!br) {
      if (form.Format == 'l')
        value.wstring[i] = **str;
      else
        value.String[i] = **str;
      i++;
      IncrementChar(str, &count, value);
      if (*form.width == count) {
        if (form.Format == 'l')
          value.wstring[i] = '\0';
        else
          value.String[i] = '\0';
        br = 1;
      }
    }
    if (br == 1) {
      break;
    }
  }
  if (error == 1)
    *value.Success = 0;
  else
    *value.Success = 1;
}

void TypeFloat(va_list argv, strInfo value, Param form, char **str) {
  float f = 0;
  double lf = 0;
  long double Lf = 0;
  if (form.Format == 'L') {
    value.llf = &Lf;
    if (form.Ignore == noIgnore) value.llf = va_arg(argv, long double *);
  } else if (form.Format == 'l') {
    value.lf = &lf;
    if (form.Ignore == noIgnore) value.lf = va_arg(argv, double *);
  } else {
    value.F = &f;
    if (form.Ignore == noIgnore) value.F = va_arg(argv, float *);
  }
  ParseFloat(str, value, form);
}

void TypeInt(va_list argv, strInfo value, Param form, char **str) {
  int d = 0;
  short sh = 0;
  long int ld = 0;
  long long int lld = 0;
  int8_t u = 0;
  if (form.Format == 216) {
    form.Type = 4;
    value.llint = &lld;
    if (form.Ignore == noIgnore) value.llint = va_arg(argv, long long int *);
  } else if (form.Format == 208) {
    form.Type = 6;
    value.Un = &u;
    if (form.Ignore == noIgnore) value.Un = va_arg(argv, int8_t *);
  } else if (form.Format == 108) {
    form.Type = 3;
    value.lint = &ld;
    if (form.Ignore == noIgnore) value.lint = va_arg(argv, long int *);
  } else if (form.Format == 104) {
    form.Type = 1;
    value.Short = &sh;
    if (form.Ignore == noIgnore) value.Short = va_arg(argv, short *);
  } else {
    form.Type = 2;
    value.Decimal = &d;
    if (form.Ignore == noIgnore) value.Decimal = va_arg(argv, int *);
  }
  Atoi(str, value, form);
}

void ParseFloat(char **str, strInfo value, Param form) {
  int minus = 0, plus = 0, count = 0, br = 0;
  *value.Success = 1;
  SkipFloat(value, form, str, &plus, &minus, &br, &count);
  if (!br) {
    long double res;
    if (ToLower(**str) == 'n' && ToLower(*(*str + 1)) == 'a' &&
        ToLower(*(*str + 2)) == 'n') {
      res = 0.0 / 0.0;
      *str += 3;
      *value.count += 3;
    } else if (ToLower(**str) == 'i' && ToLower(*(*str + 1)) == 'n' &&
               ToLower(*(*str + 2)) == 'f') {
      if (minus == 1) {
        res = -1.0 / 0.0;
      } else {
        res = 1.0 / 0.0;
      }
      minus = 0;
      *str += 3;
      *value.count += 3;
    } else {
      if (minus == 1 || plus == 1) *value.minus = 1;
      res = Atof(str, value, form);
    }
    if (*value.count == 0) *value.Success = 0;
    if (*value.Success == 1) {
      if (form.Format == 'L') {
        *value.llf = res;
      } else if (form.Format == 'l') {
        *value.lf = res;
      } else {
        *value.F = res;
      }
      if (minus == 1) {
        if (form.Format == 'L') {
          *value.llf = -(*value.llf);
        } else if (form.Format == 'l') {
          *value.lf = -(*value.lf);
        } else {
          *value.F = -(*value.F);
        }
      }
    }
  }
}

void SkipFloat(strInfo value, Param form, char **str, int *plus, int *minus,
               int *br, int *count) {
  while (**str == ' ' || (**str >= 7 && **str <= 13)) {
    (*str)++;
    *value.count += 1;
  }
  if (*form.width == 1 && (**str < '0' || **str > '9')) {
    *value.Success = 0;
  } else {
    while (**str == '+' || **str == '-') {
      if (**str == '+') {
        (*plus)++;
      }
      if (**str == '-') {
        (*minus)++;
      }
      IncrementChar(str, count, value);
      if (*form.width == *count) {
        break;
      }
    }
    if (*plus > 1 || *minus > 1 || (*plus > 0 && *minus > 0)) {
      *value.Success = 0;
      *br = 1;
    }
  }
}

long double Atof(char **str, strInfo value, Param form) {
  long double a = 0.0;
  int e = 0, c = **str, count = -1, prov = 0, prov_ch = 0, pp = 1;
  if (**str != '\0') *str += 1;
  Afotblock_1(value, form, &pp, &prov_ch, &count, &prov, str, &c, &a);
  if (!prov) {
    Afotblock_2(value, form, &c, &count, &prov, &prov_ch, &e, str, &a);
  }
  if (count == 0 || prov_ch == 0) *value.Success = 0;
  return a;
}

void Afotblock_1(strInfo value, Param form, int *pp, int *prov_ch, int *count,
                 int *prov, char **str, int *c, long double *a) {
  if (*value.minus == 1) {
    *count = 1;
    *value.minus = 0;
    *pp = 0;
  }
  while (*c != '\0' && (*c >= '0' && *c <= '9')) {
    if (*prov_ch == 0) *prov_ch = 1;
    *a = *a * 10.0 + (*c - '0');
    *c = **str;
    if (*pp == 0 || *count == -1) {
      if (*count == -1) {
        *count = 1;
        *value.count += 1;
      } else {
        *count += 1;
        *value.count += 1;
        *pp = 1;
      }
    }
    if (*form.width == *count) {
      *prov = 1;
      break;
    }
    if (**str != '\0' && (**str >= '0' && **str <= '9'))
      IncrementChar(str, count, value);
  }
}

void Afotblock_2(strInfo value, Param form, int *c, int *count, int *prov,
                 int *prov_ch, int *e, char **str, long double *a) {
  if (*c == '.') {
    if (*count == 1) *value.count += 1;
    *count += 1;
    if (*form.width == *count) *prov = 1;
    if (**str != '\0' && *count != 0) IncrementChar(str, count, value);
    *c = **str;
    while (*c != '\0' && (*c >= '0' && *c <= '9') && !(*prov)) {
      if (*prov_ch == 0) *prov_ch = 1;
      *a = *a * 10.0 + (*c - '0');
      *e = *e - 1;
      if (*form.width == *count) {
        *prov = 1;
        break;
      }
      if (**str != '\0' && (**str >= '0' && **str <= '9'))
        IncrementChar(str, count, value);
      *c = **str;
    }
  }
  if (*form.width == *count) *prov = 1;
  if ((*c == 'e' || *c == 'E') && !(*prov) && *count != -1) {
    int sign = 1, i = 0;
    IncrementChar(str, count, value);
    *c = **str;
    if (*c == '+') {
      IncrementChar(str, count, value);
      *c = **str;
    } else if (*c == '-') {
      IncrementChar(str, count, value);
      *c = **str;
      sign = -1;
    }
    while ((*c >= '0' && *c <= '9')) {
      if (*prov_ch == 0) *prov_ch = 1;
      i = i * 10 + (*c - '0');
      if (**str != '\0' && (**str >= '0' && **str <= '9'))
        IncrementChar(str, count, value);
      *c = **str;
    }
    *e += i * sign;
  }
  while (*e > 0) {
    *a *= 10.0;
    (*e)--;
  }
  while (*e < 0) {
    *a *= 0.1;
    (*e)++;
  }
}

void Atoi(char **str, strInfo value, Param form) {
  int minus = 0, i = 0, plus1 = 0, counter = 0, br = 0, plus = 0;
  char x = -1, arr[50] = "\0";
  AtoiSkip(value, str, &plus1, &minus, &counter, &br);
  if (!br) {
    if (**str == '\0') *value.Success = -1;
    for (;;) {
      x = **str;
      if ((x >= '0' && x <= '9' &&
           (form.Char == 'd' || form.Char == 'i' || form.Char == 'u')) ||
          (form.Char == 'o' && x >= '0' && x <= '7') ||
          ((form.Char == 'x' || form.Char == 'X' || (form.Char == 'i')) &&
           ((x >= '0' && x <= '9') || (x >= 'A' && x <= 'F') ||
            (x >= 'a' && x <= 'f')))) {
        arr[i] = x;
        i++;
        if (i == 1 && x == '0' && (*(*str + 1) == 'x' || *(*str + 1) == 'X') &&
            (form.Char == 'i' || form.Char == 'x' || form.Char == 'X')) {
          i--;
          (*str)++;
          IncrementAtoi(value, &counter, &plus);
          form.Char = 'x';
        }
        if (i == 1 && x == '0' && (form.Char == 'i' || form.Char == 'o')) {
          i--;
          form.Char = 'o';
        }
        if (*form.width == counter) {
          if (plus > 0) *value.Success = 1;
          br = 1;
        }
        if (!br) IncrementAtoi(value, &counter, &plus);
      } else {
        if (plus > 0) *value.Success = 1;
        br = 1;
      }
      if (!br) {
        (*str) += 1;
        if (*form.width == counter || **str == '\0') {
          if (plus > 0) *value.Success = 1;
          br = 1;
        }
      }
      if (br == 1) break;
    }
    if (*value.Success == 1) {
      if (*form.width != 0) *form.width = *form.width - counter;
      if (minus == 1) *value.minus = 1;
      ParseInt(value, arr, form);
      if (minus == 1 && *value.Success == 1) FuncMinus(value, form);
    }
  }
}

void AtoiSkip(strInfo value, char **str, int *plus1, int *minus, int *counter,
              int *br) {
  while (**str == ' ' || (**str >= 7 && **str <= 13)) {
    (*str)++;
    *(value.count) += 1;
  }
  while (**str == '+' || **str == '-') {
    if (**str == '+') {
      (*plus1)++;
    }
    if (**str == '-') {
      (*minus)++;
    }
    (*str)++;
    (*counter)++;
    *(value.count) += 1;
  }

  if (*plus1 > 1 || *minus > 1 || (*plus1 > 0 && *minus > 0)) {
    *value.Success = 0;
    *br = 1;
  }
}

void FuncMinus(strInfo value, Param form) {
  if (form.Type == 1) {
    *value.Short = -(*value.Short);
  } else if (form.Type == 2) {
    *value.Decimal = -(*value.Decimal);
  } else if (form.Type == 3) {
    *value.lint = -(*value.lint);
  } else if (form.Type == 4) {
    *value.llint = -(*value.llint);
  } else if (form.Type == 6) {
    *value.Un = -(*value.Un);
  }
}

void ParseInt(strInfo value, char *arr, Param form) {
  long long int res = 0, res2 = 0, br = 0;
  int num = 0, k = s21_strlen(arr) - 1, base = 0, count = 0, count_o = 0;
  ChangeBase(form.Char, &base);
  for (size_t i = 0; i < s21_strlen(arr); i++) {
    if (s21_strlen(arr) >= 20) {
      if ((form.Char == 'o' || form.Char == 'x') && *value.minus == 1) {
        res = 9223372036854775808u;
        form.Error = -2;
      } else if (form.Type == 3 || form.Type == 4)
        res = 9223372036854775807;
      else
        res = -1;
      br = 1;
    }
    if (!br) {
      if (arr[i] == '0') count_o++;
      CharToInt(arr[i], &num);
      if (num == -1)
        res = -res;
      else if (num == -2) {
      } else {
        res2 = res;
        res += (num * (long long int)pow(base, k--));
        unsigned long long r = res;
        if ((res < 0 && res2 > 0) || res < -9223372036854775807 - 1 ||
            r > 9223372036854775807u) {
          if ((form.Char == 'i' || form.Char == 'x' || form.Char == 'o') &&
              *value.minus == 1) {
            res = 9223372036854775808u;
            form.Error = -2;
          } else if (form.Type == 3 || form.Type == 4)
            res = 9223372036854775807;
          else
            res = -1;
          br = 1;
        }
      }
      count++;
    }
    if (br == 1) break;
  }
  if (res == 0 && count_o == (int)s21_strlen(arr)) form.Error = -2;
  if (res != 0 || form.Error == -2) {
    imputInt(value, res, form);
  } else {
    *value.Success = 0;
  }
  *value.minus = 0;
}

void imputInt(strInfo value, long long int res, Param form) {
  if (form.Type == 1) {
    *value.Short = res;
  } else if (form.Type == 2) {
    *value.Decimal = res;
  } else if (form.Type == 3) {
    *value.lint = res;
  } else if (form.Type == 4) {
    *value.llint = res;
  } else if (form.Type == 5) {
    *value.Pointer = res;
  } else if (form.Type == 6) {
    *value.Un = res;
  }
}

void ChangeBase(int c, int *base) {
  if (c == 'o') {
    *base = 8;
  } else if (c == 'x' || c == 'X' || c == 'p') {
    *base = 16;
  } else {
    *base = 10;
  }
}

void CharToInt(int arr, int *x) {
  if (arr >= '0' && arr <= '9') {
    *x = arr - '0';
  } else if (arr == '-' || arr == '+') {
    if (arr == '-')
      *x = -1;
    else
      *x = -2;
  } else {
    if (arr == 'a' || arr == 'A') *x = a;
    if (arr == 'b' || arr == 'B') *x = b;
    if (arr == 'c' || arr == 'C') *x = c;
    if (arr == 'd' || arr == 'D') *x = d;
    if (arr == 'e' || arr == 'E') *x = e;
    if (arr == 'f' || arr == 'F') *x = f;
  }
}

void TypeChar(va_list argv, strInfo value, Param form, char **str) {
  if (form.Format == 'l') {
    wchar_t X;
    value.wchar = &X;
    if (form.Ignore == noIgnore) {
      value.wchar = va_arg(argv, wchar_t *);
    }
    ParseChar(str, value, form);
  } else if (form.Char == 'c') {
    char x;
    value.Char = &x;
    if (form.Ignore == noIgnore) {
      value.Char = va_arg(argv, char *);
    }
    ParseChar(str, value, form);
  } else {
    TrashSkip(str, value);
    if (**str != '\0' && **str == '%') {
      (*str)++;
      *value.Success = 1;
    } else {
      *value.Success = 0;
    }
  }
}

void ParseChar(char **str, strInfo value, Param form) {
  int counter = 0;
  if (form.Format == 'l') {
    if (**str != '0') {
      *value.wchar = **str;
      IncrementChar(str, &counter, value);
    }
  } else {
    if (**str != '\0') {
      *value.Char = **str;
      IncrementChar(str, &counter, value);
    }
  }
  *value.Success = 1;
}

char IncrementChar(char **str, int *count, strInfo value) {
  char c = **str;
  *count += 1;
  *str += 1;
  *value.count += 1;
  return c;
}

void IncrementAtoi(strInfo value, int *counter, int *plus) {
  *(value.count) += 1;
  *counter += 1;
  *plus += 1;
}

void ParamInput(Param *form, char spec) {
  if (spec == '*') {
    if (form->Ignore == noIgnore)
      form->Ignore = 1;
    else
      form->Error = 1;
  }
  if (spec == 'l' || spec == 'L' || spec == 'h') {
    if (form->Format == noIgnore) {
      form->Format = spec;
    } else {
      if (spec == 'l') {
        if (form->Format == 'l')
          form->Format += spec;
        else
          form->Error = 1;
      }
      if (spec == 'h') {
        if (form->Format == 'h') {
          form->Format += spec;
        }
      }
    }
  } else if (spec >= '0' && spec <= '9') {
    *(form)->width = *(form)->width * 10 + spec - '0';
  } else {
    TypeDef(form, spec);
    if (form->Type == TypeOfFloat &&
        (form->Format == 'h' || form->Format == 216))
      form->Error = 1;

    if ((form->Type == TypeOfInt || form->Type == TypeOfChar ||
         form->Type == TypeOfString) &&
        form->Format == 'L')
      form->Error = 1;
  }
}

void TypeDef(Param *form, char spec) {
  if (spec == 'd' || spec == 'i' || spec == 'o' || spec == 'x' || spec == 'X' ||
      spec == 'u') {
    form->Type = TypeOfInt;
  }
  if (spec == 'e' || spec == 'E' || spec == 'f' || spec == 'g' || spec == 'G') {
    form->Type = TypeOfFloat;
  }
  if (spec == 'c' || spec == '%') {
    form->Type = TypeOfChar;
  }
  if (spec == 's') {
    form->Type = TypeOfString;
  }
  if (spec == 'n') {
    form->Type = TypeOfCount;
  }
  if (spec == 'p') {
    form->Type = TypeOfPointer;
  }
  form->Char = spec;
}

char ToLower(char str) {
  char mon = str;
  if (mon >= 65 && mon <= 90) mon += 32;
  return mon;
}

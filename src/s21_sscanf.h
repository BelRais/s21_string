#include <limits.h>
#include <math.h>
#include <stdarg.h>
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>

#include "s21_string.h"

enum {
  TypeOfChar,
  TypeOfInt,
  TypeOfFloat,
  TypeOfString,
  TypeOfPointer,
  TypeOfCount,
  noIgnore = -1,
  a = 10,
  b,
  c,
  d,
  e,
  f
};

typedef struct {
  int Ignore;
  int Error;
  int Type;
  char Char;
  int Format;
  int continu;
  int *width;
} Param;

typedef struct {
  int *count;
  int *minus;
  int *Decimal;
  short *Short;
  int8_t *Un;
  long int *lint;
  long long int *llint;
  float *F;
  double *lf;
  long double *llf;
  char *Char;
  char *String;
  long long int *Pointer;
  wchar_t *wchar;
  wchar_t *wstring;
  int *Success;
  char paramString[100];
} strInfo;

int s21_sscanf(char *buf, char *format, ...);
int parsing(char **format, char *Spec, Param *form, char **str, strInfo value);
void ParamInput(Param *form, char spec);
void TypeDef(Param *form, char spec);

void TypeChar(va_list argv, strInfo value, Param form, char **str);
void TypeInt(va_list argv, strInfo value, Param form, char **str);
void NEW(va_list argv, Param form, strInfo value, char **str);

void ParseInt(strInfo value, char *arr, Param form);
void ParseFloat(char **str, strInfo value, Param form);
void TypeFloat(va_list argv, strInfo value, Param form, char **str);  //

void TypeString(va_list argv, strInfo value, Param form, char **str);
void ParseString(char **str, strInfo value, Param form);
void TypePointer(va_list argv, strInfo value, Param form, char **str);

void ParseChar(char **str, strInfo value, Param form);
void Atoi(char **str, strInfo value, Param form);
long double Atof(char **str, strInfo value, Param form);
char IncrementChar(char **str, int *count, strInfo value);

void CharToInt(int arr, int *x);
void ChangeBase(int c, int *base);
void FuncMinus(strInfo value, Param form);
void TypeCounter(va_list argv, strInfo value, char **str, Param form);
void TrashSkip(char **str, strInfo value);
void Plus(strInfo value, int *counter);
void IncrementAtoi(strInfo value, int *counter, int *plus);
char ToLower(char str);
void imputInt(strInfo value, long long int res, Param form);
void AtoiSkip(strInfo value, char **str, int *plus1, int *minus, int *counter,
              int *br);
void Afotblock_1(strInfo value, Param form, int *pp, int *prov_ch, int *count,
                 int *prov, char **str, int *c, long double *a);
void Afotblock_2(strInfo value, Param form, int *c, int *count, int *prov,
                 int *prov_ch, int *e, char **str, long double *a);
void SkipFloat(strInfo value, Param form, char **str, int *plus, int *minus,
               int *br, int *count);
void SkipFloat(strInfo value, Param form, char **str, int *plus, int *minus,
               int *br, int *count);
void SkipParsing(strInfo value, char **format, char **str);
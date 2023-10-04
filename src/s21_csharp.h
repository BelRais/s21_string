#include <stdio.h>
#include <stdlib.h>

#include "s21_string.h"

#define s21_size_t unsigned long long
void *s21_to_upper(const char *str);
void *s21_to_lower(const char *str);
void *s21_insert(const char *src, const char *str, s21_size_t start_index);
void *s21_trim(const char *src, const char *trim_chars);
#include "s21_csharp.h"

void *s21_to_upper(const char *str) {
  char *buf = s21_NULL;
  s21_size_t len = -1;
  if (str != s21_NULL) {
    len = s21_strlen(str);
    buf = malloc(sizeof(char) * (len + 1));
  }
  char *result = s21_NULL;
  if (str != s21_NULL && buf != s21_NULL) {
    result = buf;
    while (*str != '\0') {
      if (*str >= 97 && *str <= 122) {
        *buf = *str - 32;
      } else {
        *buf = *str;
      }
      buf++;
      str++;
    }
    *buf = '\0';
  }
  return result;
}

void *s21_to_lower(const char *str) {
  char *buf = s21_NULL;
  s21_size_t len = -1;
  if (str != s21_NULL) {
    len = s21_strlen(str);
    buf = malloc(sizeof(char) * (len + 1));
  }
  char *result = s21_NULL;
  if (str != s21_NULL && buf != s21_NULL) {
    result = buf;
    while (*str != '\0') {
      if (*str >= 65 && *str <= 90) {
        *buf = *str + 32;
      } else {
        *buf = *str;
      }
      buf++;
      str++;
    }
    *buf = '\0';
  }
  return result;
}

void *s21_insert(const char *src, const char *str, s21_size_t start_index) {
  char *copy = s21_NULL;
  s21_size_t len = -1, len_src = -1, len_str = -1;
  if (src != s21_NULL && str != s21_NULL) {
    len_src = s21_strlen(src);
    len_str = s21_strlen(str);
    len = len_src + len_str;
    if (start_index <= len_src) copy = malloc(sizeof(char) * (len + 1));
  }
  char *pTemp = copy;
  if (copy != s21_NULL && start_index <= len_src) {
    int count_copy = 0, count_src = 0;
    for (s21_size_t i = 0; i <= len_src; i++) {
      copy[count_copy] = src[count_src];
      if (i == start_index) {
        for (s21_size_t j = 0; j < len_str; j++) {
          copy[count_copy] = str[j];
          count_copy++;
        }
        copy[count_copy] = src[count_src];
      }
      count_copy++;
      count_src++;
    }
  }
  return pTemp;
}

void *s21_trim(const char *src, const char *trim_chars) {
  char *copy = s21_NULL;
  s21_size_t len = 0;
  if (trim_chars == s21_NULL || s21_strlen(trim_chars) == 0) {
    trim_chars = "\0";
  }
  if (src != s21_NULL && trim_chars != s21_NULL) {
    len = s21_strlen(src);
    copy = malloc(sizeof(char) * (len + 1));
  }
  char *pTemp = copy;
  if (src != s21_NULL && copy != s21_NULL && trim_chars != s21_NULL) {
    s21_strcpy(copy, src);
    for (int i = s21_strlen(copy);
         i >= 0 && s21_strchr(trim_chars, copy[i]) != s21_NULL; i--) {
      copy[i] = '\0';
    }

    while (copy[0] != '\0' && s21_strchr(trim_chars, copy[0]) != s21_NULL) {
      s21_memmove(&copy[0], &copy[1], s21_strlen(copy));
    }
  }
  return pTemp;
}

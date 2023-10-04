#include "check_main.h"

int main(void) {
  int no_failed = 0;
  Suite *test_all[] = {test_sprintf_hex(),
                       test_sprintf_HEX(),
                       test_sprintf_octal(),
                       test_sprintf_g(),
                       test_sprintf_f(),
                       test_memchr(),
                       test_memcmp(),
                       test_memcpy(),
                       test_memmove(),
                       test_memset(),
                       test_strcpy(),
                       test_strcat(),
                       test_strchr(),
                       test_strcmp(),
                       test_strcspn(),
                       test_strerror(),
                       test_strlen(),
                       test_strncat(),
                       test_strncmp(),
                       test_strncpy(),
                       test_strpbrk(),
                       test_strrchr(),
                       test_strspn(),
                       test_strstr(),
                       test_strtok(),
                       test_sprintf_c(),
                       test_sprintf_percent(),
                       test_sprintf_string(),
                       test_sprintf_unsigned(),
                       test_sprintf_signed(),
                       test_sprintf_signed_i(),
                       s21_sscanf_suite(),
                       test_sscanf_x(),
                       test_sscanf_real(),
                       test_sscanf_p(),
                       test_sscanf_o(),
                       test_sscanf_n(),
                       test_sscanf_i(),
                       test_sscanf_empty(),
                       test_sscanf_d(),
                       test_sscanf_c(),
                       test_to_lower(),
                       test_to_upper(),
                       test_trim(),
                       test_insert()};

  SRunner *runner;
  runner = srunner_create(test_all[0]);
  srunner_set_fork_status(runner, CK_NOFORK);
  for (size_t i = 1; i < (sizeof((test_all)) / sizeof((test_all)[0])); i++)
    srunner_add_suite(runner, test_all[i]);

  // CK_NORMAL печатает сводку выполнения и печатает одно сообщение для каждого
  // неудачного теста.
  srunner_run_all(runner, CK_NORMAL);
  no_failed = srunner_ntests_failed(runner);
  srunner_free(runner);
  return (no_failed == 0) ? EXIT_SUCCESS : EXIT_FAILURE;
}

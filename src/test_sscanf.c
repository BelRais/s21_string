#include "check_main.h"

START_TEST(Test_c_1) {
  char fstr[] = "%c %c %c %c";
  char str[] = " c    a  d b";
  int a1 = 0, a2 = 5, b1 = 0, b2 = 5, c1 = 0, c2 = 5, d1 = 0, d2 = 5;

  int res1 = s21_sscanf(str, fstr, &a1, &b1, &c1, &d1);

  int res2 = sscanf(str, fstr, &a2, &b2, &c2, &d2);

  ck_assert_int_eq(res1, res2);
  ck_assert_int_eq(a1, a2);
  ck_assert_int_eq(b1, b2);
  ck_assert_int_eq(c1, c2);
  ck_assert_int_eq(d1, d2);
}
END_TEST

START_TEST(Test_c_2) {
  char fstr[] = "%c%c%c%c";
  char str[] = "cadb";
  int a1 = 0, a2 = 2, b1 = 0, b2 = 2, c1 = 0, c2 = 1, d1 = 0, d2 = 3;

  int res1 = s21_sscanf(str, fstr, &a1, &b1, &c1, &d1);

  int res2 = sscanf(str, fstr, &a2, &b2, &c2, &d2);

  ck_assert_int_eq(res1, res2);
  ck_assert_int_eq(a1, a2);
  ck_assert_int_eq(b1, b2);
  ck_assert_int_eq(c1, c2);
  ck_assert_int_eq(d1, d2);
}
END_TEST

START_TEST(Test_c_3) {
  char fstr[] = "%c %c %c      %c";
  char str[] = "1        a 3   c           ";
  int a1 = 0, a2 = 2, b1 = 0, b2 = 2, c1 = 0, c2 = 1, d1 = 0, d2 = 3;

  int res1 = s21_sscanf(str, fstr, &a1, &b1, &c1, &d1);
  int res2 = sscanf(str, fstr, &a2, &b2, &c2, &d2);

  ck_assert_int_eq(res1, res2);
  ck_assert_int_eq(a1, a2);
  ck_assert_int_eq(b1, b2);
  ck_assert_int_eq(c1, c2);
  ck_assert_int_eq(d1, d2);
}
END_TEST

START_TEST(Test_c_4) {
  char fstr[] = "%c %c %c %c";
  char str[] = "   0 000    ";
  int a1 = 0, a2 = 2, b1 = 0, b2 = 2, c1 = 0, c2 = 1, d1 = 0, d2 = 3;

  int res1 = s21_sscanf(str, fstr, &a1, &b1, &c1, &d1);

  int res2 = sscanf(str, fstr, &a2, &b2, &c2, &d2);

  ck_assert_int_eq(res1, res2);
  ck_assert_int_eq(a1, a2);
  ck_assert_int_eq(b1, b2);
  ck_assert_int_eq(c1, c2);
  ck_assert_int_eq(d1, d2);
}
END_TEST

START_TEST(Test_c_5) {
  char fstr[] = "%c %c %c %c";
  char str[] = "ttee";
  int a1 = 0, a2 = 3, b1 = 0, b2 = 3, c1 = 0, c2 = 1, d1 = 0, d2 = 3;

  int res1 = s21_sscanf(str, fstr, &a1, &b1, &c1, &d1);

  int res2 = sscanf(str, fstr, &a2, &b2, &c2, &d2);

  ck_assert_int_eq(res1, res2);
  ck_assert_int_eq(a1, a2);
  ck_assert_int_eq(b1, b2);
  ck_assert_int_eq(c1, c2);
  ck_assert_int_eq(d1, d2);
}
END_TEST

START_TEST(Test_c_6) {
  char fstr[] = "%c%c%c%c";
  char str[] = "\\\n\t\t\t";
  int a1 = 0, a2 = 0, b1 = 0, b2 = 0, c1 = 0, c2 = 0, d1 = 0, d2 = 0;

  int res1 = s21_sscanf(str, fstr, &a1, &b1, &c1, &d1);
  int res2 = sscanf(str, fstr, &a2, &b2, &c2, &d2);

  ck_assert_int_eq(res1, res2);
  ck_assert_int_eq(a1, a2);
  ck_assert_int_eq(b1, b2);
  ck_assert_int_eq(c1, c2);
  ck_assert_int_eq(d1, d2);
}
END_TEST

START_TEST(Test_c_7) {
  char fstr[] = "%c %c %c %c";
  char str[] = "z ' ' /";
  int a1 = 0, a2 = 0, b1 = 0, b2 = 0, c1 = 0, c2 = 0, d1 = 0, d2 = 0;

  int res1 = s21_sscanf(str, fstr, &a1, &b1, &c1, &d1);
  int res2 = sscanf(str, fstr, &a2, &b2, &c2, &d2);

  ck_assert_int_eq(res1, res2);
  ck_assert_int_eq(a1, a2);
  ck_assert_int_eq(b1, b2);
  ck_assert_int_eq(c1, c2);
  ck_assert_int_eq(d1, d2);
}
END_TEST

START_TEST(Test_c_8) {
  char fstr[] = "%c%*c%c%c";
  char str[] = "LOOL";
  int a1 = 0, a2 = 0, b1 = 0, b2 = 0, c1 = 0, c2 = 0;

  int res1 = s21_sscanf(str, fstr, &a1, &b1, &c1);

  int res2 = sscanf(str, fstr, &a2, &b2, &c2);

  ck_assert_int_eq(res1, res2);
  ck_assert_int_eq(a1, a2);
  ck_assert_int_eq(b1, b2);
  ck_assert_int_eq(c1, c2);
}
END_TEST

START_TEST(Test_c_9) {
  char fstr[] = "%c %c %c %c";
  char str[] = "b *`@";
  int a1 = 0, a2 = 0, b1 = 0, b2 = 0, c1 = 0, c2 = 0, d1 = 0, d2 = 0;

  int res1 = s21_sscanf(str, fstr, &a1, &b1, &c1, &d1);
  int res2 = sscanf(str, fstr, &a2, &b2, &c2, &d2);

  ck_assert_int_eq(res1, res2);
  ck_assert_int_eq(a1, a2);
  ck_assert_int_eq(b1, b2);
  ck_assert_int_eq(c1, c2);
  ck_assert_int_eq(d1, d2);
}
END_TEST

START_TEST(Test_c_10) {
  char fstr[] = "%1c %c %c %0c";
  char str[] = "b *`@";
  int a1 = 0, a2 = 0, b1 = 0, b2 = 0, c1 = 0, c2 = 0, d1 = 0, d2 = 0;

  int res1 = s21_sscanf(str, fstr, &a1, &b1, &c1, &d1);
  int res2 = sscanf(str, fstr, &a2, &b2, &c2, &d2);

  ck_assert_int_eq(res1, res2);
  ck_assert_int_eq(a1, a2);
  ck_assert_int_eq(b1, b2);
  ck_assert_int_eq(c1, c2);
  ck_assert_int_eq(d1, d2);
}
END_TEST

START_TEST(Test_c_11) {
  char fstr[] = "%c %c %c %c";
  char str[] = "b *`@";
  int a1 = 0, a2 = 0, b1 = 0, b2 = 0, c1 = 0, c2 = 0, d1 = 0, d2 = 0;

  int res1 = s21_sscanf(str, fstr, &a1, &b1, &c1, &d1);
  int res2 = sscanf(str, fstr, &a2, &b2, &c2, &d2);

  ck_assert_int_eq(res1, res2);
  ck_assert_int_eq(a1, a2);
  ck_assert_int_eq(b1, b2);
  ck_assert_int_eq(c1, c2);
  ck_assert_int_eq(d1, d2);
}
END_TEST

START_TEST(Test_c_12) {
  char fstr[] = "%c %c %c %c";
  char str[] = "b* ` @";
  int a1 = 0, a2 = 0, b1 = 0, b2 = 0, c1 = 0, c2 = 0, d1 = 0, d2 = 0;

  int res1 = s21_sscanf(str, fstr, &a1, &b1, &c1, &d1);
  int res2 = sscanf(str, fstr, &a2, &b2, &c2, &d2);

  ck_assert_int_eq(res1, res2);
  ck_assert_int_eq(a1, a2);
  ck_assert_int_eq(b1, b2);
  ck_assert_int_eq(c1, c2);
  ck_assert_int_eq(d1, d2);
}
END_TEST

START_TEST(Test_c_13) {
  char fstr[] = "%*c%*c%*c%c";
  char str[] = "abcde";
  int a1 = 0, a2 = 0;

  int res1 = s21_sscanf(str, fstr, &a1);
  int res2 = sscanf(str, fstr, &a2);

  ck_assert_int_eq(res1, res2);
  ck_assert_int_eq(a1, a2);
}
END_TEST

START_TEST(Test_c_14) {
  char fstr[] = "%*c%*c%*c%*c";
  char str[] = "   u ";
  int a1 = 0, a2 = 0;

  int res1 = s21_sscanf(str, fstr, &a1);
  int res2 = sscanf(str, fstr, &a2);

  ck_assert_int_eq(res1, res2);
  ck_assert_int_eq(a1, a2);
}
END_TEST

START_TEST(Test_c_15) {
  char fstr[] = "%*c%*c%*c%c";
  char str[] = "abcd ";
  int a1 = 0, a2 = 0;

  int res1 = s21_sscanf(str, fstr, &a1);
  int res2 = sscanf(str, fstr, &a2);

  ck_assert_int_eq(res1, res2);
  ck_assert_int_eq(a1, a2);
}
END_TEST

START_TEST(Test_d_1) {
  long int a1 = 0, a2 = 0, b1 = 0, b2 = 0, c1 = 0, c2 = 0, d1 = 0, d2 = 0;
  char fstr[] = "%ld %ld %ld %ld";
  char str[] = "123 126 412 151";

  int res1 = s21_sscanf(str, fstr, &a1, &b1, &c1, &d1);
  int res2 = sscanf(str, fstr, &a2, &b2, &c2, &d2);

  ck_assert_int_eq(res1, res2);
  ck_assert_int_eq(a1, a2);
  ck_assert_int_eq(b1, b2);
  ck_assert_int_eq(c1, c2);
  ck_assert_int_eq(d1, d2);
}
END_TEST

START_TEST(Test_d_2) {
  int a1 = 0, a2 = 0, b1 = 0, b2 = 0, c1 = 0, c2 = 0, d1 = 0, d2 = 0;
  char str[] = "1412 12 1412 1415";
  char fstr[] = "%hd %hd %hd %hd";

  int res1 = s21_sscanf(str, fstr, &a1, &b1, &c1, &d1);
  int res2 = sscanf(str, fstr, &a2, &b2, &c2, &d2);

  ck_assert_int_eq(res1, res2);
  ck_assert_int_eq(a1, a2);
  ck_assert_int_eq(b1, b2);
  ck_assert_int_eq(c1, c2);
  ck_assert_int_eq(d1, d2);
}
END_TEST

START_TEST(Test_d_3) {
  long int a1 = 0, a2 = 0, b1 = 0, b2 = 0, c1 = 0, c2 = 0, d1 = 0, d2 = 0;
  char str[] = "1337 21 5008 300004";
  char fstr[] = "%ld %ld %ld %ld";

  int res1 = s21_sscanf(str, fstr, &a1, &b1, &c1, &d1);
  int res2 = sscanf(str, fstr, &a2, &b2, &c2, &d2);

  ck_assert_int_eq(res1, res2);
  ck_assert_int_eq(a1, a2);
  ck_assert_int_eq(b1, b2);
  ck_assert_int_eq(c1, c2);
  ck_assert_int_eq(d1, d2);
}
END_TEST

START_TEST(Test_d_4) {
  long int a1 = 0, a2 = 0, b1 = 0, b2 = 0, c1 = 0, c2 = 0, d1 = 0, d2 = 0;
  char str[] = "2123 12 1414 142411";
  char fstr[] = "%1ld %3ld %1ld %4ld";

  int16_t res1 = s21_sscanf(str, fstr, &a1, &b1, &c1, &d1);
  int16_t res2 = sscanf(str, fstr, &a2, &b2, &c2, &d2);

  ck_assert_int_eq(res1, res2);
  ck_assert_int_eq(a1, a2);
  ck_assert_int_eq(b1, b2);
  ck_assert_int_eq(c1, c2);
  ck_assert_int_eq(d1, d2);
}
END_TEST

START_TEST(Test_d_5) {
  long int a1 = 0, a2 = 0, b1 = 0, b2 = 0, c1 = 0, c2 = 0, d1 = 0, d2 = 0;
  char str[] = "2312";
  char fstr[] = "%1ld %1ld %1ld %1ld";

  int res1 = s21_sscanf(str, fstr, &a1, &b1, &c1, &d1);
  int res2 = sscanf(str, fstr, &a2, &b2, &c2, &d2);

  ck_assert_int_eq(res1, res2);
  ck_assert_int_eq(a1, a2);
  ck_assert_int_eq(b1, b2);
  ck_assert_int_eq(c1, c2);
  ck_assert_int_eq(d1, d2);
}
END_TEST

START_TEST(Test_d_6) {
  long int a1 = 0, a2 = 0, b1 = 0, b2 = 0, c1 = 0, c2 = 0, d1 = 0, d2 = 0;
  char str[] = "101000000000000005";
  char fstr[] = "%3ld%ld%1ld%5ld";

  int res1 = s21_sscanf(str, fstr, &a1, &b1, &c1, &d1);
  int res2 = sscanf(str, fstr, &a2, &b2, &c2, &d2);

  ck_assert_int_eq(res1, res2);
  ck_assert_int_eq(a1, a2);
  ck_assert_int_eq(b1, b2);
  ck_assert_int_eq(c1, c2);
  ck_assert_int_eq(d1, d2);
}
END_TEST

START_TEST(Test_d_7) {
  long int a1 = 0, a2 = 0, b1 = 0, b2 = 0, c1 = 0, c2 = 0, d1 = 0, d2 = 0;
  char str[] = "1431";
  char fstr[] = "%15ld %1ld %1ld %1ld";

  int res1 = s21_sscanf(str, fstr, &a1, &b1, &c1, &d1);
  int res2 = sscanf(str, fstr, &a2, &b2, &c2, &d2);

  ck_assert_int_eq(res1, res2);
  ck_assert_int_eq(a1, a2);
  ck_assert_int_eq(b1, b2);
  ck_assert_int_eq(c1, c2);
  ck_assert_int_eq(d1, d2);
}
END_TEST

START_TEST(Test_d_8) {
  long int a1 = 0, a2 = 0, b1 = 0, b2 = 0, c1 = 0, c2 = 0;
  char str[] = "1337123123 1 123412341234 1 999999 0";
  char fstr[] = "%*d %ld %*d %ld %*d %ld";

  int res1 = s21_sscanf(str, fstr, &a1, &b1, &c1);
  int res2 = sscanf(str, fstr, &a2, &b2, &c2);

  ck_assert_int_eq(res1, res2);
  ck_assert_int_eq(a1, a2);
  ck_assert_int_eq(b1, b2);
  ck_assert_int_eq(c1, c2);
}
END_TEST

START_TEST(Test_d_9) {
  long int a1 = 0, a2 = 0, b1 = 0, b2 = 0, c1 = 0, c2 = 0, d1 = 0, d2 = 0;
  char str[] = "1337";
  char fstr[] = "%15ld %1ld %1ld %1ld";

  int res1 = s21_sscanf(str, fstr, &a1, &b1, &c1, &d1);
  int res2 = sscanf(str, fstr, &a2, &b2, &c2, &d2);

  ck_assert_int_eq(res1, res2);
  ck_assert_int_eq(a1, a2);
  ck_assert_int_eq(b1, b2);
  ck_assert_int_eq(c1, c2);
  ck_assert_int_eq(d1, d2);
}
END_TEST

START_TEST(Test_d_10) {
  long int a1 = 0, a2 = 0, b1 = 0, b2 = 0, c1 = 0, c2 = 0, d1 = 0, d2 = 0;
  char str[] = "1337";
  char fstr[] = "%15ld %1ld %1ld %1ld";

  int res1 = s21_sscanf(str, fstr, &a1, &b1, &c1, &d1);
  int res2 = sscanf(str, fstr, &a2, &b2, &c2, &d2);

  ck_assert_int_eq(res1, res2);
  ck_assert_int_eq(a1, a2);
  ck_assert_int_eq(b1, b2);
  ck_assert_int_eq(c1, c2);
  ck_assert_int_eq(d1, d2);
}
END_TEST

START_TEST(Test_d_11) {
  long int a1 = 0, a2 = 0, b1 = 0, b2 = 0, c1 = 0, c2 = 0, d1 = 0, d2 = 0;
  char str[] = "1421";
  char fstr[] = "%15ld %1ld %1ld %1ld";

  int res1 = s21_sscanf(str, fstr, &a1, &b1, &c1, &d1);
  int res2 = sscanf(str, fstr, &a2, &b2, &c2, &d2);

  ck_assert_int_eq(res1, res2);
  ck_assert_int_eq(a1, a2);
  ck_assert_int_eq(b1, b2);
  ck_assert_int_eq(c1, c2);
  ck_assert_int_eq(d1, d2);
}
END_TEST

START_TEST(Test_d_12) {
  long int a1 = 0, a2 = 0, b1 = 0, b2 = 0, c1 = 0, c2 = 0, d1 = 0, d2 = 0;
  char str[] = "66337 +2 -6 --1";
  char fstr[] = "%ld %ld %ld %ld";

  int res1 = s21_sscanf(str, fstr, &a1, &b1, &c1, &d1);
  int res2 = sscanf(str, fstr, &a2, &b2, &c2, &d2);

  ck_assert_int_eq(res1, res2);
  ck_assert_int_eq(a1, a2);
  ck_assert_int_eq(b1, b2);
  ck_assert_int_eq(c1, c2);
  ck_assert_int_eq(d1, d2);
}
END_TEST

START_TEST(Test_d_13) {
  long int a1 = 0, a2 = 0, b1 = 0, b2 = 0, c1 = 0, c2 = 0, d1 = 0, d2 = 0;
  char str[] = "-1557 +1 -1 -1";
  char fstr[] = "%15ld %1ld %1ld %5ld";

  int res1 = s21_sscanf(str, fstr, &a1, &b1, &c1, &d1);
  int res2 = sscanf(str, fstr, &a2, &b2, &c2, &d2);

  ck_assert_int_eq(res1, res2);
  ck_assert_int_eq(a1, a2);
  ck_assert_int_eq(b1, b2);
  ck_assert_int_eq(c1, c2);
  ck_assert_int_eq(d1, d2);
}
END_TEST

START_TEST(Test_d_14) {
  int a1 = 0, a2 = 0, b1 = 0, b2 = 0, c1 = 0, c2 = 0, d1 = 0, d2 = 0;
  char str[] = "-0 +0 +0 -0";
  char fstr[] = "%2d %1d %1d %1d";

  int res1 = s21_sscanf(str, fstr, &a1, &b1, &c1, &d1);
  int res2 = sscanf(str, fstr, &a2, &b2, &c2, &d2);

  ck_assert_int_eq(res1, res2);
  ck_assert_int_eq(a1, a2);
  ck_assert_int_eq(b1, b2);
  ck_assert_int_eq(c1, c2);
  ck_assert_int_eq(d1, d2);
}
END_TEST

START_TEST(Test_d_15) {
  int a1 = 0, a2 = 0, b1 = 0, b2 = 0, c1 = 0, c2 = 0, d1 = 0, d2 = 0;
  char str[] = "0 10 01 1";
  char fstr[] = "%d %d %d %d";

  int res1 = s21_sscanf(str, fstr, &a1, &b1, &c1, &d1);
  int res2 = sscanf(str, fstr, &a2, &b2, &c2, &d2);

  ck_assert_int_eq(res1, res2);
  ck_assert_int_eq(a1, a2);
  ck_assert_int_eq(b1, b2);
  ck_assert_int_eq(c1, c2);
  ck_assert_int_eq(d1, d2);
}
END_TEST

START_TEST(Test_d_16) {
  int a1 = 0, a2 = 0, b1 = 0, b2 = 0, c1 = 0, c2 = 0, d1 = 0, d2 = 0;
  char str[] = "NAN 10 01 1";
  char fstr[] = "%d %d %d %d";

  int res1 = s21_sscanf(str, fstr, &a1, &b1, &c1, &d1);
  int res2 = sscanf(str, fstr, &a2, &b2, &c2, &d2);

  ck_assert_int_eq(res1, res2);
  ck_assert_int_eq(a1, a2);
  ck_assert_int_eq(b1, b2);
  ck_assert_int_eq(c1, c2);
  ck_assert_int_eq(d1, d2);
}
END_TEST

START_TEST(Test_d_17) {
  int a1 = 0, a2 = 0, b1 = 0, b2 = 0, c1 = 0, c2 = 0, d1 = 0, d2 = 0;
  char str[] = "0 0 01 inf";
  char fstr[] = "%d %d %d %d";

  int res1 = s21_sscanf(str, fstr, &a1, &b1, &c1, &d1);
  int res2 = sscanf(str, fstr, &a2, &b2, &c2, &d2);

  ck_assert_int_eq(res1, res2);
  ck_assert_int_eq(a1, a2);
  ck_assert_int_eq(b1, b2);
  ck_assert_int_eq(c1, c2);
  ck_assert_int_eq(d1, d2);
}
END_TEST

START_TEST(Test_i_1) {
  int a1 = 0, a2 = 0, b1 = 0, b2 = 0, c1 = 0, c2 = 0, d1 = 0, d2 = 0;
  char str[] = "301 555 -632 +711";
  char fstr[] = "%i %i %i %i";

  int res1 = s21_sscanf(str, fstr, &a1, &b1, &c1, &d1);
  int res2 = sscanf(str, fstr, &a2, &b2, &c2, &d2);

  ck_assert_int_eq(res1, res2);
  ck_assert_int_eq(a1, a2);
  ck_assert_int_eq(b1, b2);
  ck_assert_int_eq(c1, c2);
  ck_assert_int_eq(d1, d2);
}
END_TEST

START_TEST(Test_i_2) {
  long int a1 = 0, a2 = 0, b1 = 0, b2 = 0, c1 = 0, c2 = 0, d1 = 0, d2 = 0;
  char str[] = "312500-620+230 111";
  char fstr[] = "%li %ld %ld %li";

  int res1 = s21_sscanf(str, fstr, &a1, &b1, &c1, &d1);
  int res2 = sscanf(str, fstr, &a2, &b2, &c2, &d2);

  ck_assert_int_eq(res1, res2);
  ck_assert_int_eq(a1, a2);
  ck_assert_int_eq(b1, b2);
  ck_assert_int_eq(c1, c2);
  ck_assert_int_eq(d1, d2);
}
END_TEST

START_TEST(Test_i_3) {
  long int a1 = 0, a2 = 0, c1 = 0, c2 = 0;
  char b1 = 0, b2 = 0, d1 = 0, d2 = 0;
  char str[] = "552110-321+712+540";
  char fstr[] = "%li%c%li%c";

  int res1 = s21_sscanf(str, fstr, &a1, &b1, &c1, &d1);
  int res2 = sscanf(str, fstr, &a2, &b2, &c2, &d2);

  ck_assert_int_eq(res1, res2);
  ck_assert_int_eq(a1, a2);
  ck_assert_int_eq(b1, b2);
  ck_assert_int_eq(c1, c2);
  ck_assert_int_eq(d1, d2);
}
END_TEST

START_TEST(Test_i_4) {
  long int a1 = 0, a2 = 0, b1 = 0, b2 = 0, c1 = 0, c2 = 0, d1 = 0, d2 = 0;
  char str[] = "  52425 f f f552315 ddd   2    3    1 ";
  char fstr[] = "%li %ld %ld %li";

  int res1 = s21_sscanf(str, fstr, &a1, &b1, &c1, &d1);
  int res2 = sscanf(str, fstr, &a2, &b2, &c2, &d2);

  ck_assert_int_eq(res1, res2);
  ck_assert_int_eq(a1, a2);
  ck_assert_int_eq(b1, b2);
  ck_assert_int_eq(c1, c2);
  ck_assert_int_eq(d1, d2);
}
END_TEST

START_TEST(Test_i_5) {
  long int a1 = 0, a2 = 0, b1 = 0, b2 = 0, c1 = 0, c2 = 0, d1 = 0, d2 = 0;
  char str[] = "0xFFF 0xA123123 0x123123 0x0";
  char fstr[] = "%li %ld %ld %li";

  int res1 = s21_sscanf(str, fstr, &a1, &b1, &c1, &d1);
  int res2 = sscanf(str, fstr, &a2, &b2, &c2, &d2);

  ck_assert_int_eq(res1, res2);
  ck_assert_int_eq(a1, a2);
  ck_assert_int_eq(b1, b2);
  ck_assert_int_eq(c1, c2);
  ck_assert_int_eq(d1, d2);
}
END_TEST

START_TEST(Test_i_6) {
  long int a1 = 0, a2 = 0, b1 = 0, b2 = 0, c1 = 0, c2 = 0, d1 = 0, d2 = 0;
  char str[] = " 0xFFFF 0xf 0xf 0xf5555555 ddd   2    3    1 ";
  char fstr[] = "%li %ld %ld %li";

  int res1 = s21_sscanf(str, fstr, &a1, &b1, &c1, &d1);
  int res2 = sscanf(str, fstr, &a2, &b2, &c2, &d2);

  ck_assert_int_eq(res1, res2);
  ck_assert_int_eq(a1, a2);
  ck_assert_int_eq(b1, b2);
  ck_assert_int_eq(c1, c2);
  ck_assert_int_eq(d1, d2);
}
END_TEST

START_TEST(Test_i_7) {
  long int a1 = 0, a2 = 0, b1 = 0, b2 = 0, c1 = 0, c2 = 0, d1 = 0, d2 = 0;
  char str[] = "  055555 0f 0f 0f5555555";
  char fstr[] = "%li %ld %ld %li";

  int res1 = s21_sscanf(str, fstr, &a1, &b1, &c1, &d1);
  int res2 = sscanf(str, fstr, &a2, &b2, &c2, &d2);

  ck_assert_int_eq(res1, res2);
  ck_assert_int_eq(a1, a2);
  ck_assert_int_eq(b1, b2);
  ck_assert_int_eq(c1, c2);
  ck_assert_int_eq(d1, d2);
}
END_TEST

START_TEST(Test_i_8) {
  int a1 = 0, a2 = 0, b1 = 0, b2 = 0, c1 = 0, c2 = 0, d1 = 0, d2 = 0;
  char str[] = "  055555 0f 0f 0f5555555 0ddd   4    3    1 ";
  char fstr[] = "%i %ld %ld %li";

  int res1 = s21_sscanf(str, fstr, &a1, &b1, &c1, &d1);
  int res2 = sscanf(str, fstr, &a2, &b2, &c2, &d2);

  ck_assert_int_eq(res1, res2);
  ck_assert_int_eq(a1, a2);
  ck_assert_int_eq(b1, b2);
  ck_assert_int_eq(c1, c2);
  ck_assert_int_eq(d1, d2);
}
END_TEST

START_TEST(Test_s_1) {
  char s1[BUFF_SIZE] = {'\0'};
  char s2[BUFF_SIZE] = {'\0'};
  char s3[BUFF_SIZE] = {'\0'};
  char s4[BUFF_SIZE] = {'\0'};

  char s5[BUFF_SIZE] = {'\0'};
  char s6[BUFF_SIZE] = {'\0'};
  char s7[BUFF_SIZE] = {'\0'};
  char s8[BUFF_SIZE] = {'\0'};

  char str[] = "I'm a student School21";
  char fstr[] = "%s %s %s %s";

  int res1 = s21_sscanf(str, fstr, s1, s2, s3, s4);
  int res2 = sscanf(str, fstr, s5, s6, s7, s8);

  ck_assert_int_eq(res1, res2);

  ck_assert_str_eq(s1, s5);
  ck_assert_str_eq(s2, s6);
  ck_assert_str_eq(s3, s7);
  ck_assert_str_eq(s4, s8);
}
END_TEST

START_TEST(Test_s_2) {
  char s1[BUFF_SIZE] = {'\0'};
  char s2[BUFF_SIZE] = {'\0'};
  char s3[BUFF_SIZE] = {'\0'};
  char s4[BUFF_SIZE] = {'\0'};

  char s5[BUFF_SIZE] = {'\0'};
  char s6[BUFF_SIZE] = {'\0'};
  char s7[BUFF_SIZE] = {'\0'};
  char s8[BUFF_SIZE] = {'\0'};

  int a1 = 0, a2 = 0, b1 = 0, b2 = 0, c1 = 0, c2 = 0, d1 = 0, d2 = 0;

  char str[] = "Snowi -55 Winter -1 Sings 4124Mobiles 3123Schools 1";
  char fstr[] = "%s%d%s%d%s%d%s";

  int res1 = s21_sscanf(str, fstr, s1, &a1, s2, &b1, s3, &c1, s4, &d1);
  int res2 = s21_sscanf(str, fstr, s5, &a2, s6, &b2, s7, &c2, s8, &d2);

  ck_assert_int_eq(res1, res2);
  ck_assert_int_eq(a1, a2);
  ck_assert_int_eq(b1, b2);
  ck_assert_int_eq(c1, c2);
  ck_assert_int_eq(d1, d2);

  ck_assert_str_eq(s1, s5);
  ck_assert_str_eq(s2, s6);
  ck_assert_str_eq(s3, s7);
  ck_assert_str_eq(s4, s8);
}
END_TEST

START_TEST(Test_s_3) {
  char s1[BUFF_SIZE] = {'\0'};
  char s2[BUFF_SIZE] = {'\0'};
  char s3[BUFF_SIZE] = {'\0'};
  char s4[BUFF_SIZE] = {'\0'};

  char s5[BUFF_SIZE] = {'\0'};
  char s6[BUFF_SIZE] = {'\0'};
  char s7[BUFF_SIZE] = {'\0'};
  char s8[BUFF_SIZE] = {'\0'};

  char str[] = "thinkhowisyourlifegoing";
  char fstr[] = "%s%s%s%s";

  int res1 = s21_sscanf(str, fstr, s1, s2, s3, s4);
  int res2 = sscanf(str, fstr, s5, s6, s7, s8);

  ck_assert_int_eq(res1, res2);

  ck_assert_str_eq(s1, s5);
  ck_assert_str_eq(s2, s6);
  ck_assert_str_eq(s3, s7);
  ck_assert_str_eq(s4, s8);
}
END_TEST

START_TEST(Test_s_4) {
  char s1[BUFF_SIZE] = {'\0'};
  char s2[BUFF_SIZE] = {'\0'};
  char s3[BUFF_SIZE] = {'\0'};
  char s4[BUFF_SIZE] = {'\0'};

  char s5[BUFF_SIZE] = {'\0'};
  char s6[BUFF_SIZE] = {'\0'};
  char s7[BUFF_SIZE] = {'\0'};
  char s8[BUFF_SIZE] = {'\0'};

  char str[] = "3132 4c 55234 313232 13123 12 p p p p";
  char fstr[] = "%*s%*s%*s%*s";

  int res2 = sscanf(str, "%*s%*s%*s%*s");
  int res1 = s21_sscanf(str, fstr);

  ck_assert_int_eq(res1, res2);

  ck_assert_str_eq(s1, s5);
  ck_assert_str_eq(s2, s6);
  ck_assert_str_eq(s3, s7);
  ck_assert_str_eq(s4, s8);
}
END_TEST

START_TEST(Test_s_5) {
  char s1[BUFF_SIZE] = {'\0'};
  char s2[BUFF_SIZE] = {'\0'};
  char s3[BUFF_SIZE] = {'\0'};
  char s4[BUFF_SIZE] = {'\0'};

  char s5[BUFF_SIZE] = {'\0'};
  char s6[BUFF_SIZE] = {'\0'};
  char s7[BUFF_SIZE] = {'\0'};
  char s8[BUFF_SIZE] = {'\0'};

  char str[] = "ergsg\agagaa\agagdfgdd\aggerere";
  char fstr[] = "%1s%1s%1s%1s";

  int res1 = s21_sscanf(str, fstr, s1, s2, s3, s4);
  int res2 = sscanf(str, fstr, s5, s6, s7, s8);

  ck_assert_int_eq(res1, res2);

  ck_assert_str_eq(s1, s5);
  ck_assert_str_eq(s2, s6);
  ck_assert_str_eq(s3, s7);
  ck_assert_str_eq(s4, s8);
}
END_TEST

START_TEST(Test_s_6) {
  char s1[BUFF_SIZE] = {'\0'};
  char s2[BUFF_SIZE] = {'\0'};
  char s3[BUFF_SIZE] = {'\0'};
  char s4[BUFF_SIZE] = {'\0'};

  char s5[BUFF_SIZE] = {'\0'};
  char s6[BUFF_SIZE] = {'\0'};
  char s7[BUFF_SIZE] = {'\0'};
  char s8[BUFF_SIZE] = {'\0'};

  char str[] = "1412fggfqrteererasdf";
  char fstr[] = "%3s%2s%3s%1s";

  int res1 = s21_sscanf(str, fstr, s1, s2, s3, s4);
  int res2 = sscanf(str, fstr, s5, s6, s7, s8);

  ck_assert_int_eq(res1, res2);

  ck_assert_str_eq(s1, s5);
  ck_assert_str_eq(s2, s6);
  ck_assert_str_eq(s3, s7);
  ck_assert_str_eq(s4, s8);
}
END_TEST

START_TEST(Test_s_7) {
  char s1[BUFF_SIZE] = {'\0'};
  char s2[BUFF_SIZE] = {'\0'};
  char s3[BUFF_SIZE] = {'\0'};
  char s4[BUFF_SIZE] = {'\0'};

  char s5[BUFF_SIZE] = {'\0'};
  char s6[BUFF_SIZE] = {'\0'};
  char s7[BUFF_SIZE] = {'\0'};
  char s8[BUFF_SIZE] = {'\0'};

  char str[] = "efwfqerweqweqwrqwww";
  char fstr[] = "%150s%1s%1s %3s";

  int res1 = s21_sscanf(str, fstr, s1, s2, s3, s4);
  int res2 = sscanf(str, fstr, s5, s6, s7, s8);

  ck_assert_int_eq(res1, res2);

  ck_assert_str_eq(s1, s5);
  ck_assert_str_eq(s2, s6);
  ck_assert_str_eq(s3, s7);
  ck_assert_str_eq(s4, s8);
}
END_TEST

START_TEST(Test_s_8) {
  unsigned long long int a1 = 0, a2 = 0, b1 = 0, b2 = 0, c1 = 0, c2 = 0;
  long long d1 = 0, d2 = 0;
  long double e1 = 0, e2 = 0;

  char str[] =
      "4444444"
      "eeeeeee eeeeeee";
  char fstr[] = "%5s %1s %*s %lu %s %lu %lu %ld %Lf %3s";

  char s1[BUFF_SIZE] = {'\0'};
  char s2[BUFF_SIZE] = {'\0'};
  char s3[BUFF_SIZE] = {'\0'};
  char s4[BUFF_SIZE] = {'\0'};
  char s5[BUFF_SIZE] = {'\0'};
  char s6[BUFF_SIZE] = {'\0'};
  char s7[BUFF_SIZE] = {'\0'};
  char s8[BUFF_SIZE] = {'\0'};
  char s9[BUFF_SIZE] = {'\0'};
  char s10[BUFF_SIZE] = {'\0'};

  int res1 = s21_sscanf(str, fstr, s7, s9, &a1, s5, &b1, &c1, &d1, &e1, s1);
  int res2 = sscanf(str, fstr, s8, s10, &a2, s6, &b2, &c2, &d2, &e2, s2);

  ck_assert_int_eq(res1, res2);
  ck_assert_str_eq(s1, s2);
  ck_assert_str_eq(s3, s4);
  ck_assert_str_eq(s5, s6);
  ck_assert_int_eq(a1, a2);
  ck_assert_int_eq(b1, b2);
  ck_assert_int_eq(c1, c2);
  ck_assert_int_eq(d1, d2);
}
END_TEST

START_TEST(Test_s_9) {
  char s1[BUFF_SIZE] = {'\0'};
  char s2[BUFF_SIZE] = {'\0'};

  char str[] = "I'm";
  char fstr[] = "%ls";

  int res1 = s21_sscanf(str, fstr, s1);
  int res2 = sscanf(str, fstr, s2);

  ck_assert_int_eq(res1, res2);

  ck_assert_str_eq(s1, s2);
}
END_TEST

START_TEST(Test_n_1) {
  long int a1 = 0, a2 = 0, b1 = 0, b2 = 0, c1 = 0, c2 = 0, d1 = 0, d2 = 0;
  int n1 = 0, n2 = 5;

  char str[BUFF_SIZE] = "51 542 61 16";
  char fstr[BUFF_SIZE] = "%li %li %n %li %li";

  int res1 = s21_sscanf(str, fstr, &a1, &b1, &n1, &c1, &d1);
  int res2 = sscanf(str, fstr, &a2, &b2, &n2, &c2, &d2);

  ck_assert_int_eq(res1, res2);
  ck_assert_int_eq(n1, n2);
  ck_assert_int_eq(a1, a2);
  ck_assert_int_eq(b1, b2);
  ck_assert_int_eq(c1, c2);
  ck_assert_int_eq(d1, d2);
}
END_TEST

START_TEST(Test_n_2) {
  int n1 = 1, n2 = 5;

  char s1[BUFF_SIZE] = {'\0'};
  char s2[BUFF_SIZE] = {'\0'};
  char s3[BUFF_SIZE] = {'\0'};
  char s5[BUFF_SIZE] = {'\0'};
  char s6[BUFF_SIZE] = {'\0'};
  char s7[BUFF_SIZE] = {'\0'};

  char str[] = "gsgqqq fl? qegeryere ryertww wtwetw 2522";
  char fstr[] = "%s %s %n %s";

  int res1 = s21_sscanf(str, fstr, s1, s2, &n1, s3);
  int res2 = sscanf(str, fstr, s5, s6, &n2, s7);

  ck_assert_int_eq(res1, res2);

  ck_assert_int_eq(n1, n2);
  ck_assert_str_eq(s1, s5);
  ck_assert_str_eq(s2, s6);
  ck_assert_str_eq(s3, s7);
}
END_TEST

START_TEST(Test_n_3) {
  int n1 = 0, n2 = 5;

  char str[BUFF_SIZE] = "51 61 81 91";
  char fstr[BUFF_SIZE] = "%n";

  int res1 = s21_sscanf(str, fstr, &n1);
  int res2 = sscanf(str, fstr, &n2);

  ck_assert_int_eq(res1, res2);
  ck_assert_int_eq(n1, n2);
}
END_TEST

START_TEST(Test_n_4) {
  long long a1 = 0, a2 = 0, b1 = 0, b2 = 0, c1 = 0, c2 = 0, d1 = 0, d2 = 0;
  int n1 = 0, n2 = 5;

  char str[] = "51 20 10 60";
  char fstr[] = "%li %li %n %li %li";

  int res1 = s21_sscanf(str, fstr, &a1, &b1, &n1, &c1, &d1);
  int res2 = sscanf(str, fstr, &a2, &b2, &n2, &c2, &d2);

  ck_assert_int_eq(res1, res2);
  ck_assert_int_eq(n1, n2);
  ck_assert_int_eq(a1, a2);
  ck_assert_int_eq(b1, b2);
  ck_assert_int_eq(c1, c2);
  ck_assert_int_eq(d1, d2);
}
END_TEST

START_TEST(Test_n_5) {
  long int a1 = 0, a2 = 0, b1 = 0, b2 = 0, c1 = 0, c2 = 0, d1 = 0, d2 = 0;
  int n1 = 0, n2 = 5;

  char str[] = "50 60 70 80";
  char fstr[] = "%li %li %n %li %li";

  int res1 = s21_sscanf(str, fstr, &a1, &b1, &n1, &c1, &d1);
  int res2 = sscanf(str, fstr, &a2, &b2, &n2, &c2, &d2);

  ck_assert_int_eq(res1, res2);
  ck_assert_int_eq(n1, n2);
  ck_assert_int_eq(a1, a2);
  ck_assert_int_eq(b1, b2);
  ck_assert_int_eq(c1, c2);
  ck_assert_int_eq(d1, d2);
}
END_TEST

START_TEST(Test_n_6) {
  int n1 = 0, n2 = 5;

  char str[BUFF_SIZE] = "51 61 81 91";
  char fstr[BUFF_SIZE] = "%hn";

  int res1 = s21_sscanf(str, fstr, &n1);
  int res2 = sscanf(str, fstr, &n2);

  ck_assert_int_eq(res1, res2);
  ck_assert_int_eq(n1, n2);
}
END_TEST

START_TEST(Test_f_1) {
  long double a1 = 1, a2 = 0, b1 = 1, b2 = 0, c1 = 1, c2 = 0, d1 = 1, d2 = 0;

  char str[] = "53.1 -4.1135 41.3333 +2.0001";
  char fstr[] = "%Lf %Lf %Lf %Lf";

  int res1 = s21_sscanf(str, fstr, &a1, &b1, &c1, &d1);
  int res2 = sscanf(str, fstr, &a2, &b2, &c2, &d2);

  ck_assert_int_eq(res1, res2);
  ck_assert_float_eq(a1, a2);
  ck_assert_float_eq(b1, b2);
  ck_assert_float_eq(c1, c2);
  ck_assert_float_eq(d1, d2);
}
END_TEST

START_TEST(Test_f_2) {
  double a1 = 0, a2 = 0, b1 = 0, b2 = 0, c1 = 0, c2 = 0, d1 = 0, d2 = 0;

  char str[] = "0.00002 -5123123 7. .";
  char fstr[] = "%lf %lf %lf %lf";

  int res1 = s21_sscanf(str, fstr, &a1, &b1, &c1, &d1);
  int res2 = sscanf(str, fstr, &a2, &b2, &c2, &d2);

  ck_assert_int_eq(res1, res2);
  ck_assert_float_eq(a1, a2);
  ck_assert_float_eq(b1, b2);
  ck_assert_float_eq(c1, c2);
  ck_assert_float_eq(d1, d2);
}
END_TEST

START_TEST(Test_f_3) {
  float a1 = 0, a2 = 0, b1 = 0, b2 = 0, c1 = 0, c2 = 0, d1 = 0, d2 = 0;

  char str[] = ". . . .";
  char fstr[] = "%f %f %f %f";

  int res1 = s21_sscanf(str, fstr, &a1, &b1, &c1, &d1);
  int res2 = sscanf(str, fstr, &a2, &b2, &c2, &d2);

  ck_assert_int_eq(res1, res2);
  ck_assert_float_eq(a1, a2);
  ck_assert_float_eq(b1, b2);
  ck_assert_float_eq(c1, c2);
  ck_assert_float_eq(d1, d2);
}
END_TEST

START_TEST(Test_f_4) {
  long double a1 = 0, a2 = 0, b1 = 0, b2 = 0, c1 = 0, c2 = 0, d1 = 0, d2 = 0;

  char str[] = "513.41 -4.14135 414.3333 +112.0001";
  char fstr[] = "%Lf %Lf %Lf %Lf";

  int res1 = s21_sscanf(str, fstr, &a1, &b1, &c1, &d1);
  int res2 = sscanf(str, fstr, &a2, &b2, &c2, &d2);

  ck_assert_int_eq(res1, res2);
  ck_assert_float_eq(a1, a2);
  ck_assert_float_eq(b1, b2);
  ck_assert_float_eq(c1, c2);
  ck_assert_float_eq(d1, d2);
}
END_TEST

START_TEST(Test_f_5) {
  float a1 = 0, a2 = 0, b1 = 0, b2 = 0, c1 = 0, c2 = 0;

  char str[] = "51.1 -7.5135 912131.533 +3.0008";
  char fstr[] = "%*f %f %f %f";

  int res1 = s21_sscanf(str, fstr, &a1, &b1, &c1);
  int res2 = sscanf(str, fstr, &a2, &b2, &c2);

  ck_assert_int_eq(res1, res2);
  ck_assert_float_eq(a1, a2);
  ck_assert_float_eq(b1, b2);
  ck_assert_float_eq(c1, c2);
}
END_TEST

START_TEST(Test_f_6) {
  double a1 = 0, a2 = 0, b1 = 0, b2 = 0, c1 = 0, c2 = 0, d1 = 0, d2 = 0;

  char str[] = "NAN -5123123 7. .";
  char fstr[] = "%lf %lf %lf %lf";

  int res1 = s21_sscanf(str, fstr, &a1, &b1, &c1, &d1);
  int res2 = sscanf(str, fstr, &a2, &b2, &c2, &d2);

  ck_assert_int_eq(res1, res2);
  ck_assert_double_nan(a1);
  ck_assert_float_eq(b1, b2);
  ck_assert_float_eq(c1, c2);
  ck_assert_float_eq(d1, d2);
}
END_TEST

START_TEST(Test_f_7) {
  double a1 = 0, a2 = 0, b1 = 0, b2 = 0, c1 = 0, c2 = 0, d1 = 0, d2 = 0;

  char str[] = "2.1 -5123123 7. inf";
  char fstr[] = "%lf %lf %lf %lf";

  int res1 = s21_sscanf(str, fstr, &a1, &b1, &c1, &d1);
  int res2 = sscanf(str, fstr, &a2, &b2, &c2, &d2);

  ck_assert_int_eq(res1, res2);
  ck_assert_float_eq(a1, a2);
  ck_assert_float_eq(b1, b2);
  ck_assert_float_eq(c1, c2);
  ck_assert_float_eq(d1, d2);
}
END_TEST

START_TEST(Test_G_1) {
  float a1 = 0, a2 = 0, b1 = 0, b2 = 0, c1 = 0, c2 = 0, d1 = 0, d2 = 0;

  char str[] = "2.5122 3.41e+4 -5.32e-4 0.564e-2";
  char fstr[] = "%G %G %G %G";

  int res1 = s21_sscanf(str, fstr, &a1, &b1, &c1, &d1);
  int res2 = sscanf(str, fstr, &a2, &b2, &c2, &d2);

  ck_assert_int_eq(res1, res2);
  ck_assert_float_eq(a1, a2);
  ck_assert_float_eq(b1, b2);
  ck_assert_float_eq(c1, c2);
  ck_assert_float_eq(d1, d2);
}
END_TEST

START_TEST(Test_G_2) {
  float a1 = 0, a2 = 0, b1 = 0, b2 = 0, c1 = 0, c2 = 0, d1 = 0, d2 = 0;

  char str[] = "inf 3.11e+3 NaN 0.4244e-3";
  char fstr[] = "%G %G %G %G";

  int res1 = s21_sscanf(str, fstr, &a1, &b1, &c1, &d1);
  int res2 = sscanf(str, fstr, &a2, &b2, &c2, &d2);

  ck_assert_int_eq(res1, res2);
  ck_assert_float_eq(a1, a2);
  ck_assert_float_eq(b1, b2);
  ck_assert_float_nan(c1);
  ck_assert_float_nan(c2);
  ck_assert_float_eq(d1, d2);
}
END_TEST

START_TEST(Test_G_3) {
  float a1 = 0, a2 = 0, b1 = 0, b2 = 0, c1 = 0, c2 = 0, d1 = 0, d2 = 0;

  char str[] = "inF InF inF INF";
  char fstr[] = "%G %G %G %G";

  int res1 = s21_sscanf(str, fstr, &a1, &b1, &c1, &d1);
  int res2 = sscanf(str, fstr, &a2, &b2, &c2, &d2);

  ck_assert_int_eq(res1, res2);
  ck_assert_float_eq(a1, a2);
  ck_assert_float_eq(b1, b2);
  ck_assert_float_eq(c1, c2);
  ck_assert_float_eq(d1, d2);
}
END_TEST

START_TEST(Test_G_4) {
  float a1 = 0, a2 = 0, b1 = 0, b2 = 0, c1 = 0, c2 = 0, d1 = 0, d2 = 0;

  char str[] = "Nan NAN 0.0000 0";
  char fstr[] = "%G %G %G %G";

  int res1 = s21_sscanf(str, fstr, &a1, &b1, &c1, &d1);
  int res2 = sscanf(str, fstr, &a2, &b2, &c2, &d2);

  ck_assert_int_eq(res1, res2);
  ck_assert_float_nan(a1);
  ck_assert_float_nan(a2);
  ck_assert_float_nan(b1);
  ck_assert_float_nan(b2);
  ck_assert_float_eq(c1, c2);
  ck_assert_float_eq(d1, d2);
}
END_TEST

START_TEST(Test_G_5) {
  float a1 = 0, a2 = 0, b1 = 0, b2 = 0, c1 = 0, c2 = 0, d1 = 0, d2 = 0;

  char str[] = "nAN           INF       -0.1211         1e-10";
  char fstr[] = "%G %G %G %G";

  int res1 = s21_sscanf(str, fstr, &a1, &b1, &c1, &d1);
  int res2 = sscanf(str, fstr, &a2, &b2, &c2, &d2);

  ck_assert_int_eq(res1, res2);
  ck_assert_float_nan(a1);
  ck_assert_float_nan(a2);
  ck_assert_ldouble_eq(b1, b2);
  ck_assert_ldouble_eq(c1, c2);
  ck_assert_ldouble_eq(d1, d2);
}
END_TEST

START_TEST(Test_G_6) {
  double a1 = 0, a2 = 0, b1 = 0, b2 = 0, c1 = 0, c2 = 0, d1 = 0, d2 = 0;

  char str[] = "nAN           INF       -0.12221         1e-10";
  char fstr[] = "%lG %lG %lG %lG";

  int res1 = s21_sscanf(str, fstr, &a1, &b1, &c1, &d1);
  int res2 = sscanf(str, fstr, &a2, &b2, &c2, &d2);

  ck_assert_int_eq(res1, res2);
  ck_assert_double_nan(a1);
  ck_assert_double_nan(a2);
  ck_assert_float_eq(b1, b2);
  ck_assert_float_eq(c1, c2);
  ck_assert_float_eq(d1, d2);
}
END_TEST

START_TEST(Test_G_7) {
  double a1 = 0, a2 = 0, b1 = 0, b2 = 0, c1 = 0, c2 = 0, d1 = 0, d2 = 0;

  char str[] = "Inf           Nan       -0.00001         1e+10";
  char fstr[] = "%lG %lG %lG %lG";

  int res1 = s21_sscanf(str, fstr, &a1, &b1, &c1, &d1);
  int res2 = sscanf(str, fstr, &a2, &b2, &c2, &d2);

  ck_assert_int_eq(res1, res2);
  ck_assert_double_infinite(a1);
  ck_assert_double_infinite(a2);
  ck_assert_ldouble_nan(b1);
  ck_assert_ldouble_nan(b2);
  ck_assert_float_eq(c1, c2);
  ck_assert_float_eq(d1, d2);
}
END_TEST

START_TEST(Test_G_8) {
  long double a1 = 0, a2 = 0, b1 = 0, b2 = 0, c1 = 0, c2 = 0;

  char str[] = "-0.000000000001         0.000000000002 0.000000000000000001";
  char fstr[] = "%lG %LG %lg";

  int res1 = s21_sscanf(str, fstr, &a1, &b1, &c1);
  int res2 = sscanf(str, fstr, &a2, &b2, &c2);

  ck_assert_int_eq(res1, res2);
  ck_assert_float_eq(a1, a2);
  ck_assert_float_eq(b1, b2);
  ck_assert_float_eq(c1, c2);
}
END_TEST

START_TEST(Test_u_1) {
  short int a1 = 0, a2 = 0, b1 = 0, b2 = 0, c1 = 0, c2 = 0, d1 = 0, d2 = 0;
  char str[] = "-1337 +21 --5008 3000";
  char fstr[] = "%hu %hu %hu %hu";

  int res1 = s21_sscanf(str, fstr, &a1, &b1, &c1, &d1);
  int res2 = sscanf(str, fstr, &a2, &b2, &c2, &d2);

  ck_assert_uint_eq(res1, res2);
  ck_assert_uint_eq(a1, a2);
  ck_assert_uint_eq(b1, b2);
  ck_assert_uint_eq(c1, c2);
  ck_assert_uint_eq(d1, d2);
}
END_TEST

START_TEST(Test_u_2) {
  long int a1 = 0, a2 = 0, b1 = 0, b2 = 0, c1 = 0, c2 = 0, d1 = 0, d2 = 0;
  char str[] = "121 -2542433331 1238 1410";
  char fstr[] = "%1lu %2lu %5lu %4lu";

  int res1 = s21_sscanf(str, fstr, &a1, &b1, &c1, &d1);
  int res2 = sscanf(str, fstr, &a2, &b2, &c2, &d2);

  ck_assert_int_eq(res1, res2);
  ck_assert_int_eq(a1, a2);
  ck_assert_int_eq(b1, b2);
  ck_assert_int_eq(c1, c2);
  ck_assert_int_eq(d1, d2);
}
END_TEST

START_TEST(Test_u_3) {
  long int a1 = 0, a2 = 0, b1 = 0, b2 = 0, c1 = 0, c2 = 0;
  long long d1 = 0, d2 = 0;
  float v1, v2;

  char str[] = "ger erwww -1213    12 -5238 0.34333";
  char fstr[] = "%s %s %lu %lu %ld %f";

  char s1[BUFF_SIZE] = {'\0'};
  char s2[BUFF_SIZE] = {'\0'};

  int res1 = s21_sscanf(str, fstr, &a1, s1, &b1, &c1, &d1, &v1);
  int res2 = sscanf(str, fstr, &a2, s2, &b2, &c2, &d2, &v2);

  ck_assert_uint_eq(res1, res2);
  ck_assert_str_eq(s1, s2);
  ck_assert_uint_eq(a1, a2);
  ck_assert_uint_eq(b1, b2);
  ck_assert_uint_eq(c1, c2);
  ck_assert_uint_eq(d1, d2);
  ck_assert_double_eq(v1, v2);
}
END_TEST

START_TEST(Test_u_4) {
  short int a1 = 0, a2 = 0, b1 = 0, b2 = 0, c1 = 0, c2 = 0, d1 = 0, d2 = 0;
  char str[] = "-1227 +11 --5208 1000";
  char fstr[] = "%hu %hu %hu %hu";

  int res1 = s21_sscanf(str, fstr, &a1, &b1, &c1, &d1);
  int res2 = sscanf(str, fstr, &a2, &b2, &c2, &d2);

  ck_assert_int_eq(res1, res2);
  ck_assert_int_eq(a1, a2);
  ck_assert_int_eq(b1, b2);
  ck_assert_int_eq(c1, c2);
  ck_assert_int_eq(d1, d2);
}
END_TEST

START_TEST(Test_u_5) {
  int a1 = 0, a2 = 0, b1 = 0, b2 = 0, c1 = 0, c2 = 0, d1 = 0, d2 = 0;
  char str[] = "-1337 +21 --5008 3000";
  char fstr[] = "%hu %hu %hu %hu";

  int res1 = s21_sscanf(str, fstr, &a1, &b1, &c1, &d1);
  int res2 = sscanf(str, fstr, &a2, &b2, &c2, &d2);

  ck_assert_int_eq(res1, res2);
  ck_assert_int_eq(a1, a2);
  ck_assert_int_eq(b1, b2);
  ck_assert_int_eq(c1, c2);
  ck_assert_int_eq(d1, d2);
}
END_TEST

START_TEST(Test_u_6) {
  int a1 = 0, a2 = 0, b1 = 0, b2 = 0, c1 = 0, c2 = 0, d1 = 0, d2 = 0;
  char str[] = "-1337 +21 --5008 3000";
  char fstr[] = "%hu %hu %hu %hu";

  int res1 = s21_sscanf(str, fstr, &a1, &b1, &c1, &d1);
  int res2 = sscanf(str, fstr, &a2, &b2, &c2, &d2);

  ck_assert_int_eq(res1, res2);
  ck_assert_int_eq(a1, a2);
  ck_assert_int_eq(b1, b2);
  ck_assert_int_eq(c1, c2);
  ck_assert_int_eq(d1, d2);
}
END_TEST

START_TEST(Test_X_1) {
  int a1, a2;
  char str[] = "F";
  char fstr[] = "%X";
  int res1 = s21_sscanf(str, fstr, &a1);
  int res2 = sscanf(str, fstr, &a2);

  ck_assert_int_eq(res1, res2);
  ck_assert_int_eq(a1, a2);
}
END_TEST

START_TEST(Test_X_2) {
  int a1, a2;
  char str[] = "0xFFFFFFFF";
  char fstr[] = "%X";
  int res1 = s21_sscanf(str, fstr, &a1);
  int res2 = sscanf(str, fstr, &a2);

  ck_assert_int_eq(res1, res2);
  ck_assert_int_eq(a1, a2);
}
END_TEST

START_TEST(Test_X_3) {
  int a1, a2;
  char str[] = "0x";
  char fstr[] = "%X";
  int res1 = s21_sscanf(str, fstr, &a1);
  int res2 = sscanf(str, fstr, &a2);

  ck_assert_int_eq(res1, res2);
  ck_assert_int_eq(a1, a2);
}
END_TEST

START_TEST(Test_X_4) {
  int a1, a2;
  char str[] = "0X";
  char fstr[] = "%X";
  int res1 = s21_sscanf(str, fstr, &a1);
  int res2 = sscanf(str, fstr, &a2);

  ck_assert_int_eq(res1, res2);
  ck_assert_int_eq(a1, a2);
}
END_TEST

START_TEST(Test_X_5) {
  int a1, a2;
  char str[] = "";
  char fstr[] = "%X";
  int res1 = s21_sscanf(str, fstr, &a1);
  int res2 = sscanf(str, fstr, &a2);

  ck_assert_int_eq(res1, res2);
}
END_TEST

START_TEST(Test_X_6) {
  int a1, a2;
  char str[] = "qS";
  char fstr[] = "%X";
  int res1 = s21_sscanf(str, fstr, &a1);
  int res2 = sscanf(str, fstr, &a2);

  ck_assert_int_eq(res1, res2);
}
END_TEST

START_TEST(Test_X_7) {
  int a1 = 0, a2 = 0;
  char str[] = "        \n             \n     S";
  char fstr[] = "%X";
  int res1 = s21_sscanf(str, fstr, &a1);
  int res2 = sscanf(str, fstr, &a2);

  ck_assert_int_eq(res1, res2);
  ck_assert_int_eq(a1, a2);
}
END_TEST

START_TEST(Test_X_8) {
  short a1 = 1, a2 = 1;
  char str[] = "S";
  char fstr[] = "%hX";
  int res1 = s21_sscanf(str, fstr, &a1);
  int res2 = sscanf(str, fstr, &a2);

  ck_assert_int_eq(res1, res2);
  ck_assert_int_eq(a1, a2);
}
END_TEST

START_TEST(Test_X_9) {
  long int a1 = 1, a2 = 1;
  char str[] = "S";
  char fstr[] = "%lX";
  int res1 = s21_sscanf(str, fstr, &a1);
  int res2 = sscanf(str, fstr, &a2);

  ck_assert_int_eq(res1, res2);
  ck_assert_int_eq(a1, a2);
}
END_TEST

START_TEST(Test_X_10) {
  long int a1, a2;
  char str[] = "F";
  char fstr[] = "%lX";
  int res1 = s21_sscanf(str, fstr, &a1);
  int res2 = sscanf(str, fstr, &a2);

  ck_assert_int_eq(res1, res2);
  ck_assert_int_eq(a1, a2);
}
END_TEST

START_TEST(Test_X_11) {
  int a1, a2;
  char str[] = "0xFF0x0xFFF 0xFFxFF";
  char fstr[] = "%X";
  int res1 = s21_sscanf(str, fstr, &a1);
  int res2 = sscanf(str, fstr, &a2);

  ck_assert_int_eq(res1, res2);
  ck_assert_int_eq(a1, a2);
}
END_TEST

START_TEST(Test_X_13) {
  int a1, a2;
  char str[] = "qertqr";
  char fstr[] = "%X";
  int res1 = s21_sscanf(str, fstr, &a1);
  int res2 = sscanf(str, fstr, &a2);

  ck_assert_int_eq(res1, res2);
}
END_TEST

START_TEST(Test_X_14) {
  int a1, a2;
  char str[] = "ergeee";
  char fstr[] = "%X";
  int res1 = s21_sscanf(str, fstr, &a1);
  int res2 = sscanf(str, fstr, &a2);

  ck_assert_int_eq(res1, res2);
  ck_assert_int_eq(a1, a2);
}
END_TEST

START_TEST(Test_X_15) {
  int a1, a2;
  char str[] = "-f";
  char fstr[] = "%X";
  int res1 = s21_sscanf(str, fstr, &a1);
  int res2 = sscanf(str, fstr, &a2);

  ck_assert_int_eq(res1, res2);
  ck_assert_int_eq(a1, a2);
}
END_TEST

START_TEST(Test_x_1) {
  int a1, a2;
  char str[] = "f";
  char fstr[] = "%x";
  int res1 = s21_sscanf(str, fstr, &a1);
  int res2 = sscanf(str, fstr, &a2);

  ck_assert_int_eq(res1, res2);
  ck_assert_int_eq(a1, a2);
}
END_TEST

START_TEST(Test_x_2) {
  int a1, a2;
  char str[] = "0xfffffffffffffffffff";
  char fstr[] = "%x";
  int res1 = s21_sscanf(str, fstr, &a1);
  int res2 = sscanf(str, fstr, &a2);

  ck_assert_int_eq(res1, res2);
  ck_assert_int_eq(a1, a2);
}
END_TEST

START_TEST(Test_x_3) {
  int a1, a2;
  char str[] = "0x";
  char fstr[] = "%x";
  int res1 = s21_sscanf(str, fstr, &a1);
  int res2 = sscanf(str, fstr, &a2);

  ck_assert_int_eq(res1, res2);
  ck_assert_int_eq(a1, a2);
}
END_TEST

START_TEST(Test_x_4) {
  int a1, a2;
  char str[] = "0X";
  char fstr[] = "%x";
  int res1 = s21_sscanf(str, fstr, &a1);
  int res2 = sscanf(str, fstr, &a2);

  ck_assert_int_eq(res1, res2);
  ck_assert_int_eq(a1, a2);
}
END_TEST

START_TEST(Test_x_5) {
  int a1, a2;
  char str[] = "";
  char fstr[] = "%x";
  int res1 = s21_sscanf(str, fstr, &a1);
  int res2 = sscanf(str, fstr, &a2);

  ck_assert_int_eq(res1, res2);
}
END_TEST

START_TEST(Test_x_6) {
  int a1, a2;
  char str[] = "qF";
  char fstr[] = "%x";
  int res1 = s21_sscanf(str, fstr, &a1);
  int res2 = sscanf(str, fstr, &a2);

  ck_assert_int_eq(res1, res2);
}
END_TEST

START_TEST(Test_x_7) {
  int a1, a2;
  char str[] = "          \n             \n     F";
  char fstr[] = "%x";
  int res1 = s21_sscanf(str, fstr, &a1);
  int res2 = sscanf(str, fstr, &a2);

  ck_assert_int_eq(res1, res2);
  ck_assert_int_eq(a1, a2);
}
END_TEST

START_TEST(Test_x_8) {
  short a1, a2;
  char str[] = "ff";
  char fstr[] = "%hx";
  int res1 = s21_sscanf(str, fstr, &a1);
  int res2 = sscanf(str, fstr, &a2);

  ck_assert_int_eq(res1, res2);
  ck_assert_int_eq(a1, a2);
}
END_TEST

START_TEST(Test_x_9) {
  long int a1, a2;
  char str[] = "fa";
  char fstr[] = "%lx";
  int res1 = s21_sscanf(str, fstr, &a1);
  int res2 = sscanf(str, fstr, &a2);

  ck_assert_int_eq(res1, res2);
  ck_assert_int_eq(a1, a2);
}
END_TEST

START_TEST(Test_x_10) {
  long int a1, a2;
  char str[] = "faaafaaaaf";
  char fstr[] = "%lx";
  int res1 = s21_sscanf(str, fstr, &a1);
  int res2 = sscanf(str, fstr, &a2);

  ck_assert_int_eq(res1, res2);
  ck_assert_uint_eq(a1, a2);
}
END_TEST

START_TEST(Test_x_11) {
  int a1, a2;
  char str[] = "0xFF0x0xFFF 0xFFxFF";
  char fstr[] = "%x";
  int res1 = s21_sscanf(str, fstr, &a1);
  int res2 = sscanf(str, fstr, &a2);

  ck_assert_int_eq(res1, res2);
  ck_assert_int_eq(a1, a2);
}
END_TEST

START_TEST(Test_x_13) {
  int a1, a2;
  char str[] = "tqwqpl";
  char fstr[] = "%x";
  int res1 = s21_sscanf(str, fstr, &a1);
  int res2 = sscanf(str, fstr, &a2);

  ck_assert_int_eq(res1, res2);
}
END_TEST

START_TEST(Test_x_14) {
  int a1, a2;
  char str[] = "abcdef";
  char fstr[] = "%x";
  int res1 = s21_sscanf(str, fstr, &a1);
  int res2 = sscanf(str, fstr, &a2);

  ck_assert_int_eq(res1, res2);
  ck_assert_int_eq(a1, a2);
}
END_TEST

START_TEST(Test_x_15) {
  int a1, a2;
  char str[] = "-f";
  char fstr[] = "%x";
  int res1 = s21_sscanf(str, fstr, &a1);
  int res2 = sscanf(str, fstr, &a2);

  ck_assert_int_eq(res1, res2);
  ck_assert_int_eq(a1, a2);
}
END_TEST

START_TEST(Test_x_16) {
  int a1, a2;
  char str[] = "12123FFF";
  char fstr[] = "%2X";
  int res1 = s21_sscanf(str, fstr, &a1);
  int res2 = sscanf(str, fstr, &a2);

  ck_assert_int_eq(res1, res2);
  ck_assert_int_eq(a1, a2);
}
END_TEST

START_TEST(Test_x_17) {
  int a1, a2;
  char str[] = "131231FFF";
  char fstr[] = "%2x";
  int res1 = s21_sscanf(str, fstr, &a1);
  int res2 = sscanf(str, fstr, &a2);

  ck_assert_int_eq(res1, res2);
  ck_assert_int_eq(a1, a2);
}
END_TEST

START_TEST(Test_o_1) {
  int a1, a2;
  char str[] = "521";
  char fstr[] = "%o";
  int res1 = s21_sscanf(str, fstr, &a1);
  int res2 = sscanf(str, fstr, &a2);

  ck_assert_int_eq(res1, res2);
  ck_assert_int_eq(a1, a2);
}
END_TEST

START_TEST(Test_o_2) {
  int a1, a2;
  char str[] = "0x7777777777777777777777";
  char fstr[] = "%o";
  int res1 = s21_sscanf(str, fstr, &a1);
  int res2 = sscanf(str, fstr, &a2);

  ck_assert_int_eq(res1, res2);
  ck_assert_int_eq(a1, a2);
}
END_TEST

START_TEST(Test_o_3) {
  int a1, a2;
  char str[] = "0x";
  char fstr[] = "%o";
  int res1 = s21_sscanf(str, fstr, &a1);
  int res2 = sscanf(str, fstr, &a2);

  ck_assert_int_eq(res1, res2);
  ck_assert_int_eq(a1, a2);
}
END_TEST

START_TEST(Test_o_4) {
  int a1, a2;
  char str[] = "0X";
  char fstr[] = "%o";
  int res1 = s21_sscanf(str, fstr, &a1);
  int res2 = sscanf(str, fstr, &a2);

  ck_assert_int_eq(res1, res2);
  ck_assert_int_eq(a1, a2);
}
END_TEST

START_TEST(Test_o_5) {
  int a1, a2;
  char str[] = "";
  char fstr[] = "%o";
  int res1 = s21_sscanf(str, fstr, &a1);
  int res2 = sscanf(str, fstr, &a2);

  ck_assert_int_eq(res1, res2);
}
END_TEST

START_TEST(Test_o_6) {
  int a1, a2;
  char str[] = "c1";
  char fstr[] = "%o";
  int res1 = s21_sscanf(str, fstr, &a1);
  int res2 = sscanf(str, fstr, &a2);

  ck_assert_int_eq(res1, res2);
}
END_TEST

START_TEST(Test_o_7) {
  int a1, a2;
  char str[] = "          \n             \n     5";
  char fstr[] = "%o";
  int res1 = s21_sscanf(str, fstr, &a1);
  int res2 = sscanf(str, fstr, &a2);

  ck_assert_int_eq(res1, res2);
  ck_assert_int_eq(a1, a2);
}
END_TEST

START_TEST(Test_o_8) {
  short a1, a2;
  char str[] = "15";
  char fstr[] = "%ho";
  int res1 = s21_sscanf(str, fstr, &a1);
  int res2 = sscanf(str, fstr, &a2);

  ck_assert_int_eq(res1, res2);
  ck_assert_int_eq(a1, a2);
}
END_TEST

START_TEST(Test_o_9) {
  long int a1, a2;
  char str[] = "57234";
  char fstr[] = "%lo";
  int res1 = s21_sscanf(str, fstr, &a1);
  int res2 = sscanf(str, fstr, &a2);

  ck_assert_int_eq(res1, res2);
  ck_assert_int_eq(a1, a2);
}
END_TEST

START_TEST(Test_o_10) {
  long int a1, a2;
  char str[] = "12356226137";
  char fstr[] = "%lo";
  int res1 = s21_sscanf(str, fstr, &a1);
  int res2 = sscanf(str, fstr, &a2);

  ck_assert_int_eq(res1, res2);
  ck_assert_int_eq(a1, a2);
}
END_TEST

START_TEST(Test_o_11) {
  int a1, a2;
  char str[] = "0x12320x213x123213";
  char fstr[] = "%o";
  int res1 = s21_sscanf(str, fstr, &a1);
  int res2 = sscanf(str, fstr, &a2);

  ck_assert_int_eq(res1, res2);
  ck_assert_int_eq(a1, a2);
}
END_TEST

START_TEST(Test_o_13) {
  int a1, a2;
  char str[] = "qwqww";
  char fstr[] = "%o";
  int res1 = s21_sscanf(str, fstr, &a1);
  int res2 = sscanf(str, fstr, &a2);

  ck_assert_int_eq(res1, res2);
}
END_TEST

START_TEST(Test_o_14) {
  int a1, a2;
  char str[] = "01234567";
  char fstr[] = "%o";
  int res1 = s21_sscanf(str, fstr, &a1);
  int res2 = sscanf(str, fstr, &a2);

  ck_assert_int_eq(res1, res2);
  ck_assert_int_eq(a1, a2);
}
END_TEST

START_TEST(Test_o_15) {
  int a1, a2;
  char str[] = "-12";
  char fstr[] = "%o";
  int res1 = s21_sscanf(str, fstr, &a1);
  int res2 = sscanf(str, fstr, &a2);

  ck_assert_int_eq(res1, res2);
  ck_assert_int_eq(a1, a2);
}
END_TEST

START_TEST(Test_o_16) {
  int a1, a2;
  char str[] = "111131";
  char fstr[] = "%2o";
  int res1 = s21_sscanf(str, fstr, &a1);
  int res2 = sscanf(str, fstr, &a2);

  ck_assert_int_eq(res1, res2);
  ck_assert_int_eq(a1, a2);
}
END_TEST

START_TEST(Test_p_1) {
  int *a1 = 0, *a2 = 0, *b1 = 0, *b2 = 0, *c1 = 0, *c2 = 0, *d1 = 0, *d2 = 0;
  char str[] = "0xFFFF 0xAAAA 0x7123 0xBBC1FF";
  char fstr[] = "%p %p %p %p";

  int res1 = s21_sscanf(str, fstr, &a1, &b1, &c1, &d1);
  int res2 = sscanf(str, fstr, &a2, &b2, &c2, &d2);

  ck_assert_int_eq(res1, res2);
  ck_assert_ptr_eq(a1, a2);
  ck_assert_ptr_eq(b1, b2);
  ck_assert_ptr_eq(c1, c2);
  ck_assert_ptr_eq(d1, d2);
}
END_TEST

START_TEST(Test_p_2) {
  int *a1 = 0, *a2 = 0, *b1 = 0, *b2 = 0, *c1 = 0, *c2 = 0, *d1 = 0, *d2 = 0;
  char str[] = "0xFFFF 0xAAAA 0x7123 0xBBC1FF";
  char fstr[] = "%p %p %p %p";

  int res1 = s21_sscanf(str, fstr, &a1, &b1, &c1, &d1);
  int res2 = sscanf(str, fstr, &a2, &b2, &c2, &d2);

  ck_assert_int_eq(res1, res2);
  ck_assert_ptr_eq(a1, a2);
  ck_assert_ptr_eq(b1, b2);
  ck_assert_ptr_eq(c1, c2);
  ck_assert_ptr_eq(d1, d2);
}
END_TEST

START_TEST(Test_p_3) {
  int *a1 = 0, *a2 = 0, *b1 = 0, *b2 = 0, *c1 = 0, *c2 = 0, *d1 = 0, *d2 = 0;
  char str[] = "0xFFFF 0xAAAA 0x7123 0xBBC1FF";
  char fstr[] = "%p %p %p %p";

  int res1 = s21_sscanf(str, fstr, &a1, &b1, &c1, &d1);
  int res2 = sscanf(str, fstr, &a2, &b2, &c2, &d2);

  ck_assert_int_eq(res1, res2);
  ck_assert_ptr_eq(a1, a2);
  ck_assert_ptr_eq(b1, b2);
  ck_assert_ptr_eq(c1, c2);
  ck_assert_ptr_eq(d1, d2);
}
END_TEST

START_TEST(Test_p_4) {
  int *a1 = 0, *a2 = 0, *b1 = 0, *b2 = 0, *c1 = 0, *c2 = 0, *d1 = 0, *d2 = 0;
  char str[] = "3FFF 12AA 0x123 0xD";
  char fstr[] = "%p %p %p %p";

  int res1 = s21_sscanf(str, fstr, &a1, &b1, &c1, &d1);
  int res2 = sscanf(str, fstr, &a2, &b2, &c2, &d2);

  ck_assert_int_eq(res1, res2);
  ck_assert_ptr_eq(a1, a2);
  ck_assert_ptr_eq(b1, b2);
  ck_assert_ptr_eq(c1, c2);
  ck_assert_ptr_eq(d1, d2);
}
END_TEST

START_TEST(Test_e_1) {
  double a1 = 1, a2 = 0, b1 = 1, b2 = 0, c1 = 1, c2 = 0, d1 = 1, d2 = 0;

  char str[] = "23.1 -4.11335 42.3333 +1.1001";
  char fstr[] = "%le %le %le %le";

  int res1 = s21_sscanf(str, fstr, &a1, &b1, &c1, &d1);
  int res2 = sscanf(str, fstr, &a2, &b2, &c2, &d2);

  ck_assert_int_eq(res1, res2);
  ck_assert_float_eq(a1, a2);
  ck_assert_float_eq(b1, b2);
  ck_assert_float_eq(c1, c2);
  ck_assert_float_eq(d1, d2);
}
END_TEST

START_TEST(Test_e_2) {
  long double a1 = 0, a2 = 0, b1 = 0, b2 = 0, c1 = 0, c2 = 0, d1 = 0, d2 = 0;

  char str[] = "0.02002 -1123 6. .";
  char fstr[] = "%Le %Le %Le %Le";

  int res1 = s21_sscanf(str, fstr, &a1, &b1, &c1, &d1);
  int res2 = sscanf(str, fstr, &a2, &b2, &c2, &d2);

  ck_assert_int_eq(res1, res2);
  ck_assert_float_eq(a1, a2);
  ck_assert_float_eq(b1, b2);
  ck_assert_float_eq(c1, c2);
  ck_assert_float_eq(d1, d2);
}
END_TEST

START_TEST(Test_e_3) {
  float a1 = 0, a2 = 0, b1 = 0, b2 = 0, c1 = 0, c2 = 0, d1 = 0, d2 = 0;

  char str[] = ". . . .";
  char fstr[] = "%e %e %e %e";

  int res1 = s21_sscanf(str, fstr, &a1, &b1, &c1, &d1);
  int res2 = sscanf(str, fstr, &a2, &b2, &c2, &d2);

  ck_assert_int_eq(res1, res2);
  ck_assert_double_eq(a1, a2);
  ck_assert_double_eq(b1, b2);
  ck_assert_double_eq(c1, c2);
  ck_assert_double_eq(d1, d2);
}
END_TEST

START_TEST(Test_e_4) {
  long double a1 = 0, a2 = 0, b1 = 0, b2 = 0, c1 = 0, c2 = 0, d1 = 0, d2 = 0;

  char str[] = "113.41 -4.235 114.3333 +222.0001";
  char fstr[] = "%Le %Le %Le %Le";

  int res1 = s21_sscanf(str, fstr, &a1, &b1, &c1, &d1);
  int res2 = sscanf(str, fstr, &a2, &b2, &c2, &d2);

  ck_assert_int_eq(res1, res2);
  ck_assert_float_eq(a1, a2);
  ck_assert_float_eq(b1, b2);
  ck_assert_float_eq(c1, c2);
  ck_assert_float_eq(d1, d2);
}
END_TEST

START_TEST(Test_percent_1) {
  int a1, a2, b1 = 1, b2 = 1, c1 = 0, c2 = 0, d1 = 0, d2 = 0;

  char str[] = " 23 -4.11335 42.3333 +1.1001";
  char fstr[] = " %d %% %% %%";

  int res1 = s21_sscanf(str, fstr, &a1, &b1, &c1, &d1);
  int res2 = sscanf(str, fstr, &a2, &b2, &c2, &d2);

  ck_assert_int_eq(res1, res2);
  ck_assert_int_eq(a1, a2);
  ck_assert_int_eq(b1, b2);
  ck_assert_int_eq(c1, c2);
  ck_assert_int_eq(d1, d2);
}
END_TEST

START_TEST(Test_percent_2) {
  long double a1 = 0, a2 = 0, b1 = 0, b2 = 0, c1 = 0, c2 = 0, d1 = 0, d2 = 0;

  char str[] = "e -1123 6. .";
  char fstr[] = "%% %Le %Le %%";

  int res1 = s21_sscanf(str, fstr, &a1, &b1, &c1, &d1);
  int res2 = sscanf(str, fstr, &a2, &b2, &c2, &d2);

  ck_assert_int_eq(res1, res2);
  ck_assert_double_eq(a1, a2);
  ck_assert_double_eq(b1, b2);
  ck_assert_double_eq(c1, c2);
  ck_assert_double_eq(d1, d2);
}
END_TEST

START_TEST(Test_percent_3) {
  float a1 = 0, a2 = 0, b1 = 0, b2 = 0, c1 = 0, c2 = 0, d1 = 0, d2 = 0;

  char str[] = ". . . .";
  char fstr[] = "%% %e %% %e";

  int res1 = s21_sscanf(str, fstr, &a1, &b1, &c1, &d1);
  int res2 = sscanf(str, fstr, &a2, &b2, &c2, &d2);

  ck_assert_int_eq(res1, res2);
  ck_assert_double_eq(a1, a2);
  ck_assert_double_eq(b1, b2);
  ck_assert_double_eq(c1, c2);
  ck_assert_double_eq(d1, d2);
}
END_TEST

START_TEST(Test_percent_4) {
  long double a1 = 0, a2 = 0, b1 = 0, b2 = 0, c1 = 0, c2 = 0, d1 = 0, d2 = 0;

  char str[] = "113.41  +222.0001";
  char fstr[] = "%Le %%";

  int res1 = s21_sscanf(str, fstr, &a1, &b1, &c1, &d1);
  int res2 = sscanf(str, fstr, &a2, &b2, &c2, &d2);

  ck_assert_int_eq(res1, res2);
  ck_assert_float_eq(a1, a2);
  ck_assert_double_eq(b1, b2);
  ck_assert_double_eq(c1, c2);
  ck_assert_double_eq(d1, d2);
}
END_TEST

START_TEST(Test_1) {
  char fstr[] = "%d";
  char str[] = "        ";

  int res1 = s21_sscanf(str, fstr, 0);
  int res2 = sscanf(str, fstr, 100);
  ck_assert_int_eq(res1, res2);
}
END_TEST

START_TEST(Test_2) {
  char fstr[] = "%d ";
  char str[] = "               ";
  int a1 = 0, a2 = 0;

  int res1 = s21_sscanf(str, fstr, &a1);
  int res2 = sscanf(str, fstr, &a2);
  ck_assert_int_eq(res1, res2);
}
END_TEST

START_TEST(Test_3) {
  char fstr[] = "%d ";
  char str[] = "  ";
  int a1 = 0, a2 = 0;

  int res1 = s21_sscanf(str, fstr, &a1);
  int res2 = sscanf(str, fstr, &a2);
  ck_assert_int_eq(res1, res2);
}
END_TEST

START_TEST(Test_4) {
  int a1, a2;
  int b1 = 0, b2 = 0;
  char str[] = "12wwsww 12";
  char fstr[] = "%derwraa %d";
  int res1 = s21_sscanf(str, fstr, &a1, &b1);
  int res2 = sscanf(str, fstr, &a2, &b2);

  ck_assert_int_eq(res1, res2);
  ck_assert_int_eq(a1, a2);
  ck_assert_int_eq(b1, b2);
}
END_TEST

Suite *s21_sscanf_suite(void) {
  Suite *s;
  TCase *ts_core;
  s = suite_create("\033[45m-=S21_SSCANF=-\033[0m");  // создает набор кейсов с
                                                      // заданным именем
  ts_core = tcase_create("case_sscanf");
  tcase_add_test(ts_core, Test_c_1);
  tcase_add_test(ts_core, Test_c_2);
  tcase_add_test(ts_core, Test_c_3);
  tcase_add_test(ts_core, Test_c_4);
  tcase_add_test(ts_core, Test_c_5);
  tcase_add_test(ts_core, Test_c_6);
  tcase_add_test(ts_core, Test_c_7);
  tcase_add_test(ts_core, Test_c_8);
  tcase_add_test(ts_core, Test_c_9);
  tcase_add_test(ts_core, Test_c_10);
  tcase_add_test(ts_core, Test_c_11);
  tcase_add_test(ts_core, Test_c_12);
  tcase_add_test(ts_core, Test_c_13);
  tcase_add_test(ts_core, Test_c_14);
  tcase_add_test(ts_core, Test_c_15);
  tcase_add_test(ts_core, Test_d_1);
  tcase_add_test(ts_core, Test_d_2);
  tcase_add_test(ts_core, Test_d_3);
  tcase_add_test(ts_core, Test_d_4);
  tcase_add_test(ts_core, Test_d_5);
  tcase_add_test(ts_core, Test_d_6);
  tcase_add_test(ts_core, Test_d_7);
  tcase_add_test(ts_core, Test_d_8);
  tcase_add_test(ts_core, Test_d_9);
  tcase_add_test(ts_core, Test_d_10);
  tcase_add_test(ts_core, Test_d_11);
  tcase_add_test(ts_core, Test_d_12);
  tcase_add_test(ts_core, Test_d_13);
  tcase_add_test(ts_core, Test_d_14);
  tcase_add_test(ts_core, Test_d_15);
  tcase_add_test(ts_core, Test_d_16);
  tcase_add_test(ts_core, Test_d_17);
  tcase_add_test(ts_core, Test_i_1);
  tcase_add_test(ts_core, Test_i_2);
  tcase_add_test(ts_core, Test_i_3);
  tcase_add_test(ts_core, Test_i_4);
  tcase_add_test(ts_core, Test_i_5);
  tcase_add_test(ts_core, Test_i_6);
  tcase_add_test(ts_core, Test_i_7);
  tcase_add_test(ts_core, Test_i_8);
  tcase_add_test(ts_core, Test_s_1);
  tcase_add_test(ts_core, Test_s_2);
  tcase_add_test(ts_core, Test_s_3);
  tcase_add_test(ts_core, Test_s_4);
  tcase_add_test(ts_core, Test_s_5);
  tcase_add_test(ts_core, Test_s_6);
  tcase_add_test(ts_core, Test_s_7);
  tcase_add_test(ts_core, Test_s_8);
  tcase_add_test(ts_core, Test_s_9);
  tcase_add_test(ts_core, Test_n_1);
  tcase_add_test(ts_core, Test_n_2);
  tcase_add_test(ts_core, Test_n_3);
  tcase_add_test(ts_core, Test_n_4);
  tcase_add_test(ts_core, Test_n_5);
  tcase_add_test(ts_core, Test_n_6);
  tcase_add_test(ts_core, Test_f_1);
  tcase_add_test(ts_core, Test_f_2);
  tcase_add_test(ts_core, Test_f_3);
  tcase_add_test(ts_core, Test_f_4);
  tcase_add_test(ts_core, Test_f_5);
  tcase_add_test(ts_core, Test_f_6);
  tcase_add_test(ts_core, Test_f_7);
  tcase_add_test(ts_core, Test_G_1);
  tcase_add_test(ts_core, Test_G_2);
  tcase_add_test(ts_core, Test_G_3);
  tcase_add_test(ts_core, Test_G_4);
  tcase_add_test(ts_core, Test_G_5);
  tcase_add_test(ts_core, Test_G_6);
  tcase_add_test(ts_core, Test_G_7);
  tcase_add_test(ts_core, Test_G_8);
  tcase_add_test(ts_core, Test_u_1);
  tcase_add_test(ts_core, Test_u_2);
  tcase_add_test(ts_core, Test_u_3);
  tcase_add_test(ts_core, Test_u_4);
  tcase_add_test(ts_core, Test_u_5);
  tcase_add_test(ts_core, Test_u_6);
  tcase_add_test(ts_core, Test_X_1);
  tcase_add_test(ts_core, Test_X_2);
  tcase_add_test(ts_core, Test_X_3);
  tcase_add_test(ts_core, Test_X_4);
  tcase_add_test(ts_core, Test_X_5);
  tcase_add_test(ts_core, Test_X_6);
  tcase_add_test(ts_core, Test_X_7);
  tcase_add_test(ts_core, Test_X_8);
  tcase_add_test(ts_core, Test_X_9);
  tcase_add_test(ts_core, Test_X_10);
  tcase_add_test(ts_core, Test_X_11);
  tcase_add_test(ts_core, Test_X_13);
  tcase_add_test(ts_core, Test_X_14);
  tcase_add_test(ts_core, Test_X_15);
  tcase_add_test(ts_core, Test_x_1);
  tcase_add_test(ts_core, Test_x_2);
  tcase_add_test(ts_core, Test_x_3);
  tcase_add_test(ts_core, Test_x_4);
  tcase_add_test(ts_core, Test_x_5);
  tcase_add_test(ts_core, Test_x_6);
  tcase_add_test(ts_core, Test_x_7);
  tcase_add_test(ts_core, Test_x_8);
  tcase_add_test(ts_core, Test_x_9);
  tcase_add_test(ts_core, Test_x_10);
  tcase_add_test(ts_core, Test_x_11);
  tcase_add_test(ts_core, Test_x_13);
  tcase_add_test(ts_core, Test_x_14);
  tcase_add_test(ts_core, Test_x_15);
  tcase_add_test(ts_core, Test_x_16);
  tcase_add_test(ts_core, Test_x_17);
  tcase_add_test(ts_core, Test_o_1);
  tcase_add_test(ts_core, Test_o_2);
  tcase_add_test(ts_core, Test_o_3);
  tcase_add_test(ts_core, Test_o_4);
  tcase_add_test(ts_core, Test_o_5);
  tcase_add_test(ts_core, Test_o_6);
  tcase_add_test(ts_core, Test_o_7);
  tcase_add_test(ts_core, Test_o_8);
  tcase_add_test(ts_core, Test_o_9);
  tcase_add_test(ts_core, Test_o_10);
  tcase_add_test(ts_core, Test_o_11);
  tcase_add_test(ts_core, Test_o_13);
  tcase_add_test(ts_core, Test_o_14);
  tcase_add_test(ts_core, Test_o_15);
  tcase_add_test(ts_core, Test_o_16);
  tcase_add_test(ts_core, Test_p_1);
  tcase_add_test(ts_core, Test_p_2);
  tcase_add_test(ts_core, Test_p_3);
  tcase_add_test(ts_core, Test_p_4);
  tcase_add_test(ts_core, Test_e_1);
  tcase_add_test(ts_core, Test_e_2);
  tcase_add_test(ts_core, Test_e_3);
  tcase_add_test(ts_core, Test_e_4);
  tcase_add_test(ts_core, Test_percent_1);
  tcase_add_test(ts_core, Test_percent_2);
  tcase_add_test(ts_core, Test_percent_3);
  tcase_add_test(ts_core, Test_percent_4);
  tcase_add_test(ts_core, Test_1);
  tcase_add_test(ts_core, Test_2);
  tcase_add_test(ts_core, Test_3);
  tcase_add_test(ts_core, Test_4);
  suite_add_tcase(s, ts_core);
  return s;
}

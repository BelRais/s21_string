CC=gcc
CFLAG=-c
All_Flag=-Wall -Wextra -Werror -std=c11
OFlags=-o

Test_Flag = -pedantic -lcheck -lm -lpthread -lgcov --coverage
ifeq ($(shell uname), Linux)
Test_Flag = -pedantic -lcheck -lsubunit -lrt -lm -lpthread -lgcov --coverage
endif


All_H = s21*.h
All_C = s21*.c
All_O = s21*.o
#All_H_test = test*.h
All_C_test = test*.c
All_O_test = test*.o
A_string = s21_string.a
A_Tests = check_test.a

all: gcov_report

s21_string.a:
	$(CC) $(CFLAG) $(All_Flag) $(All_C)
	ar rc $(A_string) $(All_O)
	ranlib $(A_string) 	

test: $(A_string)
	$(CC) $(All_Flag) $(OFlags) test $(All_C) $(All_C_test) main.c $(Test_Flag)
	./test
# c - Захват данных о покрытии

test_leaks: $(A_string)
	$(CC) $(All_Flag) $(OFlags) test $(All_C) $(All_C_test) main.c $(Test_Flag)

gcov_report:
	gcc --coverage $(Test_Flag) $(All_C_test) main.c   $(All_C) -o ./gcov
	./gcov
	lcov -t "./gcov" -o report.info --no-external -c -d .
	genhtml -o report report.info
	open ./report/index.html
	rm -rf *.gcno *gcda *.gcov

check_format:
	clang-format -i *.c *.h

clang:
	cp ../materials/linters/.clang-format ./ 
	clang-format -n *.c *.h

leaks_m:
	CK_FORK=no leaks --atExit -- ./test

clean :
	rm -rf *.o *.a gcov *.gch *.gcda *.gcno *.info *.out test report check.c

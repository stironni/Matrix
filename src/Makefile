CC=gcc
CFLAGS=-Wall -Wextra -Werror -std=c11
LINUX=-lsubunit -lrt -lpthread -lm
LIBS=-lcheck
LFLAGS=-fprofile-arcs -ftest-coverage
OS=$(shell uname -s)

FILES=s21_create_matrix.c\
	  s21_remove_matrix.c\
	  s21_eq_matrix.c\
	  s21_sum_matrix.c\
	  s21_sub_matrix.c\
	  s21_mult_number.c\
	  s21_mult_matrix.c\
	  s21_transpose.c\
	  s21_determinant.c\
	  s21_calc_complements.c\
	  s21_inverse_matrix.c

OBJ_LIB=obj/s21_create_matrix.o\
		obj/s21_remove_matrix.o\
		obj/s21_eq_matrix.o\
		obj/s21_sum_matrix.o\
		obj/s21_sub_matrix.o\
		obj/s21_mult_number.o\
		obj/s21_mult_matrix.o\
		obj/s21_transpose.o\
		obj/s21_determinant.o\
		obj/s21_calc_complements.o\
		obj/s21_inverse_matrix.o

all:  clean s21_matrix.a test gcov_report

s21_matrix.a: s21_matrix.o
	@ar r s21_matrix.a $(OBJ_LIB)
	@cp s21_matrix.a libs21_matrix.a
	@cp s21_matrix.a lss21_matrix.a
	@ranlib libs21_matrix.a
	@ranlib lss21_matrix.a

s21_matrix.o: $(FILES) s21_matrix.h
	@$(CC) $(FILES) -c
	@rm -rf obj report
	@mkdir obj
	@mv *.o obj/

test: s21_matrix.a
	#checkmk clean_mode=1 test.check > s21_test.c
ifeq ($(OS), Darwin)
	@$(CC) $(CFLAGS) s21_test.c s21_matrix.a -o s21_test  $(LIBS)
	@./s21_test
else
	@$(CC) $(CFLAGS) s21_test.c s21_matrix.a -o s21_test $(LINUX) $(LIBS)
	@./s21_test
endif

gcov_report:
ifeq ($(OS), Darwin)
	$(CC) $(CFLAGS) $(LFLAGS) s21_test.c $(FILES) -o s21_test $(LIBS)
else
	$(CC) $(CFLAGS) $(LFLAGS) s21_test.c $(FILES) -o s21_test $(LINUX) $(LIBS)
endif
	./s21_test
	lcov -t "test" -o s21_test.info -c -d .
	genhtml -o report s21_test.info

open:
	open report/index.html

rebuild: clean all

check:
	@python3 ../materials/linters/cpplint.py --extensions=c *.c *.h
	@make test
ifeq ($(OS), Darwin)
	CK_FORK=no leaks --atExit -- ./s21_test
else
	valgrind ./s21_test --leak-check=full
endif
	@make clean

clean:
	@rm -rf *.gc* *.o *.a *.out *.info s21_test
	@rm -rf report obj

CC=gcc
CFLAGS=-Wall -Wextra -Werror -std=c11
LINUX=-lsubunit -lrt -lpthread -lm
LIBS=-lcheck
LFLAGS=-fprofile-arcs -ftest-coverage
OS=$(shell uname -s)
s
FILES=c_create_matrix.c\
	  c_remove_matrix.c\
	  c_eq_matrix.c\
	  c_sum_matrix.c\
	  c_sub_matrix.c\
	  c_mult_number.c\
	  c_mult_matrix.c\
	  c_transpose.c\
	  c_determinant.c\
	  c_calc_complements.c\
	  c_inverse_matrix.c

OBJ_LIB=obj/c_create_matrix.o\
		obj/c_remove_matrix.o\
		obj/c_eq_matrix.o\
		obj/c_sum_matrix.o\
		obj/c_sub_matrix.o\
		obj/c_mult_number.o\
		obj/c_mult_matrix.o\
		obj/c_transpose.o\
		obj/c_determinant.o\
		obj/c_calc_complements.o\
		obj/c_inverse_matrix.o

all:  clean c_matrix.a test gcov_report

c_matrix.a: c_matrix.o
	@ar r c_matrix.a $(OBJ_LIB)
	@cp c_matrix.a libc_matrix.a
	@cp c_matrix.a lsc_matrix.a
	@ranlib libc_matrix.a
	@ranlib lsc_matrix.a

c_matrix.o: $(FILES) c_matrix.h
	@$(CC) $(FILES) -c
	@rm -rf obj report
	@mkdir obj
	@mv *.o obj/

test: c_matrix.a
	#checkmk clean_mode=1 test.check > c_test.c
ifeq ($(OS), Darwin)
	@$(CC) $(CFLAGS) c_test.c c_matrix.a -o c_test  $(LIBS)
	@./c_test
else
	@$(CC) $(CFLAGS) c_test.c c_matrix.a -o c_test $(LINUX) $(LIBS)
	@./c_test
endif

gcov_report:
ifeq ($(OS), Darwin)
	$(CC) $(CFLAGS) $(LFLAGS) c_test.c $(FILES) -o c_test $(LIBS)
else
	$(CC) $(CFLAGS) $(LFLAGS) c_test.c $(FILES) -o c_test $(LINUX) $(LIBS)
endif
	./c_test
	lcov -t "test" -o c_test.info -c -d .
	genhtml -o report c_test.info

open:
	open report/index.html

rebuild: clean all

check:
	@python3 ../materials/linters/cpplint.py --extensions=c *.c *.h
	@make test
ifeq ($(OS), Darwin)
	CK_FORK=no leaks --atExit -- ./c_test
else
	valgrind ./c_test --leak-check=full
endif
	@make clean

clean:
	@rm -rf *.gc* *.o *.a *.out *.info c_test
	@rm -rf report obj

GCC =  g++ -g -Wall -Werror -Wextra
SOURCE = vector.cc
TEST = ../tests/tests.cc
LIBA = vector.a
LIBO = vector.o
GCOV =--coverage

OS = $(shell uname)

ifeq ($(OS), Darwin)
	LIBFLAGS = -lm -lgtest -lstdc++
else
	LIBFLAGS=-lstdc++ `pkg-config --cflags --libs gtest`
endif

all: clean test

clean:
	rm -rf *.o *.a *.so *.cfg *.out *.dSYM test *.txt report *.info *.gcda *.gcno .clang-format

test: vector.a
	@$(GCC) $(TEST) $(LIBA) $(LIBFLAGS)  -o test
	@./test

vector.a: clean
	$(GCC) -c $(SOURCE)
	ar rcs $(LIBA) $(LIBO)
	ranlib $(LIBA)

test_:
	clear
	@$(GCC) matrix_test.cc s21_matrix_oop.cc -o test
	@./test

git:
	make clean
	git add Makefile s21_matrix_oop.cc s21_matrix_oop.h matrix_test.cc
	git commit -m "clang format"
	git push origin tysaneno

gcov_report: vector.a
	$(GCC) $(GCOV) $(TEST) $(SOURCE) $(LIBA) -L. $(LIBA)  $(LIBFLAGS) -o test
	./test
	lcov -t "test" -c -d  ./ --no-external --output-file ./coverage.info
	genhtml ./coverage.info --output-directory ./report/
	open ./report/index.html

check:
	cppcheck --enable=all --suppress=missingIncludeSystem --inconclusive --check-config $(SOURCE) *.h
	cp ../materials/linters/.clang-format .clang-format
	#clang-format -style=file exp.cc # как должно быть
	clang-format -n s21_matrix_oop.cc s21_matrix_oop.h
	rm -rf .clang-format
ifeq ($(OS), Darwin)
	leaks --atExit -- test
else
	CK_FORK=no valgrind --vgdb=no --leak-check=full --show-leak-kinds=all --track-origins=yes --verbose --log-file=RESULT_VALGRIND.txt ./test
endif
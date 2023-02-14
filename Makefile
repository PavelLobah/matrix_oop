CC=g++
CFLAGS = -Wall -Werror -Wextra -g -fsanitize=address -lm
VFLAGS = -Wall -Werror -Wextra -lm
CTEST = -lgtest -pthread --coverage
UNAME=$(shell uname)
DATE = $(shell date -R)

.PHONY: all s21_matrix_oop.a test gcov_report clean valg

all: clean test gcov_report

s21_matrix_oop.a:
	$(CC) -c s21_matrix_oop.cpp
	ar rc s21_matrix_oop.a s21_matrix_oop.o
	ranlib s21_matrix_oop.a
	rm *.o

test: clean s21_matrix_oop.a
	$(CC) $(CFLAGS) test.cpp s21_matrix_oop.a -o test $(CTEST) -L.
	./test

gcov_report:
	$(CC) -fprofile-arcs -ftest-coverage s21_matrix_oop.cpp test.cpp $(CTEST)
	./a.out
	lcov -t a.out -o rep.info -c -d . --no-external
	genhtml -o report rep.info
	open ./report/index.html

clean:
	rm -f *.html *.o *.a *.gcno *.gcda *.info *.out *.css
	rm -rf ./report
	rm -rf *.dSYM
	rm -rf test
	clear

clang:
	cp ../materials/linters/.clang-format .
	clang-format -i ./*.cpp
	clang-format -n ./*.cpp
	clang-format -i ./*.h
	clang-format -n ./*.h
	rm -f .clang-format

valg: clean s21_matrix_oop.a
	$(CC) $(VFLAGS) test.cpp s21_matrix_oop.a -o test $(CTEST) -L.
	valgrind --track-origins=yes -q ./test
#	valgrind ./test --leak-check=full
#	valgrind --tool=memcheck --leak-check=yes --track-origins=yes ./test

git:
	git add .
	git commit -m "$(DATE)"
	git push origin main

#include <gtest/gtest.h>

#include <utility>

#include "../src/s21_matrix_oop.h"

TEST(Basic, defaultConstructor) {
  S21Matrix m;
  EXPECT_EQ(m.getRows(), 0);
  EXPECT_EQ(m.getCols(), 0);
  EXPECT_EQ(m.getMatrix(), nullptr);
  //  std::cout << "test1" << "\n";
}

TEST(Basic, parameterizedCconstructor) {
  S21Matrix m(2, 3);
  EXPECT_EQ(m.getRows(), 2);
  EXPECT_EQ(m.getCols(), 3);
}

TEST(Basic, copyConstructor) {
  S21Matrix m(2, 3);
  S21Matrix copy(m);
  EXPECT_EQ(copy.getRows(), 2);
  EXPECT_EQ(copy.getCols(), 3);
  // need equals test
}

TEST(Basic, moveConstructor) {
  S21Matrix m(2, 3);
  S21Matrix res(std::move(m));
  EXPECT_EQ(res.getRows(), 2);
  EXPECT_EQ(res.getCols(), 3);
  EXPECT_EQ(m.getRows(), 0);
  EXPECT_EQ(m.getCols(), 0);
  EXPECT_EQ(m.getMatrix(), nullptr);
}

TEST(GetterAndSetter, setRows) {
  S21Matrix m(2, 3);
  m[1][1] = 4.4;
  EXPECT_EQ(m(1, 1), 4.4);
  EXPECT_EQ(m.getRows(), 2);
  EXPECT_EQ(m.getCols(), 3);
  m.setRows(4);
  m[3][2] = 5.5;
  EXPECT_EQ(m(1, 1), 4.4);
  EXPECT_EQ(m(3, 2), 5.5);
  EXPECT_EQ(m.getRows(), 4);
  EXPECT_EQ(m.getCols(), 3);
}

TEST(GetterAndSetter, setCols) {
  S21Matrix m(2, 3);
  m[1][1] = 4.4;
  EXPECT_EQ(m(1, 1), 4.4);
  EXPECT_EQ(m.getRows(), 2);
  EXPECT_EQ(m.getCols(), 3);
  m.setCols(5);
  m[1][4] = 5.5;
  EXPECT_EQ(m(1, 1), 4.4);
  EXPECT_EQ(m(1, 4), 5.5);
  EXPECT_EQ(m.getRows(), 2);
  EXPECT_EQ(m.getCols(), 5);
}

TEST(assignmentOperator, brakets) {
  S21Matrix m(2, 3);
  m(1, 1) = 3;
  EXPECT_EQ(m(1, 1), 3);
  EXPECT_EQ(m[1][1], 3);
}

TEST(assignmentOperator, braketsTrow) {
  S21Matrix m(2, 3);
  EXPECT_ANY_THROW(m(1, 5));
}

TEST(assignmentOperator, brakets2) {
  S21Matrix m(2, 3);
  m[1][1] = 3;
  EXPECT_EQ(m(1, 1), 3);
  EXPECT_EQ(m[1][1], 3);
}

TEST(supportFunction, removeAndSetZeroMatrix) {
  S21Matrix m(2, 3);
  EXPECT_EQ(m.getRows(), 2);
  EXPECT_EQ(m.getCols(), 3);
  m.removeMatrix();
  m.setZeroMatrix();
  EXPECT_EQ(m.getRows(), 0);
  EXPECT_EQ(m.getCols(), 0);
  EXPECT_EQ(m.getMatrix(), nullptr);
}

TEST(functionalTest, copy) {
  S21Matrix a(2, 2);
  S21Matrix b(2, 2);
  a[1][1] = 1.1;
  b[1][1] = 2.2;
  a = b;
  EXPECT_DOUBLE_EQ(a[1][1], 2.2);
}

TEST(functionalTest, Plus) {
  S21Matrix a(2, 2);
  S21Matrix b(2, 2);
  a[1][1] = 1.1;
  b[1][1] = 2.2;
  S21Matrix res = a + b;
  EXPECT_DOUBLE_EQ(res[1][1], 3.3);
}

TEST(functionalTest, PlusEx) {
  S21Matrix a(2, 3);
  S21Matrix b(2, 2);
  a[1][1] = 1.1;
  b[1][1] = 2.2;
  EXPECT_ANY_THROW(S21Matrix res = a + b);
}

TEST(functionalTest, Plus2) {
  S21Matrix a(2, 2);
  S21Matrix b(2, 2);
  a[1][1] = 1.1;
  b[1][1] = 2.2;
  a += b;
  EXPECT_DOUBLE_EQ(a[1][1], 3.3);
}

TEST(functionalTest, PlusEx2) {
  S21Matrix a(2, 3);
  S21Matrix b(2, 2);
  a[1][1] = 1.1;
  b[1][1] = 2.2;
  EXPECT_ANY_THROW(a += b);
}

TEST(functionalTest, Plus3) {
  S21Matrix a(2, 2);
  S21Matrix b(2, 2);
  a[1][1] = 1.1;
  b[1][1] = 2.2;
  a.sumMatrix(b);
  EXPECT_DOUBLE_EQ(a[1][1], 3.3);
}

TEST(functionalTest, PlusEx3) {
  S21Matrix a(2, 3);
  S21Matrix b(2, 2);
  a[1][1] = 1.1;
  b[1][1] = 2.2;
  EXPECT_ANY_THROW(a.sumMatrix(b));
}

TEST(functionalTest, Minus) {
  S21Matrix a(2, 2);
  S21Matrix b(2, 2);
  a[1][1] = 1.1;
  b[1][1] = 2.2;
  S21Matrix res = a - b;
  EXPECT_DOUBLE_EQ(res[1][1], -1.1);
}

TEST(functionalTest, MinusEx) {
  S21Matrix a(2, 3);
  S21Matrix b(2, 2);
  a[1][1] = 1.1;
  b[1][1] = 2.2;
  EXPECT_ANY_THROW(S21Matrix res = a + b);
}

TEST(functionalTest, Minus2) {
  S21Matrix a(2, 2);
  S21Matrix b(2, 2);
  a[1][1] = 1.1;
  b[1][1] = 2.2;
  a -= b;
  EXPECT_DOUBLE_EQ(a[1][1], -1.1);
}

TEST(functionalTest, MinusEx2) {
  S21Matrix a(2, 3);
  S21Matrix b(2, 2);
  a[1][1] = 1.1;
  b[1][1] = 2.2;
  EXPECT_ANY_THROW(a -= b);
}

TEST(functionalTest, Minus3) {
  S21Matrix a(2, 2);
  S21Matrix b(2, 2);
  a[1][1] = 1.1;
  b[1][1] = 2.2;
  a.subMatrix(b);
  EXPECT_DOUBLE_EQ(a[1][1], -1.1);
}

TEST(functionalTest, MinusEx3) {
  S21Matrix a(2, 3);
  S21Matrix b(2, 2);
  a[1][1] = 1.1;
  b[1][1] = 2.2;
  EXPECT_ANY_THROW(a.subMatrix(b));
}

TEST(functionalTest, MinusEx4) {
  S21Matrix a(2, 3);
  S21Matrix b(2, 2);
  a[1][1] = 1.1;
  b[1][1] = 2.2;
  EXPECT_ANY_THROW(a - b);
}

TEST(functionalTest, MultMatrix) {
  S21Matrix a(3, 2);
  S21Matrix b(2, 3);
  a[1][1] = 1.1;
  b[1][1] = 2;
  S21Matrix res = a * b;
  EXPECT_DOUBLE_EQ(res[1][1], 2.2);
}

TEST(functionalTest, MultMatrixEx) {
  S21Matrix a(2, 3);
  S21Matrix b(2, 2);
  a[1][1] = 1.1;
  b[1][1] = 2.2;
  EXPECT_ANY_THROW(S21Matrix res = a * b);
}

TEST(functionalTest, MultMatrix2) {
  S21Matrix a(3, 2);
  S21Matrix b(2, 3);
  a[1][1] = 1.1;
  b[1][1] = 2;
  a *= b;
  EXPECT_DOUBLE_EQ(a[1][1], 2.2);
}

TEST(functionalTest, MultMatrixEx2) {
  S21Matrix a(2, 3);
  S21Matrix b(2, 2);
  a[1][1] = 1.1;
  b[1][1] = 2.2;
  EXPECT_ANY_THROW(a *= b);
}

TEST(functionalTest, MultMatrix3) {
  S21Matrix a(3, 2);
  S21Matrix b(2, 3);
  a[1][1] = 1.1;
  b[1][1] = 2;
  a.mulMatrix(b);
  EXPECT_DOUBLE_EQ(a[1][1], 2.2);
}

TEST(functionalTest, MultMatrixEx3) {
  S21Matrix a(2, 3);
  S21Matrix b(2, 2);
  a[1][1] = 1.1;
  b[1][1] = 2.2;
  EXPECT_ANY_THROW(a.mulMatrix(b));
}

TEST(functionalTest, MultMatrixNum) {
  S21Matrix a(3, 2);
  a[1][1] = 1.1;
  S21Matrix res = a * 2;
  EXPECT_DOUBLE_EQ(res[1][1], 2.2);
}

TEST(functionalTest, MultMatrixNum2) {
  S21Matrix a(3, 2);
  a[1][1] = 1.1;
  a *= 2;
  EXPECT_DOUBLE_EQ(a[1][1], 2.2);
}

TEST(functionalTest, MultMatrixNum3) {
  S21Matrix a(3, 2);
  a[1][1] = 1.1;
  a.mulNumber(2);
  EXPECT_DOUBLE_EQ(a[1][1], 2.2);
}

TEST(functionalTest, equal) {
  S21Matrix a(2, 3);
  S21Matrix b(2, 2);
  EXPECT_EQ(a == b, false);
  b.setCols(3);
  a[1][1] = 1.1;
  b[1][1] = 1.1;
  EXPECT_EQ(a == b, true);
  b[1][2] = 1.1;
  EXPECT_EQ(a == b, false);
}

TEST(functionalTest, equalFunc) {
  S21Matrix a(2, 3);
  S21Matrix b(2, 2);
  EXPECT_EQ(a.eqMatrix(b), false);
  b.setCols(3);
  a[1][1] = 1.1;
  b[1][1] = 1.1;
  EXPECT_EQ(a.eqMatrix(b), true);
  b[1][2] = 1.1;
  EXPECT_EQ(a.eqMatrix(b), false);
}

TEST(functionalFuncTest, transpose) {
  S21Matrix m(2, 3);
  m[0][0] = 1;
  m[0][1] = 2;
  m[0][2] = 3;
  m[1][0] = 4;
  m[1][1] = 5;
  m[1][2] = 6;
  // 1 2 3
  // 4 5 6
  EXPECT_EQ(m[1][1], 5);
  m = std::move(m.transpose());
  // 1 4
  // 2 5
  // 3 6
  EXPECT_EQ(m[0][0], 1);
  EXPECT_EQ(m[2][1], 6);
}

TEST(functionalFuncTest, determinant) {
  S21Matrix m(4, 4);
  m[0][0] = 9;
  m[0][1] = 2;
  m[0][2] = 2;
  m[0][3] = 4;

  m[1][0] = 3;
  m[1][1] = 4;
  m[1][2] = 4;
  m[1][3] = 4;

  m[2][0] = 4;
  m[2][1] = 4;
  m[2][2] = 9;
  m[2][3] = 9;

  m[3][0] = 1;
  m[3][1] = 1;
  m[3][2] = 5;
  m[3][3] = 1;
  EXPECT_EQ(m.determinant(), -578);
  S21Matrix m1(1, 1);
  m1[0][0] = 10;
  EXPECT_EQ(m1.determinant(), 10);
  S21Matrix m2(2, 2);
  m2[0][0] = 1.1;
  m2[0][1] = 3.5;
  m2[1][0] = -2;
  m2[1][1] = 4;
  EXPECT_DOUBLE_EQ(m2.determinant(), 11.4);
}

TEST(functionalFuncTest, determinant2) {
  S21Matrix m(4, 4);
  m[0][0] = 1;
  m[0][1] = 2;
  m[0][2] = 3;
  m[0][3] = 4;

  m[1][0] = 1;
  m[1][1] = 2;
  m[1][2] = 5;
  m[1][3] = 7;

  m[2][0] = 1;
  m[2][1] = 0;
  m[2][2] = 6;
  m[2][3] = 8;

  m[3][0] = 1;
  m[3][1] = 0;
  m[3][2] = 6;
  m[3][3] = 6;
  EXPECT_EQ(m.determinant(), -8);
}

TEST(functionalFuncTest, determinantEx) {
  S21Matrix m(4, 3);

  EXPECT_ANY_THROW(m.determinant());
}

TEST(functionalFuncTest, calcComplements) {
  S21Matrix m(3, 3);
  m[0][0] = 1;
  m[0][1] = 2;
  m[0][2] = 3;

  m[1][0] = 0;
  m[1][1] = 4;
  m[1][2] = 2;

  m[2][0] = 5;
  m[2][1] = 2;
  m[2][2] = 1;

  m = m.calcComplements();

  EXPECT_EQ(m[0][0], 0);
  EXPECT_EQ(m[0][1], 10);
  EXPECT_EQ(m[0][2], -20);
  EXPECT_EQ(m[1][0], 4);
  EXPECT_EQ(m[1][1], -14);
  EXPECT_EQ(m[1][2], 8);
  EXPECT_EQ(m[2][0], -8);
  EXPECT_EQ(m[2][1], -2);
  EXPECT_EQ(m[2][2], 4);
}

TEST(functionalFuncTest, calcComplementsEx) {
  S21Matrix m(4, 3);

  EXPECT_ANY_THROW(m.calcComplements());
}

TEST(functionalFuncTest, inverseMatrix) {
  S21Matrix m(3, 3);
  // var 1
  m[0][0] = 4;
  m[0][1] = -2;
  m[0][2] = 1;
  m[1][0] = 1;
  m[1][1] = 6;
  m[1][2] = -2;
  m[2][0] = 1;
  m[2][1] = 0;
  m[2][2] = 0;

  m = m.inverseMatrix();

  EXPECT_EQ(m[0][1], 0);
  EXPECT_EQ(m[0][2], 1);
  EXPECT_EQ(m[1][0], 1);
  EXPECT_EQ(m[2][0], 3);
  EXPECT_EQ(m[2][1], 1);
  EXPECT_EQ(m[2][2], -13);
}

TEST(functionalFuncTest, inverseMatrixEx) {
  S21Matrix m(3, 3);

  //  determ = 0
  m[0][0] = 1;
  m[0][1] = 1;
  m[0][2] = 3;
  m[1][0] = 4;
  m[1][1] = 4;
  m[1][2] = 6;
  m[2][0] = 4;
  m[2][1] = 4;
  m[2][2] = 9;
  EXPECT_EQ(m.determinant(), 0);
  EXPECT_ANY_THROW(m.inverseMatrix());
}

TEST(functionalFuncTest, inverseMatrixEx2) {
  S21Matrix m(3, 3);

  m[0][0] = 1;
  m[0][1] = 4;
  m[0][2] = 1;
  m[1][0] = 3;
  m[1][1] = 7;
  m[1][2] = 2;
  m[2][0] = 3;
  m[2][1] = 2;
  m[2][2] = 1;
  EXPECT_EQ(m.determinant(), 0);
  EXPECT_ANY_THROW(m.inverseMatrix());
}

TEST(functionalFuncTest, inverseMatrixEx3) {
  S21Matrix m(3, 2);
  EXPECT_ANY_THROW(m.inverseMatrix());
}

TEST(functionalFuncTest, minorEx) {
  S21Matrix m(1, 1);
  EXPECT_ANY_THROW(m.minorMatrix());
}

TEST(functionalFuncTest, braketEx) {
  S21Matrix m(1, 1);
  EXPECT_ANY_THROW(m[5][0] = 5);
}

int main(int argc, char *argv[]) {
  testing::InitGoogleTest(&argc, argv);
  return RUN_ALL_TESTS();
}
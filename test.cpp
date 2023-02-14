#include "gtest/gtest.h"
#include "s21_matrix_oop.h"

S21Matrix fill_matrix_example() {
  S21Matrix matrix(5, 5);
  matrix(0, 0) = 1.0;
  matrix(0, 1) = 2.0;
  matrix(0, 2) = 3.0;
  matrix(0, 3) = 4.0;
  matrix(0, 4) = 3.0;
  matrix(1, 0) = 0.0;
  matrix(1, 1) = 4.0;
  matrix(1, 2) = 2.0;
  matrix(1, 3) = 3.0;
  matrix(1, 4) = 2.0;
  matrix(2, 0) = 5.0;
  matrix(2, 1) = 2.0;
  matrix(2, 2) = 1.0;
  matrix(2, 3) = 3.0;
  matrix(2, 4) = 3.0;
  matrix(3, 0) = 5.0;
  matrix(3, 1) = 1.0;
  matrix(3, 2) = 1.0;
  matrix(3, 3) = 3.0;
  matrix(3, 4) = 3.0;
  matrix(4, 0) = 5.0;
  matrix(4, 1) = 2.0;
  matrix(4, 2) = 1.0;
  matrix(4, 3) = 8.0;
  matrix(4, 4) = 3.0;
  return matrix;
}

TEST(MatrixEqualTest, HandlesZeroMatrixInput) {
  try {
    S21Matrix matrixOne(3, 3);
    S21Matrix matrixTwo(3, 3);
    matrixOne.SumMatrix(matrixTwo);
    bool check = matrixOne.EqMatrix(matrixTwo);
    EXPECT_EQ(check, true);
  } catch (std::exception& ex) {
    std::cout << ex.what();
  }
}

TEST(MatrixConstructorTest, HandlesMatrixInput) {
  try {
    S21Matrix matrixOne(3, 3);
    matrixOne = fill_matrix_example();
    S21Matrix matrixTwo(matrixOne);
    bool check = matrixOne.EqMatrix(matrixTwo);
    EXPECT_EQ(check, true);
  } catch (std::exception& ex) {
    std::cout << ex.what();
  }
}

TEST(MatrixEqualTest, HandlesCorrectMatrixInput) {
  S21Matrix matrixOne = fill_matrix_example();
  S21Matrix matrixTwo = fill_matrix_example();
  bool check = matrixOne.EqMatrix(matrixTwo);
  EXPECT_EQ(check, true);
}

TEST(MatrixEqualTest, HandlesMatrixInput) {
  S21Matrix matrixOne = fill_matrix_example();
  S21Matrix matrixTwo(5, 5);
  bool check = matrixOne.EqMatrix(matrixTwo);
  EXPECT_EQ(check, false);
}

TEST(MatrixSumTest, HandlesZerMatrixInput) {
  S21Matrix matrixOne;
  S21Matrix matrixTwo(3, 3);
  matrixOne.SumMatrix(matrixTwo);
  bool check = matrixOne.EqMatrix(matrixTwo);
  EXPECT_EQ(check, true);
}

TEST(MatrixSumTest, HandlesMatrixInput) {
  S21Matrix matrixTwo(5, 5);
  S21Matrix matrixOne = fill_matrix_example();
  matrixTwo.SumMatrix(matrixOne);
  bool check = matrixOne.EqMatrix(matrixTwo);
  EXPECT_EQ(check, true);
}

TEST(MatrixSumTest, HandlesMatrixInputCorrect) {
  S21Matrix matrixOne = fill_matrix_example();
  S21Matrix matrixTwo = fill_matrix_example();
  matrixOne.SumMatrix(matrixTwo);
  matrixTwo *= 2;
  bool check = matrixOne.EqMatrix(matrixTwo);
  EXPECT_EQ(check, true);
}

TEST(MatrixSubTest, HandlesZeroMatrixInput) {
  S21Matrix matrixOne;
  S21Matrix matrixTwo(3, 3);
  matrixOne.SubMatrix(matrixTwo);
  bool check = matrixOne.EqMatrix(matrixTwo);
  EXPECT_EQ(check, true);
}

TEST(MatrixSubTest, HandlesMatrixInput) {
  S21Matrix matrixZero(5, 5);
  S21Matrix matrixOne = fill_matrix_example();
  S21Matrix matrixTwo = fill_matrix_example();
  matrixOne.SubMatrix(matrixTwo);
  bool check = matrixOne.EqMatrix(matrixZero);
  EXPECT_EQ(check, true);
}

TEST(MatrixSubTest, HandlesMatrixInputCorrect) {
  S21Matrix matrixOne = fill_matrix_example();
  S21Matrix matrixTwo = fill_matrix_example();
  matrixOne *= 2;
  matrixOne.SubMatrix(matrixTwo);
  bool check = matrixOne.EqMatrix(matrixTwo);
  EXPECT_EQ(check, true);
}

TEST(MatrixMulTest, HandlesZeroMatrixInput) {
  S21Matrix matrixOne;
  S21Matrix matrixTwo(3, 3);
  matrixOne.MulMatrix(matrixTwo);
  bool check = matrixOne.EqMatrix(matrixTwo);
  EXPECT_EQ(check, true);
}

TEST(MatrixMulTest, HandlesDifferentMatrixInput) {
  S21Matrix matrixOne(3, 3);
  matrixOne.FillMatrix();
  S21Matrix matrixTwo(3, 1);
  matrixTwo(0, 0) = 1.0;
  matrixTwo(1, 0) = 2.0;
  matrixTwo(2, 0) = 3.0;
  matrixOne.MulMatrix(matrixTwo);
  S21Matrix matrixResult(3, 1);
  matrixResult(0, 0) = 8.0;
  matrixResult(1, 0) = 14.0;
  matrixResult(2, 0) = 20.0;
  bool check = matrixOne.EqMatrix(matrixResult);
  EXPECT_EQ(check, true);
}

TEST(MatrixMulTest, HandlesMatrixInput) {
  S21Matrix matrixOne(3, 3);
  S21Matrix matrixTwo(3, 3);
  S21Matrix matrixThree(3, 3);
  matrixOne.FillMatrix();
  matrixTwo.FillMatrix();
  matrixOne.MulMatrix(matrixTwo);
  matrixThree(0, 0) = 5.0;
  matrixThree(0, 1) = 8.0;
  matrixThree(0, 2) = 11.0;
  matrixThree(1, 0) = 8.0;
  matrixThree(1, 1) = 14.0;
  matrixThree(1, 2) = 20.0;
  matrixThree(2, 0) = 11.0;
  matrixThree(2, 1) = 20.0;
  matrixThree(2, 2) = 29.0;
  bool check = matrixOne.EqMatrix(matrixThree);
  EXPECT_EQ(check, true);
}

TEST(MatrixTransposeTest, HandlesMatrixInput) {
  S21Matrix matrixOne(3, 3);
  S21Matrix matrixTwo(3, 3);
  matrixOne.FillMatrix();
  matrixTwo.FillMatrix();
  matrixOne.Transpose();
  bool check = matrixOne.EqMatrix(matrixTwo);
  EXPECT_EQ(check, true);
}

TEST(MatrixCalcComplecsTest, HandlesMatrixInput) {
  try {
    S21Matrix matrixOne(3, 3);
    S21Matrix matrixTwo(3, 3);
    matrixOne(0, 0) = 1.0;
    matrixOne(0, 1) = 2.0;
    matrixOne(0, 2) = 3.0;
    matrixOne(1, 0) = 0.0;
    matrixOne(1, 1) = 4.0;
    matrixOne(1, 2) = 2.0;
    matrixOne(2, 0) = 5.0;
    matrixOne(2, 1) = 2.0;
    matrixOne(2, 2) = 1.0;

    matrixTwo(0, 0) = 0.0;
    matrixTwo(0, 1) = 10.0;
    matrixTwo(0, 2) = -20.0;
    matrixTwo(1, 0) = 4.0;
    matrixTwo(1, 1) = -14.0;
    matrixTwo(1, 2) = 8.0;
    matrixTwo(2, 0) = -8.0;
    matrixTwo(2, 1) = -2.0;
    matrixTwo(2, 2) = 4.0;

    S21Matrix matrixResult = matrixOne.CalcComplements();
    bool check = matrixResult.EqMatrix(matrixTwo);
    EXPECT_EQ(check, true);
  } catch (std::exception& ex) {
    std::cout << ex.what();
  }
}

TEST(MatrixDetermanantTest, HandlesMatrixInput) {
  S21Matrix matrixOne = fill_matrix_example();
  double resultDet = matrixOne.Determinant();
  EXPECT_EQ(resultDet, 20);
}

TEST(MatrixDetermanantTest, HandlesMatrixZeroInput) {
  S21Matrix matrixOne(5, 5);
  EXPECT_EQ(matrixOne.Determinant(), 0);
}

TEST(MatrixDetermanantTest, HandlesOrdinaryMatrixInput) {
  S21Matrix matrixOne(1, 1);
  matrixOne(0, 0) = 1;
  EXPECT_EQ(matrixOne.Determinant(), 1);
}

TEST(MatrixInverseTest, HandlesMatrixInput) {
  S21Matrix matrixOne(3, 3);
  S21Matrix matrixTwo(3, 3);
  matrixOne(0, 0) = 1.0;
  matrixOne(0, 1) = 2.0;
  matrixOne(0, 2) = 3.0;
  matrixOne(1, 0) = 0.0;
  matrixOne(1, 1) = 4.0;
  matrixOne(1, 2) = 2.0;
  matrixOne(2, 0) = 5.0;
  matrixOne(2, 1) = 2.0;
  matrixOne(2, 2) = 1.0;
  matrixTwo(0, 0) = 0.0;
  matrixTwo(0, 1) = -0.1;
  matrixTwo(0, 2) = 0.2;
  matrixTwo(1, 0) = -0.25;
  matrixTwo(1, 1) = 0.35;
  matrixTwo(1, 2) = 0.05;
  matrixTwo(2, 0) = 0.5;
  matrixTwo(2, 1) = -0.2;
  matrixTwo(2, 2) = -0.1;
  S21Matrix matrixResult = matrixOne.InverseMatrix();
  bool check = matrixResult.EqMatrix(matrixTwo);
  EXPECT_EQ(check, true);
}

TEST(MatrixSubTestUnary, HandlesMatrixInput) {
  S21Matrix matrixZero(5, 5);
  S21Matrix matrixOne = fill_matrix_example();
  S21Matrix matrixTwo(matrixOne);
  matrixOne -= matrixTwo;
  bool check = matrixOne.EqMatrix(matrixZero);
  EXPECT_EQ(check, true);
}

TEST(MatrixSubTestBinary, HandlesMatrixInput) {
  S21Matrix matrixZero(5, 5);
  S21Matrix matrixOne = fill_matrix_example();
  S21Matrix matrixTwo(matrixOne);
  S21Matrix matrixResult = matrixOne - matrixTwo;
  bool check = matrixResult.EqMatrix(matrixZero);
  EXPECT_EQ(check, true);
}

TEST(MatrixSumTestUnary, HandlesMatrixInput) {
  S21Matrix matrixOne = fill_matrix_example();
  S21Matrix matrixTwo(matrixOne);
  matrixOne += matrixTwo;
  S21Matrix matrixResult(matrixOne);
  bool check = matrixOne.EqMatrix(matrixResult);
  EXPECT_EQ(check, true);
}

TEST(MatrixSumTestBinary, HandlesMatrixInput) {
  S21Matrix matrixOne = fill_matrix_example();
  S21Matrix matrixTwo(matrixOne);
  S21Matrix matrixResult = matrixOne + matrixTwo;
  matrixOne *= 2;
  bool check = matrixOne.EqMatrix(matrixResult);
  EXPECT_EQ(check, true);
}

TEST(MatrixMulTestBinary, HandlesMatrixInput) {
  S21Matrix matrixOne(3, 3);
  S21Matrix matrixTwo(3, 3);
  S21Matrix matrixThree(3, 3);
  matrixOne.FillMatrix();
  matrixTwo.FillMatrix();
  S21Matrix matrixResult = matrixOne * matrixTwo;
  matrixThree(0, 0) = 5.0;
  matrixThree(0, 1) = 8.0;
  matrixThree(0, 2) = 11.0;
  matrixThree(1, 0) = 8.0;
  matrixThree(1, 1) = 14.0;
  matrixThree(1, 2) = 20.0;
  matrixThree(2, 0) = 11.0;
  matrixThree(2, 1) = 20.0;
  matrixThree(2, 2) = 29.0;
  bool check = matrixThree.EqMatrix(matrixResult);
  EXPECT_EQ(check, true);
}

TEST(MatrixMulTestUnary, HandlesMatrixInput) {
  S21Matrix matrixOne(3, 3);
  S21Matrix matrixThree(3, 3);
  S21Matrix matrixResult(3, 3);
  matrixOne.FillMatrix();
  matrixResult.FillMatrix();
  matrixResult *= matrixOne;
  matrixThree(0, 0) = 5.0;
  matrixThree(0, 1) = 8.0;
  matrixThree(0, 2) = 11.0;
  matrixThree(1, 0) = 8.0;
  matrixThree(1, 1) = 14.0;
  matrixThree(1, 2) = 20.0;
  matrixThree(2, 0) = 11.0;
  matrixThree(2, 1) = 20.0;
  matrixThree(2, 2) = 29.0;
  bool check = matrixThree.EqMatrix(matrixResult);
  EXPECT_EQ(check, true);
}

TEST(NumberMulTestBinary, HandlesMatrixInput) {
  S21Matrix matrixOne(3, 3);
  matrixOne.FillMatrix();
  S21Matrix matrixResult = matrixOne * 2.0;
  matrixOne.MulNumber(2.0);
  bool check = matrixOne.EqMatrix(matrixResult);
  EXPECT_EQ(check, true);
}

TEST(BoolOperator, HandlesMatrixInput) {
  S21Matrix matrixOne(3, 3);
  S21Matrix matrixTwo(3, 3);
  matrixOne.FillMatrix();
  matrixTwo.FillMatrix();
  bool check = false;
  if (matrixOne == matrixTwo) check = true;
  EXPECT_EQ(check, true);
}

TEST(GetterCols, HandlesMatrixInput) {
  S21Matrix matrixOne(3, 3);
  matrixOne.FillMatrix();
  ASSERT_EQ(3, matrixOne.GetCols());
}

TEST(SetterRows, HandlesMatrixInputBigger) {
  S21Matrix matrixOne(3, 3);
  S21Matrix matrixTwo(5, 3);
  S21Matrix matrixResult(5, 3);

  matrixTwo.FillMatrix();
  matrixTwo(3, 0) = 0.0;
  matrixTwo(4, 0) = 0.0;
  matrixTwo(3, 1) = 0.0;
  matrixTwo(4, 1) = 0.0;
  matrixTwo(3, 2) = 0.0;
  matrixTwo(4, 2) = 0.0;
  matrixOne.FillMatrix();

  matrixOne.SetRows(5);
  ASSERT_EQ(5, matrixOne.GetRows());

  matrixOne.SubMatrix(matrixTwo);

  bool check = matrixOne.EqMatrix(matrixResult);
  EXPECT_EQ(check, true);
}

TEST(SetterRows, HandlesMatrixInputSmaller) {
  S21Matrix matrixOne(5, 5);
  S21Matrix matrixTwo(3, 5);
  S21Matrix matrixResult(3, 5);

  matrixTwo.FillMatrix();
  matrixOne.FillMatrix();

  matrixOne.SetRows(3);
  ASSERT_EQ(3, matrixOne.GetRows());

  matrixOne.SubMatrix(matrixTwo);

  bool check = matrixOne.EqMatrix(matrixResult);
  EXPECT_EQ(check, true);
}

TEST(SetterCols, HandlesMatrixInputBigger) {
  S21Matrix matrixOne(3, 3);
  S21Matrix matrixTwo(3, 5);
  S21Matrix matrixResult(3, 5);

  matrixTwo.FillMatrix();
  matrixTwo(0, 3) = 0.0;
  matrixTwo(1, 3) = 0.0;
  matrixTwo(2, 3) = 0.0;
  matrixTwo(0, 4) = 0.0;
  matrixTwo(1, 4) = 0.0;
  matrixTwo(2, 4) = 0.0;
  matrixOne.FillMatrix();

  matrixOne.SetCols(5);
  ASSERT_EQ(5, matrixOne.GetCols());

  matrixOne.SubMatrix(matrixTwo);

  bool check = matrixOne.EqMatrix(matrixResult);
  EXPECT_EQ(check, true);
}

TEST(SetterCols, HandlesMatrixInputSmaller) {
  S21Matrix matrixOne(5, 5);
  S21Matrix matrixTwo(5, 3);
  S21Matrix matrixResult(5, 3);

  matrixTwo.FillMatrix();
  matrixOne.FillMatrix();

  matrixOne.SetCols(3);
  ASSERT_EQ(3, matrixOne.GetCols());

  matrixOne.SubMatrix(matrixTwo);

  bool check = matrixOne.EqMatrix(matrixResult);
  EXPECT_EQ(check, true);
}

int main() {
  testing::InitGoogleTest();
  return RUN_ALL_TESTS();
}
#include <cmath>
#include <iostream>

class S21Matrix {
 private:
  // Attributes
  int rows_, cols_;
  double** matrix_;

 public:
  // Accessor and mutator
  int GetRows();
  void SetRows(int valueRows);
  int GetCols();
  void SetCols(int valueCols);

  S21Matrix();
  ~S21Matrix();
  S21Matrix(int rows, int cols);
  S21Matrix(const S21Matrix& other);
  S21Matrix(S21Matrix&& other);

  // Other methods..
  bool EqMatrix(const S21Matrix& other);
  void SumMatrix(const S21Matrix& other);
  void SubMatrix(const S21Matrix& other);
  void MulNumber(const double num);
  void MulMatrix(const S21Matrix& other);
  S21Matrix Transpose();
  S21Matrix CalcComplements();
  double Determinant();
  S21Matrix InverseMatrix();

  // Additional functions
  void CreateMatrix();
  void PrintMatrix();
  void DeleteMatrix();
  void FillMatrix();
  S21Matrix MinorMatrix(int rows, int cols);
  void SetNewSize(int new_rows, int new_cols);

  // Overloading the following operators
  S21Matrix operator+(const S21Matrix& other);
  S21Matrix operator-(const S21Matrix& other);
  S21Matrix operator*(const S21Matrix& other);
  S21Matrix operator*(const double value);
  bool operator==(const S21Matrix& other);
  S21Matrix& operator=(const S21Matrix& other);
  S21Matrix& operator+=(const S21Matrix& other);
  S21Matrix& operator-=(const S21Matrix& other);
  S21Matrix& operator*=(const S21Matrix& other);
  S21Matrix& operator*=(const double value);
  double& operator()(int row, int col);
};

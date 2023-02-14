#include "s21_matrix_oop.h"

int S21Matrix::GetRows() { return rows_; }
void S21Matrix::SetRows(int valueRows) { SetNewSize(valueRows, 0); }
int S21Matrix::GetCols() { return cols_; }
void S21Matrix::SetCols(int valueCols) { SetNewSize(0, valueCols); }

S21Matrix::S21Matrix() {
  rows_ = 3;
  cols_ = 3;
  CreateMatrix();
}
S21Matrix::S21Matrix(int rows, int cols) {
  rows_ = rows;
  cols_ = cols;
  CreateMatrix();
}
S21Matrix::S21Matrix(const S21Matrix &other) {
  rows_ = other.rows_;
  cols_ = other.cols_;
  CreateMatrix();
  for (int i = 0; i < rows_; i++) {
    for (int j = 0; j < cols_; j++) {
      matrix_[i][j] = other.matrix_[i][j];
    }
  }
}
S21Matrix::S21Matrix(S21Matrix &&other) {
  rows_ = other.rows_;
  cols_ = other.cols_;
  matrix_ = other.matrix_;
  other.matrix_ = 0;
}
S21Matrix::~S21Matrix() { DeleteMatrix(); }

bool S21Matrix::EqMatrix(const S21Matrix &other) {
  bool res = true;
  if ((other.cols_ == cols_) && (other.rows_ == rows_)) {
    for (int i = 0; i < rows_; i++) {
      for (int j = 0; j < cols_; j++) {
        if (fabs(fabs(matrix_[i][j]) - fabs(other.matrix_[i][j])) >= 1e-07) {
          res = false;
        }
      }
    }
  } else {
    res = false;
  }
  return res;
}
void S21Matrix::SumMatrix(const S21Matrix &other) {
  if (rows_ != other.rows_ || cols_ != other.cols_) {
    throw std::out_of_range(
        "Incorrect input, matrices should have the same size");
  } else {
    for (int i = 0; i < rows_; i++) {
      for (int j = 0; j < cols_; j++) {
        matrix_[i][j] = matrix_[i][j] + other.matrix_[i][j];
      }
    }
  }
}
void S21Matrix::SubMatrix(const S21Matrix &other) {
  if (rows_ != other.rows_ || cols_ != other.cols_) {
    throw std::out_of_range(
        "Incorrect input, matrices should have the same size");
  } else {
    for (int i = 0; i < rows_; i++) {
      for (int j = 0; j < cols_; j++) {
        matrix_[i][j] = matrix_[i][j] - other.matrix_[i][j];
      }
    }
  }
}
void S21Matrix::MulNumber(const double num) {
  if (!std::isnan(num)) {
    for (int i = 0; i < rows_; i++) {
      for (int j = 0; j < cols_; j++) {
        matrix_[i][j] = matrix_[i][j] * num;
      }
    }
  }
}
void S21Matrix::MulMatrix(const S21Matrix &other) {
  if (cols_ != other.rows_) {
    throw std::out_of_range(
        "Incorrect input, intput matrices should have same cols equal rows");
  } else {
    S21Matrix matrixTemp(rows_, other.cols_);
    for (int i = 0; i < rows_; i++) {
      for (int j = 0; j < other.cols_; j++) {
        for (int k = 0; k < cols_; k++) {
          matrixTemp.matrix_[i][j] += matrix_[i][k] * other.matrix_[k][j];
        }
      }
    }
    *this = matrixTemp;
  }
}
S21Matrix S21Matrix::Transpose() {
  S21Matrix matrixResult(cols_, rows_);
  for (int i = 0; i < rows_; i++) {
    for (int j = 0; j < cols_; j++) {
      matrixResult.matrix_[j][i] = matrix_[i][j];
    }
  }
  return matrixResult;
}

S21Matrix S21Matrix::CalcComplements() {
  S21Matrix matrixResult(rows_, cols_);
  if (rows_ != cols_ && rows_ <= 1) {
    throw std::out_of_range(
        "Incorrect input, matrices should have the same size");
  }
  for (int i = 0; i < cols_; i++) {
    for (int j = 0; j < rows_; j++) {
      S21Matrix matrixMinor = MinorMatrix(i, j);
      matrixResult.matrix_[i][j] = pow(-1.0, i + j) * matrixMinor.Determinant();
    }
  }

  return matrixResult;
}
double S21Matrix::Determinant() {
  double determinantResult = 0.0;
  if (rows_ != cols_ || rows_ <= 0) {
    throw std::out_of_range(
        "Incorrect input, matrices should have the same size");
  }
  if (rows_ == 1) {
    determinantResult = matrix_[0][0];
  } else if (rows_ == 2) {
    determinantResult =
        matrix_[0][0] * matrix_[1][1] - matrix_[0][1] * matrix_[1][0];
  } else {
    for (int i = 0; i < rows_; i++) {
      S21Matrix MatrixMinor = MinorMatrix(0, i);
      determinantResult +=
          pow(-1.0, i) * matrix_[0][i] * MatrixMinor.Determinant();
    }
  }
  return determinantResult;
}
S21Matrix S21Matrix::InverseMatrix() {
  double det = Determinant();
  S21Matrix transp(rows_, cols_);
  if (cols_ != rows_ || !det) {
    throw std::out_of_range(
        "Incorrect input, matrices should have the same size");
  } else {
    S21Matrix comp = CalcComplements();
    transp = comp.Transpose();
    transp.MulNumber(1.0 / det);
  }
  return transp;
}
void S21Matrix::PrintMatrix() {
  if (matrix_ != nullptr) {
    for (int i = 0; i < rows_; ++i) {
      for (int j = 0; j < cols_; ++j) {
        std::cout << matrix_[i][j] << "\t";
        if (j != cols_ - 1) printf(" ");
      }
      std::cout << std::endl;
    }
  } else {
    std::cout << "Matrix does not exist" << std::endl;
  }
}
void S21Matrix::CreateMatrix() {
  matrix_ = new double *[rows_];
  for (int i = 0; i < rows_; i++) {
    matrix_[i] = new double[cols_]{0};
  }
}

void S21Matrix::DeleteMatrix() {
  if (matrix_ != nullptr) {
    for (int i = 0; i < rows_; i++) {
      delete[] matrix_[i];
    }
    delete[] matrix_;
  }
}
void S21Matrix::FillMatrix() {
  for (int i = 0; i < rows_; i++) {
    for (int j = 0; j < cols_; j++) {
      matrix_[i][j] = i + j;
    }
  }
}

S21Matrix S21Matrix::MinorMatrix(int rows, int cols) {
  S21Matrix matrixResult(rows_ - 1, cols_ - 1);
  int rowsTemp = 0;
  for (int i = 0; i < matrixResult.rows_; i++) {
    if (i == rows) {
      rowsTemp = 1;
    }
    int colsTemp = 0;
    for (int j = 0; j < matrixResult.cols_; j++) {
      if (j == cols) {
        colsTemp = 1;
      }
      matrixResult.matrix_[i][j] = matrix_[i + rowsTemp][j + colsTemp];
    }
  }
  return matrixResult;
}
void S21Matrix::SetNewSize(int new_rows, int new_cols) {
  S21Matrix T(std::move(*this));

  if (new_rows > 0) {
    rows_ = new_rows;
  } else {
    rows_ = T.rows_;
  }
  if (new_cols > 0) {
    cols_ = new_cols;
  } else {
    cols_ = T.cols_;
  }
  matrix_ = new double *[rows_];
  for (int i = 0; i != rows_; ++i) {
    matrix_[i] = new double[cols_]();
  }

  for (int i = 0; i != rows_ && i != T.rows_; ++i) {
    for (int j = 0; j != cols_ && j != T.cols_; ++j) {
      matrix_[i][j] = T.matrix_[i][j];
    }
  }
}

S21Matrix S21Matrix::operator+(const S21Matrix &other) {
  S21Matrix resultMatrix(*this);
  resultMatrix.SumMatrix(other);
  return resultMatrix;
}

S21Matrix S21Matrix::operator-(const S21Matrix &other) {
  S21Matrix resultMatrix(*this);
  resultMatrix.SubMatrix(other);
  return resultMatrix;
}
S21Matrix S21Matrix::operator*(const S21Matrix &other) {
  S21Matrix res(*this);
  res.MulMatrix(other);
  return res;
}
S21Matrix S21Matrix::operator*(const double value) {
  S21Matrix res(*this);
  res.MulNumber(value);
  return res;
}
bool S21Matrix ::operator==(const S21Matrix &other) { return EqMatrix(other); }
S21Matrix &S21Matrix::operator=(const S21Matrix &other) {
  if (this != &other) {
    DeleteMatrix();
    rows_ = other.rows_;
    cols_ = other.cols_;
    CreateMatrix();
  }
  for (int i = 0; i < rows_; i++) {
    for (int j = 0; j < cols_; j++) {
      matrix_[i][j] = other.matrix_[i][j];
    }
  }
  return *this;
}

S21Matrix &S21Matrix::operator+=(const S21Matrix &other) {
  return *this = *this + other;
}

S21Matrix &S21Matrix::operator-=(const S21Matrix &other) {
  return *this = *this - other;
}
S21Matrix &S21Matrix::operator*=(const S21Matrix &other) {
  return *this = *this * other;
}

S21Matrix &S21Matrix::operator*=(const double value) {
  return *this = *this * value;
}
double &S21Matrix::operator()(int row, int col) {
  if (row >= rows_ || col >= cols_ || row < 0 || col < 0) {
    throw std::out_of_range("Incorrect input, index is out of range");
  } else {
    return matrix_[row][col];
  }
}

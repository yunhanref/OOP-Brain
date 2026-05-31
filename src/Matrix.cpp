#include "Matrix.h"

Matrix::Matrix(int r, int c) : rows(r), cols(c) {
    data = new double[r * c]{0.0};
}

Matrix::~Matrix() noexcept {
    delete[] data;
}

Matrix::Matrix(const Matrix& other) : rows(other.rows), cols(other.cols) {
    data = new double[rows * cols];
    for (int i = 0; i < rows * cols; i++) data[i] = other.data[i];
}

Matrix::Matrix(Matrix&& other) noexcept : rows(other.rows), cols(other.cols), data(other.data) {
    other.data = nullptr;
    other.rows = 0;
    other.cols = 0;
}

Matrix& Matrix::operator=(const Matrix& other) {
    if (this == &other) return *this;
    delete[] data;
    rows = other.rows;
    cols = other.cols;
    data = new double[rows * cols];
    for (int i = 0; i < rows * cols; i++) data[i] = other.data[i];
    return *this;
}

Matrix& Matrix::operator=(Matrix&& other) noexcept {
    if (this == &other) return *this;
    delete[] data;
    data = other.data;
    rows = other.rows;
    cols = other.cols;
    other.data = nullptr;
    other.rows = 0;
    other.cols = 0;
    return *this;
}

double& Matrix::at(int r, int c) { return data[r * cols + c]; }
const double& Matrix::at(int r, int c) const { return data[r * cols + c]; }

Matrix Matrix::operator*(const Matrix& other) const {
    if (cols != other.rows) throw DimensionMismatchException();
    Matrix result(rows, other.cols);
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < other.cols; j++) {
            double sum = 0;
            for (int k = 0; k < cols; k++) {
                sum += at(i, k) * other.at(k, j);
            }
            result.at(i, j) = sum;
        }
    }
    return result;
}

// Katmanlarin toplanabilmesi (bias eklemek) icin gerekli fonksiyon (Senin isini cozer)
Matrix Matrix::operator+(const Matrix& other) const {
    if (rows != other.rows || cols != other.cols) throw DimensionMismatchException();
    Matrix result(rows, cols);
    for (int i = 0; i < rows * cols; i++) {
        result.data[i] = data[i] + other.data[i];
    }
    return result;
}

#include "Matrix.h"

// 1. Kurucu (Constructor) - Sifirlarla doldurur
Matrix::Matrix(int r, int c) : rows(r), cols(c) {
    data = new double[r * c]();
}

// 2. Yikici (Destructor) - 0 Leak Garantisi
Matrix::~Matrix() noexcept {
    delete[] data;
}

// 3. Kopya Kurucu (Copy Constructor)
Matrix::Matrix(const Matrix& other) : rows(other.rows), cols(other.cols) {
    data = new double[rows * cols];
    for (int i = 0; i < rows * cols; i++) {
        data[i] = other.data[i];
    }
}

// 4. Tasima Kurucusu (Move Constructor)
Matrix::Matrix(Matrix&& other) noexcept : rows(other.rows), cols(other.cols), data(other.data) {
    other.rows = 0;
    other.cols = 0;
    other.data = nullptr;
}

// 5. Kopya Atama (Copy Assignment)
Matrix& Matrix::operator=(const Matrix& other) {
    if (this == &other) return *this;
    delete[] data;
    rows = other.rows;
    cols = other.cols;
    data = new double[rows * cols];
    for (int i = 0; i < rows * cols; i++) {
        data[i] = other.data[i];
    }
    return *this;
}

// 6. Tasima Atamasi (Move Assignment)
Matrix& Matrix::operator=(Matrix&& other) noexcept {
    if (this == &other) return *this;
    delete[] data;
    rows = other.rows;
    cols = other.cols;
    data = other.data;
    other.rows = 0;
    other.cols = 0;
    other.data = nullptr;
    return *this;
}

// 7. Eleman Erisimi (at)
double& Matrix::at(int r, int c) {
    return data[r * cols + c];
}

const double& Matrix::at(int r, int c) const {
    return data[r * cols + c];
}

// 8. Matris Carpimi (operator*)
Matrix Matrix::operator*(const Matrix& other) const {
    if (cols != other.rows) throw DimensionMismatchException();
    Matrix result(rows, other.cols);
    for (int i = 0; i < rows; ++i) {
        for (int j = 0; j < other.cols; ++j) {
            double sum = 0;
            for (int k = 0; k < cols; ++k) {
                sum += at(i, k) * other.at(k, j);
            }
            result.at(i, j) = sum;
        }
    }
    return result;
}

// 9. Matris Toplamasi (operator+)
Matrix Matrix::operator+(const Matrix& other) const {
    if (rows != other.rows || cols != other.cols) throw DimensionMismatchException();
    Matrix result(rows, cols);
    for (int i = 0; i < rows * cols; i++) {
        result.data[i] = data[i] + other.data[i];
    }
    return result;
}
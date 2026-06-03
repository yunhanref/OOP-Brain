#include "Matrix.h"
#include <cstdlib>
#include <ctime>
#include <stdexcept>

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

// 5. Kopya Atama (Copy Assignment) - Exception-Safe derin kopyalama
Matrix& Matrix::operator=(const Matrix& other) {
    if (this == &other) return *this;
    double* new_data = new double[other.rows * other.cols];
    for (int i = 0; i < other.rows * other.cols; i++) {
        new_data[i] = other.data[i];
    }
    delete[] data;
    rows = other.rows;
    cols = other.cols;
    data = new_data;
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

// 7. Eleman Erisimi (at ve operator())
double& Matrix::at(int r, int c) {
    return data[r * cols + c];
}

const double& Matrix::at(int r, int c) const {
    return data[r * cols + c];
}

double& Matrix::operator()(int r, int c) {
    return data[r * cols + c];
}

const double& Matrix::operator()(int r, int c) const {
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

// 9. Matris Toplamasi (operator+) - Broadcasting Destegi Eklenmis Hali
Matrix Matrix::operator+(const Matrix& other) const {
    // Kolon bazli broadcasting: (R, C) + (R, 1)
    if (rows == other.rows && other.cols == 1) {
        Matrix result(rows, cols);
        for (int i = 0; i < rows; ++i) {
            double val = other.at(i, 0);
            for (int j = 0; j < cols; ++j) {
                result.at(i, j) = at(i, j) + val;
            }
        }
        return result;
    }
    // Satir bazli broadcasting: (R, C) + (1, C)
    if (cols == other.cols && other.rows == 1) {
        Matrix result(rows, cols);
        for (int j = 0; j < cols; ++j) {
            double val = other.at(0, j);
            for (int i = 0; i < rows; ++i) {
                result.at(i, j) = at(i, j) + val;
            }
        }
        return result;
    }
    // Normal eleman bazli toplama
    if (rows != other.rows || cols != other.cols) throw DimensionMismatchException();
    Matrix result(rows, cols);
    for (int i = 0; i < rows * cols; i++) {
        result.data[i] = data[i] + other.data[i];
    }
    return result;
}

// 10. Matris Cikarmasi (operator-) - Broadcasting Destegi Eklenmis Hali
Matrix Matrix::operator-(const Matrix& other) const {
    // Kolon bazli broadcasting: (R, C) - (R, 1)
    if (rows == other.rows && other.cols == 1) {
        Matrix result(rows, cols);
        for (int i = 0; i < rows; ++i) {
            double val = other.at(i, 0);
            for (int j = 0; j < cols; ++j) {
                result.at(i, j) = at(i, j) - val;
            }
        }
        return result;
    }
    // Satir bazli broadcasting: (R, C) - (1, C)
    if (cols == other.cols && other.rows == 1) {
        Matrix result(rows, cols);
        for (int j = 0; j < cols; ++j) {
            double val = other.at(0, j);
            for (int i = 0; i < rows; ++i) {
                result.at(i, j) = at(i, j) - val;
            }
        }
        return result;
    }
    // Normal eleman bazli cikarma
    if (rows != other.rows || cols != other.cols) throw DimensionMismatchException();
    Matrix result(rows, cols);
    for (int i = 0; i < rows * cols; i++) {
        result.data[i] = data[i] - other.data[i];
    }
    return result;
}

// 11. Skaler Islemler
Matrix Matrix::operator*(double scalar) const {
    Matrix result(rows, cols);
    for (int i = 0; i < rows * cols; i++) {
        result.data[i] = data[i] * scalar;
    }
    return result;
}

Matrix Matrix::operator+(double scalar) const {
    Matrix result(rows, cols);
    for (int i = 0; i < rows * cols; i++) {
        result.data[i] = data[i] + scalar;
    }
    return result;
}

Matrix Matrix::operator-(double scalar) const {
    Matrix result(rows, cols);
    for (int i = 0; i < rows * cols; i++) {
        result.data[i] = data[i] - scalar;
    }
    return result;
}

Matrix Matrix::operator/(double scalar) const {
    if (scalar == 0.0) throw std::runtime_error("[Hata]: Sifira bolme hatasi.");
    Matrix result(rows, cols);
    for (int i = 0; i < rows * cols; i++) {
        result.data[i] = data[i] / scalar;
    }
    return result;
}

Matrix operator*(double scalar, const Matrix& matrix) {
    return matrix * scalar;
}

Matrix operator+(double scalar, const Matrix& matrix) {
    return matrix + scalar;
}

// 12. Bilesik Atama Operatorleri
Matrix& Matrix::operator+=(const Matrix& other) {
    *this = *this + other;
    return *this;
}

Matrix& Matrix::operator-=(const Matrix& other) {
    *this = *this - other;
    return *this;
}

Matrix& Matrix::operator*=(double scalar) {
    for (int i = 0; i < rows * cols; i++) {
        data[i] *= scalar;
    }
    return *this;
}

Matrix& Matrix::operator/=(double scalar) {
    if (scalar == 0.0) throw std::runtime_error("[Hata]: Sifira bolme hatasi.");
    for (int i = 0; i < rows * cols; i++) {
        data[i] /= scalar;
    }
    return *this;
}

// 13. Temel Matris Islemleri
Matrix Matrix::transpose() const {
    Matrix result(cols, rows);
    for (int i = 0; i < rows; ++i) {
        for (int j = 0; j < cols; ++j) {
            result.at(j, i) = at(i, j);
        }
    }
    return result;
}

Matrix Matrix::hadamard(const Matrix& other) const {
    if (rows != other.rows || cols != other.cols) throw DimensionMismatchException();
    Matrix result(rows, cols);
    for (int i = 0; i < rows * cols; i++) {
        result.data[i] = data[i] * other.data[i];
    }
    return result;
}

void Matrix::randomize(double minVal, double maxVal) {
    for (int i = 0; i < rows * cols; i++) {
        data[i] = minVal + ((double)std::rand() / RAND_MAX) * (maxVal - minVal);
    }
}

// 14. Yazdirma Yardimcilari
void Matrix::print() const {
    std::cout << *this;
}

std::ostream& operator<<(std::ostream& os, const Matrix& matrix) {
    for (int i = 0; i < matrix.rows; i++) {
        for (int j = 0; j < matrix.cols; j++) {
            os << matrix.at(i, j);
            if (j < matrix.cols - 1) os << "\t";
        }
        os << "\n";
    }
    return os;
}
#include "Matrix.h"

Matrix::Matrix(int r, int c) : rows(r), cols(c), data(nullptr) {}
Matrix::~Matrix() noexcept {}
Matrix::Matrix(const Matrix& other) : rows(other.rows), cols(other.cols), data(nullptr) {}
Matrix& Matrix::operator=(const Matrix& other) { return *this; }

Matrix Matrix::operator*(const Matrix& other) const { return Matrix(0, 0); }
Matrix Matrix::operator+(const Matrix& other) const { return Matrix(0, 0); }
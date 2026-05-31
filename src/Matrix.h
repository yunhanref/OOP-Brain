#pragma once

class Matrix {
public:
    int rows;
    int cols;
    double* data; 

    Matrix(int r, int c);
    ~Matrix() noexcept;
    Matrix(const Matrix& other);
    Matrix& operator=(const Matrix& other);

    Matrix operator*(const Matrix& other) const;
    Matrix operator+(const Matrix& other) const;
};
#pragma once
#include "Exceptions.h"

class Matrix {
public:
    int rows;
    int cols;
    double* data;

    Matrix(int r, int c);
    ~Matrix() noexcept;
    
    // Copy ve Move kurallari
    Matrix(const Matrix& other);
    Matrix(Matrix&& other) noexcept;
    Matrix& operator=(const Matrix& other);
    Matrix& operator=(Matrix&& other) noexcept;

    // Eleman erisimi
    double& at(int r, int c);
    const double& at(int r, int c) const;

    // Operator asiri yuklemeleri
    Matrix operator*(const Matrix& other) const;
    Matrix operator+(const Matrix& other) const; 
};

#pragma once
#include "Exceptions.h"
#include <iostream>

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
    double& operator()(int r, int c);
    const double& operator()(int r, int c) const;

    // Operator asiri yuklemeleri (Matris - Matris)
    Matrix operator*(const Matrix& other) const;
    Matrix operator+(const Matrix& other) const; 
    Matrix operator-(const Matrix& other) const;

    // Operator asiri yuklemeleri (Matris - Scalar)
    Matrix operator*(double scalar) const;
    Matrix operator+(double scalar) const;
    Matrix operator-(double scalar) const;
    Matrix operator/(double scalar) const;

    // Dost fonksiyonlar (Scalar - Matris)
    friend Matrix operator*(double scalar, const Matrix& matrix);
    friend Matrix operator+(double scalar, const Matrix& matrix);

    // Bilesik atama operatorleri
    Matrix& operator+=(const Matrix& other);
    Matrix& operator-=(const Matrix& other);
    Matrix& operator*=(double scalar);
    Matrix& operator/=(double scalar);

    // Temel matris islemleri
    Matrix transpose() const;
    Matrix hadamard(const Matrix& other) const;
    void randomize(double minVal = -1.0, double maxVal = 1.0);
    
    // Yazdirma fonksiyonlari
    void print() const;
    friend std::ostream& operator<<(std::ostream& os, const Matrix& matrix);
};


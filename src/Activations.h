#pragma once
#include "IActivation.h"
#include <cmath>

// 1. Sigmoid Sınıfı Uygulaması
class Sigmoid : public IActivation {
public:
    double transform(double val) const noexcept override {
        // Formül: 1 / (1 + e^-x)
        return 1.0 / (1.0 + std::exp(-val));
    }
};

// 2. ReLU Sınıfı Uygulaması
class ReLU : public IActivation {
public:
    double transform(double val) const noexcept override {
        // Formül: max(0, x)
        return (val > 0.0) ? val : 0.0;
    }
};

// 3. Tanh Sınıfı Uygulaması 
class Tanh : public IActivation {
public:
    double transform(double val) const noexcept override {
        // Formül: tanh(x)
        return std::tanh(val);
    }
};
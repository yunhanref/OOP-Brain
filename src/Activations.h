#pragma once
#include "IActivation.h"
#include <cmath>

class Sigmoid : public IActivation {
public:
    double transform(double val) const noexcept override {
        return 1.0 / (1.0 + std::exp(-val));
    }
};

class ReLU : public IActivation {
public:
    double transform(double val) const noexcept override {
        return (val > 0.0) ? val : 0.0;
    }
};

class Tanh : public IActivation {
public:
    double transform(double val) const noexcept override {
        return std::tanh(val);
    }
};

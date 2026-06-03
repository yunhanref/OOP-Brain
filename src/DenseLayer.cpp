#include "DenseLayer.h"
#include <cstdlib>
#include <ctime>

DenseLayer::DenseLayer(int in_dim, int out_dim, IActivation* act) 
    : weights(out_dim, in_dim), bias(out_dim, 1), actFunc(act) {
    
    std::srand(static_cast<unsigned int>(std::time(nullptr)));
    weights.randomize(-1.0, 1.0);
    bias.randomize(-1.0, 1.0);
}

DenseLayer::~DenseLayer() noexcept {}

Matrix DenseLayer::forward(const Matrix& in) {
    // 1. Lineer Donusum (Z = W * X + b)
    Matrix z = weights * in + bias;
    
    // 2. Aktivasyon Fonksiyonu
    Matrix a(z.rows, z.cols);
    for (int i = 0; i < z.rows; i++) {
        for (int j = 0; j < z.cols; j++) {
            a.at(i, j) = actFunc->transform(z.at(i, j));
        }
    }
    return a;
}

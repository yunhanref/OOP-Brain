#include "DenseLayer.h"
#include <cstdlib>
#include <ctime>

DenseLayer::DenseLayer(int in_dim, int out_dim, IActivation* act) 
    : weights(out_dim, in_dim), bias(out_dim, 1), actFunc(act) {
    
    // Matematik ekibini beklemeden agirliklari rastgele dolduruyoruz (-1 ile 1 arasinda)
    std::srand(std::time(nullptr));
    for(int i = 0; i < weights.rows * weights.cols; i++) {
        weights.data[i] = ((double) std::rand() / (RAND_MAX)) * 2.0 - 1.0;
    }
    for(int i = 0; i < bias.rows * bias.cols; i++) {
        bias.data[i] = ((double) std::rand() / (RAND_MAX)) * 2.0 - 1.0;
    }
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

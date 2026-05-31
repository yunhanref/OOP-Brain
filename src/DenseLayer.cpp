#include "DenseLayer.h"

DenseLayer::DenseLayer(int in_dim, int out_dim, IActivation* act) 
    : weights(out_dim, in_dim), bias(out_dim, 1), actFunc(act) {
    // Kurucu fonksiyon matrisleri 0 ile baslatir. 
    // Gercek projede bu agirliklara rastgele deger atamasi yapan bir fonksiyon yazilmalidir.
}

DenseLayer::~DenseLayer() noexcept {}

Matrix DenseLayer::forward(const Matrix& in) {
    // 1. Lineer Donusum (Z = W * X + b)
    Matrix z = weights * in + bias;
    
    // 2. Aktivasyon Fonksiyonu (A = sigma(Z))
    Matrix a(z.rows, z.cols);
    for (int i = 0; i < z.rows; i++) {
        for (int j = 0; j < z.cols; j++) {
            a.at(i, j) = actFunc->transform(z.at(i, j));
        }
    }
    return a;
}

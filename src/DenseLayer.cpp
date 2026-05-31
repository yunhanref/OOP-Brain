#include "DenseLayer.h"

DenseLayer::DenseLayer(int in_dim, int out_dim, IActivation* act) 
    : weights(in_dim, out_dim), bias(1, out_dim), actFunc(act) {}

DenseLayer::~DenseLayer() noexcept {}

Matrix DenseLayer::process(const Matrix& in) {
    return Matrix(0, 0);
}
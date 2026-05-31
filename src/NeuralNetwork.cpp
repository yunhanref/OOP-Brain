#include "NeuralNetwork.h"

NeuralNetwork::~NeuralNetwork() noexcept {
    for (BaseLayer* layer : pipeline) {
        delete layer;
    }
    pipeline.clear();
}

void NeuralNetwork::pushLayer(BaseLayer* l) { 
    pipeline.push_back(l); 
}

Matrix NeuralNetwork::run(const Matrix& input) {
    return Matrix(0, 0);
}
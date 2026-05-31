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
    Matrix current = input;
    // Agin icindeki tum katmanlari sirayla calistirip birbirine baglar
    for (BaseLayer* layer : pipeline) {
        current = layer->forward(current);
    }
    return current;
}

#pragma once
#include <vector>
#include "BaseLayer.h"

class NeuralNetwork {
private:
    std::vector<BaseLayer*> pipeline; 

public:
    ~NeuralNetwork() noexcept;
    void pushLayer(BaseLayer* l);
    Matrix run(const Matrix& input);
};
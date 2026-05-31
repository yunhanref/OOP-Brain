#pragma once
#include "BaseLayer.h"
#include "IActivation.h"

class DenseLayer : public BaseLayer {
private:
    Matrix weights;
    Matrix bias;
    IActivation* actFunc; 

public:
    DenseLayer(int in_dim, int out_dim, IActivation* act);
    ~DenseLayer() noexcept override;
    
    Matrix process(const Matrix& in) override;
};
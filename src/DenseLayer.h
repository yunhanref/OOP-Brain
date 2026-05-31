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

    Matrix forward(const Matrix& in) override;

    // Veri/Dosya isleme modulu icin agirlik erisimi
    const Matrix& getWeights() const { return weights; }
    const Matrix& getBias() const { return bias; }
    void setWeights(const Matrix& w) { weights = w; }
    void setBias(const Matrix& b) { bias = b; }
};
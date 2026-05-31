#pragma once
#include "Matrix.h"

class BaseLayer {
public:
    virtual ~BaseLayer() noexcept = default; 
    virtual Matrix forward(const Matrix& in) = 0; 
};

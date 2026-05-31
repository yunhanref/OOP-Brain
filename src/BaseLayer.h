#pragma once
#include "Matrix.h"

class BaseLayer {
public:
    virtual ~BaseLayer() noexcept = default; 
    virtual Matrix process(const Matrix& in) = 0; 
};
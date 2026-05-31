#pragma once

class IActivation {
public:
    virtual ~IActivation() noexcept = default; 
    virtual double transform(double val) const noexcept = 0; 
};
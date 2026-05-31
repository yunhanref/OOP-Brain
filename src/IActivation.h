#pragma once

class IActivation {
public:
    virtual ~IActivation() = default;
    virtual double transform(double val) const noexcept = 0; 
};

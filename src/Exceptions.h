#pragma once
#include <exception>

class DimensionMismatchException : public std::exception {
public:
    virtual const char* what() const noexcept override {
        return "[Hata]: Matris boyutlari islem icin uyumsuzdur.";
    }
};
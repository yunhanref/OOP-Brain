#pragma once
#include <exception>

class DimensionMismatchException : public std::exception {
public:
    virtual const char* what() const noexcept override {
        return "[Hata]: Matris boyutlari islem icin uyumsuzdur.";
    }
};

class FileIOException : public std::exception {
public:
    virtual const char* what() const noexcept override {
        return "[Hata]: Dosya acilamadi.";
    }
};

class InvalidFormatException : public std::exception {
public:
    virtual const char* what() const noexcept override {
        return "[Hata]: CSV format bozuk veya tutarsiz satir uzunlugu.";
    }
};
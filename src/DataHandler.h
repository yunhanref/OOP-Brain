#pragma once
#include <string>
#include "Matrix.h"

// Veri ve Dosya Isleme modulu
class DataHandler {
public:
    // CSV dosyasini okur ve bir Matrix dondurur.
    // hasHeader = true ise ilk satir (basliklar) atlanir.
    static Matrix loadCSV(const std::string& path, bool hasHeader = false);

    // Bir Matrix'i CSV olarak diske yazar.
    static void saveCSV(const std::string& path, const Matrix& m);
};

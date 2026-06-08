#include "DataHandler.h"
#include "Exceptions.h"
#include <fstream>
#include <sstream>
#include <vector>
#include <string>
#include <algorithm> // trim için gerekli olabilir

Matrix DataHandler::loadCSV(const std::string& path, bool hasHeader) {
    std::ifstream file(path);
    if (!file.is_open()) {
        throw FileIOException();
    }

    std::vector<std::vector<double>> rows;
    std::string line;

    if (hasHeader) {
        std::getline(file, line); // Başlık satırını her zaman atla
    }

    while (std::getline(file, line)) {
        // Satırı temizle: Başındaki/sonundaki boşlukları ve \r karakterini (Windows/Linux farkı) at
        line.erase(std::remove(line.begin(), line.end(), '\r'), line.end());
        if (line.empty() || line.find_first_not_of(" \t\n\v\f\r") == std::string::npos) continue;

        std::vector<double> row;
        std::stringstream ss(line);
        std::string cell;

        while (std::getline(ss, cell, ',')) {
            // Hücre boşsa veya sadece boşluksa atla
            if (cell.empty()) continue; 
            try {
                row.push_back(std::stod(cell));
            } catch (...) {
                throw InvalidFormatException(); // Sayısal olmayan hücre
            }
        }
        
        // Eğer satırda hiç veri yoksa (sadece virgül varsa) atla
        if (!row.empty()) {
            rows.push_back(row);
        }
    }

    if (rows.empty()) {
        throw InvalidFormatException();
    }

    int nRows = static_cast<int>(rows.size());
    int nCols = static_cast<int>(rows[0].size());

    // Tüm satırların aynı uzunlukta olduğunu doğrula
    for (const auto& r : rows) {
        if (static_cast<int>(r.size()) != nCols) {
            throw InvalidFormatException();
        }
    }

    Matrix result(nRows, nCols);
    for (int i = 0; i < nRows; i++) {
        for (int j = 0; j < nCols; j++) {
            result.at(i, j) = rows[i][j];
        }
    }
    return result;
}

void DataHandler::saveCSV(const std::string& path, const Matrix& m) {
    std::ofstream file(path);
    if (!file.is_open()) {
        throw FileIOException();
    }

    for (int i = 0; i < m.rows; i++) {
        for (int j = 0; j < m.cols; j++) {
            file << m.at(i, j);
            if (j < m.cols - 1) file << ",";
        }
        file << "\n";
    }
}

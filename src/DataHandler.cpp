#include "DataHandler.h"
#include "Exceptions.h"
#include <fstream>
#include <sstream>
#include <vector>
#include <string>

Matrix DataHandler::loadCSV(const std::string& path, bool hasHeader) {
    std::ifstream file(path);
    if (!file.is_open()) {
        throw FileIOException();
    }

    std::vector<std::vector<double>> rows;
    std::string line;

    if (hasHeader) {
        std::getline(file, line); // baslik satirini atla
    }

    while (std::getline(file, line)) {
        if (line.empty()) continue; // bos satirlari gec

        std::vector<double> row;
        std::stringstream ss(line);
        std::string cell;

        while (std::getline(ss, cell, ',')) {
            try {
                row.push_back(std::stod(cell));
            } catch (...) {
                throw InvalidFormatException(); // sayisal olmayan hucre
            }
        }
        rows.push_back(row);
    }

    if (rows.empty()) {
        throw InvalidFormatException();
    }

    int nRows = static_cast<int>(rows.size());
    int nCols = static_cast<int>(rows[0].size());

    // Tum satirlarin ayni uzunlukta oldugunu dogrula
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

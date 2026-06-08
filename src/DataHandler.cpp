#include "DataHandler.h"
#include "Exceptions.h"
#include <fstream>
#include <sstream>
#include <vector>
#include <string>
#include <algorithm> // trim için gerekli olabilir

Matrix DataHandler::loadCSV(const std::string& path, bool hasHeader) {
    std::ifstream file(path);
    if (!file.is_open()) throw FileIOException();

    std::vector<std::vector<double>> rows;
    std::string line;

    if (hasHeader) std::getline(file, line); 

    while (std::getline(file, line)) {
        if (line.empty()) continue; 

        std::vector<double> row;
        std::stringstream ss(line);
        std::string cell;

        while (std::getline(ss, cell, ',')) {
            try {
                // Sadece sayıya çevrilebilenleri al
                size_t pos;
                double val = std::stod(cell, &pos);
                row.push_back(val);
            } catch (...) {
                // Sayıya çevrilemiyorsa (örn: metin varsa) atla
                continue; 
            }
        }
        
        if (!row.empty()) rows.push_back(row);
    }
    
    // Matris oluşturma kısmında satır/sütun eşitleme
    int nRows = static_cast<int>(rows.size());
    int nCols = 0;
    for(const auto& r : rows) if((int)r.size() > nCols) nCols = (int)r.size();

    Matrix result(nRows, nCols);
    for (int i = 0; i < nRows; i++) {
        for (int j = 0; j < nCols; j++) {
            result.at(i, j) = (j < (int)rows[i].size()) ? rows[i][j] : 0.0;
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

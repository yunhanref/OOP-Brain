#pragma once
#include <string>
#include "DenseLayer.h"

// Egitilmis agirliklari diske yazar / geri okur
class ModelStorage {
public:
    // Bir katmanin agirlik ve bias'ini "<prefix>_w.csv" ve "<prefix>_b.csv" olarak kaydeder
    static void saveLayer(const std::string& prefix, const DenseLayer& layer);

    // Diskten okunan agirliklari mevcut katmana yukler
    static void loadLayer(const std::string& prefix, DenseLayer& layer);
};

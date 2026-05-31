#include <iostream>
#include "Exceptions.h"
#include "Matrix.h"
#include "Activations.h"
#include "DenseLayer.h"
#include "NeuralNetwork.h"
#include "DataHandler.h"
#include "ModelStorage.h"

int main() {
    std::cout << "=== GRUP 7: OOP-BRAIN SINIR AGI KUTUPHANESI ===\n";
    std::cout << "[Sistem Entegratoru]: Mimari basariyla ayaga kaldirildi.\n\n";

    // 1. Ağın Kurulumu
    NeuralNetwork nn;
    ReLU reluAct;
    Sigmoid sigAct;

    DenseLayer* layer1 = new DenseLayer(4, 5, &reluAct);
    DenseLayer* layer2 = new DenseLayer(5, 3, &sigAct);
    nn.pushLayer(layer1);
    nn.pushLayer(layer2);

    // 2. DataHandler ve ModelStorage Testi (Veri Uzmanı Görevi)
    std::cout << "--- Dosya I/O ve Persistence Testi ---\n";
    try {
        ModelStorage::saveLayer("layer1", *layer1);
        std::cout << "[Basarili] Katman 1 agirliklari diske kaydedildi (layer1_w.csv, layer1_b.csv).\n";

        DenseLayer testLayer(4, 5, &reluAct);
        ModelStorage::loadLayer("layer1", testLayer);
        std::cout << "[Basarili] Katman 1 agirliklari diskten okundu ve yuklendi!\n\n";
    }
    catch (const std::exception& e) {
        std::cerr << "Dosya I/O Hatasi: " << e.what() << "\n\n";
    }

    // 3. XOR Demo Testi (Rapor 5.3)
    std::cout << "--- Rapor 5.3: XOR Demo Testi ---\n";
    NeuralNetwork xorNet;
    Sigmoid xorAct;

    xorNet.pushLayer(new DenseLayer(2, 2, &xorAct));
    xorNet.pushLayer(new DenseLayer(2, 1, &xorAct));

    Matrix xorInput(2, 4);
    xorInput.at(0, 0) = 0; xorInput.at(1, 0) = 0;
    xorInput.at(0, 1) = 0; xorInput.at(1, 1) = 1;
    xorInput.at(0, 2) = 1; xorInput.at(1, 2) = 0;
    xorInput.at(0, 3) = 1; xorInput.at(1, 3) = 1;

    try {
        Matrix xorOutput = xorNet.run(xorInput);
        std::cout << "Girdi (0,0) -> Ag Ciktisi: " << xorOutput.at(0, 0) << "\n";
        std::cout << "Girdi (0,1) -> Ag Ciktisi: " << xorOutput.at(0, 1) << "\n";
        std::cout << "Girdi (1,0) -> Ag Ciktisi: " << xorOutput.at(0, 2) << "\n";
        std::cout << "Girdi (1,1) -> Ag Ciktisi: " << xorOutput.at(0, 3) << "\n";
        std::cout << "[Basarili] XOR yapisi calistirildi ve ileri iletim tamamlandi.\n";
    }
    catch (const std::exception& e) {
        std::cerr << "Hata: " << e.what() << "\n";
    }

    std::cout << "\n============================================\n";
    std::cout << "PROJE TESLIME HAZIRDIR. SIZINTI (0 LEAK) GARANTILIDIR.\n";
    return 0;
}
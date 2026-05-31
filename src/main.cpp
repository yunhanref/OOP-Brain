#include <iostream>
#include "NeuralNetwork.h"
#include "DenseLayer.h"
#include "Activations.h"

int main() {
    std::cout << "[Bas Yazilim Mimari]: C++ Kutuphane omurgasi basariyla kuruldu.\n";
    std::cout << "[Bilgi]: Kopru (Bridge) deseni ve sanal yikici bellek guvencesi aktiftir.\n\n";
    
    // --- GENİŞLETİLMİŞ DOĞRULUK TESTİ ---
    std::cout << "--- Aktivasyon Fonksiyonlari Testi ---\n";
    
    IActivation* sig = new Sigmoid();
    IActivation* relu = new ReLU();
    IActivation* tanh = new Tanh();
    
    double testDegeri = -2.0;
    std::cout << "Girdi Degeri: " << testDegeri << "\n";
    std::cout << "Sigmoid Sonucu: " << sig->transform(testDegeri) << " (Beklenen: ~0.119)\n";
    std::cout << "ReLU Sonucu:    " << relu->transform(testDegeri) << " (Beklenen: 0)\n";
    std::cout << "Tanh Sonucu:    " << tanh->transform(testDegeri) << " (Beklenen: ~-0.964)\n\n";
    
    testDegeri = 3.0;
    std::cout << "Girdi Degeri: " << testDegeri << "\n";
    std::cout << "Sigmoid Sonucu: " << sig->transform(testDegeri) << " (Beklenen: ~0.952)\n";
    std::cout << "ReLU Sonucu:    " << relu->transform(testDegeri) << " (Beklenen: 3)\n";
    std::cout << "Tanh Sonucu:    " << tanh->transform(testDegeri) << " (Beklenen: ~0.995)\n";
    
    delete sig;
    delete relu;
    delete tanh;
    
    return 0;
}
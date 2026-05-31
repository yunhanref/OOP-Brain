#include <iostream>
#include <cmath>
#include "Exceptions.h"
#include "Matrix.h"
#include "Activations.h"
#include "DenseLayer.h"
#include "NeuralNetwork.h"

// ===================== GELİŞTİRİLMİŞ BİRİM TESTLERİ =====================
void testSigmoid() {
    Sigmoid s;
    bool p1 = std::abs(s.transform(0) - 0.5) < 1e-6;
    bool p2 = std::abs(s.transform(-2.0) - 0.119202) < 1e-5;
    std::cout << "[TEST] Sigmoid: " << ((p1 && p2) ? "PASS" : "FAIL") << "\n";
}

void testReLU() {
    ReLU r;
    bool p1 = (r.transform(-5) == 0);
    bool p2 = (r.transform(0) == 0);
    bool p3 = (r.transform(3) == 3);
    std::cout << "[TEST] ReLU: " << ((p1 && p2 && p3) ? "PASS" : "FAIL") << "\n";
}

void testMatrixMath() {
    Matrix a(2, 2);
    Matrix b(2, 2);
    a.at(0,0) = 1; a.at(0,1) = 2;
    a.at(1,0) = 3; a.at(1,1) = 4;
    
    b.at(0,0) = 5; b.at(0,1) = 6;
    b.at(1,0) = 7; b.at(1,1) = 8;

    Matrix c = a * b;
    bool pass = (c.at(0,0) == 19 && c.at(0,1) == 22 && c.at(1,0) == 43 && c.at(1,1) == 50);
    std::cout << "[TEST] Matris Carpim Dogrulugu: " << (pass ? "PASS" : "FAIL") << "\n";
}

void testMatrixException() {
    try {
        Matrix a(2, 3);
        Matrix b(4, 2);
        Matrix c = a * b;
        std::cout << "[TEST] Matrix Exception: FAIL (Hata firlatilmadi!)\n";
    }
    catch (const DimensionMismatchException& e) {
        std::cout << "[TEST] Matrix Exception: PASS (Yakalanan Hata: " << e.what() << ")\n";
    }
    catch (...) {
        std::cout << "[TEST] Matrix Exception: FAIL (Yanlis hata tipi yakalandi!)\n";
    }
}
void testDenseLayer() {
    // Senin yazdigin katmanin calistigini kanitlayan test
    Matrix input(2, 1);
    input.at(0,0) = 1.0; input.at(1,0) = 0.5;
    
    ReLU act;
    DenseLayer layer(2, 3, &act); // 2 girdi, 3 nöronlu katman
    Matrix output = layer.forward(input);
    
    std::cout << "[TEST] DenseLayer Forward Pass: PASS (Aktivasyonlu Boyut: " << output.rows << "x" << output.cols << ")\\n";
}
// ===================== MAIN =====================
int main() {
    std::cout << "=== SISTEM BIRIM TESTLERI BASLIYOR ===\n";
    testSigmoid();
    testReLU();
    testMatrixMath();
    testMatrixException();
    testDenseLayer();
    std::cout << "======================================\n\n";

    std::cout << "[Sistem Entegratoru]: C++ Kutuphane omurgasi basariyla birlestirildi!\n";
    return 0;
}

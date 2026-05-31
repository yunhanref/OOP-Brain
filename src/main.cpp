#include <iostream>
#include <cmath>
#include "Exceptions.h"
#include "Matrix.h"
#include "Activations.h"
#include "DenseLayer.h"
#include "NeuralNetwork.h"
#include "DataHandler.h"
#include "ModelStorage.h"

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

// ===================== VERI & DOSYA ISLEME TESTLERI =====================

// CSV yaz -> oku (round-trip): yazilan veri aynen geri okunmali
void testCSVRoundTrip() {
    Matrix original(2, 3);
    original.at(0,0) = 1.5; original.at(0,1) = 2.5; original.at(0,2) = 3.5;
    original.at(1,0) = 4.5; original.at(1,1) = 5.5; original.at(1,2) = 6.5;

    bool pass = false;
    try {
        DataHandler::saveCSV("test_data.csv", original);
        Matrix loaded = DataHandler::loadCSV("test_data.csv");

        if (loaded.rows == original.rows && loaded.cols == original.cols) {
            pass = true;
            for (int i = 0; i < original.rows && pass; i++) {
                for (int j = 0; j < original.cols && pass; j++) {
                    if (std::abs(loaded.at(i, j) - original.at(i, j)) > 1e-6) {
                        pass = false;
                    }
                }
            }
        }
    }
    catch (...) {
        pass = false;
    }
    std::cout << "[TEST] CSV Yaz/Oku (Round-Trip): " << (pass ? "PASS" : "FAIL") << "\n";
}

// Olmayan dosya acilinca FileIOException firlatilmali
void testCSVFileException() {
    try {
        Matrix m = DataHandler::loadCSV("bu_dosya_yok_12345.csv");
        std::cout << "[TEST] CSV Dosya Hatasi: FAIL (Hata firlatilmadi!)\n";
    }
    catch (const FileIOException& e) {
        std::cout << "[TEST] CSV Dosya Hatasi: PASS (Yakalanan Hata: " << e.what() << ")\n";
    }
    catch (...) {
        std::cout << "[TEST] CSV Dosya Hatasi: FAIL (Yanlis hata tipi yakalandi!)\n";
    }
}

// Katman agirliklarini kaydet -> yukle: deger korunmali
void testModelStorage() {
    Sigmoid act;
    DenseLayer layer(3, 2, &act); // weights: 2x3, bias: 2x1

    // Agirliklara bilinen degerler ata
    Matrix w(2, 3);
    w.at(0,0) = 0.1; w.at(0,1) = 0.2; w.at(0,2) = 0.3;
    w.at(1,0) = 0.4; w.at(1,1) = 0.5; w.at(1,2) = 0.6;
    Matrix b(2, 1);
    b.at(0,0) = 0.7;
    b.at(1,0) = 0.8;
    layer.setWeights(w);
    layer.setBias(b);

    bool pass = false;
    try {
        ModelStorage::saveLayer("test_layer", layer);

        // Yeni bir katmana geri yukle
        DenseLayer loadedLayer(3, 2, &act);
        ModelStorage::loadLayer("test_layer", loadedLayer);

        const Matrix& lw = loadedLayer.getWeights();
        const Matrix& lb = loadedLayer.getBias();

        pass = (lw.rows == 2 && lw.cols == 3 && lb.rows == 2 && lb.cols == 1);
        for (int i = 0; i < 2 && pass; i++) {
            for (int j = 0; j < 3 && pass; j++) {
                if (std::abs(lw.at(i, j) - w.at(i, j)) > 1e-6) pass = false;
            }
        }
        for (int i = 0; i < 2 && pass; i++) {
            if (std::abs(lb.at(i, 0) - b.at(i, 0)) > 1e-6) pass = false;
        }
    }
    catch (...) {
        pass = false;
    }
    std::cout << "[TEST] Agirlik Kaydet/Yukle: " << (pass ? "PASS" : "FAIL") << "\n";
}

// ===================== MAIN =====================
int main() {
    std::cout << "=== SISTEM BIRIM TESTLERI BASLIYOR ===\n";
    testSigmoid();
    testReLU();
    testMatrixMath();
    testMatrixException();

    std::cout << "--- Veri & Dosya Isleme Testleri ---\n";
    testCSVRoundTrip();
    testCSVFileException();
    testModelStorage();
    std::cout << "======================================\n\n";

    std::cout << "[Sistem Entegratoru]: C++ Kutuphane omurgasi basariyla birlestirildi!\n";
    return 0;
}
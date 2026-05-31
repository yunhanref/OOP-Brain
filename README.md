<div align="center">
  <img width="480" height="320" alt="Flag_of_Turkey svg" src="https://github.com/user-attachments/assets/4c6a0544-41c5-4a51-99e9-fc813302013a" />
</div>

# OOP-Brain: Modüler C++ Sinir Ağı Kütüphanesi

**OOP-Brain**, C++'ın düşük seviyeli performans avantajları ile yüksek seviyeli Nesne Yönelimli Programlama (OOP) prensiplerini birleştiren, sıfırdan (hiçbir harici ML kütüphanesi kullanılmadan) geliştirilmiş bir yapay sinir ağı ileri iletim (forward pass) motorudur. 

7. Grup tarafından 14 haftalık akademik müfredat kapsamında; **sıfır bellek sızıntısı (0 memory leak)**, katı hata yönetimi ve maksimum genişletilebilirlik hedeflenerek tasarlanmıştır.

---

## Temel Özellikler

* **Kütüphanesiz (No Dependencies):** Yalnızca Standart C++ kütüphaneleri kullanılarak inşa edilmiştir.
* ** Sıfır Bellek Sızıntısı (0 Leak):** Deep copy, taşıma (move) semantikleri ve sanal yıkıcılar (virtual destructors) kullanılarak dinamik bellek yönetimi kusursuzlaştırılmıştır.
* ** Arayüz Tabanlı Tasarım (Interface-Based Design):** Polimorfizm (çok biçimlilik) sayesinde, sistemin ana omurgasına dokunmadan yeni aktivasyon fonksiyonları veya katman türleri sisteme kolayca enjekte edilebilir (Open/Closed Principle).
* ** Model Persistence (Kalıcılık):** Eğitilmiş ağ ağırlıkları (weights) ve sapma (bias) değerleri `.csv` formatında diske kaydedilebilir ve sonradan diskten okunabilir.
* ** Özel Hata Yönetimi:** Matris boyut uyuşmazlıkları (örn. geçersiz matris çarpımları) veya hatalı dosya formatları, özel Exception sınıfları ile çalışma zamanında sistem çökmeden güvenle yakalanır.

---

## Mimari ve Bileşenler

Sistem 3 ana katmandan oluşmaktadır:

1. **Matematik Motoru (`Matrix`):** Matris çarpımı ve toplaması için operatör aşırı yüklemeleri (`*`, `+`) barındıran, bellek kontrolünü encapsulate etmiş (sarmalamış) çekirdek birim.
2. **Katman ve Aktivasyon (`DenseLayer` & `IActivation`):** $Z = W \cdot X + b$ ve $A = \sigma(Z)$ matematiksel operasyonlarını yürüten, `Sigmoid`, `ReLU` ve `Tanh` destekli çok katmanlı ağ yapısı.
3. **Veri ve Entegrasyon (`DataHandler` & `NeuralNetwork`):** Dosya okuma/yazma (CSV) operasyonlarını ve ağın uçtan uca ileri iletim (forward pass) boru hattını (`pipeline`) yöneten birleştirici sistem.

```
OOP-Brain/
│
├── .gitignore
├── README.md
├── src/
│   ├── main.cpp
│   ├── Matrix.h
│   ├── Matrix.cpp
│   ├── IActivation.h
│   ├── Activations.h
│   ├── BaseLayer.h
│   ├── DenseLayer.h
│   ├── DenseLayer.cpp
│   ├── NeuralNetwork.h
│   ├── NeuralNetwork.cpp
│   └── Exceptions.h
```

---

## Kurulum ve Çalıştırma

Projeyi derlemek ve test sonuçlarını görmek için terminalinizde projenin `src` klasörü dizinine gidin ve derleyicinize uygun komutu çalıştırın:

**Windows (MSVC - Developer Command Prompt):**
```cmd
cl /EHsc *.cpp /Fe:oop_brain.exe
oop_brain.exe

```
<div align="center">
  <img width="736" height="887" alt="ataturk" src="https://github.com/user-attachments/assets/78fbb9f4-3472-43f3-b809-440d3070ed84" />
  <p>"1881-193∞"</p>
</div>

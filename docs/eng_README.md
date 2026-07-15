<div align="center">
  <img width="717" height="348" alt="CBU KOU" src="https://github.com/user-attachments/assets/039e3da1-d1a3-4a53-a005-4539d2ab705d" />
</div>

<div align="center">
  <img src="https://readme-typing-svg.herokuapp.com?font=Fira+Code&weight=500&size=26&pause=1000&color=007ACC&center=true&vCenter=true&width=800&lines=OOP+Neural+Network+Project;MCBÜ+%7C+KOU" alt="Proje Başlığı Animasyonu" />
  
  <p><b>Developed by the students of Kocaeli, Manisa Celal Bayar universities.</b></p>

</div>

<p align="center">
  <img src="https://img.shields.io/badge/C++-14354C?style=for-the-badge&logo=C++&logoColor=white" alt="C++" />
  <img src="https://img.shields.io/badge/Object Oriented Programming-FF9900?style=for-the-badge" alt="Object Oriented Programming" />
  <img src="https://img.shields.io/badge/Artificial Neural Network-007ACC?style=for-the-badge" alt="Artificial Neural Network" />
</p>

# OOP-Brain: Artificial Neural Network Library

**OOP-Brain** is an artificial neural network forward pass engine developed from scratch (without using any external ML libraries) that combines the low-level performance advantages of C++ with high-level Object-Oriented Programming (OOP) principles. 

It was designed with the goals of achieving **zero memory leaks (0 memory leak)**, robust error handling, and maximum extensibility

---

## Key Features

 **No Dependencies:** Built using only Standard C++ libraries.
 **Zero Memory Leak (0 Leak):** Dynamic memory management is perfected using deep copy, move semantics, and virtual destructors.
 **Interface-Based Design:** Thanks to polymorphism, new activation functions or layer types can be easily injected into the system without touching the system's main backbone (Open/Closed Principle).
 **Model Persistence:** Trained network weights and bias values can be saved to disk in '.csv' format and later read from the disk.
 **Custom Error Handling:** Matrix size mismatches (e.g., invalid matrix multiplications) or incorrect file formats are safely caught at runtime without causing a system crash using custom Exception classes.

---

## Architecture and Components

The system consists of 3 main layers:

1. **Mathematics Engine ('Matrix'):** A core unit that contains operator overloads ('*', '+') for matrix multiplication and addition and encapsulates memory control.
2. **Layer and Activation ('DenseLayer' & 'IActivation'):** A multilayer network structure that performs the mathematical operations $Z = W \cdot X + b$ and $A = \sigma(Z)$ and supports 'Sigmoid', 'ReLU', and 'Tanh'.
3. **Data and Integration ('DataHandler' & 'NeuralNetwork'):** The aggregator system that manages file read/write (CSV) operations and the network's end-to-end forward pass pipeline.

```
OOP-Brain/
│
├── .gitignore
├── README.md
├── iris_dataset/
   ├── iris.csv
   └── cleared_iris.csv
├── src/
   ├── main.cpp
   ├── Matrix.h
   ├── Matrix.cpp
   ├── IActivation.h
   ├── Activations.h
   ├── BaseLayer.h
   ├── DenseLayer.h
   ├── DenseLayer.cpp
   ├── NeuralNetwork.h
   ├── NeuralNetwork.cpp
   ├── Exceptions.h
   ├── DataHandler.cpp
   ├── DataHandler.h
   ├── ModelStorage.cpp
   └── ModelStorage.h

```

---

## Kurulum ve Çalıştırma

To compile the project and see the test results, go to the 'src' folder directory of the project in your terminal and run the command appropriate for your compiler:

**Windows (MSVC - Developer Command Prompt):**
```cmd
cd /d %USERPROFILE%\Desktop
git clone https://github.com/Grup7-Proje/OOP-Brain.git
Go to the repository cloned to your desktop and copy the cleared_iris.csv file in the iris_dataset folder into the src file.
Then rename the cleared_iris.csv file to iris.csv.
cd .\OOP-Brain\
cd src
cl /EHsc *.cpp /Fe:oop_brain.exe
del *.obj
oop_brain.exe

```
<div align="center">
  <img width="480" height="320" alt="Flag_of_Turkey svg" src="https://github.com/user-attachments/assets/4c6a0544-41c5-4a51-99e9-fc813302013a" />
</div>

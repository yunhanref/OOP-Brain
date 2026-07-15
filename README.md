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

[Turkish Documentation](https://github.com/Grup7-Proje/OOP-Brain/blob/main/docs/TR_README.md)

---
## My Role & Contributions

In this collaborative multi-university project, I served as the **Math Engine Developer**, **Layer Implementation Specialist**, and **System Integration Lead**. My primary focus was building the mathematical foundation and orchestrating the runtime execution of the neural network.

Here are my specific technical contributions to the `OOP-Brain` framework:

* **Linear Algebra Math Engine (`Matrix.cpp/h`):** 
    * Engineered the core matrix operations from scratch without external libraries.
    * Implemented robust memory management using deep copy and move semantics, ensuring the project passed all tests with **0 memory leaks**.
    * Developed operator overloading (`*`, `+`, `()`) for intuitive and high-performance matrix calculations during the forward pass.
* **Layer Architecture (`DenseLayer.cpp/h`):** 
    * Built the fully connected layer logic incorporating weights, biases, and activation function pointers.
    * Designed the forward pass mathematical execution ($Z = W \cdot X + b$) utilizing method overriding derived from the base class.
* **System Orchestration (`NeuralNetwork.cpp/h`):** 
    * Led the integration of all system components, managing the polymorphic execution pipeline.
    * Ensured seamless data flow across hidden layers and managed the final architectural testing and documentation processes.

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

## Setup
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

<div align="center">

  <img src="https://img.icons8.com/fluency/96/000000/gym.png" alt="Gym Logo" width="80" />

  # 🏋️ Gym Membership Management System
  
  **A robust C++ console application built with advanced Object-Oriented Programming principles.**

  <!-- Badges -->
  <p>
    <img src="https://img.shields.io/badge/Language-C++-00599C?style=for-the-badge&logo=c%2B%2B&logoColor=white" />
    <img src="https://img.shields.io/badge/Paradigm-OOP-ff69b4?style=for-the-badge" />
    <img src="https://img.shields.io/badge/Status-Completed-success?style=for-the-badge" />
    <img src="https://img.shields.io/badge/License-MIT-blue?style=for-the-badge" />
  </p>

  <h4>
    <a href="#-features">View Features</a>
    <span> · </span>
    <a href="#-installation">How to Run</a>
    <span> · </span>
    <a href="#-oop-concepts-applied">OOP Concepts</a>
  </h4>
</div>

<br />

## 📖 Introduction
The **Gym Membership Management System** is a modular C++ application designed to digitize gym operations. It handles various membership tiers (Regular, Premium, Student), calculates fees dynamically using **Operator Overloading**, and ensures data persistence through file handling. 

This project was developed as a case study for **Object-Oriented Programming (OOP)**, demonstrating efficient code reusability and architecture.

---

## 🚀 Features

| Feature | Description |
| :--- | :--- |
| **👥 Member Management** | Add, Remove, and View members of different categories. |
| **💰 Smart Fee Calculation** | Calculates fees based on duration, applying discounts automatically for Students or Long-term Premium members. |
| **💾 Data Persistence** | Automatically saves and loads member records from a text file (`members.txt`). |
| **🔐 Encapsulation** | Secure data handling with private attributes and public interfaces. |
| **➕ Extra Services** | Ability to add optional services (like Personal Trainers) to the fee structure. |

---

## 🧩 OOP Concepts Applied

This project is a practical implementation of the four pillars of OOP:

| Concept | Implementation in Project |
| :--- | :--- |
| **Inheritance** | `Member` (Base) → `RegularMember`, `PremiumMember`, `StudentMember` (Derived). |
| **Polymorphism** | `display()` and `operator*` are **virtual functions**, behaving differently based on the object type. |
| **Encapsulation** | All member data (Name, ID, Fee) is private; accessed only via methods to ensure integrity. |
| **Abstraction** | The complex logic of fee calculation and file parsing is hidden behind simple function calls in `GymManager`. |
| **Operator Overloading** | • `operator*`: Calculates total fee (Monthly Fee × Months).<br>• `operator+`: Adds extra charges (e.g., Locker Fees). |

---

## 📂 Project Structure

```bash
GymManagementSystem/
├── 📂 include/           # Header files (.h)
│   ├── GymManager.h
│   ├── Member.h
│   ├── PremiumMember.h
│   ├── RegularMember.h
│   └── StudentMember.h
├── 📂 src/               # Source files (.cpp)
│   ├── GymManager.cpp
│   ├── Member.cpp
│   ├── main.cpp
│   └── ...
├── 📂 data/              # Database
│   └── members.txt       # Auto-generated file
└── README.md


<div align="center">
  <table>
    <tr>
      <!-- IMAGE 1 -->
      <td width="50%" align="center">
        <h3>🏠 Main Menu</h3>
        <a href="assets/output1.png" target="_blank">
          <img src="screenshot/1.png" width="100%" alt="Main Menu Screen" />
        </a>
      </td>
      
      <!-- IMAGE 2 -->
      <td width="50%" align="center">
        <h3>💰 Fee Calculation</h3>
        <a href="assets/output2.png" target="_blank">
          <img src="ascreenshot/2.png" width="100%" alt="Fee Calculation Screen" />
        </a>
      </td>
    </tr>
  </table>
  <sub>👆 Click on any image to maximize</sub>
</div>

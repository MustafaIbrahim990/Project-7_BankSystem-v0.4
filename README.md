"# Project-7 _ BankSystem-v0.4"

# Project-7: Bank System (v0.4)

Author: Mustafa A. Ibrahim

This repository contains a comprehensive console-based Bank System application developed in C++, leveraging Object-Oriented Programming (OOP) principles. It expands significantly on previous versions by introducing features such as currency exchange, transfer logging, and a modular design.

---

## 🧾 General Overview and Main Functionality

The system provides robust functionalities for:

- Managing client accounts (account numbers, PIN codes, names, phone numbers, and balances)
- Handling financial transactions (deposits, withdrawals, balance inquiries)
- Managing a secure user system with authentication and granular permissions
- Currency exchange and real-time currency conversion
- Logging and auditing all money transfers

> All data (clients, users, currencies, and logs) is stored persistently in separate text files.

---

## 💻 Programming Language Used

- C++

---

## 📚 Frameworks & Libraries Used

### Standard Libraries:
- <iostream> – Input/output operations
- <fstream> – File handling and persistence
- <iomanip> – Output formatting
- <vector> – Dynamic arrays
- <string> – String manipulation

### Custom Classes:
- clsBankClient, clsUser, clsCurrency
- clsScreen, clsLoginScreen, clsTransactionsScreen
- clsManageUsersScreen, clsCurrencyScreen, clsTransferLogScreen
- clsUtil, clsString, clsInputValidate, clsDate
- clsPerson, clsEmployee, clsPeriod

---

## 🌟 Key Features

- OOP Design: Modular, extensible, and maintainable using encapsulation and inheritance
- User Authentication & Authorization: Secure login and role-based access control
- User Management: Full CRUD operations with permission assignment
- Client Management: Create, read, update, delete client data and financial details
- Transaction Management: Deposit, withdraw, and total balance calculation
- Currency Exchange: Real-time conversions and rate management
- Transfer Log: Audit trail for all money transfers
- Data Persistence: Stores data in .txt files
- CLI Interface: Clean command-line interface with nested menus
- Input Validation: Prevents invalid inputs and ensures system stability

---

## 🛠️ Installation and Running

### Using g++ (Linux/macOS/MinGW):

`bash
git clone https://github.com/MustafaIbrahim990/Project-7_BankSystem-v0.4.git
cd Project-7_BankSystem-v0.4/Project\ 7\ Bank\ System\ With\ OOP
g++ *.cpp -o BankSystem.exe
./BankSystem.exe

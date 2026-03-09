
# 🏦 Bank Management System (Console Based)

A **Console-Based Bank Management System** implemented in **C programming language**.
This mini project simulates basic banking operations such as account creation, login authentication, deposit, withdrawal, balance checking, account updates, and money transfer.

The system stores account details using **file handling**, making it a simple demonstration of how data persistence works in C.

---

## 📌 Features

* 🧾 Create a new bank account
* 🔐 Secure login using username and password
* 💰 Deposit money
* 💸 Withdraw money
* 📊 Check account balance
* ✏️ Update account information
* 🔄 Transfer money between accounts
* 📂 File-based data storage

---

## 🛠️ Technologies Used

* **Programming Language:** C
* **Concepts Used:**

  * Structures
  * File Handling
  * Functions
  * String Manipulation
  * Pointer Usage
  * Conditional Statements

---

## 📁 File Structure

```
Bank-Management-System/
│
├── main.c
├── accounts.txt
└── README.md
```

**main.c** → Contains the complete source code.
**accounts.txt** → Stores user account data (username, password, balance)

---

## ⚙️ How It Works

1. The program displays a menu with multiple banking options.
2. Users can create an account with a username and password.
3. Account data is stored in a file (`accounts.txt`).
4. After logging in, users can perform operations like:

   * Deposit money
   * Withdraw money
   * Check balance
   * Update account details
   * Transfer money to another account
5. All changes are saved back to the file.

---

## ▶️ How to Run the Program

### Step 1: Compile the program

```bash
gcc main.c -o bank
```

### Step 2: Run the program

```bash
./bank
```

---

## 📋 Sample Menu

```
--BANK MANAGEMENT SYSTEM--

1. Create Account
2. Login
3. Deposit
4. Withdraw
5. Check Balance
6. Update Account Info
7. Transfer Money
8. Exit
```

---

## 📚 Learning Objectives

This project helps in understanding:

* File handling in C
* Struct-based data storage
* Menu-driven programs
* Basic banking logic
* Working with pointers and functions

---

## ⚠️ Limitations

* Passwords are stored in **plain text** (not encrypted)
* No database (file-based storage only)
* Works for small-scale simulation only
* No multi-user concurrency handling

---

## 🚀 Future Improvements

* Add password encryption
* Convert to **GUI or Web Application**
* Add **database support (MySQL / SQLite)**
* Implement **transaction history**
* Improve error handling



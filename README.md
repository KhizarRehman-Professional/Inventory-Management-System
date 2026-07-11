# 📦 Inventory Management System

A simple console-based inventory management system written in C++. This program allows users to manage products with features like adding, removing, updating, searching, and tracking inventory value — all with persistent file storage.

---

## ✨ Features

| Feature | Description |
|---------|-------------|
| ➕ **Add Product** | Add new products with unique ID, name, quantity, price, and category |
| ➖ **Remove Product** | Delete products by ID with confirmation |
| ✏️ **Update Product** | Modify quantity, price, and category of existing products |
| 📋 **View Inventory** | Display all products in a clean, formatted table |
| 🔍 **Search Product** | Find products by name |
| ⚠️ **Low Stock Alert** | Identify products below a custom threshold |
| 💰 **Total Inventory Value** | Calculate total value of all stock |
| 💾 **Auto Save & Load** | Data persists in `inventory.txt` between sessions |

---

## 🚀 Getting Started

### Prerequisites
- A C++ compiler (GCC, Clang, or MSVC)

### Compilation
```bash
g++ Inventory-Management-System.cpp -o inventory
```

### Run
```bash
./inventory
```

---

## 🗂️ File Structure

```
.
├── Inventory-Management-System.cpp    # Main source code
├── inventory.txt
├── README.md                # This file
├── .gitignore          # Git ignore rules
└── .gitattributes           # Data file (auto-generated)
```

---

## 🛠️ Built With

- C++
- Standard Library (`<iostream>`, `<fstream>`)

---

## 📝 Data Format

Products are stored in `inventory.txt` as comma-separated values:

```
ID,Name,Quantity,Price,Category
```

Example:
```
1,Laptop,10,85000.00,Electronics
2,Mouse,50,1200.00,Accessories
```

---

## 📄 License

This project is for educational purposes.

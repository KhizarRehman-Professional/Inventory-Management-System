#include <iostream>
#include <fstream>
using namespace std;

const int totalProducts = 100;

// Product structure
struct Product {
    int id;
    string name;
    int quantity;
    float price;
    string category;
};

// Function prototypes
void addProduct(Product inventory[], int &count);
void removeProduct(Product inventory[], int &count);
void updateProduct(Product inventory[], int count);
void viewInventory(const Product inventory[], int count);
void searchProduct(const Product inventory[], int count);
void lowStockAlert(const Product inventory[], int count, int threshold);
void totalInventoryValue(const Product inventory[], int count);
void saveToFile(const Product inventory[], int count);
void loadFromFile(Product inventory[], int &count);

// Main Function
int main() {
    Product inventory[totalProducts];
    int count = 0;
    int choice;

    // Load inventory from file
    loadFromFile(inventory, count);

    do {
        cout << "-----------------------------------------------------------\n";
        cout << "\t\tInventory Management System" << endl;
        cout << "-----------------------------------------------------------" << endl;
        cout << "1. Add Product" << endl;
        cout << "2. Remove Product" << endl;
        cout << "3. Update Product" << endl;
        cout << "4. View Inventory" << endl;
        cout << "5. Search Product" << endl;
        cout << "6. Low Stock Alert" << endl;
        cout << "7. Total Inventory Value" << endl;
        cout << "8. Exit" << endl;
        cout << "Enter Your Choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
            addProduct(inventory, count);
            break;

            case 2:
            removeProduct(inventory, count);
            break;
            
            case 3:
            updateProduct(inventory, count);
            break;
            
            case 4:
            viewInventory(inventory, count);
            break;
            
            case 5:
            searchProduct(inventory, count);
            break;
            
            case 6: {
                int threshold;
                cout << "Enter Stock Threshold: ";
                cin >> threshold;
                lowStockAlert(inventory, count, threshold);
                break;
            }
            
            case 7:
            totalInventoryValue(inventory, count);
            break;
            
            case 8: 
            saveToFile(inventory, count);
            cout << "Exiting the program." << endl;
            cout << "Exited Program Successfully." << endl;
            cout << "-------------------------------------" << endl;
            break;
            
            default:
            cout << "Invalid choice! Please Try Again." << endl;
        }
    } while (choice != 8);

    return 0;
}

// Function to add a new product
void addProduct(Product inventory[], int &count) {
    if (count >= totalProducts) {
        cout << "Inventory is full. Cannot add more products." << endl;
        return;
    }
    
    Product newProduct;
    cout << "Enter Product ID: ";
    cin >> newProduct.id;
    cout << "Enter Product Name: ";
    cin.ignore();
    getline(cin, newProduct.name);
    cout << "Enter Quantity: ";
    cin >> newProduct.quantity;
    cout << "Enter Price: Rs ";
    cin >> newProduct.price;
    cout << "Enter Category: ";
    cin.ignore();
    getline(cin, newProduct.category);

    // Check for unique Product ID
    for (int i = 0; i < count; i++) {
        if (inventory[i].id == newProduct.id) {
            cout << "-------------------------------------" << endl;
            cout << "Product ID must be unique. Product not added." << endl;
            cout << "-------------------------------------" << endl;
            return;
        }
    }

    inventory[count] = newProduct;
    count++;
    cout << "-------------------------------------" << endl;
    cout << "\tProduct Added Successfully!" << endl;
    cout << "-------------------------------------" << endl;
    cout << "Product ID: " << newProduct.id << endl;
    cout << "Product Name: " << newProduct.name << endl;
    cout << "Product Quantity: " << newProduct.quantity << endl;
    cout << "Product Price: Rs " << newProduct.price << endl;
    cout << "Product Category: " << newProduct.category << endl;
}

// Function to remove a product
void removeProduct(Product inventory[], int &count) {
    int id;
    
    cout << "Enter Product ID to remove: ";
    cin >> id;

    for (int i = 0; i < count; i++) {
        if (inventory[i].id == id) {
            cout << "-------------------------------------" << endl;
            cout << "\tRemoving Product!" << endl;
            cout << "-------------------------------------" << endl;
            cout << "Product ID:" << inventory[i].id << endl;
            cout << "Product Name: " << inventory[i].name << endl;
            for (int j = i; j < count - 1; j++) {
                inventory[j] = inventory[j + 1];
            }
            count--;
            cout << "-------------------------------------" << endl;
            cout << "Product Removed Successfully!" << endl;
            return;
        }
    }
    cout << "Product ID not found!" << endl;
}

// Function to update an existing product
void updateProduct(Product inventory[], int count) {
    int id;
    
    cout << "-------------------------------------" << endl;
    cout << "Enter Product ID to update: ";
    cin >> id;

    for (int i = 0; i < count; i++) {
        if (inventory[i].id == id) {
            cout << "-------------------------------------" << endl;
            cout << "Updating Product: " << inventory[i].name << "\n";
            cout << "Enter New Quantity: ";
            cin >> inventory[i].quantity;
            cout << "Enter New Price: Rs ";
            cin >> inventory[i].price;
            cout << "Enter New Category: ";
            cin.ignore();
            getline(cin, inventory[i].category);
            cout << "-------------------------------------" << endl;
            cout << "Product Updated Successfully!" << endl;
            cout << "-------------------------------------" << endl;
            cout << "Product ID: " << inventory[i].id << endl;
            cout << "Product Name: " << inventory[i].name << endl;
            cout << "Product Quantity: " << inventory[i].quantity << endl;
            cout << "Product Price: Rs " << inventory[i].price << endl;
            cout << "Product Category: " << inventory[i].category << endl;
            cout << "-------------------------------------" << endl;

            return;
        }
    }
    cout << "-------------------------------------" << endl;
    cout << "Product ID not found." << endl;
}

// Function to view inventory
void viewInventory(const Product inventory[], int count) {
    if (count == 0) {
        cout << "Inventory is Empty!" << endl;
        return;
    }
    cout << "Inventory List:" << endl;
    cout << "----------------------------------------------------------------------------------------------------------------" << endl;
    cout << "Product ID\tProduct Name\t\tProduct Category\tProduct Quantity\tProduct Price\n";
    cout << "----------------------------------------------------------------------------------------------------------------" << endl;
    for (int i = 0; i < count; i++) {
        cout << inventory[i].id << "\t\t";
        cout << inventory[i].name << "\t\t\t";
        cout << inventory[i].category << "\t\t\t";
        cout << inventory[i].quantity << "\t\t\t";
        cout << inventory[i].price << endl;
    }
    cout << "----------------------------------------------------------------------------------------------------------------" << endl;
}

// Function to search for a product
void searchProduct(const Product inventory[], int count) {
    string name;
    
    cout << "Enter Product Name to search: ";
    cin.ignore();
    getline(cin, name);

    for (int i = 0; i < count; i++) {
         if (inventory[i].name == name) {
            cout << "-------------------------------------" << endl;
            cout << "\tProduct Found!" << endl;
            cout << "-------------------------------------" << endl;
            cout << "Product ID: " << inventory[i].id << endl;
            cout << "Product Name: " << inventory[i].name << endl;
            cout << "Product Category: " << inventory[i].category << endl;
            cout << "Product Quantity: " << inventory[i].quantity << endl;
            cout << "Product Price: Rs " << inventory[i].price << endl;
            return;
        }
    }
    cout << "Product not found!" << endl;
}

// Function to display low stock alert
void lowStockAlert(const Product inventory[], int count, int threshold) {
    int found = 0;
    cout << "-------------------------------------" << endl;
    cout << "Products with stock below " << threshold << " are:" << endl;
    cout << "-------------------------------------" << endl;
    for (int i = 0; i < count; i++) {
        if (inventory[i].quantity < threshold) {
            cout << "Product ID: " << inventory[i].id << endl;
            cout << "Product Name: " << inventory[i].name << endl; 
            cout << "Product Quantity: " << inventory[i].quantity << endl;
            found = 1;
        }
    }
    if (found == 0) {
        cout << "No Products with Low Stock Found!" << endl;
    }
}

// Function to calculate and display total inventory value
void totalInventoryValue(const Product inventory[], int count) {
    float sum = 0.0;
    
    for (int i = 0; i < count; i++) {
        sum = sum + (inventory[i].quantity * inventory[i].price);
    }
    cout << "-------------------------------------" << endl;
    cout << "Total Inventory Value: Rs " << sum << endl;
}

// Function to load inventory data from a file
void loadFromFile(Product inventory[], int &count) {
    ifstream inFile("inventory.txt");
    if (!inFile) {
        cout << "No Existing Inventory File Found!" << endl;
        return;
    }

    count = 0;

    while (inFile.good() && count < totalProducts) {
        inFile >> inventory[count].id;
        inFile.ignore();
        getline(inFile, inventory[count].name, ',');
        inFile >> inventory[count].quantity;
        inFile.ignore();
        inFile >> inventory[count].price;
        inFile.ignore();
        getline(inFile, inventory[count].category);
        count++;
    }

    inFile.close();
    cout << "-------------------------------------" << endl;
    cout << "Inventory Loaded from File Successfully!" << endl;
}

// Function to save inventory data to a file
void saveToFile(const Product inventory[], int count) {
    ofstream outFile("inventory.txt");
    if (!outFile) {
        cout << "Error Saving to File!" << endl;
        return;
    }

    for (int i = 0; i < count; i++) {
        outFile << inventory[i].id << "," 
                << inventory[i].name << "," 
                << inventory[i].quantity << "," 
                << inventory[i].price << "," 
                << inventory[i].category << endl;
    }

    outFile.close();
    cout << "-------------------------------------" << endl;
    cout << "Inventory Saved to File Successfully." << endl;
    cout << "-------------------------------------" << endl;
}
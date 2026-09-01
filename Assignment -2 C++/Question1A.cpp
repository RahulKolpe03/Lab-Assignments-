// ============================================================
// Question 1 - Part A: Product class with Array of Objects
// ============================================================
#include <iostream>
#include <iomanip>
#include <string>
using namespace std;

class Product {
private:
    int productId;
    string name;
    double price;
    int quantity;

public:
    void acceptDetails() {
        cout << "Enter Product ID: ";
        cin >> productId;
        cin.ignore();
        cout << "Enter Product Name: ";
        getline(cin, name);
        cout << "Enter Price: ";
        cin >> price;
        cout << "Enter Quantity: ";
        cin >> quantity;
    }

    void displayDetails() const {
        cout << left << setw(6) << productId
             << setw(15) << name
             << right << setw(10) << fixed << setprecision(2) << price
             << setw(8) << quantity
             << setw(15) << totalValue();
        if (isLowStock(10))
            cout << "  <- LOW STOCK";
        cout << endl;
    }

    double totalValue() const {
        return price * quantity;
    }

    bool isLowStock(int threshold) const {
        return quantity < threshold;
    }

    int getId() const { return productId; }
    string getName() const { return name; }
};

int main() {
    const int N = 5;
    Product products[N];   // array of 5 Product objects on the stack

    cout << "===== ENTER DETAILS FOR " << N << " PRODUCTS =====\n";
    for (int i = 0; i < N; i++) {
        cout << "\n-- Product " << (i + 1) << " --\n";
        products[i].acceptDetails();
    }

    cout << "\n===== INVENTORY REPORT =====\n";
    cout << left << setw(6) << "ID" << setw(15) << "Name"
         << right << setw(10) << "Price" << setw(8) << "Qty"
         << setw(15) << "Total Value" << endl;

    for (int i = 0; i < N; i++)
        products[i].displayDetails();

    // Highest value product
    int highestIdx = 0;
    for (int i = 1; i < N; i++)
        if (products[i].totalValue() > products[highestIdx].totalValue())
            highestIdx = i;

    cout << "\nHighest Value Product : " << products[highestIdx].getName()
         << " (Rs. " << fixed << setprecision(2) << products[highestIdx].totalValue() << ")\n";

    // Low stock report
    int threshold;
    cout << "\nEnter low-stock threshold: ";
    cin >> threshold;

    cout << "Low Stock (threshold: " << threshold << ") : ";
    bool any = false;
    for (int i = 0; i < N; i++) {
        if (products[i].isLowStock(threshold)) {
            if (any) cout << ", ";
            cout << products[i].getName();
            any = true;
        }
    }
    if (!any) cout << "None";
    cout << endl;

    return 0;
}
// ============================================================
// Question 1 - Part B: Function Overloading + Default Argument
// ============================================================
#include <iostream>
using namespace std;

// Overloaded reorderCost functions
double reorderCost(int qty, double unitPrice) {
    cout << "[reorderCost - int qty] ";
    return qty * unitPrice;
}

double reorderCost(double qty, double unitPrice) {
    cout << "[reorderCost - double qty] ";
    return qty * unitPrice;
}

double reorderCost(int qty, double unitPrice, double taxRate) {
    cout << "[reorderCost - with tax] ";
    double base = qty * unitPrice;
    return base + (base * taxRate / 100.0);
}

// Function with a default argument
double applyDiscount(double price, double discountPercent = 10.0) {
    // If no discount is passed, apply 10% by default
    return price - (price * discountPercent / 100.0);
}

int main() {
    cout << "===== FUNCTION OVERLOADING DEMO =====\n";
    cout << "Result: " << reorderCost(50, 12.5) << endl;            // integer quantity
    cout << "Result: " << reorderCost(12.75, 8.0) << endl;          // fractional (by weight)
    cout << "Result: " << reorderCost(100, 20.0, 18.0) << endl;     // with tax

    cout << "\n===== DEFAULT ARGUMENT DEMO =====\n";
    cout << "Price after default 10% discount : " << applyDiscount(1000.0) << endl;
    cout << "Price after explicit 25% discount : " << applyDiscount(1000.0, 25.0) << endl;

    return 0;
}
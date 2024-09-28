#include <iostream>
#include <iomanip>  // For setting decimal precision
using namespace std;

int main() {
    int numItems;
    double price, total = 0, taxRate = 0.07;  // 7% sales tax

    // Ask for the number of items
    cout << "Enter the number of items: ";
    cin >> numItems;

    // Loop to input the price of each item
    for (int i = 1; i <= numItems; i++) {
        cout << "Enter the price of item " << i << ": ";
        cin >> price;
        total += price;  // Add the price to the total
    }

    // Calculate tax and total due
    double tax = total * taxRate;
    double totalDue = total + tax;

    // Display the results
    cout << fixed << setprecision(2);  // Set precision to 2 decimal places
    cout << "Subtotal: $" << total << endl;
    cout << "Tax (7%): $" << tax << endl;
    cout << "Total due: $" << totalDue << endl;

    return 0;
}
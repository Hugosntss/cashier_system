#include <iostream>
#include <iomanip>
using namespace std;

// Function prototypes
double selectRice();
double selectNoodle();
void displayMenu();

// Main function
int main() {
    int numSalad, numGrilledVeg, bowlChoice;
    double total = 0, taxRate = 0.07;  // 7% sales tax

    // Display the menu to the user
    displayMenu();

    // Ask the user to choose between Rice Bowl or Noodle Bowl
    cout << "Would you like to pick a Rice Bowl or Noodle Bowl?\n";
    cout << "1. Rice Bowl\n";
    cout << "2. Noodle Bowl\n";
    cout << "Enter your choice (1 or 2): ";
    cin >> bowlChoice;

    // Depending on the user's choice, offer rice or noodle options
    if (bowlChoice == 1) {
        total += selectRice();
    } else if (bowlChoice == 2) {
        total += selectNoodle();
    } else {
        cout << "Invalid choice, no bowl selected.\n";
    }


   /*  cout << "salad bolw to be added? ($2.75 each): ";
    cin >> numSalad;
    total += numSalad * 2.75;
 */

    cout << "Would you like to add Grilled Vegetanles for $3.50?";
    cin >> numGrilledVeg;
    total += numGrilledVeg * 3.50;

    // Calculate tax and total due
    double tax = total * taxRate;
    double totalDue = total + tax;

    cout << fixed << setprecision(2);  // set decimals with small numbers
    cout << "Subtotal: $" << total << endl;
    cout << "Tax (7%): $" << tax << endl;
    cout << "Total due: $" << totalDue << endl;

    return 0;
}

double selectRice() {
    int choice;
    double price = 0;

    cout << "Select a Rice Bowl:\n";
    cout << "1. Fried Rice ($3.25)\n";
    cout << "2. White Rice ($2.20)\n";
    cout << "Enter your choice (1 or 2): ";
    cin >> choice;

    if (choice == 1) {
        price = 3.25;
    } else if (choice == 2) {
        price = 2.20;
    } else {
        cout << "Invalid choice, no rice added.\n";
    }

    return price;
}

double selectNoodle() {
    int choice;
    double price = 0;

    cout << "Select a Noodle Bowl:\n";
    cout << "1. Udon ($4.35)\n";
    cout << "2. Egg Noodles ($3.25)\n";
    cout << "3. Rice Noodles ($3.00)\n";
    cout << "Enter your choice (1, 2 or 3): ";
    cin >> choice;

    if (choice == 1) {
        price = 4.35;
    } else if (choice == 2) {
        price = 3.25;
    } else if (choice == 3) {
        price = 3.00;
    } else {
        cout << "Invalid choice, no noodles added.\n";
    }

    return price;
}

// Function to display the menu
void displayMenu() {
    cout << "Welcome to the Food Bowl Menu\n";
    cout << "-----------------------------\n";
    cout << "1. Rice Bowls:\n";
    cout << "   - Fried Rice ($3.25)\n";
    cout << "   - White Rice ($2.20)\n";
    cout << "2. Noodle Bowls:\n";
    cout << "   - Udon ($4.35)\n";
    cout << "   - Egg Noodles ($3.25)\n";
    cout << "   - Rice Noodles ($3.00)\n";
    cout << "3. Salad Bowl: $2.75\n";
    cout << "4. Grilled Vegetables: $3.50\n";
    cout << "-----------------------------\n";
}

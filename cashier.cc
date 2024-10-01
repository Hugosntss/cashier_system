#include <iostream>
#include <iomanip>
using namespace std;

// Function prototypes
double selectRice();
double selectNoodle();
double selectSalad();
double selectProtein();
void displayMenu();

// Main function
int main() {
    int bowlChoice, numGrilledVeg;
    double total = 0, taxRate = 0.07;  // 7% sales tax

    // Display the menu to the user
    displayMenu();

    // Ask the user to choose between Rice Bowl, Noodle Bowl, or Salad Bowl
    cout << "Would you like to pick a Rice Bowl, Noodle Bowl, or Salad Bowl?\n";
    cout << "1. Rice Bowl\n";
    cout << "2. Noodle Bowl\n";
    cout << "3. Salad Bowl ($2.75)\n";
    cout << "Enter your choice (1, 2, or 3): ";
    cin >> bowlChoice;

    // Depending on the user's choice, offer rice, noodle, or salad options
    if (bowlChoice == 1) {
        total += selectRice();
    } else if (bowlChoice == 2) {
        total += selectNoodle();
    } else if (bowlChoice == 3) {
        total += selectSalad();
    } else {
        cout << "Invalid choice, no bowl selected.\n";
        return 0; // Exit if invalid choice
    }

    // Added protein options
    total += selectProtein();

    // Ask the user if they want to add Grilled Vegetables
    cout << "Would you like to add Grilled Vegetables for $3.50? (Enter 1 for Yes or 0 for No): ";
    cin >> numGrilledVeg;
    total += numGrilledVeg * 3.50;

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

// Function to select and return the cost of rice
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

// Function to select and return the cost of noodles
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

// Function to select and return the cost of a salad
double selectSalad() {
    return 2.75;
}

// Function to select and return the cost of a protein
double selectProtein() {
    int choice;
    double price = 0;

    cout << "Select a Protein:\n";
    cout << "1. Chicken ($3.00)\n";
    cout << "2. Steak ($5.50)\n";
    cout << "3. Tofu ($4.25)\n";
    cout << "4. Sweet Ribs ($7.00)\n";
    cout << "Enter your choice (1, 2, 3 or 4): ";
    cin >> choice;

    if (choice == 1) {
        price = 3.00;
    } else if (choice == 2) {
        price = 5.50;
    } else if (choice == 3) {
        price = 4.25;
    } else if (choice == 4) {
        price = 7.00;
    } else {
        cout << "Invalid choice, no protein added.\n";
    }

    return price;
}

// Function to display the menu
void displayMenu() {
    cout << "Welcome to the Tsushima's Cuisine Menu\n";
    cout << "-----------------------------\n";
    cout << "1. Rice Bowls:\n";
    cout << "   - Fried Rice ($3.25)\n";
    cout << "   - White Rice ($2.20)\n";
    cout << "2. Noodle Bowls:\n";
    cout << "   - Udon ($4.35)\n";
    cout << "   - Egg Noodles ($3.25)\n";
    cout << "   - Rice Noodles ($3.00)\n";
    cout << "3. Salad Bowl: $2.75\n";
    cout << "4. Protein options:\n";
    cout << "   - Chicken ($3.00)\n";
    cout << "   - Steak ($5.50)\n";
    cout << "   - Tofu ($4.25)\n";
    cout << "   - Sweet Ribs ($7.00)\n";
    cout << "5. Grilled Vegetables: $3.50\n";
    cout << "-----------------------------\n";
}

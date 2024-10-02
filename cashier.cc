#include <iostream>
#include <iomanip>
#include <string>
#include <fstream>
#include <ctime>
using namespace std;

// Constants
const int MAX_ITEMS = 10;  // Maximum number of items in the cart

// Function prototypes
double selectRice(string cart[], double prices[], int &itemCount);
double selectNoodle(string cart[], double prices[], int &itemCount);
double selectSalad(string cart[], double prices[], int &itemCount);
double selectProtein(string cart[], double prices[], int &itemCount);
void displayMenu();
double applyStudentDiscount(double total);
void removeItem(string cart[], double prices[], int &itemCount, double &total);
void saveOrder(string cart[], double prices[], int itemCount, double total);

int main() {
    int bowlChoice, numGrilledVeg;
    string cart[MAX_ITEMS];   // Array to store item names
    double prices[MAX_ITEMS]; // Array to store item prices
    int itemCount = 0;        // Track number of items in the cart
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
        total += selectRice(cart, prices, itemCount);
    } else if (bowlChoice == 2) {
        total += selectNoodle(cart, prices, itemCount);
    } else if (bowlChoice == 3) {
        total += selectSalad(cart, prices, itemCount);
    } else {
        cout << "Invalid choice, no bowl selected.\n";
        return 0;
    }

    // Add protein options
    total += selectProtein(cart, prices, itemCount);

    // Ask the user if they want to add Grilled Vegetables
    cout << "Would you like to add Grilled Vegetables for $3.50? (Enter 1 for Yes or 0 for No): ";
    cin >> numGrilledVeg;
    if (numGrilledVeg == 1 && itemCount < MAX_ITEMS) {
        cart[itemCount] = "Grilled Vegetables";
        prices[itemCount] = 3.50;
        total += 3.50;
        itemCount++;
    }

    // Ask if the user wants to remove any items from the cart
    cout << "Would you like to remove any items from your cart? (Enter 1 for Yes or 0 for No): ";
    int removeChoice;
    cin >> removeChoice;
    if (removeChoice == 1) {
        removeItem(cart, prices, itemCount, total);  // Pass total by reference
    }

    // Apply student discount if eligible
    total = applyStudentDiscount(total);

    // Calculate tax and total due
    double tax = total * taxRate;
    double totalDue = total + tax;

    // Display the cart and total
    cout << "\nItems in your cart:\n";
    for (int i = 0; i < itemCount; i++) {
        cout << "- " << cart[i] << ": $" << fixed << setprecision(2) << prices[i] << endl;
    }

    cout << "Subtotal: $" << total << endl;
    cout << "Tax (7%): $" << tax << endl;
    cout << "Total due: $" << totalDue << endl;

    // Save the order
    saveOrder(cart, prices, itemCount, totalDue);

    return 0;
}

// Function to select and return the cost of rice
double selectRice(string cart[], double prices[], int &itemCount) {
    int choice;
    double price = 0;

    cout << "Select a Rice Bowl:\n";
    cout << "1. Fried Rice ($3.25)\n";
    cout << "2. White Rice ($2.20)\n";
    cout << "Enter your choice (1 or 2): ";
    cin >> choice;

    if (choice == 1 && itemCount < MAX_ITEMS) {
        price = 3.25;
        cart[itemCount] = "Fried Rice";
        prices[itemCount] = price;
        itemCount++;
    } else if (choice == 2 && itemCount < MAX_ITEMS) {
        price = 2.20;
        cart[itemCount] = "White Rice";
        prices[itemCount] = price;
        itemCount++;
    } else {
        cout << "Invalid choice, no rice added.\n";
    }

    return price;
}

// Function to select and return the cost of noodles
double selectNoodle(string cart[], double prices[], int &itemCount) {
    int choice;
    double price = 0;

    cout << "Select a Noodle Bowl:\n";
    cout << "1. Udon ($4.35)\n";
    cout << "2. Egg Noodles ($3.25)\n";
    cout << "3. Rice Noodles ($3.00)\n";
    cout << "Enter your choice (1, 2, or 3): ";
    cin >> choice;

    if (choice == 1 && itemCount < MAX_ITEMS) {
        price = 4.35;
        cart[itemCount] = "Udon";
        prices[itemCount] = price;
        itemCount++;
    } else if (choice == 2 && itemCount < MAX_ITEMS) {
        price = 3.25;
        cart[itemCount] = "Egg Noodles";
        prices[itemCount] = price;
        itemCount++;
    } else if (choice == 3 && itemCount < MAX_ITEMS) {
        price = 3.00;
        cart[itemCount] = "Rice Noodles";
        prices[itemCount] = price;
        itemCount++;
    } else {
        cout << "Invalid choice, no noodles added.\n";
    }

    return price;
}

// Function to select and return the cost of a salad
double selectSalad(string cart[], double prices[], int &itemCount) {
    if (itemCount < MAX_ITEMS) {
        cart[itemCount] = "Salad Bowl";
        prices[itemCount] = 2.75;
        itemCount++;
        return 2.75;
    }
    return 0;
}

// Function to select and return the cost of a protein
double selectProtein(string cart[], double prices[], int &itemCount) {
    int choice;
    double price = 0;

    cout << "Select a Protein:\n";
    cout << "1. Chicken ($3.00)\n";
    cout << "2. Steak ($5.50)\n";
    cout << "3. Tofu ($4.25)\n";
    cout << "4. Sweet Ribs ($7.00)\n";
    cout << "Enter your choice (1, 2, 3 or 4): ";
    cin >> choice;

    if (choice == 1 && itemCount < MAX_ITEMS) {
        price = 3.00;
        cart[itemCount] = "Chicken";
        prices[itemCount] = price;
        itemCount++;
    } else if (choice == 2 && itemCount < MAX_ITEMS) {
        price = 5.50;
        cart[itemCount] = "Steak";
        prices[itemCount] = price;
        itemCount++;
    } else if (choice == 3 && itemCount < MAX_ITEMS) {
        price = 4.25;
        cart[itemCount] = "Tofu";
        prices[itemCount] = price;
        itemCount++;
    } else if (choice == 4 && itemCount < MAX_ITEMS) {
        price = 7.00;
        cart[itemCount] = "Sweet Ribs";
        prices[itemCount] = price;
        itemCount++;
    } else {
        cout << "Invalid choice, no protein added.\n";
    }

    return price;
}

// Function to remove items from the cart
void removeItem(string cart[], double prices[], int &itemCount, double &total) {
    if (itemCount == 0) {
        cout << "Your cart is empty. No items to remove.\n";
        return;
    }

    // Display current items in the cart
    cout << "\nCurrent items in your cart:\n";
    for (int i = 0; i < itemCount; i++) {
        cout << i + 1 << ". " << cart[i] << ": $" << fixed << setprecision(2) << prices[i] << endl;
    }

    // Ask which item to remove
    int removeIndex;
    cout << "Enter the number of the item you want to remove (1 to " << itemCount << "): ";
    cin >> removeIndex;

    // Remove the selected item
    if (removeIndex > 0 && removeIndex <= itemCount) {
        // Subtract the price of the removed item from total
        total -= prices[removeIndex - 1];

        // Shift items to fill the gap
        for (int i = removeIndex - 1; i < itemCount - 1; i++) {
            cart[i] = cart[i + 1];
            prices[i] = prices[i + 1];
        }
        itemCount--;  // Decrease the item count
        cout << "Item removed successfully!\n";
    } else {
        cout << "Invalid selection.\n";
    }
}

// Function to save the order to a file
void saveOrder(string cart[], double prices[], int itemCount, double total) {
    ofstream outFile("completed_orders.txt", ios::app);
    if (!outFile) {
        cout << "Error opening file for writing.\n";
        return;
    }

    // Get the current date and time
    time_t now = time(0);
    char* dt = ctime(&now);

    // Write date and time
    outFile << "Order completed on: " << dt;

    // Write cart details
    for (int i = 0; i < itemCount; i++) {
        outFile << cart[i] << ": $" << fixed << setprecision(2) << prices[i] << endl;
    }

    // Write total amount
    outFile << "Total: $" << fixed << setprecision(2) << total << endl;
    outFile << "------------------------------\n";

    cout << "Order saved successfully!\n";
    outFile.close();
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

// Function to apply a student discount if eligible
double applyStudentDiscount(double total) {
    int isStudent;
    string studentNumber;

    cout << "Are you a student? (Enter 1 for Yes or 0 for No): ";
    cin >> isStudent;

    // If the user is a student, ask for a 9-digit student number
    if (isStudent == 1) {
        cout << "Please enter your 9-digit student number: ";
        cin >> studentNumber;

        // Check if the student number is 9 digits
        if (studentNumber.length() == 9) {
            cout << "Student discount applied! You receive 15% off your total.\n";
            total *= 0.85;  // Apply 15% discount
        } else {
            cout << "Invalid student number. No discount applied.\n";
        }
    }

    return total;
}

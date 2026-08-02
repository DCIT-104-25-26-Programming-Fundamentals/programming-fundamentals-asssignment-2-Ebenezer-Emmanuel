// =============================================================================
// PROGRAMMING FUNDAMENTALS — Assignment 9
// =============================================================================
//
// TASK: Console-Based Simple Calculator
//
// Build a calculator program that runs in the console and performs basic
// arithmetic operations based on the user's input.
//
// -----------------------------------------------------------------------------
// OPERATIONS YOUR CALCULATOR MUST SUPPORT
// -----------------------------------------------------------------------------
//
//   1. Addition          ( + )    e.g.  10 + 3  =  13
//   2. Subtraction       ( - )    e.g.  10 - 3  =  7
//   3. Multiplication    ( * )    e.g.  10 * 3  =  30
//   4. Division          ( / )    e.g.  10 / 3  =  3.33
//   5. Modulus           ( % )    e.g.  10 % 3  =  1  (remainder)
//   6. Exponentiation    ( ^ )    e.g.  2 ^ 8   =  256
//   7. Quit
//
// -----------------------------------------------------------------------------
// HOW THE MENU SHOULD LOOK
// -----------------------------------------------------------------------------
//
//   ============================
//        SIMPLE CALCULATOR
//   ============================
//   1. Addition
//   2. Subtraction
//   3. Multiplication
//   4. Division
//   5. Modulus
//   6. Exponentiation
//   7. Quit
//   Select an operation (1-7):
//
// -----------------------------------------------------------------------------
// EXPECTED INTERACTION EXAMPLE
// -----------------------------------------------------------------------------
//
//   Select an operation (1-7): 4
//   Enter first number : 10
//   Enter second number: 3
//   Result: 10 / 3 = 3.33
//
//   Select an operation (1-7): 4
//   Enter first number : 5
//   Enter second number: 0
//   Error: Cannot divide by zero.
//
//   Select an operation (1-7): 7
//   Goodbye!
//
// -----------------------------------------------------------------------------
// REQUIREMENTS
// -----------------------------------------------------------------------------
// - Each arithmetic operation MUST be written as its own function.
// - Use a loop so the calculator keeps running until the user selects Quit.
// - Division by zero must be caught and handled with a clear error message
//   (do NOT let the program crash).
// - Use fixed and setprecision(2) to display results to 2 decimal places.
// - Handle invalid menu choices gracefully.
// - For exponentiation use a loop or the pow() function from <cmath>.
//

// =============================================================================
// YOUR CODE BELOW — remove the // symbols from the scaffold and fill it in
// =============================================================================

#include <iostream>
#include <iomanip>
#include <cmath>
using namespace std;

#include <iostream>
#include <iomanip>
#include <cmath>
using namespace std;

// Function prototypes
void displayMenu();
double addValues(double x, double y);
double subtractValues(double x, double y);
double multiplyValues(double x, double y);
double divideValues(double x, double y);
int modulusValues(int x, int y);
double powerValue(double base, double exp);

int main() {
    int choice = 0;

    // Set fixed decimal formatting to 2 decimal places
    cout << fixed << setprecision(2);

    do {
        displayMenu();
        cin >> choice;

        if (choice >= 1 && choice <= 4) {
            double num1, num2;
            cout << "Enter first number : ";
            cin >> num1;
            cout << "Enter second number: ";
            cin >> num2;

            if (choice == 1) {
                cout << "Result: " << num1 << " + " << num2 << " = " << addValues(num1, num2) << endl;
            } else if (choice == 2) {
                cout << "Result: " << num1 << " - " << num2 << " = " << subtractValues(num1, num2) << endl;
            } else if (choice == 3) {
                cout << "Result: " << num1 << " * " << num2 << " = " << multiplyValues(num1, num2) << endl;
            } else if (choice == 4) {
                if (num2 == 0) {
                    cout << "Error: Cannot divide by zero." << endl;
                } else {
                    cout << "Result: " << num1 << " / " << num2 << " = " << divideValues(num1, num2) << endl;
                }
            }
        } 
        else if (choice == 5) {
            int num1, num2;
            cout << "Enter first number : ";
            cin >> num1;
            cout << "Enter second number: ";
            cin >> num2;

            if (num2 == 0) {
                cout << "Error: Cannot divide by zero." << endl;
            } else {
                cout << "Result: " << num1 << " % " << num2 << " = " << modulusValues(num1, num2) << endl;
            }
        } 
        else if (choice == 6) {
            double base, exp;
            cout << "Enter base number    : ";
            cin >> base;
            cout << "Enter exponent number: ";
            cin >> exp;

            cout << "Result: " << base << " ^ " << exp << " = " << powerValue(base, exp) << endl;
        } 
        else if (choice == 7) {
            cout << "Goodbye!" << endl;
        } 
        else {
            cout << "Invalid selection. Please enter a number from 1 to 7." << endl;
        }

        cout << endl;

    } while (choice != 7);

    return 0;
}

// Function to print the main menu screen
void displayMenu() {
    cout << "============================" << endl;
    cout << "       SIMPLE CALCULATOR    " << endl;
    cout << "============================" << endl;
    cout << "1. Addition" << endl;
    cout << "2. Subtraction" << endl;
    cout << "3. Multiplication" << endl;
    cout << "4. Division" << endl;
    cout << "5. Modulus" << endl;
    cout << "6. Exponentiation" << endl;
    cout << "7. Quit" << endl;
    cout << "Select an operation (1-7): ";
}

// Operation functions
double addValues(double x, double y) {
    return x + y;
}

double subtractValues(double x, double y) {
    return x - y;
}

double multiplyValues(double x, double y) {
    return x * y;
}

double divideValues(double x, double y) {
    return x / y;
}

int modulusValues(int x, int y) {
    return x % y;
}

double powerValue(double base, double exp) {
    return pow(base, exp);
}
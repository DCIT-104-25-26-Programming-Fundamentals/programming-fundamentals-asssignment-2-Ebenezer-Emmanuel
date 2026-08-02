// =============================================================================
// PROGRAMMING FUNDAMENTALS — Assignment 3
// =============================================================================
//
// TASK: Array Statistics Calculator
//
// Write a C++ program that reads a collection of numbers from the user
// and computes key statistical values using separate functions.
//
// -----------------------------------------------------------------------------
// EXPECTED INPUT / OUTPUT EXAMPLE
// -----------------------------------------------------------------------------
//
//   How many numbers? 5
//   Enter number 1: 4
//   Enter number 2: 7
//   Enter number 3: 2
//   Enter number 4: 9
//   Enter number 5: 1
//
//   Results:
//   Sum:     23
//   Average: 4.6
//   Maximum: 9
//   Minimum: 1
//
// -----------------------------------------------------------------------------
// REQUIREMENTS
// -----------------------------------------------------------------------------
// - You MUST implement each calculation in its own function (see scaffold).
// - You may NOT use any standard library functions like accumulate(), max(),
//   or min(). Implement the logic yourself using loops.
// - N must be a positive integer. If the user enters 0 or a negative number,
//   print an error message and stop.
//

//
// =============================================================================
// YOUR CODE BELOW — remove the // symbols from the scaffold and fill it in
// =============================================================================

#include <iostream>
using namespace std;

#include <iostream>
using namespace std;

// Function prototypes
double calculateSum(double arr[], int n);
double calculateAverage(double sum, int n);
double findMax(double arr[], int n);
double findMin(double arr[], int n);

int main() {
    int n;

    // Ask user for the count of numbers
    cout << "How many numbers? ";
    cin >> n;

    // Input validation
    if (n <= 0) {
        cout << "Error: Number of elements must be greater than zero." << endl;
        return 1;
    }

    // Allocate array dynamically based on input size
    double* numbers = new double[n];

    // Read the numbers from the user
    for (int i = 0; i < n; i++) {
        cout << "Enter number " << (i + 1) << ": ";
        cin >> numbers[i];
    }

    // Calculate statistical results using our functions
    double sum = calculateSum(numbers, n);
    double avg = calculateAverage(sum, n);
    double maxVal = findMax(numbers, n);
    double minVal = findMin(numbers, n);

    // Display the results
    cout << "\nResults:" << endl;
    cout << "Sum:     " << sum << endl;
    cout << "Average: " << avg << endl;
    cout << "Maximum: " << maxVal << endl;
    cout << "Minimum: " << minVal << endl;

    // Clean up dynamic memory
    delete[] numbers;

    return 0;
}

// Function to calculate sum manually
double calculateSum(double arr[], int n) {
    double total = 0;
    for (int i = 0; i < n; i++) {
        total += arr[i];
    }
    return total;
}

// Function to calculate average
double calculateAverage(double sum, int n) {
    return sum / n;
}

// Function to find maximum element manually
double findMax(double arr[], int n) {
    double maxVal = arr[0];
    for (int i = 1; i < n; i++) {
        if (arr[i] > maxVal) {
            maxVal = arr[i];
        }
    }
    return maxVal;
}

// Function to find minimum element manually
double findMin(double arr[], int n) {
    double minVal = arr[0];
    for (int i = 1; i < n; i++) {
        if (arr[i] < minVal) {
            minVal = arr[i];
        }
    }
    return minVal;
}
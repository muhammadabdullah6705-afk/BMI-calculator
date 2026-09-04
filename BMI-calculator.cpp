#include <iostream>
#include <cmath>
#include <iomanip>

using namespace std;

// Function to calculate BMI using metric units
double calculateMetricBMI(double weightKg, double heightCm) {
    double heightMeters = heightCm / 100.0;
    return weightKg / (heightMeters * heightMeters);
}

// Function to calculate BMI using imperial units
double calculateImperialBMI(double weightLbs, int feet, double inches) {
    double totalInches = (feet * 12) + inches;
    return (weightLbs / (totalInches * totalInches)) * 703.0;
}

// Function to display the BMI Category
void printBMICategory(double bmi) {
    cout << fixed << setprecision(1);
    cout << "\nYour BMI is: " << bmi << endl;
    cout << "Category: ";

    if (bmi < 18.5) {
        cout << "Underweight" << endl;
    } else if (bmi >= 18.5 && bmi < 25.0) {
        cout << "Normal weight" << endl;
    } else if (bmi >= 25.0 && bmi < 30.0) {
        cout << "Overweight" << endl;
    } else {
        cout << "Obesity" << endl;
    }
}

int main() {
    int choice;
    double bmi = 0.0;

    cout << "=================================\n";
    cout << "       BMI CALCULATOR (C++)      \n";
    cout << "=================================\n";
    cout << "Select input units:\n";
    cout << "1. Metric (Centimeters & Kilograms)\n";
    cout << "2. Imperial (Feet/Inches & Pounds)\n";
    cout << "Enter choice (1 or 2): ";
    cin >> choice;

    if (choice == 1) {
        double weightKg, heightCm;
        
        cout << "\nEnter weight in kilograms (kg): ";
        cin >> weightKg;
        cout << "Enter height in centimeters (cm): ";
        cin >> heightCm;

        if (heightCm <= 0 || weightKg <= 0) {
            cout << "Invalid input. Weight and height must be positive numbers.\n";
            return 1;
        }

        bmi = calculateMetricBMI(weightKg, heightCm);

    } else if (choice == 2) {
        double weightLbs, inches;
        int feet;

        cout << "\nEnter weight in pounds (lbs): ";
        cin >> weightLbs;
        cout << "Enter height (feet portion): ";
        cin >> feet;
        cout << "Enter height (remaining inches portion): ";
        cin >> inches;

        if (feet < 0 || inches < 0 || weightLbs <= 0 || (feet == 0 && inches == 0)) {
            cout << "Invalid input. Weight and height must be positive numbers.\n";
            return 1;
        }

        bmi = calculateImperialBMI(weightLbs, feet, inches);

    } else {
        cout << "Invalid choice! Please run the program again and select 1 or 2.\n";
        return 1;
    }

    printBMICategory(bmi);

    return 0;
}
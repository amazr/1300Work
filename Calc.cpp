#include <iostream>
#include <string>
using namespace std;

//Created on 6/6/2019 by Alex Mazur

int main() {
    
    bool stop  = false;
    bool error = false;
    int num1, num2, result;
    string add = "add";
    string subtract = "subtract";
    string multiply = "multiply";
    string divide = "divide";
    string modulus = "modulus";
    string stopCommand = "stop";
    string operand; 

    while (!stop) {
        cout << "\nEnter an operation: ";
        cin >> operand;

        if (operand == stopCommand) {
            stop = true;
        }

        if (operand != add && operand != subtract && operand != multiply && operand != divide && operand != modulus && !stop) {
            cout << "\nentered an invalid operand, try lowercase plain english!" << endl;
            error = true;
        }

        if (!stop && !error) {
            cout << "Enter number 1: ";
            cin >> num1;
            cout << "Enter number 2: ";
            cin >> num2;
        }

        if (operand == add) {
            result = num1 + num2;
        }
        else if (operand == subtract) {
            result = num1 - num2;
        }
        else if (operand == multiply) {
            result = num1 * num2;
        }
        else if (operand == divide) {
            result = num1 / num2;
        }
        else if (operand == modulus) {
            result = num1 % num2;
        }
        else if (operand == stopCommand) {
            error = true;
        }

        if (!error) {
            cout << "\nYour result is: " << result << endl;
        }
        
        error = false;
    }  
}
#include <iostream>
using namespace std;

int main() {

	bool stop = false;
	bool error = false;
	int bound = 20;
	int sum;
	string add = "add";
	string subtract = "subtract";
	string multiply = "multiply";
	string divide = "divide";
	string modulus = "modulus";
	string stopCommand = "stop";
	string operand;

	while (!stop) {

		sum = 1;

		cout << "\nEnter an operation (Enter 'stop' to end): ";
		cin >> operand;

		if (operand == stopCommand) {
			stop = true;
		}

		if (operand != add && operand != subtract && operand != multiply && operand != divide && operand != modulus && !stop) {
			cout << "\nentered an invalid operand, try lowercase plain english!" << endl;
			error = true;
		}

		if (!stop && !error) {
			cout << "\nEnter an upper bound: ";
			cin >> bound;

			if (!bound || bound < 2) {
				error = true;
				cout << "/nInvalid bound.";
			}
		}

		if (!stop) {
			for (int i = 2; i <= bound; i++) {
				cout << sum << endl;
				if (operand == add) {
					sum += i;
				}
				else if (operand == subtract) {
					sum -= i;
				}
				else if (operand == multiply) {
					sum *= i;
				}
				else if (operand == divide) {
					sum /= i;
				}
				else if (operand == modulus) {
					sum %= i;
				}
				else if (operand == stopCommand) {
					error = true;
				}
			}
		}
		
		if (!error) {
			cout << "\nYour result is: " << sum << endl;
		}

		error = false;
	}
}
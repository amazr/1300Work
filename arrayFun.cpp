#include <iostream>
using namespace std;

int main() {

	int L = 0;
	int tempSwap = 0;
	int arraySum = 0;
	bool unsorted = true;

	cout << "Please enter an array length: ";
	cin >> L;

	int funArray[L]; 

	cout << "Enter array values: " << endl;
	for (int i = 0; i < L; i++) {
		cin >> funArray[i];
	}

	//sum of every other number
	for (int i = 0; i < L; i+=2) {
		arraySum += funArray[i];
	}

	cout << "The sum of every other value is: " << arraySum << endl << endl;

	//sorting array
	for (int i = 0; i < L; i++) {
		if (funArray[i] > funArray[i + 1]) {
			tempSwap = funArray[i + 1];
			funArray[i + 1] = funArray[i];
			funArray[i] = tempSwap;
			i = 0;
		}
	}

	//displaying the sorted array
	cout << "The sorted array is: ";
	for (int i = 0; i < L; i++) {
		cout << funArray[i] << " ";
	}
	cout << endl << endl;

	//getting divisors
	for (int i = 0; i < L; i++) {
		cout << "The divisors of array[" << i << "]=" <<funArray[i]<< " are: ";
		for (int d = 1; d <= funArray[i]; d++) {
			if (funArray[i] % d == 0) {
				cout << d << " ";
			}
		}
		cout << endl;
	}


}
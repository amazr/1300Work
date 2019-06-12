#include <iostream>
using namespace std;

int main() {

	int L = 0;
	int tempSwap = 0;
	int arraySum = 0;
	bool unsorted = true;

	string isPalindrome = "";
	string reverse;

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

	//find if a string is a palindrome
	cout << endl << "Enter a string to check its palindrome-nes: ";
	cin >> isPalindrome;

	for (int i = isPalindrome.size(); i > 0; i--) {
		reverse += isPalindrome[i - 1];
	}

	if (reverse == isPalindrome) {
		cout << "The string you entered is a palindrome!" << endl;
	}
	else {
		cout << "The string you entered is definitely NOT a palindrome!" << endl;
	}

	//check the number of occurences in an array
	char alphabet[26] = {'a','b','c','d','e','f', 'g','h','i', 'j','k','l','m','n','o','p','q','r','s','t','u','v','w','x','y','z' };
	int occurences[26] = {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0};
	
	cout << endl << "Number of character occurences: " << endl;
	for (int i = 0; i < isPalindrome.size(); i++) {
		for (int j = 0; j < 26; j++) {
			if (isPalindrome[i] == alphabet[j]) {
				occurences[j]++;
				break;
			}
		}
	}

	for (int i = 0; i < 26; i++) {
		if (occurences[i] != 0) {
			cout << alphabet[i] << ": " << occurences[i] << endl;
		}
	}
	cout << endl;
	

	return 0;
}
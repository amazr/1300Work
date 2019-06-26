#include <iostream>
#include <vector>
#include <cstdlib>
#include <ctime>
using namespace std;

void partition(vector<int> &quick, int start, int &pivotIndex) {
	//cout << "in partition " <<  "s: " << start << " p: " << pivotIndex << endl;
	if (start >= pivotIndex) {
		return;
	}
	else if (quick.at(start) > quick.at(pivotIndex)) {

		int temp = quick.at(start);
		quick.erase(quick.begin() + start);
		quick.insert(quick.begin() + pivotIndex, temp);
		pivotIndex--;
		partition(quick, start, pivotIndex);

	}
	else {
		start++;
		partition(quick, start, pivotIndex);
	}

}

void doQuickSort(vector<int> &quick, int start, int pivotIndex) {
	//cout << "in doQuickSort" << "s: " << start << " p: " << pivotIndex << endl;
	if (start < pivotIndex) {
		partition(quick, start, pivotIndex);

		doQuickSort(quick, start, pivotIndex - 1);
		doQuickSort(quick, pivotIndex + 1, quick.size() - 1);
	}
	return;
}

void displayList(vector<int>& quick) {

	cout << endl;
	for (int i = 0; i < quick.size(); i++) {
		cout << quick.at(i) << " ";
	}
	cout << endl;
}


int main() {

	int L = 100;
	int scale = 100;
	vector<int> quick(L);

	srand(time(0));

	for (int i = 0; i < L; i++) {
		quick[i] = rand() % scale;
	}

	cout << "The unsorted list: ";
	displayList(quick);

	doQuickSort(quick, 0, quick.size() - 1);

	cout << "The sorted list: ";
	displayList(quick);

}
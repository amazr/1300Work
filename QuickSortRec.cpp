#include <iostream>
#include <vector>
#include <cstdlib>
#include <ctime>
using namespace std;

int partition(vector<int> &quick, int start, int pivotIndex) {

	if (start == pivotIndex) {
		return pivotIndex;
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

void doQuickSort(vector<int> &quick, int start, int high) {

	if (start < high) {
		int pi = partition(quick, start, high);

		doQuickSort(quick, start, pi - 1);
		doQuickSort(quick, pi + 1, high);
	}
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
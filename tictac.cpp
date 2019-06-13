#include <iostream>
using namespace std;

int main() {

	int R = 3;
	int C = 3;
	int row;
	int column;

	string score[R][C] = {  {" "," "," "}, 
							{" "," "," "}, 
							{" "," "," "} };

	string display_game = "   0     1     2  \n"
		"      |     |     \n"
		"0  " + score[0][0] + "  |  " + score[0][1] + "  |  " + score[0][2] + "   \n"
		" _ _ _|_ _ _|_ _ _\n"
		"      |     |     \n"
		"1  " + score[1][0] + "  |  " + score[1][1] + "  |  " + score[1][2] + "   \n"
		" _ _ _|_ _ _|_ _ _\n"
		"      |     |     \n"
		"2  " + score[2][0] + "  |  " + score[2][1] + "  |  " + score[2][2] + "   \n"
		"      |     |     \n";


	cout << display_game << endl;

	cout << "Player X choose a row: ";
	cin >> row;
	cout << "Player X choose a column: ";
	cin >> column;

	score[row][column] = "X";
	
	display_game = "   0     1     2  \n"
		"      |     |     \n"
		"0  " + score[0][0] + "  |  " + score[0][1] + "  |  " + score[0][2] + "   \n"
		" _ _ _|_ _ _|_ _ _\n"
		"      |     |     \n"
		"1  " + score[1][0] + "  |  " + score[1][1] + "  |  " + score[1][2] + "   \n"
		" _ _ _|_ _ _|_ _ _\n"
		"      |     |     \n"
		"2  " + score[2][0] + "  |  " + score[2][1] + "  |  " + score[2][2] + "   \n"
		"      |     |     \n";

	cout << display_game << endl;






	return 0;
}
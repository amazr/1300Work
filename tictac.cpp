#include <iostream>
using namespace std;

int main() {

	int R = 3;
	int C = 3;

	string score[R][C] = {  {" "," "," "}, 
							{" "," "," "}, 
							{" "," "," "} };

	string *score_pointer[R][C];

	//set the pointer array to point to the score array
	for (int i = 0; i < R; i++) {
		for (int j = 0; j < C; j++) {
			score_pointer[i][j] = &score[i][j];
		}
	}

	string display_game = "   0     1     2  \n"
		"      |     |     \n"
		"0  " + *score_pointer[0][0] + "  |  " + *score_pointer[0][1] + "  |  " + *score_pointer[0][2] + "   \n"
		" _ _ _|_ _ _|_ _ _\n"
		"      |     |     \n"
		"1  " + *score_pointer[1][0] + "  |  " + *score_pointer[1][1] + "  |  " + *score_pointer[1][2] + "   \n"
		" _ _ _|_ _ _|_ _ _\n"
		"      |     |     \n"
		"2  " + *score_pointer[2][0] + "  |  " + *score_pointer[2][1] + "  |  " + *score_pointer[2][2] + "   \n"
		"      |     |     \n";


	cout << display_game;




	return 0;
}
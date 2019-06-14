#include <iostream>
using namespace std;

int main() {

	int R = 3;
	int C = 3;
	int row;
	int column;
	int turnCounter = 0;
	int xHCounter = 0;
	int oHCounter = 0;
	int xVCounter = 0;
	int oVCounter = 0;
	int diagCounter = 0;
	int xDLCounter = 0;
	int xDRCounter = 0;
	int oDLCounter = 0;
	int oDRCounter = 0;

	bool gameOver = false;
	bool gameDraw = false;
	bool gameX = false;
	bool gameO = false;


	string playerX = "X";
	string playerO = "O";
	string playerReset = " ";

	string draw = "The game ended in a draw!";
	string xWon = "Player X won the game!";
	string oWon = "Player O won the game!";



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

	//While loop for the game
	while (!gameOver) {

		//Get player input and update score array
		if (turnCounter % 2 == 0) {
			cout << "Player X enter a row: ";
			cin >> row;
			cout << "Player X enter a column: ";
			cin >> column;

			//Check to see if the tile has already been played
			if (score[row][column] != " ") {
				cout << "You cannot move there!" << endl;
				continue;
			}
			score[row][column] = "X"; //update array
		}
		else {	//Same as above, but for player O
			cout << "Player O enter a row: ";
			cin >> row;
			cout << "Player O enter a column: ";
			cin >> column;

			if (score[row][column] != " ") { 
				cout << "You cannot move there!" << endl;
				continue;
			}

			score[row][column] = "O"; //update array
		}

		//update the game board
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

		//display the updated game board
		cout << display_game << endl;

		//Check if someone has won the game
		if (turnCounter == 4) {
			for (int i = 0; i < R; i++) {
				for (int j = 0; j < C; j++) {
					//Horizontal win check
					if (score[i][j] == "X") {
						xHCounter++;
					}
					if (score[i][j] == "O") {
						oHCounter++;
					}

					//Vertical win check
					if (score[j][i] == "X") {
						xVCounter++;
					}
					if (score[j][i] == "O") {
						oVCounter++;
					}

					//Diagonal win check
					if (diagCounter == 0 || diagCounter == 4 || diagCounter == 8) {
						if (score[i][j] == "X") {
							xDLCounter++;
						}
						if (score[i][j] == "O") {
							oDLCounter++;
						}
					}

					if (diagCounter == 2 || diagCounter == 4 || diagCounter == 6) {
						if (score[i][j] == "X") {
							xDRCounter++;
						}
						if (score[i][j] == "O") {
							oDRCounter++;
						}
					}
				}

				//set win bool and break the loop if the game was won
				if (xHCounter == 3 || xVCounter == 3 || xDRCounter == 3 || xDLCounter == 3) {
					gameX = true;
					break;
				}
				else if (oHCounter == 3 || oVCounter == 3 || oDRCounter == 3 || oDLCounter == 3) {
					gameO = true;
					break;
				}

				//Reset win check counters
				xHCounter = 0;
				oHCounter = 0;
				xVCounter = 0;
				oVCounter = 0;
			}
		}

		xDLCounter = 0;
		xDRCounter = 0;
		oDLCounter = 0;
		oDRCounter = 0;

		//update the current round
		turnCounter++;

		//Check for game ending condition bools, display, and break the loop if the game is over
		if (turnCounter == 9) {
			cout << draw << endl;
			break;
		}
		else if (gameX) {
			cout << xWon << endl;
			break;
		}
		else if (gameO) {
			cout << oWon << endl;
			break;
		}
	}
	return 0;
}
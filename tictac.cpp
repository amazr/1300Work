#include <iostream>
using namespace std;

int main() {

	int R = 3;
	int C = 3;
	int row;
	int column;
	int turnCounter = 0;

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

	//This command will clear the terminal!
	string clearTerminal = "clear";
	const char *clearCommand = clearTerminal.c_str();
	system(clearCommand);

	//Creating the game board and then displaying it down below for the first time
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

	cout << "Welcome to tic tac toe!" << endl;
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
		if (turnCounter >= 4) {

			//Horizontal Win Check
			if ((score[0][0] == "X" && score[0][1] == "X" && score[0][2] == "X") || (score[1][0] == "X" && score[1][1] == "X" && score[1][2] == "X") || (score[2][0] == "X" && score[2][1] == "X" && score[2][2] == "X")) {
				gameX = true;
			}
			if ((score[0][0] == "O" && score[0][1] == "O" && score[0][2] == "O") || (score[1][0] == "O" && score[1][1] == "O" && score[1][2] == "O") || (score[2][0] == "O" && score[2][1] == "O" && score[2][2] == "O")) {
				gameO = true;
			}

			//Vertical Win Check
			if ((score[0][0] == "X" && score[1][0] == "X" && score[2][0] == "X") || (score[0][1] == "X" && score[1][1] == "X" && score[2][1] == "X") || (score[0][2] == "X" && score[1][2] == "X" && score[2][2] == "X")) {
				gameX = true;
			}
			if ((score[0][0] == "O" && score[1][0] == "O" && score[2][0] == "O") || (score[0][1] == "O" && score[1][1] == "O" && score[2][1] == "O") || (score[0][2] == "O" && score[1][2] == "O" && score[2][2] == "O")) {
				gameO = true;
			}

			//Diagonal Win Check
			if ((score[0][0] == "X" && score[1][1] == "X" && score[2][2] == "X") || (score[0][2] == "X" && score[1][1] == "X" && score[2][0] == "X")) {
				gameX = true;
			}
			if ((score[0][0] == "O" && score[1][1] == "O" && score[2][2] == "O") || (score[0][2] == "O" && score[1][1] == "O" && score[2][0] == "O")) {
				gameO = true;
			}
		}

		//update the current round
		turnCounter++;

		//Check for game ending condition bools, display, and break the loop if the game is over
		if (turnCounter == 9) {
			cout << draw << endl;
			gameOver = true;
		}
		else if (gameX) {
			cout << xWon << endl;
			gameOver = true;
		}
		else if (gameO) {
			cout << oWon << endl;
			gameOver = true;
		}

		if (gameOver) {

			//Asks player if they'd like to play again
			char playagain;
			cout << "Would you like to play again? ('y'/'n'): ";
			cin >> playagain;
			
			//Stuff for if the player chose to play again
			if (playagain == 'y') { 
				system(clearCommand); //Clears terminal

				//Clears array
				for (int i = 0; i < R; i++) {
					for (int j = 0; j < C; j++) {
						score[i][j] = playerReset;
					}
				}

				//Clears the game board
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

				//Clears terminal and displays new board and sets gameOver to false and resets all the counters
				turnCounter = 0;
				system(clearCommand);
				cout << display_game << endl;
				gameOver = false;
				gameDraw = false;
				gameX = false;
				gameO = false;
			}
			else { //If the player did not choose to play again
				system(clearCommand);
				cout << "Thanks for playing!!!" << endl;
				break;
			}
		}
	}
	return 0;
}

#include <iostream>
#include <conio.h>
#include <string>

using namespace std;


char matrix[3][3] = { '\0' };
bool gameover;
string player1, player2;


void Map(string player1, string player2) 
{
	system("cls");
	cout << player1 << " VS " << player2<<endl;
	cout << endl;
	cout << "      |     |     " << endl;
	cout << "  "<<matrix[0][0]<<"   |  "<< matrix[0][1] << "  |  "<<matrix[0][2]<< "   " << endl;
	cout << "______|_____|_____" << endl;
	cout << "      |     |     " << endl;
	cout << "  " << matrix[1][0] << "   |  " << matrix[1][1] << "  |  " << matrix[1][2] << "   " << endl;
	cout << "______|_____|_____" << endl;
	cout << "      |     |     " << endl;
	cout << "  " << matrix[2][0] << "   |  " << matrix[2][1] << "  |  " << matrix[2][2] << "   " << endl;
	cout << "      |     |     " << endl;
}


string Actual_player_turn (string player1 , string player2)
{
	char char_P1, char_P2;
	static string current_player=" ";
	int Choosed_Number;

	current_player == " " || current_player == player1 ? current_player = player2 : current_player=player1;

	if (current_player==player1) {

		char_P2 = 'O';
		cout << player1 << " turn ";
	}
	else {

		char_P2 = 'X';
		cout << player2 << " turn ";
	}
	
	bool correct;
		do {

			correct = false;
			cin >> Choosed_Number;

			switch (Choosed_Number) {

			case 9:
				matrix[0][2] == '\0' ? matrix[0][2] = char_P2 : correct = true;
				break;
			case 8:
				matrix[0][1] == '\0' ? matrix[0][1] = char_P2 : correct = true;
				break;
			case 7:
				matrix[0][0] == '\0' ? matrix[0][0] = char_P2 : correct = true;
				break;
			case 6:
				matrix[1][2] == '\0' ? matrix[1][2] = char_P2 : correct = true;
				break;
			case 5:
				matrix[1][1] == '\0' ? matrix[1][1] = char_P2 : correct = true;
				break;
			case 4:
				matrix[1][0] == '\0' ? matrix[1][0] = char_P2 : correct = true;
				break;
			case 3:
				matrix[2][2] == '\0' ? matrix[2][2] = char_P2 : correct = true;
				break;
			case 2:
				matrix[2][1] == '\0' ? matrix[2][1] = char_P2 : correct = true;
				break;
			case 1:
				matrix[2][0] == '\0' ? matrix[2][0] = char_P2 : correct = true;
				break;

			}

			if (correct) {
				cout << "please choose another box";
			}

		} while (correct);

		return(current_player);
}

bool check_colomne() {

	if ((matrix[0][0] == 'X' && matrix[1][0] == 'X' && matrix[2][0] == 'X') || (matrix[0][0] == 'O' && matrix[1][0] == 'O' && matrix[2][0] == 'O')) return(true);
	else if ((matrix[0][1] == 'X' && matrix[1][1] == 'X' && matrix[2][1] == 'X') || (matrix[0][1] == 'O' && matrix[1][1] == 'O' && matrix[2][1] == 'O')) return(true);
	else if ((matrix[0][2] == 'X' && matrix[1][2] == 'X' && matrix[2][2] == 'X') || (matrix[0][2] == 'O' && matrix[1][2] == 'O' && matrix[2][2] == 'O')) return(true);

	else return(false);
}

bool check_line() {

	if ((matrix[0][0] =='X' &&  matrix[0][1] == 'X' && matrix[0][2] == 'X') || (matrix[0][0] == 'O' && matrix[0][1] == 'O' &&  matrix[0][2] == 'O')) return(true);
	else if ((matrix[1][0] =='X' && matrix[1][1] =='X' && matrix[1][2] == 'X') || (matrix[1][0] =='O' && matrix[1][1] =='O' && matrix[1][2] == 'O')) return(true);
	else if ((matrix[2][0] =='X' && matrix[1][1] =='X' && matrix[0][2] == 'X') || (matrix[2][0] =='O' && matrix[1][1] =='O' && matrix[0][2] == 'O')) return(true);
	else return(false);

 }

bool check_diag() {

	if ((matrix[0][0] =='X' && matrix[1][1] == 'X' && matrix[2][2] == 'X'  ) || (matrix[0][0] =='O' && matrix[1][1] =='O' && matrix[2][2] == 'O')) return(true);
			
	else if ((matrix[0][2] =='X' && matrix[1][1] =='X' && matrix[2][0] == 'X') || (matrix[0][2] =='O' && matrix[1][1] =='O' && matrix[2][0] == 'O')) return(true);

	else return(false);
}


void Setup() {

	cout << " please enter player 1 name's with X";
	cin >> player1;

	cout << "please enter player 2 name's with O";
	cin >> player2;

	gameover = false;

}

void aa(){
	for (size_t i = 0; i < 3; i++)
	{
		for (size_t j = 0; j < 3; j++)
		{
			cout << matrix[i][j];
		}
	}
}


int main()
{
	string player_name;
	player1 = "ahmed";
	player2 = "rami";

	while (!gameover)
	{

		Map(player1, player2);
		player_name= Actual_player_turn(player1, player2);
		Map(player1, player2);

		if ( check_colomne() || check_line() || check_diag() ) {

			gameover = true;
			cout << player_name << " win the game";

		}
		
		
	}
	
	


	


     
}


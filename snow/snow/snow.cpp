#include <iostream>
#include <string>
#include <cmath>
using namespace std;

/* Prints grid to the screen */
void displayGrid(long long grid) {
	// Horizontal lines occupy three spaces (---)
	// Diagonal lines (/ or \) occupy one space
	string g1 = "   ", g2 = "   ", g3 = " ", g4 = " ", g5 = " ", g6 = " ";
	string g7 = " ", g8 = "   ", g9 = "   ", g10 = " ", g11 = " ", g12 = " ";
	string g13 = " ", g14 = " ", g15 = "   ", g16 = "   ";
	int p1, p2;

	p2 = grid % 10;             // Player 2's score
	p1 = grid / 10 % 10;        // Player 1's score

	// LL suffix denotes a long long constant
	if (grid / 100000000000000000LL % 10 != 0)
		g1 = "---";
	if (grid / 10000000000000000LL % 10 != 0)
		g2 = "---";
	if (grid / 1000000000000000LL % 10 != 0)
		g3 = "/";
	if (grid / 100000000000000LL % 10 != 0)
		g4 = "\\";
	if (grid / 10000000000000LL % 10 != 0)
		g5 = "/";
	if (grid / 1000000000000LL % 10 != 0)
		g6 = "\\";
	if (grid / 100000000000LL % 10 != 0)
		g7 = "/";
	if (grid / 10000000000LL % 10 != 0)
		g8 = "---";
	if (grid / 1000000000 % 10 != 0)
		g9 = "---";
	if (grid / 100000000 % 10 != 0)
		g10 = "/";
	if (grid / 10000000 % 10 != 0)
		g11 = "\\";
	if (grid / 1000000 % 10 != 0)
		g12 = "/";
	if (grid / 100000 % 10 != 0)
		g13 = "\\";
	if (grid / 10000 % 10 != 0)
		g14 = "/";
	if (grid / 1000 % 10 != 0)
		g15 = "---";
	if (grid / 100 % 10 != 0)
		g16 = "---";

	cout << "    o" << g1 << "o" << g2 << "o\n";
	cout << "   " << g3 << " " << g4 << " " << g5 << " " << g6 << " " << g7 << "\n";
	cout << "  o" << g8 << "o" << g9 << "o\n";
	cout << " " << g10 << " " << g11 << " " << g12 << " " << g13 << " " << g14 << "      Player 1 score: " << p1 << endl;
	cout << "o" << g15 << "o" << g16 << "o       Player 2 score: " << p2 << endl;
}

/* Returns true if position pos of grid is filled with a line; returns false
otherwise. */
bool isFilled(long long grid, int pos) {
	grid /= 100;
	// Shift position pos to the units-digit
	for (int i = 0; i < 16 - pos; i++)
		grid /= 10;
	return (grid % 10 != 0);
}

/* Returns the score of Player p in grid. (Either the 17th or 18th digits in
grid.) */
int playerScore(long long grid, int p) {
	int score = 0;
	if (p == 1)
		score = grid / 10 % 10;
	else
		score = grid % 10;



	return score;
}

/* Performs the task of Player p putting a line in position pos in grid. The
grid should get updated, and if any new triangles are formed, the score of
Player p should be incremented. Note that putting one line can form at most
two triangles. The reference parameter grid should store the updated grid
when the function returns. To determine if a new triangle is formed, calling
the isFilled(...) function is useful.
*/
void updateGrid(long long &grid, int pos, int p) {

	long long oldgrid = grid;
	grid = grid + pow(10, 18 - pos);
	int g1 = grid / 100000000000000000LL % 10, g2 = grid / 10000000000000000LL % 10 != 0, g3 = grid / 1000000000000000LL % 10 != 0, g4 = grid / 100000000000000LL % 10 != 0, g5 = grid / 10000000000000LL % 10 != 0, g6 = grid / 1000000000000LL % 10 != 0, g7 = grid / 100000000000LL % 10, g8 = grid / 10000000000LL % 10, g9 = grid / 1000000000LL % 10, g10 = grid / 100000000LL % 10, g11 = grid / 10000000LL % 10, g12 = grid / 1000000LL % 10, g13 = grid / 100000LL % 10, g14 = grid / 10000 % 10, g15 = grid / 1000 % 10, g16 = grid / 100 % 10;
	int og1 = oldgrid / 100000000000000000LL % 10, og2 = oldgrid / 10000000000000000LL % 10 != 0, og3 = oldgrid / 1000000000000000LL % 10 != 0, og4 = oldgrid / 100000000000000LL % 10 != 0, og5 = oldgrid / 10000000000000LL % 10 != 0, og6 = oldgrid / 1000000000000LL % 10 != 0, og7 = oldgrid / 100000000000LL % 10, og8 = oldgrid / 10000000000LL % 10, og9 = oldgrid / 1000000000LL % 10, og10 = oldgrid / 100000000LL % 10, og11 = oldgrid / 10000000LL % 10, og12 = oldgrid / 1000000LL % 10, og13 = oldgrid / 100000LL % 10, og14 = oldgrid / 10000 % 10, og15 = oldgrid / 1000 % 10, og16 = oldgrid / 100 % 10;

	if (og3 + og4 + og8<3 && g3 + g4 + g8 == 3)
		grid = grid + pow(10, (2 - p));
	if (og1 + og4 + og5<3 && g1 + g4 + g5 == 3)
		grid = grid + pow(10, (2 - p));
	if (og5 + og6 + og9<3 && g5 + g6 + g9 == 3)
		grid = grid + pow(10, (2 - p));
	if (og2 + og6 + og7<3 && g2 + g6 + g7 == 3)
		grid = grid + pow(10, (2 - p));
	if (og10 + og11 + og15<3 && g10 + g11 + g15 == 3)
		grid = grid + pow(10, (2 - p));
	if (og8 + og11 + og12<3 && g8 + g11 + g12 == 3)
		grid = grid + pow(10, (2 - p));
	if (og12 + og13 + og16<3 && g12 + g13 + g16 == 3)
		grid = grid + pow(10, (2 - p));
	if (og9 + og13 + og14<3 && g9 + g13 + g14 == 3)
		grid = grid + pow(10, (2 - p));

	for (int k=1, i = 1; i <= 18 - pos; i++)
		k *= 10;



}

/* Returns an integer 0, 1, 2, or 3, denoting the game state of grid listed
below:
0: Game is finished and is a draw.
1: Game is finished and Player 1 wins.
2: Game is finished and Player 2 wins.
3: Game is not yet finished. (That is, grid is not full.)
*/

int gameState(long long grid) {

	int p2 = grid % 10;             // Player 2's score
	int p1 = grid / 10 % 10;
	if (p1 + p2<8)
		return 3;
	if (p1 + p2 == 8 && p1<p2)
		return 2;
	if (p1 + p2 == 8 && p1>p2)
		return 1;

	return 0;
}

int main() {
	long long grid=0;
	
	int p = 1, pos = 0;
	while (gameState(grid) == 3)
	{
		displayGrid(grid);

		int Point_o = playerScore(grid, p);
		cout << "Player " << p << ", make your move (1-16):";
		cin >> pos;
		while (pos <= 0 || pos >= 16 || (10 ^ (18 - pos)) == 1)
		{
			cout << "Invalid move! Try again." << endl;
			cout << "Player " << p << ", make your move (1-16):";
			cin >> pos;
		}

		updateGrid(grid, pos, p);

		int Point_n = playerScore(grid, p);

		if (Point_n == Point_o)
		{
			if (p == 1)
				p = 2;
			else
				p = 1;
		}

	}


	displayGrid(grid);



	if (gameState(grid) == 1)
		cout << "Player 1 wins!";
	if (gameState(grid) == 2)
		cout << "Player 2 wins!";
	if (gameState(grid) == 0)
		cout << "Draw game!";







	return 0;
}

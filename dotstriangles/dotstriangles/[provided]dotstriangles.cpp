#include <iostream>
#include <string>
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
    return (grid % 10 != 0);//in main there will be a while function to while if filled.
}

/* Returns the score of Player p in grid. (Either the 17th or 18th digits in
   grid.) */
int playerScore(long long grid, int p) {//return score of p1 or p2  
    int score = 0;
	
	if (isFilled(grid, 1) && isFilled(grid, 4) && isFilled(grid, 5))//1 1£¬4£¬5
		score += 1;
	if (isFilled(grid, 2) && isFilled(grid, 6) && isFilled(grid, 7))//2 2£¬6£¬7
		score += 1;
	if (isFilled(grid, 3) && isFilled(grid, 4) && isFilled(grid, 8))//3 3£¬4£¬8
		score += 1;
	if (isFilled(grid, 5) && isFilled(grid, 9) && isFilled(grid, 6))//4 5£¬9£¬6
		score += 1;
	if (isFilled(grid, 8) && isFilled(grid, 11) && isFilled(grid, 12))//5 8£¬11£¬12
		score += 1;
	if (isFilled(grid, 9) && isFilled(grid, 13) && isFilled(grid, 14))//6 9£¬13£¬14
		score += 1;
	if (isFilled(grid, 10) && isFilled(grid, 11) && isFilled(grid, 15))//7 10£¬11£¬15
		score += 1;
	if (isFilled(grid, 12) && isFilled(grid, 16) && isFilled(grid, 13))//8 12£¬16£¬13
		score += 1;
    // Calculate new score
	score = score - p;//ifp=p1 score=p2 if p=p2 score=p1
	
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

    // TO DO BELOW


	string g1 = "   ", g2 = "   ", g3 = " ", g4 = " ", g5 = " ", g6 = " ";
	string g7 = " ", g8 = "   ", g9 = "   ", g10 = " ", g11 = " ", g12 = " ";
	string g13 = " ", g14 = " ", g15 = "   ", g16 = "   ";
	long long k=1;
	int p1, p2;
	p2 = grid % 10;             // Player 2's score
	p1 = grid / 10 % 10;        // Player 1's score

	
	for (int i = 1; i <= 18-pos; i++)
		k *= 10;
	grid += k;

	if (p >= 100){ //this is p1 turn while p=p2+100
		p = p - 100;//p=p2
		p1 = playerScore(grid, p); //we get new p1
	}
	else p2 = playerScore(grid, p);//p2 turn while p=p1;


	//p1=new score - p2   p2= new score -p1

	grid = grid / 100 + p1 * 10 + p2;



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



/* Returns an integer 0, 1, 2, or 3, denoting the game state of grid listed
   below:
       0: Game is finished and is a draw.
       1: Game is finished and Player 1 wins.
       2: Game is finished and Player 2 wins.
       3: Game is not yet finished. (That is, grid is not full.)
*/
int gameState(long long grid) {

    // TO DO BELOW
	int p1, p2;
	p2 = grid % 10;             // Player 2's score
	p1 = grid / 10 % 10;        // Player 1's score
	if (p1 + p2 < 8)
		return 3;
	if (p1 + p2 == 8 && p1 < p2)
		return 2;
	if (p1 + p2 == 8 && p1 > p2)
		return 1;
	if (p1 == 4 && p2 == 4)
		return 0;
	
}

int main() {

    // TO DO: Fill in your game flow below.
	long long grid = 0;
	int p1 = 0, p2 = 0, p=0, pos, i = 1;
	p2 = grid % 10;             // Player 2's score
	p1 = grid / 10 % 10;        // Player 1's score
	displayGrid(grid);
	while (gameState(grid) == 3){
		if (i % 2 == 1){
			cout << "Player 1, make your move";
			cin >> pos;
			while (pos <= 0 && isFilled(grid, pos)){
				cout << "Invalid move! Try angin." << endl;
				cout << "Player 1, make your move";
				cin >> pos;
			}
			p = p2 + 100;//attention this may have logic problem, this is used to define p1 and p2  when is player1 p>=100 and =p2+100
			updateGrid(grid, pos, p);
			if (p1 < grid / 10 % 10){
				p1 = grid / 10 % 10;
				cout << "Player 1, make your move";
				cin >> pos;
				while (pos <= 0 && isFilled(grid, pos)){
					cout << "Invalid move! Try angin." << endl;
					cout << "Player 1, make your move";
					cin >> pos;
				}p = p2 + 100;//attention this may have logic problem, this is used to define p1 and p2  when is player1 p>=100 and =p2+100
				updateGrid(grid, pos, p);
				i += 1;
			}
			else i += 1;

		}
		else	{
			cout << "Player 2, make your move";
			cin >> pos;
			while (pos <= 0 && isFilled(grid, pos)){
				cout << "Invalid move! Try angin." << endl;
				cout << "Player 2, make your move";
				cin >> pos;
			}
			p = p1;//attention this may have logic problem, this is used to define p1 and p2  when is player2 p=p1
			updateGrid(grid, pos, p);
			if (p2 < grid / 10 % 10){
				p2 = grid / 10 % 10;
				cout << "Player 2, make your move";
				cin >> pos;
				while (pos <= 0 && isFilled(grid, pos)){
					cout << "Invalid move! Try angin." << endl;
					cout << "Player 2, make your move";
					cin >> pos;
				}p = p1;//attention this may have logic problem, this is used to define p1 and p2  when is player2 p=p1
				updateGrid(grid, pos, p);
				i += 1;
			}
			else i += 1;
		}

	}
	if (gameState(grid) == 2)
		cout << "Player 2 wins!"<<endl;
	if (gameState(grid) == 1)
		cout << "Player 1 wins!"<<endl;
	if (gameState(grid) == 0)
		cout << "Draw game!" << endl;
    return 0;
}

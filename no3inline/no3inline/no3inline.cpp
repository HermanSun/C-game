//CSCI1540
//Assignment: 5
//Student ID: 1155047154
//Name      : SUN WUFAN
//E-mail adr: hermansun@qq.com

#include <iostream>
#include <string>
using namespace std;

/* Prints grid to the screen */
void print_out(char board[] [11], int ) {
	for (int i = 0; i < 11; i++){
		for (int j = 0; j < 11; j++){
			if (i == 0 && j == 0)
				cout << " "<<" ";
			else if (i == 0 && j != 0)
				cout << j - 1<<" ";
			else if (i != 0 && j == 0)
				cout << i - 1<<" ";
			else
				cout << board[i][j]<<" ";
		}
		cout << endl;
	}


}//display part well done

bool check_full(char board[][11], int){
	bool flag = true;
	for (int i = 0; i < 10; i++)
		for (int j = 0; j < 10; j++){
		if (board[i + 1][j + 1] == '.'){
			flag = false;
			break;
		}
		}
	return flag;
}

bool check_input(char board[][11], int row, int col){
	if (row < 0 || col < 0 || row>9 || col>9)//out of range
		return false;
	else if (board[row + 1][col + 1] == '.')
		return true;
	else if (board[row + 1][col + 1] == '@' || board[row + 1][col + 1] == 'X')
		return false;
	return 0;
}
int check_input_position_ver(char board[][11], int row, int col){
	int num = 0;
	for (int i = 0; i < 10; i++){
		if (board[i+1][col+1] == '@')//check if need +1
			num++;
	}
	return num;
}
int check_input_position_hor(char board[][11], int row, int col){
	int num = 0;
	for (int i = 0; i < 10; i++){
		if (board[row + 1][i + 1]=='@')
			num++;
	}
	return num;
}
int check_input_position_lt_rb(char board[][11], int row,int col){
	int num = 0;
	for (int i = 0;; i++){
		if (row - i < 0 || col - i < 0)
			break;
		if (board[row - i + 1][col - i + 1] == '@')
			num++;
	}
	for (int i = 1;; i++){
		if (row + i>9 || col + i > 9)
			break;
		if (board[row + i + 1][col + i + 1] == '@')
			num++;
	}
	return num;
}
int check_input_position_rt_lb(char board[][11], int row, int col){
	int num = 0;
	for (int i = 0;; i++){
		if (row - i < 0 || col + i > 9)
			break;
		if (board[row - i + 1][col + i + 1] == '@')
			num++;
	}
	for (int i = 1;; i++){
		if (row + i>9 || col - i < 0)
			break;
		if (board[row + i + 1][col - i + 1] == '@')
			num++;
	}
	return num;
}



void renew_board(char board[][11], int row, int col){
	board[row + 1][col + 1] = '@';
	int hor = check_input_position_hor(board, row, col);
	if (hor == 2){
		for (int i = 0; i < 10; i++){
			if (board[row + 1][i + 1] == '.')
				board[row + 1][i + 1] = 'X';
		}
	}
	int ver = check_input_position_ver(board, row, col);
		if (ver == 2){
			for (int i = 0; i < 10; i++){
				if (board[i + 1][col + 1] == '.')
					board[i + 1][col + 1] = 'X';
			}
		}
	int left_top = check_input_position_lt_rb(board, row, col);
	if (left_top == 2){
			for (int i = 1;; i++){
				if (row - i < 0 || col - i < 0)
					break;
				if (board[row - i + 1][col - i + 1] == '.')
					board[row - i + 1][col - i + 1] = 'X';
			}
			for (int i = 1;; i++){
				if (row + i>9 || col + i > 9)
					break;
				if (board[row + i + 1][col + i + 1] == '.')
					board[row + i + 1][col + i + 1] = 'X';
			}
		}
	int right_top = check_input_position_rt_lb(board, row, col);
	if (right_top == 2){
			for (int i = 1;; i++){
				if (row - i < 0 || col + i > 9)
					break;
				if (board[row - i + 1][col + i + 1] == '.')
					board[row - i + 1][col + i + 1] = 'X';
			}
			for (int i = 1;; i++){
				if (row + i>9 || col - i < 0)
					break;
				if (board[row + i + 1][col - i + 1] == '.')
					board[row + i + 1][col - i + 1] = 'X';
			}
		}

}
int main(){
	int i, j;
	char board[11][11];
	for (i = 0; i < 11; i++)
		for (j = 0; j < 11; j++)
			board[i][j] = '.';   //initiallize board
	int count = 0;
	print_out(board, 11);
	bool full = check_full(board,11);//well done before
	while (!full){
		count++;
		cout << "Make a move <row col>: ";
		cin >> i >> j;
		while (!check_input(board, i, j)){
			cout << "Invalid. Try again!" << endl;
			cout << "Make a move <row col>: ";
			cin >> i >> j;
		}//before well done to invalid value
		renew_board(board, i,j);
		print_out(board, 11);
		full = check_full(board, 11);//check full


	}
	cout << "Number of pieces: " << count<<endl;
	return 0;
}
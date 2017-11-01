#ifndef CROSS_H
#define CROSS_H
#include <iostream>
#include <string>
#include <vector>

using std::cout;
using std::cin;
using std::string;
using std::vector;

const char X = 'X';
const char O = 'O';
const char EMPTY = ' ';
const char TIE = 'T';
const char NO_ONE = 'N';

class Cross {
private:
	string question;
	char piece;
	int high;
	int low;
	char computer;
	char human;

public:

	Cross();
	char askYesNo(string question);
	int askNumber(string question, int high, int low = 0);
	char humanPiece();
	char opponent(char piece);
	void displayBoard(const vector<char>& board);
	char winner(const vector<char>& board);
	bool isLegal(int move, const vector<char>& board);
	int humanMove(const vector<char>& board, char human);
	int computerMove(vector<char> board, char computer);
	void announceWinner(char winner, char computer, char human);
	~Cross();

};

#endif 
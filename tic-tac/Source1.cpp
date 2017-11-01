//tic-tac-toe game
#include "Header.h"

int main()
{
	int move;
	const int NUM_SQUARES = 9;
	vector<char> board(NUM_SQUARES, EMPTY);
	Cross step;
	char human = step.humanPiece();
	char computer = step.opponent(human);
	char turn = X;
	step.displayBoard(board);

	while (step.winner(board) == NO_ONE)
	{
		if (turn == human)
		{
			move = step.humanMove(board, human);
			board[move] = human;
		}
		else
		{
			move = step.computerMove(board, computer);
			board[move] = computer;
		}
		step.displayBoard(board);
		turn = step.opponent(turn);
	}

	step.announceWinner(step.winner(board), computer, human);

	return 0;
}




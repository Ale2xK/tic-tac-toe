#include "Header.h"

Cross::Cross() {

}


char Cross::askYesNo(string question)
{
	char response;
	do
	{
		cout << question << " (y/n): ";
		cin >> response;
	} while (response != 'y' && response != 'n');

	return response;
}

int  Cross::askNumber(string question, int high, int low)
{
	int number;
	do
	{
		cout << question << " (" << low << " - " << high << "): ";
		cin >> number;
	} while (number > high || number < low);

	return number;
}

char Cross::humanPiece()
{
	char go_first = askYesNo("Do you require the first move?");
	if (go_first == 'y')
	{
		cout << "\nThen take the first move.  You will need it.\n";
		return X;
	}
	else
	{
		cout << "\nYour bravery will be your undoing... I will go first.\n";
		return O;
	}
}

char Cross::opponent(char piece)
{
	if (piece == X)
	{
		return O;
	}
	else
	{
		return X;
	}
}

void Cross::displayBoard(const vector<char>& board)
{
	cout << "\n\t" << board[0] << " | " << board[1] << " | " << board[2];
	cout << "\n\t" << "---------";
	cout << "\n\t" << board[3] << " | " << board[4] << " | " << board[5];
	cout << "\n\t" << "---------";
	cout << "\n\t" << board[6] << " | " << board[7] << " | " << board[8];
	cout << "\n\n";
}

char Cross::winner(const vector<char>& board)
{
	const int WINNING_ROWS[8][3] = { { 0, 1, 2 },
	{ 3, 4, 5 },
	{ 6, 7, 8 },
	{ 0, 3, 6 },
	{ 1, 4, 7 },
	{ 2, 5, 8 },
	{ 0, 4, 8 },
	{ 2, 4, 6 } };
	const int TOTAL_ROWS = 8;

	
	for (int row = 0; row < TOTAL_ROWS; ++row)
	{
		if ((board[WINNING_ROWS[row][0]] != EMPTY) &&
			(board[WINNING_ROWS[row][0]] == board[WINNING_ROWS[row][1]]) &&
			(board[WINNING_ROWS[row][1]] == board[WINNING_ROWS[row][2]]))
		{
			return board[WINNING_ROWS[row][0]];
		}
	}

	if (count(board.begin(), board.end(), EMPTY) == 0)
		return TIE;

	
	return NO_ONE;
}

bool Cross::isLegal(int move, const vector<char>& board)
{
	return (board[move] == EMPTY);
}

int Cross::humanMove(const vector<char>& board, char human)
{
	int move = askNumber("Where will you move?", (board.size() - 1));
	while (!isLegal(move, board))
	{
		cout << "\nThat square is already occupied, foolish human.\n";
		move = askNumber("Where will you move?", (board.size() - 1));
	}
	cout << "Fine...\n";

	return move;
}

int Cross::computerMove(vector<char> board, char computer)
{
	unsigned int move = 0;
	bool found = false;

	
	while (!found && move < board.size())
	{
		if (isLegal(move, board))
		{
			
			board[move] = computer;
			
			found = winner(board) == computer;
			
			board[move] = EMPTY;
		}

		if (!found)
		{
			++move;
		}
	}

	
	if (!found)
	{
		move = 0;
		char human = opponent(computer);

		while (!found && move < board.size())
		{
			if (isLegal(move, board))
			{
				
				board[move] = human;
				
				found = winner(board) == human;
				
				board[move] = EMPTY;
			}

			if (!found)
			{
				++move;
			}
		}
	}

	
	if (!found)
	{
		move = 0;
		unsigned int i = 0;

		const int BEST_MOVES[] = { 4, 0, 2, 6, 8, 1, 3, 5, 7 };
		
		while (!found && i <  board.size())
		{
			move = BEST_MOVES[i];
			if (isLegal(move, board))
			{
				found = true;
			}

			++i;
		}
	}

	cout << "I shall take square number " << move << std::endl;
	return move;
}

void Cross::announceWinner(char winner, char computer, char human)
{
	if (winner == computer)
	{
		cout << winner << "'s won!\n";

	}

	else if (winner == human)
	{
		cout << winner << "'s won!\n";

	}

	else
	{
		cout << "It's a tie.\n";

	}
}

Cross::~Cross() {}
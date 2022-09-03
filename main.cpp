#include <iostream>
using std::cout;
using std::cin;
using std::endl;
using std::string;

// board
char board[] = { 49 , 50 , 51 , 52 , 53 , 54 , 55 , 56 , 57};
char	choice[] = {'X','0'};

void	draw_board(void);
char	check_win(void);
int	valid_move(string move);

int main(void)
{

	int		i;
	char	winner;
	int		curr = 1;
	string move;

	draw_board();
	i = -1;
	while (++i <= 8)
	{
		curr = !curr;
		do
		{
			cout << "\nPlayer" << (curr + 1) << " (" << choice[curr] << ") : ";
			cin >> move;

		} while (!valid_move(move));
		board[(char)move[0] - 1 - 48] = choice[curr];
		draw_board();
		if (winner = check_win())
		{
			if (winner == 'X')
				curr = 1;
			else
				curr = 2;
			cout << "\nPlayer " << curr << " has won !" << endl;
			return (0);

		}
	}
	cout << "\nThis is a draw !" << endl;
	return (0);
}

int	valid_move(string move)
{
	char c;
	if (move.size() > 1 || move.empty())
	{
		cout << "Invalid move" << endl;
		return (0);
	}
	c = move[0];
	if (c <= '0' || c > '9')
	{
		cout << "Invalid move" << endl;
		return (0);
	}
	if (board[c - 48 - 1] == 'X' || board[c - 48 - 1] == '0')
	{
		cout << "Invalid move" << endl;
		return (0);
	}
	return (1);
}

char	check_win(void)
{
	//check vertical
	for (int i = 0; i <= 2; i++)
	{
		if (board[i] == board[3 + i] && board[i] == board[6 + i])
			return (board[i]);
	}
	// check horizontal
	for (int i = 0; i <= 6; i += 3)
	{
		if (board[i] == board[1 + i] && board[i] == board[2 + i])
			return (board[i]);
	}
	// check diagonal
	if (board[0] == board[4] && board[0] == board[8])
		return (board[0]);
	if (board[2] == board[4] && board[2] == board[6])
		return (board[2]);
	return (0);
}

void	draw_board(void)
{
	system("cls");
	cout << "\n\n#_____________ Welcome to joeTacToe :D _____________#\n" << endl;
	cout << " #___________PLAYER 1 (X) | PLAYER 2 (0)___________#\n\n" << endl;
	cout << "      "    << "|" << "     "    << "|" << "     "    << endl;
	cout << "   " << board[0] << "  " << "|" << "  " << board[1] << "  " << "|"  << "  " << board[2] << "  " << endl;
	cout << " _____"    << "|" << "_____"    << "|" << "_____"    << endl;

	cout << "      " << "|" << "     " << "|" << "     " << endl;
	cout << "   " << board[3] << "  " << "|" << "  " << board[4] << "  " << "|" << "  " << board[5] << "  " << endl;
	cout << " _____" << "|" << "_____" << "|" << "_____" << endl;


	cout << "      " << "|" << "     " << "|" << "     " << endl;
	cout << "   " << board[6] << "  " << "|" << "  " << board[7] << "  " << "|" << "  " << board[8] << "  " << endl;
	cout << "      " << "|" << "     " << "|" << "     " << endl;
}
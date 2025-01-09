#include <stdlib.h>
#include <stdio.h>

void print_board(int *board, int n)
{
	int i = 0;
	while (i < n)
	{
		printf("%d", board[i]);
		if (i < n - 1)
			printf(" ");
		else
			printf("\n");
		i++;
	}
}

int queen_safe(int *board, int col, int row)
{
	int i = 0;

	while (i < col)
	{
		if (board[i] == row) 
			return (0); // horizontal
		if (board[i] - i == row - col)
			return (0); // diagonal up left
		if (board[i] + i == row + col)
			return (0); // diagonal down left
		i++;
	}
	return (1);
}

void solve(int *board, int col, int n)
{
	if (col == n)
	{
		print_board(board, n);
		return ;
	}
	int row = 0;
	while (row < n)
	{
		if (queen_safe(board, col, row))
		{
			board[col] = row;
			solve(board, col + 1, n);
		}
		row++;
	}
}

int main(int argc, char *argv[])
{
	if (argc != 2)
		return (1);
	int *board;
	int n = atoi(argv[1]);
	board = malloc(sizeof(int) * n);

	solve(board, 0, n);
}

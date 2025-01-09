def solve(board: list[int], col: int, n: int):
	if col == n:
		print(board)
		return
	row = 0
	while row < n:
		if queen_safe(board, col, row):
			board[col] = row
			solve(board, col + 1, n)
		row += 1

def queen_safe(board: list[int], col: int, row: int):
	# check horizontally, diagonally up left, diagonally down left
	i = 0
	while i < col:
		if board[i] == row:
			return False
		if board[i] - i == row - col:
			return False
		if board[i] + i == row + col:
			return False
		i += 1
	return True

n = 12
board = [0] * n
solve(board, 0, n)

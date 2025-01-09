def permute(input: str, pos: int, end: int):
	if pos == end:
		print("".join(input))
		return
	i = pos
	while i < end:
		letter_to_front(input, pos, i)
		permute(input, pos + 1, end)
		letter_to_back(input, pos, i)
		i += 1

def swap_letters(input: str, a: int, b: int):
	temp = input[a]
	input[a] = input[b]
	input[b] = temp

def letter_to_front(input: str, front_pos: int, letter_pos: int):
	i = letter_pos
	while i > front_pos:
		swap_letters(input, i, i - 1)
		i -= 1

def letter_to_back(input: str, letter_pos: int, back_pos: int):
	i = letter_pos
	while i < back_pos:
		swap_letters(input, i, i + 1)
		i += 1

# sort alphabetically before starting
boing = list("abc")
permute(boing, 0, len(boing))

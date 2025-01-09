def rip(input: str, output: str, balance: int, pos: int):
	if pos == len(input):
		if balance == 0 and is_valid(output):
			print("".join(output))
		return

	if input[pos] == "(" and balance < 0: #in case we are removing (s
		output[pos] = "_" #remove current
		rip(input, output, balance + 1, pos + 1) #and continue

	if input[pos] == ")" and balance > 0:
		output[pos] = "_"
		rip(input, output, balance - 1, pos + 1)

	output[pos] = input[pos]
	rip(input, output, balance, pos + 1)

def get_balance(input: str):
	balance = 0
	i = 0
	while i < len(input):
		if input[i] == "(":
			balance -= 1
		elif input[i] == ")":
			balance += 1
		i += 1
	return balance

def is_valid(input: str):
	balance = 0
	i = 0
	while i < len(input):
		if input[i] == "(":
			balance -= 1
		elif input[i] == ")":
			balance += 1
		i += 1
		if balance > 0:
			return False
	return True

input = "(()(()("
output = [" "] * len(input)
balance = get_balance(input)
print(f"balance is {balance}")
rip(input, output, balance, 0)

# 5 01234
#   0 23
#     23
#   01  4

def get_sets(input: str, output: str, sum: int, pos: int):
	if pos == len(input):
		if check_sum(output, sum):
			print("".join(output))
		return
	output[pos] = "_" #						#first remove, 
	get_sets(input, output, sum, pos + 1) #	#and do everything
	output[pos] = input[pos] #				#then don't remove,
	get_sets(input, output, sum, pos + 1) #	#and do everything

def check_sum(output: str, sum: int):
	i = 0
	total = 0
	while i < len(output):
		if output[i] != "_":
			total += int(output[i])
		i += 1
	if total == sum:
		return True
	return False

input = "0123"
output = [""] * len(input)
get_sets(input, output, 3, 0)

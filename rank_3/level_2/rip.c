#include <string.h>
#include <stdlib.h>
#include <stdio.h>

/* get balance and isvalid are almost the same. start there */

int	get_balance(char *input)
{
	int balance = 0;
	int i = 0;

	while (i < strlen(input))
	{
		if (input[i] == '(')
			balance--;
		if (input[i] == ')')
			balance++;
		i++;
	}
	return (balance);
}

int is_valid(char *input)
{
	int balance = 0;
	int i = 0;

	while (i < strlen(input))
	{
		if (input[i] == '(')
			balance--;
		if (input[i] == ')')
			balance++;
		if (balance > 0)
			return (0);
		i++;
	}
	return (1);
}

void rip(char *input, char *output, int pos, int balance)
{
	if (pos == strlen(input))
	{
		if (balance == 0 && is_valid(output))
			printf("%s\n", output);
		return ;
	}
	if (input[pos] == '(' && balance < 0)
	{
		output[pos] = ' ';
		rip(input, output, pos + 1, balance + 1);
	}
	else if (input[pos] == ')' && balance > 0)
	{
		output[pos] == ' ';
		rip(input, output, pos + 1, balance - 1);
	}
	output[pos] = input[pos];
	rip(input, output, pos + 1, balance);
}

int	main(int argc, char *argv[])
{
	if (argc != 2)
		return (1);
	
	char *output;
	output = malloc(sizeof(char) * strlen(argv[1]));
	rip(argv[1], output, 0, get_balance(argv[1]));
	free(output);
}

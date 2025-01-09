#include <string.h>
#include <unistd.h>
#include <stdlib.h>
#include <ctype.h>

/* good idea for this one:
	1st write print set + check sum and test.
	when this is done working on the recursion is simpler */

void print_set(char *set)
{
	int i = 0;
	while (i < strlen(set))
	{
		if (isdigit(set[i]))
			write(1, &set[i], 1);
		i++;
	}
	write(1, "\n", 1);
}

int	check_sum(char *set, int sum)
{
	int i = 0;
	int total = 0;

	while (i < strlen(set))
	{
		if (isdigit(set[i]))
			total += set[i] - '0';
		i++;
	}
	if (total == sum)
		return 1;
	return 0;
}

void	get_sets(char *input, char *output, int pos, int sum)
{
	if (pos == strlen(input))
	{
		if (check_sum(output, sum))
			print_set(output);
		return ;
	}
	output[pos] = '_';
	get_sets(input, output, pos + 1, sum);
	output[pos] = input[pos];
	get_sets(input, output, pos + 1, sum);
}

int	main(int argc, char *argv[])
{
	if (argc != 2)
		return (1);

	// if (check_sum(argv[1], 5))
	// 	print_set(argv[1]);

	char *output;
	int sum;

	output = malloc(sizeof(char) * strlen(argv[1]) - 1);
	sum = argv[1][0] - '0';
	get_sets(argv[1] + 1, output, 0, sum); // +1 because i dont need the first one
	free(output);
	return (0);
}

#include <stdio.h>
#include <string.h>

void swap_letters(char *input, int a, int b)
{
	char temp;
	temp = input[a];
	input[a] = input[b];
	input[b] = temp;
}

void letter_to_front(char *input, int target_pos, int current_pos)
{
	int i = current_pos;

	while (i > target_pos)
	{
		swap_letters(input, i, i - 1);
		i--;
	}
}

void letter_to_back(char *input, int current_pos, int target_pos)
{
	int i = current_pos;

	while (i < target_pos)
	{
		swap_letters(input, i, i + 1);
		i++;
	}
}

int	find_min(char *input)
{
	int i = 0;
	int min = 0;

	while (input[i])
	{
		if (input[i] < input[min])
			min = i;
		i++;
	}
	return (min);
}

void sort_alpha(char *input)
{
	int i = 0;

	while (input[i])
	{
		letter_to_front(input, i, find_min(input + i) + i);
		i++;
	}
}

void permute(char *input, int pos, int end)
{
	if (pos == end)
	{
		printf("%s\n", input);
		return ;
	}
	int i = pos;
	while (i < end)
	{
		letter_to_front(input, pos, i);
		permute(input, pos + 1, end);
		letter_to_back(input, pos, i);
		i++;
	}
}

int main(int argc, char *argv[])
{
	if (argc != 2)
		return (1);

	sort_alpha(argv[1]);
	permute(argv[1], 0, strlen(argv[1]));
	return (0);
}

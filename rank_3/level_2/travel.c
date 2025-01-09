#include <stdio.h>
#include <math.h>
#include <float.h>

typedef struct {
	float	x;
	float	y;
} pair;

float	calculate_distance(pair *cities, int amount)
{
	int		i = 0;
	float	distance = 0;
	pair	diff;

	while (i < amount)
	{
		diff.x = cities[i].x - cities[(i + 1) % amount].x;
		diff.y = cities[i].y - cities[(i + 1) % amount].y;
		distance += sqrtf(diff.x * diff.x + diff.y * diff.y);
		i++;
	}
	return (distance);
}

void	swap_cities(pair *cities, int a, int b)
{
	pair temp;

	temp = cities[a];
	cities[a] = cities[b];
	cities[b] = temp;
}

void	travel(pair *cities, int pos, int total, float *shortest)
{
	if (pos == total)
	{
		if (calculate_distance(cities, total) < *shortest)
			*shortest = calculate_distance(cities, total);
		return ;
	}
	int i = pos;
	while (i < total)
	{
		swap_cities(cities, pos, i);
		travel(cities, pos + 1, total, shortest);
		swap_cities(cities, pos, i);
		i++;
	}
}

int	main(void)
{
	pair	cities[11]; // max cities in the subject?
	float	shortest = 10000000.0; // pointer, to pass the address and update
	int	n = 0; // to count cities as they are provided

	/* fscanf returns the number of things it matched to the format string
		we want 2 floats per city, so ideal return is 2.
		the matched floats are stored in the struct n.
		we go on until we can't match. */
	while (fscanf(stdin, "%f, %f\n", &cities[n].x, &cities[n].y) == 2)
		n++;
	n--;
	travel(cities, 0, n, &shortest);
	printf("%f\n", shortest);
	return (0);
}

from math import sqrt

shortest = 10000000000.6 # in C i can pass this as an argument because of pointer shit

def solve(cities: list[dict], pos: int, end: int):
	global shortest
	if pos == end:
		if calculate_distance(cities, end) < shortest:
			shortest = calculate_distance(cities, end)
		return
	i = pos
	while i < end:
		swap_cities(cities, pos, i)
		solve(cities, pos + 1, end)
		swap_cities(cities, pos, i)
		i += 1

def swap_cities(cities: list[dict], a: int, b: int):
	temp = cities[a]
	cities[a] = cities[b]
	cities[b] = temp

def calculate_distance(cities: list[dict], num_cities: int):
	i = 0
	distance = 0.0
	while i < num_cities:
		diff_x = cities[i]["x"] - cities[(i + 1) % num_cities]["x"]
		diff_y = cities[i]["y"] - cities[(i + 1) % num_cities]["y"]
		distance += sqrt(diff_x * diff_x + diff_y * diff_y)
		i += 1
	return distance

cities = [{"x": 1.0, "y": 1.0}, {"x": 0.0, "y": 0.0}, {"x": 1.0, "y": 0.0}, {"x": 0.0, "y": 1.0}]
solve(cities, 0, len(cities))
print(shortest)

#include <iostream>
#include <algorithm>

int Edge[3];

void Judge()
{
	if (Edge[0] + Edge[1] <= Edge[2])
	{
		std::cout << "Not triangle\n";
		return;
	}
	for (int i = 0; i < 3; i++)
		Edge[i] *= Edge[i];
	int sum = Edge[0] + Edge[1];
	if (sum == Edge[2])
		std::cout << "Right triangle\n";
	if (sum > Edge[2])
		std::cout << "Acute triangle\n";
	if (sum < Edge[2])
		std::cout << "Obtuse triangle\n";
	if (Edge[0] == Edge[1] || Edge[1] == Edge[2])
		std::cout << "Isosceles triangle\n";
	if (Edge[0] == Edge[2])
		std::cout << "Equilateral triangle\n";
}

int main()
{
	std::ios::sync_with_stdio(false);
	std::cin.tie(nullptr);

	std::cin >> Edge[0] >> Edge[1] >> Edge[2];
	std::sort(Edge, Edge + 3);
	Judge();

	return 0;
}
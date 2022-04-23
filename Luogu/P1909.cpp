#include <iostream>
#include <cmath>

int main()
{
	std::ios::sync_with_stdio(false);
	std::cin.tie(nullptr);

	int PencilNeed, MinCost = 0x7fffffff;
	std::cin >> PencilNeed;
	for (int i = 0; i < 3; i++)
	{
		int x, y;
		std::cin >> x >> y;
		int Cost = std::ceil((double)PencilNeed / x) * y;
		MinCost = std::min(Cost, MinCost);
	}
	std::cout << MinCost << '\n';

	return 0;
}
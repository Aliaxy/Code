#include <iostream>
#include <cmath>

double Rank, Exa, Blood;

int main()
{
	std::ios::sync_with_stdio(false);
	std::cin.tie(nullptr);
	int n;
	std::cin >> n;
	Blood = 10;
	while (n--)
	{
		double lose, get;
		std::cin >> lose >> get;
		Blood -= lose;
		if (Blood <= 0)
			break;
		if (Blood > 10)
			Blood = 10;
		Exa += get;
		while (Exa >= std::pow(2, Rank))
		{
			Exa -= std::pow(2, Rank);
			Rank++;
		}
	}
	std::cout << Rank << ' ' << Exa << '\n';

	return 0;
}
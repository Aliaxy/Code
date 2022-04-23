#include <iostream>
#include <cmath>

int Set[31];
long long Sum;

int main()
{
	std::ios::sync_with_stdio(false);
	std::cin.tie(nullptr);

	int Cnt = 0;
	while (std::cin >> Set[Cnt++])
		;
	for (int i = 0; i < Cnt; i++)
		Sum += Set[i];
	Sum *= std::pow(2, Cnt - 2);
	std::cout << Sum << '\n';

	return 0;
}
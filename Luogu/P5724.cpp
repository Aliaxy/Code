#include <iostream>
#include <algorithm>

int Num[100];

int main()
{
	std::ios::sync_with_stdio(false);
	std::cin.tie(nullptr);

	int n;
	std::cin >> n;
	for (int i = 0; i < n; i++)
		std::cin >> Num[i];
	std::sort(Num, Num + n);
	std::cout << Num[n - 1] - Num[0] << '\n';

	return 0;
}
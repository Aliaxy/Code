#include <iostream>

int People[1000];

int main()
{
	std::ios::sync_with_stdio(false);
	std::cin.tie(nullptr);

	int Num, PageNum;
	std::cin >> Num >> PageNum;
	for (int i = 0; i < PageNum; i++)
	{
		int x;
		std::cin >> x;
		People[x]++;
	}
	for (int i = 0; i <= Num; i++)
		while (People[i]--)
			std::cout << i << ' ';

	return 0;
}
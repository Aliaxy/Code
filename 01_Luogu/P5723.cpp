#include <iostream>
#include <vector>

int Visit[10000], L;
std::vector<int> Prime;

void GetPrime()
{
	Prime.push_back(0);
	for (int i = 2;; i++)
	{
		if (!Visit[i])
		{
			L -= i;
			if (L >= 0)
			{
				Prime.push_back(i);
				std::cout << i << '\n';
			}
			else
			{
				std::cout << Prime.size() - 1 << '\n';
				return;
			}
		}
		for (int j = 1; i * Prime[j] < 10000; j++)
		{
			Visit[i * Prime[j]] = 1;
			if (i % Prime[j] == 0)
				break;
		}
	}
}

int main()
{
	std::ios::sync_with_stdio(false);
	std::cin.tie(nullptr);

	std::cin >> L;
	GetPrime();

	return 0;
}
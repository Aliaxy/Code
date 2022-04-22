#include <iostream>
#include <vector>

const int MAX = 1e7 + 1;

int a, n, Visit[MAX], tot;
std::vector<int> Prime;

bool Judge(int n)
{
	int temp = n, sum = 0;
	while (temp)
	{
		sum = sum * 10 + temp % 10;
		temp /= 10;
	}
	return sum == n;
}

void GetPrime()
{
	Prime.push_back(0);
	for (int i = 2; i <= n; i++)
	{
		if (!Visit[i])
		{
			Prime.push_back(i);
			if (i >= a && !tot)
				tot = Prime.size() - 1;
		}
		for (int j = 1; j <= Prime.size() && i * Prime[j] <= n; j++)
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

	std::cin >> a >> n;
	if (n > 10000000)
		n = 10000000;
	GetPrime();
	for (int i = tot; i < Prime.size(); i++)
		if (Judge(Prime[i]))
			std::cout << Prime[i] << '\n';

	return 0;
}
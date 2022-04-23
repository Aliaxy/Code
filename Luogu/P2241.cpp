#include <iostream>
#include <algorithm>

int main()
{
	std::ios::sync_with_stdio(false);
	std::cin.tie(nullptr);

	int n, m;
	long long sum1 = 0, sum2 = 0;
	std::cin >> n >> m;
	for (int i = 1; i <= n; i++)
	{
		for (int j = 1; j <= m; j++)
		{
			sum1 += std::min(i, j);
			sum2 += (long long)i * j;
		}
	}
	std::cout << sum1 << ' ' << sum2 - sum1 << '\n';

	return 0;
}
#include <iostream>

int main()
{
	std::ios::sync_with_stdio(false);
	std::cin.tie(nullptr);

	int n, x, cnt = 0;
	std::cin >> n >> x;
	for (int i = 1; i <= n; i++)
	{
		int temp = i;
		while (temp)
		{
			if (temp % 10 == x)
				cnt++;
			temp /= 10;
		}
	}
	std::cout << cnt << '\n';

	return 0;
}
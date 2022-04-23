#include <iostream>
#include <algorithm>

const int MAX = 2e7;

int a[MAX];

int main()
{
	std::ios::sync_with_stdio(false);
	std::cin.tie(nullptr);
	int n, ans = 0;
	std::cin >> n;
	for (int i = 0; i < n; i++)
		std::cin >> a[i];
	std::sort(a, a + n);
	ans += a[0] * 6 + 6;
	for (int i = 0; i < n - 1; i++)
	{
		int flag = a[i + 1] - a[i];
		if (flag == 0)
			ans += 1;
		else
			ans += (flag * 6 + 6);
	}
	ans += a[n - 1] * 4;
	std::cout << ans << '\n';

	return 0;
}
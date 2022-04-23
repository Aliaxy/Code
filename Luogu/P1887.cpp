#include <iostream>

int main()
{
	std::ios::sync_with_stdio(false);
	std::cin.tie(nullptr);
	int n, m, ans;
	std::cin >> n >> m;
	int a = n % m;
	ans = n / m;
	for (int i = a; i < m; i++)
		std::cout << ans << ' ';
	for (int i = 0; i < a; i++)
		std::cout << ans + 1 << ' ';

	return 0;
}
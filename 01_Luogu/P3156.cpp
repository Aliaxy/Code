#include <iostream>

const int MAX = 2e6 + 1;

int a[MAX];

int main()
{
	std::ios::sync_with_stdio(false);
	std::cin.tie(nullptr), std::cout.tie(nullptr);

	int n, m;
	std::cin >> n >> m;
	for (int i = 1; i <= n; i++) std::cin >> a[i];
	while (m--)
	{
		int x;
		std::cin >> x;
		std::cout << a[x] << '\n';
	}

	return 0;
}
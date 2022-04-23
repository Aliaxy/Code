#include <iostream>

int Map[101][101], cnt[101][101];

int main()
{
	std::ios::sync_with_stdio(false);
	std::cin.tie(nullptr);
	int n, m, x, y;
	std::cin >> n >> m >> x >> y;
	for (int k = 0; k < x; k++)
	{
		int a, b, c, d;
		std::cin >> a >> b >> c >> d;
		for (int i = a; i <= c; i++)
			for (int j = b; j <= d; j++)
			{
				Map[i][j] = k + 1;
				cnt[i][j]++;
			}
	}
	while (y--)
	{
		int a, b;
		std::cin >> a >> b;
		if (Map[a][b])
			std::cout << "Y " << cnt[a][b] << ' ' << Map[a][b] << '\n';
		else
			std::cout << "N\n";
	}

	return 0;
}
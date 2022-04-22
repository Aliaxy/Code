#include <algorithm>
#include <cctype>
#include <cmath>
#include <cstdio>
#include <cstring>
#include <iostream>
#include <string>

const int dxFour[] = {-1, 0, 1, 0};
const int dyFour[] = {0, 1, 0, -1};

const int dxEight[] = {-1, 0, 1, 0, -1, -1, 1, 1};
const int dyEight[] = {0, 1, 0, -1, -1, 1, -1, 1};

const int dxHorse[] = {-2, -2, -1, -1, 1, 1, 2, 2};
const int dyHorse[] = {1, -1, 2, -2, 2, -2, 1, -1};

const int INF = 0x3f3f3f3f;
const double PI = std::acos(-1.0);
const double EPS = 1e-9;

inline int read()
{
	int x = 0, f = 1;
	char c = getchar();
	while (c < '0' || c > '9')
	{
		if (c == '-')
			f = -1;
		c = getchar();
	}
	while (c >= '0' && c <= '9')
	{
		x = (x << 3) + (x << 1) + (c ^ 48);
		c = getchar();
	}
	return x * f;
}

inline void write(int x)
{
	if (x < 0)
		putchar('-'), x = -x;
	if (x > 9)
		write(x / 10);
	putchar(x % 10 + '0');
}

inline void max(int &a, int b) { a < b ? a = b : 0; }
inline void min(int &a, int b) { a > b ? a = b : 0; }

// #include <vector>
// #include <map>
// #include <unordered_map>
// #include <set>
// #include <queue>
// #include <deque>
// #include <functional>
// #include <bitset>

int n, m, ans;
char farm[100][100];

inline bool Judge(int x, int y)
{
	if (x < 0 || x >= n || y < 0 || y >= m || farm[x][y] != 'W') return false;
	return true;
}

void DFS(int x, int y)
{
	farm[x][y] = '.';
	for (int i = 0; i < 8; i++)
	{
		int nextX = x + dxEight[i], nextY = y + dyEight[i];
		if (Judge(nextX, nextY))
			DFS(nextX, nextY);
	}
}

int main()
{
	// std::ios::sync_with_stdio(false);
	// std::cin.tie(nullptr), std::cout.tie(nullptr);

	n = read(), m = read();
	for (int i = 0; i < n; i++) std::cin >> farm[i];
	for (int i = 0; i < n; i++)
		for (int j = 0; j < m; j++)
			if (farm[i][j] == 'W')
			{
				DFS(i, j);
				ans++;
			}
	write(ans);

	return 0;
}
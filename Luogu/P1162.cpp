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
#include <queue>
// #include <deque>
// #include <functional>
// #include <bitset>

int n, marix[32][32];

inline bool Judge(int x, int y)
{
	if (x < 0 || y < 0 || x > n + 1 || y > n + 1 || marix[x][y]) return false;
	return true;
}

void BFS()
{
	std::queue<std::pair<int, int>> qu;
	qu.push(std::pair<int, int>(0, 0));
	while (!qu.empty())
	{
		std::pair<int, int> now = qu.front();
		qu.pop();
		marix[now.first][now.second] = 2;
		for (int i = 0; i < 4; i++)
		{
			std::pair<int, int> next;
			next.first = now.first + dxFour[i];
			next.second = now.second + dyFour[i];
			if (Judge(next.first, next.second)) qu.push(next);
		}
	}
}

int main()
{
	// std::ios::sync_with_stdio(false);
	// std::cin.tie(nullptr), std::cout.tie(nullptr);

	n = read();
	for (int i = 1; i <= n; i++)
		for (int j = 1; j <= n; j++) marix[i][j] = read();
	BFS();
	for (int i = 1; i <= n; i++)
	{
		for (int j = 1; j <= n; j++)
			write(2 - marix[i][j]), putchar(' ');
		putchar('\n');
	}

	return 0;
}
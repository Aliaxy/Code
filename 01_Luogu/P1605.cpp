#include <algorithm>
#include <cctype>
#include <cmath>
#include <cstdio>
#include <cstring>
#include <iostream>
#include <string>

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
#include <map>
// #include <set>
// #include <queue>
// #include <deque>
// #include <functional>
// #include <bitset>

const int MAX = 5e5 + 1;

int move[4][2] = {1, 0, -1, 0, 0, -1, 0, 1};
int n, m, t, maze[6][6];
int stX, stY, edX, edY, sumRoute;

void DFS(int x, int y)
{
	if (x < 1 || x > n || y < 1 || y > m || maze[x][y]) return;
	if (x == edX && y == edY)
	{
		sumRoute++;
		return;
	}
	maze[x][y] = 1;
	for (int i = 0; i < 4; i++) DFS(x + move[i][0], y + move[i][1]);
	maze[x][y] = 0;
}

int main()
{
	// std::ios::sync_with_stdio(false);
	// std::cin.tie(nullptr), std::cout.tie(nullptr);

	n = read(), m = read(), t = read();
	stX = read(), stY = read(), edX = read(), edY = read();
	while (t--)
	{
		int x = read(), y = read();
		maze[x][y] = 1;
	}
	DFS(stX, stY);

	write(sumRoute);

	return 0;
}
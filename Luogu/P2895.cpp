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
// #include <map>
// #include <set>
#include <queue>
// #include <deque>
// #include <functional>
// #include <bitset>

const int MAX = 302, INF = 0x3f3f3f3f;

int move[5][2] = {0, 0, 1, 0, -1, 0, 0, 1, 0, -1};
int n, farm[MAX][MAX];
bool vis[MAX][MAX];

struct point
{
	int x, y, t;
};

int f(int t) { return t == -1 ? INF : t; }

inline bool Judge(int x, int y, int t)
{
	if (x < 0 || y < 0 || vis[x][y] || f(farm[x][y]) <= t) return false;
	return true;
}

void BFS()
{
	std::queue<point> qu;
	qu.push({0, 0, 0});
	vis[0][0] = true;
	while (!qu.empty())
	{
		point now = qu.front();
		qu.pop();
		if (farm[now.x][now.y] == -1)
		{
			write(now.t);
			return;
		}
		for (int i = 1; i < 5; i++)
		{
			point next = now;
			next.x += move[i][0], next.y += move[i][1];
			if (Judge(next.x, next.y, next.t + 1))
			{
				vis[next.x][next.y] = true;
				next.t++;
				qu.push(next);
			}
		}
	}
	write(-1);
}

int main()
{
	// std::ios::sync_with_stdio(false);
	// std::cin.tie(nullptr), std::cout.tie(nullptr);

	n = read();
	std::memset(farm, -1, sizeof(farm));
	for (int i = 0; i < n; i++)
	{
		int x = read(), y = read(), t = read();
		for (int j = 0; j < 5; j++)
		{
			int xx = x + move[j][0], yy = y + move[j][1];
			if (xx >= 0 && yy >= 0 && (farm[xx][yy] == -1 || farm[xx][yy] > t))
				farm[xx][yy] = t;
		}
	}

	BFS();

	return 0;
}
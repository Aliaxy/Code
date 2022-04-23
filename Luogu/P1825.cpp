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

int n, m;
char farm[300][300];
bool vis[300][300];
int stX, stY;
struct node
{
	int x, y, t;
};

void TP(int &x, int &y, int t)
{
	for (int i = 0; i < n; i++)
		for (int j = 0; j < m; j++)
			if (farm[i][j] == farm[x][y] && (i != x || j != y))
			{
				x = i, y = j;
				return;
			}
}

inline bool Judge(int x, int y)
{
	if (x < 0 || y < 0 || x > n || y > m || farm[x][y] == '#' || vis[x][y]) return false;
	return true;
}

void BFS()
{
	std::queue<node> qu;
	qu.push({stX, stY, 0});
	vis[stX][stY] = 1;
	while (!qu.empty())
	{
		node now = qu.front();
		qu.pop();
		if (farm[now.x][now.y] == '=')
		{
			std::cout << now.t;
			return;
		}
		if (isupper(farm[now.x][now.y])) TP(now.x, now.y, now.t);
		for (int i = 0; i < 4; i++)
		{
			node next = now;
			next.x += dxFour[i], next.y += dyFour[i];
			if (Judge(next.x, next.y))
			{
				next.t += 1;
				vis[next.x][next.y] = true;
				qu.push(next);
			}
		}
	}
}

int main()
{
	std::ios::sync_with_stdio(false);
	std::cin.tie(nullptr), std::cout.tie(nullptr);

	std::cin >> n >> m;
	for (int i = 0; i < n; i++)
		for (int j = 0; j < m; j++)
		{
			std::cin >> farm[i][j];
			if (farm[i][j] == '@') stX = i, stY = j;
		}

	BFS();

	return 0;
}
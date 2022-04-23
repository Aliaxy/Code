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

const int MAX = 401;
const int move[8][2] = {2, 1, 2, -1, 1, 2, 1, -2, -1, -2, -1, 2, -2, -1, -2, 1};
int n, m, xStart, yStart, board[MAX][MAX];
bool vis[MAX][MAX];
struct node
{
	int x, y;
};

inline bool Judge(int x, int y)
{
	if (x < 1 || x > n || y < 1 || y > m || vis[x][y]) return false;
	return true;
}

void BFS()
{
	std::queue<node> qu;
	vis[xStart][yStart] = true, board[xStart][yStart] = 0;
	qu.push({xStart, yStart});
	while (!qu.empty())
	{
		node now = qu.front();
		qu.pop();
		for (int i = 0; i < 8; i++)
		{
			node next = now;
			next.x += move[i][0], next.y += move[i][1];
			if (Judge(next.x, next.y))
			{
				vis[next.x][next.y] = true;
				board[next.x][next.y] = board[now.x][now.y] + 1;
				qu.push(next);
			}
		}
	}
}

int main()
{
	// std::ios::sync_with_stdio(false);
	// std::cin.tie(nullptr), std::cout.tie(nullptr);
	n = read(), m = read(), xStart = read(), yStart = read();
	std::memset(board, -1, sizeof(board));
	BFS();

	for (int i = 1; i <= n; i++)
	{
		for (int j = 1; j <= m; j++)
			printf("%-5d", board[i][j]);
		putchar('\n');
	}

	return 0;
}
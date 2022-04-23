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

const int MAX = 201;

int n, m, start, end, step[MAX], move[MAX];
bool vis[MAX];

inline bool Judge(int x)
{
	if (x < 1 || x > n || vis[x]) return false;
	return true;
}

void BFS()
{
	std::queue<int> qu;
	qu.push(start);
	vis[start] = true, step[start] = 0;
	while (!qu.empty())
	{
		int now = qu.front();
		qu.pop();
		if (now == end)
		{
			write(step[now]);
			return;
		}
		int next = now + move[now];
		if (Judge(next))
		{
			qu.push(next);
			vis[next] = true;
			step[next] = step[now] + 1;
		}
		next = now - move[now];
		if (Judge(next))
		{
			qu.push(next);
			vis[next] = true;
			step[next] = step[now] + 1;
		}
	}
	write(-1);
}
int ans = 0x7fffffff;
void DFS(int now, int cnt)
{
	if (now == end) min(ans, cnt);
	if (cnt > ans) return;
	vis[now] = 1;
	if (now + move[now] <= n && !vis[now + move[now]]) DFS(now + move[now], cnt + 1);
	if (now - move[now] > 0 && !vis[now - move[now]]) DFS(now - move[now], cnt + 1);
	vis[now] = 0;
}

int main()
{
	// std::ios::sync_with_stdio(false);
	// std::cin.tie(nullptr), std::cout.tie(nullptr);

	n = read(), start = read(), end = read();
	for (int i = 1; i <= n; i++) move[i] = read();
	std::memset(step, -1, sizeof(step));

	// BFS();
	DFS(start, 0);
	if (ans != 0x7fffffff)
		write(ans);
	else
		write(-1);

	return 0;
}
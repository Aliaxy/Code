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
// #include <queue>
// #include <deque>
// #include <functional>
// #include <bitset>

int n, ans[15], cnt;
bool vis[3][50];

void Dfs(int cur)
{
	if (cur == n)
	{
		if (cnt < 3)
		{
			for (int i = 0; i < n; i++) write(ans[i]), putchar(' ');
			putchar('\n');
		}
		cnt++;
		return;
	}
	for (int i = 1; i <= n; i++)
	{
		if (!vis[0][i] && !vis[1][cur + i] && !vis[2][cur - i + n])
		{
			ans[cur] = i;
			vis[0][i] = vis[1][cur + i] = vis[2][cur - i + n] = 1;
			Dfs(cur + 1);
			vis[0][i] = vis[1][cur + i] = vis[2][cur - i + n] = 0;
		}
	}
}

int main()
{
	// std::ios::sync_with_stdio(false);
	// std::cin.tie(nullptr), std::cout.tie(nullptr);

	n = read();
	Dfs(0);
	write(cnt);
	return 0;
}
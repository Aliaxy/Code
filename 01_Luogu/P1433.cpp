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

int n;
double x[20], y[20], dp[65000][20];
bool vis[20];
double ans = 0x3f3f3f3f;

inline double f(int a, int b) { return std::sqrt((x[a] - x[b]) * (x[a] - x[b]) + (y[a] - y[b]) * (y[a] - y[b])); }

void DFS(int t, int now, double s, double bit)
{
	if (s > ans) return;
	if (t == n)
	{
		ans = std::min(ans, s);
		return;
	}
	for (int i = 1; i <= n; i++)
	{
		if (!vis[i])
		{
			int p = bit + (1 << (i - 1));
			if (dp[p][i] != 0 && dp[p][i] <= s + f(now, i)) continue;
			vis[i] = 1;
			dp[p][i] = s + f(now, i);
			DFS(t + 1, i, dp[p][i], p);
			vis[i] = 0;
		}
	}
}
int main()
{
	// std::ios::sync_with_stdio(false);
	// std::cin.tie(nullptr), std::cout.tie(nullptr);

	n = read();
	for (int i = 1; i <= n; i++) std::cin >> x[i] >> y[i];

	DFS(0, 0, 0, 0);

	printf("%.2f", ans);

	return 0;
}
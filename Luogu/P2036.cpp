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

// #include <vector>
// #include <map>
// #include <set>
// #include <queue>
// #include <deque>
// #include <functional>
// #include <bitset>

int n, s[10], b[10], ans = 0x3f3f3f3f;

void dfs(int now, int x, int y)
{
	if (now == n)
	{
		if (x == 1 && y == 0) return;
		ans = std::min(std::abs(x - y), ans);
		return;
	}
	dfs(now + 1, x * s[now], y + b[now]);
	dfs(now + 1, x, y);
}

int main()
{
	n = read();
	for (int i = 0; i < n; i++) s[i] = read(), b[i] = read();
	dfs(0, 1, 0);

	write(ans);

	return 0;
}
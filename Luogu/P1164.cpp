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

int n, m, a[101], f[101][10001];

int main()
{
	n = read(), m = read();
	for (int i = 1; i <= n; i++) a[i] = read();

	for (int i = 1; i <= n; i++)
		for (int j = 1; j <= m; j++)
		{
			if (j == a[i]) f[i][j] = f[i - 1][j] + 1;
			if (j > a[i]) f[i][j] = f[i - 1][j] + f[i - 1][j - a[i]];
			if (j < a[i]) f[i][j] = f[i - 1][j];
		}
	write(f[n][m]);

	return 0;
}
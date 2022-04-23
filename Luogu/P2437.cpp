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

int f[1001][1001], len;

int main()
{
	int m = read(), n = read();
	f[0][1] = f[1][1] = 1;
	len = 1;
	for (int i = 2; i <= n - m; i++)
	{
		for (int j = 1; j <= len; j++) f[i][j] = f[i - 1][j] + f[i - 2][j];
		for (int j = 1; j <= len; j++)
			if (f[i][j] > 9)
			{
				f[i][j + 1] += f[i][j] / 10;
				f[i][j] %= 10;
				if (f[i][len + 1]) len++;
			}
	}
	for (int i = len; i; i--) write(f[n - m][i]);

	return 0;
}
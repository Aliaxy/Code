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

inline void write(long long x)
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

int n;
long long f[20][20];

long long dfs(int i, int j)
{
	long long &F = f[i][j];
	if (F) return F;
	if (i == 0) return 1;
	if (j > 0) f[i][j] += dfs(i, j - 1);
	f[i][j] += dfs(i - 1, j + 1);
	return F;
}

int main()
{
	n = read();
	write(dfs(n, 0));

	return 0;
}
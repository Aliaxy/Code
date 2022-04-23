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

const int MAX = 1e6 + 1, MOD = 1e4;

int n, f[MAX], sum[MAX];

int main()
{
	n = read();
	f[1] = sum[1] = 2;
	f[2] = 2, sum[2] = 4;
	f[3] = 5, sum[3] = 9;
	for (int i = 4; i <= n; i++)
	{
		f[i] = (sum[i - 1] + sum[i - 3]) % MOD;
		sum[i] = (sum[i - 1] + f[i]) % MOD;
	}
	write(f[n]);

	return 0;
}
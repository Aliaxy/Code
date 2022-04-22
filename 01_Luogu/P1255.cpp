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

int n, len, fibo[5001][5001];

int main()
{
	n = read();
	fibo[0][1] = fibo[1][1] = 1;
	len = 1;
	for (int i = 2; i <= n; i++)
	{
		for (int j = 1; j <= len; j++) fibo[i][j] = fibo[i - 1][j] + fibo[i - 2][j];
		for (int j = 1; j <= len; j++)
			if (fibo[i][j] > 9)
			{
				fibo[i][j + 1] += fibo[i][j] / 10;
				fibo[i][j] %= 10;
				if (fibo[i][len + 1]) len++;
			}
	}
	for (int i = len; i; i--) write(fibo[n][i]);

	return 0;
}
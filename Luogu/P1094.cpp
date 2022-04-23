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
		if (c == '-') f = -1;
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
	if (x < 0) putchar('-'), x = -x;
	if (x > 9) write(x / 10);
	putchar(x % 10 + '0');
}

// #include <vector>
// #include <map>
// #include <set>
// #include <queue>
// #include <deque>
// #include <functional>
// #include <bitset>

const int MAX = 3e4;

int Price[MAX];

int main()
{
	int w = read(), n = read();
	for (int i = 0; i < n; i++) Price[i] = read();
	std::sort(Price, Price + n);
	int l = 0, r = n - 1, ans = 0;
	while (l <= r)
	{
		if (Price[l] + Price[r] <= w) l++;
		r--, ans++;
	}
	write(ans);

	return 0;
}
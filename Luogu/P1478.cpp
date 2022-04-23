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

const int MAX = 5e3;

int n, s, a, b, ans;

struct Node
{
	int Height, Cost;
	bool operator<(const Node &x) const { return Cost < x.Cost; }
} Apple[MAX];

int main()
{
	n = read(), s = read();
	a = read(), b = read();
	a += b;
	for (int i = 0; i < n; i++) Apple[i].Height = read(), Apple[i].Cost = read();
	std::sort(Apple, Apple + n);
	for (int i = 0; i < n; i++)
	{
		if (a < Apple[i].Height) continue;
		if (s < Apple[i].Cost) break;
		ans++, s -= Apple[i].Cost;
	}
	write(ans);

	return 0;
}
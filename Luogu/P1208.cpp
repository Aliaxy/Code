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

struct Node
{
	int Price, Sum;
	bool operator<(const Node &x) const { return Price < x.Price; }
} Farm[MAX];

int main()
{
	int n = read(), m = read(), cost = 0;
	for (int i = 0; i < m; i++) Farm[i].Price = read(), Farm[i].Sum = read();
	std::sort(Farm, Farm + m);
	for (int i = 0; i < m; i++)
	{
		if (n < Farm[i].Sum)
		{
			cost += n * Farm[i].Price;
			break;
		}
		cost += Farm[i].Price * Farm[i].Sum;
		n -= Farm[i].Sum;
	}
	write(cost);
	return 0;
}
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

struct Node
{
	int Weight, Value;
} Pile[100];

bool Cmp(Node x, Node y) { return x.Value * y.Weight > x.Weight * y.Value; }

int main()
{
	int PileNum = read(), BagSize = read();
	double ans = 0.0;
	for (int i = 0; i < PileNum; i++) Pile[i].Weight = read(), Pile[i].Value = read();
	std::sort(Pile, Pile + PileNum, Cmp);
	for (int i = 0; i < PileNum; i++)
	{
		if (BagSize > Pile[i].Weight)
			ans += Pile[i].Value, BagSize -= Pile[i].Weight;
		else
		{
			ans += (double) Pile[i].Value / Pile[i].Weight * BagSize;
			break;
		}
	}
	printf("%.2f\n", ans);

	return 0;
}
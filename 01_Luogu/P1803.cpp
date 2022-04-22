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

const int MAX = 1e6;

struct Node
{
	int st, ed;
} Battle[MAX];

inline bool Cmp(Node x, Node y) { return x.ed < y.ed; }

int main()
{
	int n = read();
	for (int i = 0; i < n; i++) Battle[i].st = read(), Battle[i].ed = read();
	std::sort(Battle, Battle + n, Cmp);
	int temp = Battle[0].ed, cnt = 1;
	for (int i = 1; i < n; i++)
		if (Battle[i].st >= temp) cnt++, temp = Battle[i].ed;
	write(cnt);

	return 0;
}
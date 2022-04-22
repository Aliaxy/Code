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

const int MAX = 1e3 + 1;

struct Node
{
	int ID, Time;
} Person[MAX];

inline bool Cmp(Node x, Node y) { return x.Time < y.Time; }

int main()
{
	int n = read();
	for (int i = 0; i < n; i++) Person[i].Time = read(), Person[i].ID = i + 1;

	std::sort(Person, Person + n, Cmp);
	double ans = 0.0;
	for (int i = 0; i < n; i++)
	{
		std::cout << Person[i].ID << ' ';
		ans += Person[i].Time * (n - i - 1);
	}
	printf("\n%.2f", ans / n);

	return 0;
}
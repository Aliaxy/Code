#include <algorithm>
#include <cctype>
#include <cmath>
#include <cstdio>
#include <cstring>
#include <iomanip>
#include <iostream>
#include <string>

using namespace std;

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

int n, Visit[100], a[100];

void print()
{
	for (int i = 1; i <= n; i++) printf("%5d", a[i]);
	cout << '\n';
}

void dfs(int k)
{
	if (k == n)
	{
		print();
		return;
	}
	for (int i = 1; i <= n; i++)
	{
		if (!Visit[i])
		{
			Visit[i] = 1;
			a[k + 1] = i;
			dfs(k + 1);
			Visit[i] = 0;
		}
	}
}

int main()
{
	n = read();
	dfs(0);

	return 0;
}
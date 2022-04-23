#include <algorithm>
#include <cctype>
#include <cmath>
#include <cstdio>
#include <cstring>
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

int n, m, a[10001], flag;
bool Visit[10001], p;

void dfs(int step)
{
	if (p)
		return;
	if (step > n)
	{
		flag++;
		if (flag == m + 1)
		{
			for (int i = 1; i <= n; i++)
			{
				write(a[i]);
				cout << ' ';
			}
			p = !p;
			return;
		}
	}
	for (int i = 1; i <= n; i++)
	{
		if (!flag) i = a[step];
		if (!Visit[i])
		{
			Visit[i] = 1;
			a[step] = i;
			dfs(step + 1);
			Visit[i] = 0;
		}
	}
}

int main()
{
	n = read(), m = read();
	for (int i = 1; i <= n; i++) a[i] = read();
	dfs(1);

	return 0;
}
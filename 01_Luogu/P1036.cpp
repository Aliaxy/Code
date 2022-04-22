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

int a[20], n, k, ans;

bool IsPrime(int x)
{
	int flag = sqrt(x);
	for (int i = 2; i <= flag; i++)
		if (x % i == 0) return false;
	return true;
}

void dfs(int m, int sum, int startx)
{
	if (m == k)
	{
		if (IsPrime(sum)) ans++;
		return;
	}
	for (int i = startx; i < n; i++) dfs(m + 1, sum + a[i], i + 1);
	return;
}

int main()
{
	n = read(), k = read();
	for (int i = 0; i < n; i++) a[i] = read();

	dfs(0, 0, 0);

	write(ans);

	return 0;
}
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

int n, r, a[100];

void dfs(int k)
{
	if (k > r)
	{
		for (int i = 1; i <= r; i++) cout << setw(3) << a[i];
		cout << '\n';
		return;
	}
	for (int i = a[k - 1] + 1; i <= n; i++)
	{
		a[k] = i;
		dfs(k + 1);
	}
}
int main()
{
	n = read(), r = read();
	dfs(1);

	return 0;
}
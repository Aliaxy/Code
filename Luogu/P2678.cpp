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

inline void max(int &a, int b) { a < b ? a = b : 0; }
inline void min(int &a, int b) { a > b ? a = b : 0; }

// #include <vector>
// #include <map>
// #include <set>
// #include <queue>
// #include <deque>
// #include <functional>
// #include <bitset>

const int MAX = 5e4 + 1;

int l, n, m, dis[MAX];

bool Judge(int x)
{
	int cnt = 0;
	int next = 0, now = 0;
	while (next++ < n + 1)
	{
		if (dis[next] - dis[now] < x)
			cnt++;
		else
			now = next;
	}
	if (cnt > m) return false;
	return true;
}

int main()
{
	// std::ios::sync_with_stdio(false);
	// std::cin.tie(nullptr), std::cout.tie(nullptr);

	l = read(), n = read(), m = read();
	for (int i = 1; i <= n; i++) dis[i] = read();
	dis[n + 1] = l;
	int left = 1, right = dis[n + 1], ans = 0;
	while (left <= right)
	{
		int mid = (left + right) >> 1;
		if (Judge(mid))
			ans = mid, left = mid + 1;
		else
			right = mid - 1;
	}
	write(ans);

	return 0;
}
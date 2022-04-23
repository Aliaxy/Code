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

const int MAX = 1e5 + 1;

int l, n, k, pos[MAX];

bool Judge(int x)
{
	int cnt = 0;
	for (int i = 0; i <= n; i++)
	{
		if (pos[i + 1] - pos[i] > x)
		{
			cnt += (pos[i + 1] - pos[i]) / x;
			if ((pos[i + 1] - pos[i]) % x == 0) cnt--;
		}
		if (cnt > k) return false;
	}
	return true;
}

int main()
{
	// std::ios::sync_with_stdio(false);
	// std::cin.tie(nullptr), std::cout.tie(nullptr);

	l = read(), n = read(), k = read();
	for (int i = 1; i <= n; i++) pos[i] = read();
	pos[n + 1] = l, pos[0] = 0;
	int left = 0, right = l, ans;
	while (left <= right)
	{
		int mid = (left + right) >> 1;
		if (Judge(mid))
			ans = mid, right = mid - 1;
		else
			left = mid + 1;
	}
	write(ans);
	return 0;
}
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

int n, m, a[MAX];

inline int Judge(int x)
{
	int sum = 0, cnt = 1;
	for (int i = 0; i < n; i++)
	{
		if (sum + a[i] <= x)
			sum += a[i];
		else
			sum = a[i], cnt++;
	}
	return cnt;
}

int main()
{
	// std::ios::sync_with_stdio(false);
	// std::cin.tie(nullptr), std::cout.tie(nullptr);

	n = read(), m = read();
	int left = 0, right = 0, ans;
	for (int i = 0; i < n; i++) a[i] = read(), max(left, a[i]), right += a[i];
	while (left <= right)
	{
		int mid = (left + right) >> 1;
		if (Judge(mid) <= m)
			right = mid - 1, ans = mid;
		else
			left = mid + 1;
	}
	write(ans);

	return 0;
}
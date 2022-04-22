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

const int MAX = 1e5;

int n, k, len[MAX];

int Judge(int x)
{
	if (x == 0) return 0;
	int ans = 0;
	for (int i = 0; i < n; i++)
		ans += len[i] / x;
	return ans;
}

int main()
{
	// std::ios::sync_with_stdio(false);
	// std::cin.tie(nullptr), std::cout.tie(nullptr);

	n = read(), k = read();
	for (int i = 0; i < n; i++) len[i] = read();

	int left = 0, right = 1e8;
	int ans = 0;
	while (left <= right)
	{
		int mid = (left + right) >> 1;
		if (Judge(mid) >= k)
			left = mid + 1, ans = mid;
		else
			right = mid - 1;
	}
	write(ans);
	return 0;
}
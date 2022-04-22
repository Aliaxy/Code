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

const int MAX = 1e6 + 1;

long long n, m, height[MAX];

long long Judge(long long val)
{
	long long sum = 0;
	for (int i = 0; i < n; i++)
		if (height[i] > val) sum += height[i] - val;
	return sum;
}

int main()
{
	// std::ios::sync_with_stdio(false);
	// std::cin.tie(nullptr), std::cout.tie(nullptr);

	std::cin >> n >> m;
	long long right = 0;
	for (int i = 0; i < n; i++) std::cin >> height[i], right = std::max(right, height[i]);

	long long ans = 0, left = 0;
	while (left <= right)
	{
		long long mid = (left + right) >> 1;
		if (Judge(mid) >= m)
			left = mid + 1, ans = mid;
		else
			right = mid - 1;
	}
	std::cout << ans;

	return 0;
}
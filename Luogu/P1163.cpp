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

double n, m, k;

inline bool Judge(double x)
{
	return (std::pow(1.0 / (1.0 + x), k) >= 1 - n / m * x);
}

int main()
{
	// std::ios::sync_with_stdio(false);
	// std::cin.tie(nullptr), std::cout.tie(nullptr);

	std::cin >> n >> m >> k;

	double left = 0, right = 10, ans;
	while (right - left >= 1e-5)
	{
		double mid = (left + right) / 2;
		if (Judge(mid))
			right = mid - 1e-6, ans = mid;
		else
			left = mid + 1e-6;
	}
	printf("%.1f", ans * 100);
	return 0;
}
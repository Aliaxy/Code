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

double n, p, a[MAX], b[MAX];

int Judge(double x)
{
	double temp = p * x, sum = 0;
	for (int i = 0; i < n; i++)
	{
		if (a[i] * x <= b[i]) continue;
		sum += a[i] * x - b[i];
	}
	return sum <= temp;
}

int main()
{
	// std::ios::sync_with_stdio(false);
	// std::cin.tie(nullptr), std::cout.tie(nullptr);

	std::cin >> n >> p;
	double sum = 0;
	for (int i = 0; i < n; i++) std::cin >> a[i] >> b[i], sum += a[i];
	if (sum <= p)
	{
		std::cout << -1.000000 << '\n';
		return 0;
	}
	double left = 0, right = 1e10, ans;
	while (right - left >= 1e-6)
	{
		double mid = (left + right) / 2;
		if (Judge(mid))
			left = mid + 1e-6, ans = mid;
		else
			right = mid - 1e-6;
	}
	std::cout << ans;
	return 0;
}
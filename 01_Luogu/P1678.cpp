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

int school[MAX];

int main()
{
	// std::ios::sync_with_stdio(false);
	// std::cin.tie(nullptr), std::cout.tie(nullptr);

	int m = read(), n = read();
	for (int i = 0; i < m; i++) school[i] = read();
	std::sort(school, school + m);
	long long sum = 0;
	for (int i = 0; i < n; i++)
	{
		int x = read();
		int temp = std::upper_bound(school, school + m, x) - school;
		if (temp == m)
			sum += x - school[temp - 1];
		else if (temp == 0)
			sum += school[temp] - x;
		else
			sum += std::min(school[temp] - x, x - school[temp - 1]);
	}
	std::cout << sum;

	return 0;
}
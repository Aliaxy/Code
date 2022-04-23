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

const int MAX = 301;

int Height[MAX];

int main()
{
	int n = read();
	for (int i = 1; i <= n; i++) Height[i] = read();

	std::sort(Height + 1, Height + n + 1);
	int l = 0, r = n;
	long long ans = 0;
	while (l < r)
	{
		ans += std::pow(Height[r] - Height[l], 2);
		l++;
		ans += std::pow(Height[r] - Height[l], 2);
		r--;
	}
	std::cout << ans;
	return 0;
}
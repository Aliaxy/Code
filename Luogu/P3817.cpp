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

int main()
{
	long long n, x, ans = 0, last;
	std::cin >> n >> x;
	std::cin >> last;
	if (last > x)
	{
		ans += last - x;
		last = x;
	}
	for (int i = 1; i < n; i++)
	{
		long long now;
		std::cin >> now;
		if (now + last > x)
		{
			ans += now + last - x;
			last = x - last;
		}
		else
			last = now;
	}
	std::cout << ans;
	return 0;
}
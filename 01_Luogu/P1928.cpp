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

// #include <vector>
// #include <map>
// #include <set>
// #include <queue>
// #include <deque>
// #include <functional>
// #include <bitset>

std::string solve()
{
	int cnt;
	char c;
	std::string str = "", ans = "";
	while (std::cin >> c)
	{
		if (c == '[')
		{
			std::cin >> cnt;
			str = solve();
			while (cnt--) ans += str;
		}
		else if (c == ']')
			return ans;
		else
			ans += c;
	}
}

int main()
{
	std::cout << solve();

	return 0;
}
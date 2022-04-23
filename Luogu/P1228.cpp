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

void Solve(int x, int y, int a, int b, int l)
{
	if (l == 1) return;
	if (x - a <= l / 2 - 1 && y - b <= l / 2 - 1)
	{
		std::cout << a + l / 2 << ' ' << b + l / 2 << " 1\n";
		Solve(x, y, a, b, l / 2);
		Solve(a + l / 2 - 1, b + l / 2, a, b + l / 2, l / 2);
		Solve(a + l / 2, b + l / 2 - 1, a + l / 2, b, l / 2);
		Solve(a + l / 2, b + l / 2, a + l / 2, b + l / 2, l / 2);
	}
	else if (x - a <= l / 2 - 1 && y - b > l / 2 - 1)
	{
		std::cout << a + l / 2 << ' ' << b + l / 2 - 1 << " 2\n";
		Solve(a + l / 2 - 1, b + l / 2 - 1, a, b, l / 2);
		Solve(x, y, a, b + l / 2, l / 2);
		Solve(a + l / 2, b + l / 2 - 1, a + l / 2, b, l / 2);
		Solve(a + l / 2, b + l / 2, a + l / 2, b + l / 2, l / 2);
	}
	else if (x - a > l / 2 - 1 && y - b <= l / 2 - 1)
	{
		std::cout << a + l / 2 - 1 << ' ' << b + l / 2 << " 3\n";
		Solve(a + l / 2 - 1, b + l / 2 - 1, a, b, l / 2);
		Solve(a + l / 2 - 1, b + l / 2, a, b + l / 2, l / 2);
		Solve(x, y, a + l / 2, b, l / 2);
		Solve(a + l / 2, b + l / 2, a + l / 2, b + l / 2, l / 2);
	}
	else
	{
		std::cout << a + l / 2 - 1 << ' ' << b + l / 2 - 1 << " 4\n";
		Solve(a + l / 2 - 1, b + l / 2 - 1, a, b, l / 2);
		Solve(a + l / 2 - 1, b + l / 2, a, b + l / 2, l / 2);
		Solve(a + l / 2, b + l / 2 - 1, a + l / 2, b, l / 2);
		Solve(x, y, a + l / 2, b + l / 2, l / 2);
	}
}

int main()
{
	int k = read(), x = read(), y = read();
	int len = 1 << k;
	Solve(x, y, 1, 1, len);

	return 0;
}
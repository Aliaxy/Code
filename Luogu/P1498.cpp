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

int a[1000];

int main()
{
	int n = read();
	a[0] = 1;
	for (int i = 0; i < 1 << n; i++)
	{
		for (int j = 1; j < (1 << n) - i; j++) std::cout << ' ';
		for (int j = i; ~j; j--) a[j] ^= a[j - 1];
		if (!(i & 1))
			for (int j = 0; j <= i; j++) std::cout << (a[j] ? "/\\" : "  ");
		else
			for (int j = 0; j <= i; j += 2) std::cout << (a[j] ? "/__\\" : "    ");
		std::cout << '\n';
	}

	return 0;
}
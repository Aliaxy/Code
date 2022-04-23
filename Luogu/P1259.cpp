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

char Chess[203];
int n, s;

void Print()
{
	for (int i = 1; i <= 2 * n + 2; i++) std::cout << Chess[i];
	std::cout << '\n';
}

void Initial()
{
	s = 2 * n + 1;
	for (int i = 1; i <= n; i++) Chess[i] = 'o';
	for (int i = n + 1; i <= 2 * n; i++) Chess[i] = '*';
	for (int i = 2 * n + 1; i <= 2 * n + 2; i++) Chess[i] = '-';
	Print();
}

void Span(int k)
{
	for (int i = 0; i <= 1; i++)
	{
		Chess[s + i] = Chess[k + i];
		Chess[k + i] = '-';
	}
	s = k;
	Print();
}

void solve(int k)
{
	if (k == 4)
	{
		Span(4);
		Span(8);
		Span(2);
		Span(7);
		Span(1);
	}
	else
	{
		Span(k);
		Span(2 * k - 1);
		solve(k - 1);
	}
}

int main()
{
	n = read();
	Initial();
	solve(n);

	return 0;
}
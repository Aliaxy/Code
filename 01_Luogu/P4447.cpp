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

const int MAX = 1e5 + 40;

int Power[MAX], f[MAX], top, Size[MAX];

int main()

{
	int n = read();
	for (int i = 1; i <= n; i++) Power[i] = read();
	std::sort(Power + 1, Power + n + 1);
	for (int i = 1; i <= n; i++)
	{
		int pos = std::lower_bound(f + 1, f + top + 1, Power[i]) - f;
		while (f[pos + 1] == Power[i] && pos < top) pos++;
		if (pos > top || f[pos] != Power[i])
			Size[++top] = 1, f[top] = Power[i] + 1;
		else
			Size[pos]++, f[pos]++;
	}
	int ans = 1e9;
	for (int i = 1; i <= top; i++) ans = std::min(ans, Size[i]);
	std::cout << ans;

	return 0;
}
#include <algorithm>
#include <cctype>
#include <cmath>
#include <cstdio>
#include <cstring>
#include <iostream>
#include <string>

using namespace std;

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

int n, m, w[51], b[51], r[51];

int main()
{
	n = read(), m = read();
	for (int i = 1; i <= n; i++)
		for (int j = 0; j < m; j++)
		{
			char c;
			cin >> c;
			if (c != 'W') w[i]++;
			if (c != 'B') b[i]++;
			if (c != 'R') r[i]++;
		}
	int ans = n * m, temp = 0, temp1 = 0;
	for (int i = 1; i <= n - 2; i++)
	{
		temp += w[i];
		for (int j = 1; j <= n - 2 && i + j <= n - 1; j++)
		{
			temp1 += b[i + j];
			int sum = 0;
			for (int k = i + j + 1; k <= n; k++)
				sum += r[k];
			if (sum + temp + temp1 < ans)
				ans = sum + temp + temp1;
		}
		temp1 = 0;
	}
	write(ans);

	return 0;
}
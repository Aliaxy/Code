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

int n[4], cost[20], dp[1201], ans, sum;

int main()
{
	for (int i = 0; i < 4; i++)
		n[i] = read();
	for (int i = 0; i < 4; i++)
	{
		std::memset(dp, 0, sizeof(dp));
		sum = 0;
		for (int j = 0; j < n[i]; j++)
		{
			cost[j] = read();
			sum += cost[j];
		}
		for (int j = 0; j < n[i]; j++)
			for (int k = sum / 2; k >= cost[j]; k--)
				dp[k] = std::max(dp[k], dp[k - cost[j]] + cost[j]);
		ans += sum - dp[sum / 2];
	}
	write(ans);

	return 0;
}
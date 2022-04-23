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

#define c1(a) (a)
#define c2(a) ((a) * ((a) -1) / 2)

const int MAX = 1e5 + 1, MOD = 1e9 + 7;
int n, a[MAX], len[5001];
long long ans;

int main()
{
	n = read();
	int MinLen = 5001, MaxLen = 0;
	for (int i = 1; i <= n; i++)
	{
		a[i] = read();
		MaxLen = std::max(MaxLen, a[i]);
		MinLen = std::min(MinLen, a[i]);
		len[a[i]]++;
	}
	for (int i = MinLen + 1; i <= MaxLen; i++)
	{
		for (int j = MinLen; j <= i / 2; j++)
		{
			int temp = i - j;
			if (temp != j && len[i] >= 2 && len[j] >= 1 && len[temp] >= 1)
				ans += ((c2(len[i]) % MOD) * (c1(len[j]) % MOD) * (c1(len[temp]) % MOD)) % MOD;
			else if (temp == j && len[i] >= 2 && len[j] >= 2)
				ans += ((c2(len[i]) % MOD) * (c2(len[j]) % MOD)) % MOD;
			ans %= MOD;
		}
	}
	write(ans);

	return 0;
}
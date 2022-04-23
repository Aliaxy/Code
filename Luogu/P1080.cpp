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

const int MAX = 1e3 + 1;

int n, lens, lenm, lena;
int sum[10010] = {0, 1}, maxn[10010] = {0, 1}, ans[10010];
struct Node
{
	long long l, r;
	bool operator<(const Node &x) const { return l * r < x.l * x.r; }
} Coin[MAX];

void muti(long long x)
{
	int temp = 0;
	for (int i = 1; i <= lens; i++) sum[i] *= x;
	for (int i = 1; i <= lens; i++)
	{
		temp += sum[i];
		sum[i] = temp % 10;
		temp /= 10;
	}
	while (temp)
	{
		lens++;
		sum[lens] = temp % 10;
		temp /= 10;
	}
}

void cut(long long x)
{
	std::memset(ans, 0, sizeof(ans));
	lena = lens;
	int tmp = 0;
	for (int i = lena; i >= 1; i--)
	{
		tmp *= 10;
		tmp += sum[i];
		if (tmp >= x)
		{
			ans[i] = tmp / x;
			tmp %= x;
		}
	}
	while (ans[lena] == 0)
	{
		if (lena == 1)
			break;
		lena--;
	}
}

void max()
{
	if (lena > lenm)
	{
		for (int i = 1; i <= lena; i++)
			maxn[i] = ans[i];
		lenm = lena;
	}
	else if (lena == lenm)
	{
		for (int i = lena; i >= 1; i--)
			if (maxn[i] < ans[i])
			{
				for (int j = 1; j <= lena; j++)
					maxn[j] = ans[j];
				lenm = lena;
				break;
			}
	}
}

int main()
{
	lens = lena = lenm = 1;
	n = read();
	std::cin >> Coin[0].l >> Coin[0].r;
	for (int i = 1; i <= n; i++) std::cin >> Coin[i].l >> Coin[i].r;
	std::sort(Coin + 1, Coin + n + 1);
	for (int i = 1; i <= n; i++)
	{
		muti(Coin[i - 1].l);
		cut(Coin[i].r);
		max();
	}
	for (int i = lenm; i; i--) std::cout << maxn[i];

	return 0;
}
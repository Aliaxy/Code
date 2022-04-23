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

int Order[400], step[20], LastTime[20], mac[21][100001], ans;
struct Info
{
	int ID, Time;
} a[20][20];

int main()
{
	// ios::sync_with_stdio(false);
	// cin.tie(nullptr), cout.tie(nullptr);

	int m = read(),
		n = read();
	for (int i = 1; i <= m * n; i++) Order[i] = read();
	for (int i = 1; i <= n; i++)
		for (int j = 1; j <= m; j++) a[i][j].ID = read();
	for (int i = 1; i <= n; i++)
		for (int j = 1; j <= m; j++) a[i][j].Time = read();

	for (int i = 1; i <= m * n; i++)
	{
		int now = Order[i];
		step[now]++;
		int id = a[now][step[now]].ID, cost = a[now][step[now]].Time, s = 0;
		for (int j = LastTime[now] + 1;; j++)
		{
			if (!mac[id][j])
				s++;
			else
				s = 0;
			if (s == cost)
			{
				for (int k = j - cost + 1; k <= j; k++) mac[id][k] = 1;
				if (j > ans) ans = j;
				LastTime[now] = j;
				break;
			}
		}
	}
	write(ans);

	return 0;
}
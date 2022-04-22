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

int r, c, k, ans;
char map[101][101];

int main()
{
	r = read(), c = read(), k = read();
	for (int i = 1; i <= r; i++)
		for (int j = 1; j <= c; j++) cin >> map[i][j];
	bool flag;
	for (int i = 1; i <= r; i++)
	{
		for (int j = 1; j <= c; j++)
		{
			flag = true;
			for (int s = 0; s < k; s++)
				if (map[i + s][j] != '.')
				{
					flag = false;
					break;
				}
			if (flag) ans++;
		}
	}

	for (int i = 1; i <= c; i++)
		for (int j = 1; j <= r; j++)
		{
			flag = true;
			for (int s = 0; s < k; s++)
				if (map[i][j + s] != '.')
				{
					flag = false;
					break;
				}
			if (flag) ans++;
		}
	if (k == 1) ans /= 2;
	write(ans);

	return 0;
}
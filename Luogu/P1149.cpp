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

int num[1001] = {6, 2, 5, 5, 4, 5, 6, 3, 7, 6};
int n, b[3], ans;

void search(int cnt)
{
	for (int i = 0; i < 1001; i++)
	{
		if (n - num[i] >= 0)
		{
			b[cnt] = i;
			n -= num[i];
			if (cnt == 2)
			{
				if (b[0] + b[1] == b[2] && n == 0) ans++;
			}
			else
				search(cnt + 1);
			n += num[i];
		}
	}
}

int main()
{
	n = read();
	n -= 4;
	for (int i = 10; i < 1001; i++) num[i] = num[i / 10] + num[i % 10];
	search(0);
	write(ans);

	return 0;
}
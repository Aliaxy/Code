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

#include <vector>
// #include <map>
// #include <set>
#include <queue>
// #include <deque>
// #include <functional>
// #include <bitset>

const int MAX = 1e4;

int Apple[MAX];
std::priority_queue<int, std::vector<int>, std::greater<int>> q;

int main()
{
	int Kind = read();
	for (int i = 0; i < Kind; i++)
	{
		int x = read();
		q.push(x);
	}
	int ans = 0;
	while (q.size() >= 2)
	{
		int a = q.top();
		q.pop();
		int b = q.top();
		q.pop();
		ans += a + b;
		q.push(a + b);
	}
	write(ans);

	return 0;
}
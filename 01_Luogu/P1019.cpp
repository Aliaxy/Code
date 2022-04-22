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

inline void max(int &a, int b) { a < b ? a = b : 0; }
inline void min(int &a, int b) { a > b ? a = b : 0; }

// #include <vector>
// #include <map>
// #include <set>
// #include <queue>
// #include <deque>
// #include <functional>
// #include <bitset>

std::string str[21];
int n, maxLen;
int vis[20];

int IsLink(std::string str1, std::string str2)
{
	int len = std::min(str1.size(), str2.size());
	for (int i = 1; i < len; i++)
	{
		int flag = 1;
		for (int j = 0; j < i; j++)
			if (str1[str1.length() - i + j] != str2[j]) flag = 0; //逐个检测是否相等
		if (flag) return i;										  //检测完毕相等则立即return
	}
	return 0;
}

void DFS(std::string now, int len)
{
	max(maxLen, len);
	for (int i = 0; i < n; i++)
	{
		if (vis[i] >= 2) continue;
		int state = IsLink(now, str[i]);
		if (state)
		{
			vis[i]++;
			DFS(str[i], len + str[i].size() - state);
			vis[i]--;
		}
	}
}

int main()
{
	// std::ios::sync_with_stdio(false);
	// std::cin.tie(nullptr), std::cout.tie(nullptr);

	n = read();
	for (int i = 0; i <= n; i++) std::cin >> str[i];

	DFS(' ' + str[n], 1);

	write(maxLen);

	return 0;
}
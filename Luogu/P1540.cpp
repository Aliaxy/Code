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

inline void max(int &a, int b) { a < b ? a = b : 0; }
inline void min(int &a, int b) { a > b ? a = b : 0; }

#include <vector>
// #include <map>
// #include <unordered_map>
// #include <set>
// #include <queue>
// #include <deque>
// #include <functional>
// #include <bitset>

std::vector<int> v;

int main()
{
	// std::ios::sync_with_stdio(false);
	// std::cin.tie(nullptr), std::cout.tie(nullptr);

	int m = read(), n = read(), ans = 0;
	for (int i = 0; i < n; i++)
	{
		int x = read();
		if (std::find(v.begin(), v.end(), x) == v.end()) v.push_back(x), ans++;
		if (v.size() > m) v.erase(v.begin());
	}
	write(ans);

	return 0;
}
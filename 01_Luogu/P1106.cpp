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

std::string str;
int k;

int main()
{
	std::cin >> str >> k;
	str += '0';
	int len = str.size();
	while (k--)
	{
		for (int i = 0; i <= len - 2; i++)
			if (str[i] > str[i + 1])
			{
				str.erase(i, 1);
				break;
			}
	}
	str.erase(str.size() - 1, 1);
	while (str[0] == '0') str.erase(0, 1);
	if (str != "")
		std::cout << str;
	else
		std::cout << 0;

	return 0;
}
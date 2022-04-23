#include <algorithm>
#include <cctype>
#include <cmath>
#include <cstdio>
#include <cstring>
#include <iostream>
#include <string>

const int dxFour[] = {-1, 0, 1, 0};
const int dyFour[] = {0, 1, 0, -1};

const int dxEight[] = {-1, 0, 1, 0, -1, -1, 1, 1};
const int dyEight[] = {0, 1, 0, -1, -1, 1, -1, 1};

const int dxHorse[] = {-2, -2, -1, -1, 1, 1, 2, 2};
const int dyHorse[] = {1, -1, 2, -2, 2, -2, 1, -1};

const int INF = 0x3f3f3f3f;
const double PI = std::acos(-1.0);
const double EPS = 1e-9;

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

#include <vector>
// #include <map>
// #include <unordered_map>
// #include <set>
// #include <queue>
// #include <deque
// #include <functional>
// #include <bitset>

const int MAX = 1e5 + 1;
int n, q;
struct node
{
	std::vector<int> pos, w;
} desk[MAX];

int main()
{
	// std::ios::sync_with_stdio(false);
	// std::cin.tie(nullptr), std::cout.tie(nullptr);

	n = read(), q = read();
	for (int i = 0; i < q; i++)
	{
		int f = read(), x = read(), y = read();
		if (f == 1)
		{
			int k = read();
			desk[x].pos.push_back(y), desk[x].w.push_back(k);
		}
		else
		{
			for (int j = desk[x].pos.size() - 1; ~j; j--)
				if (y == desk[x].pos[j])
				{
					write(desk[x].w[j]), putchar('\n');
					break;
				}
		}
	}

	return 0;
}
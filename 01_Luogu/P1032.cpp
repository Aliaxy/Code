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

// #include <vector>
#include <map>
// #include <unordered_map>
// #include <set>
#include <queue>
// #include <deque>
// #include <functional>
// #include <bitset>

std::string st[10], ed[10];
std::map<std::string, int> mp;
int n, ans;

struct node
{
	std::string str;
	int step;
};

inline std::string Replace(std::string str, int i, int j)
{
	std::string res = "";
	if (i + st[j].size() > str.size()) return res;
	for (int k = 0; k < st[j].size(); k++)
		if (str[i + k] != st[j][k])
			return res;
	res = str.substr(0, i);
	res += ed[j];
	res += str.substr(i + st[j].size());
	return res;
}

void BFS()
{
	std::queue<node> qu;
	node now = {st[0], 0};
	qu.push(now);
	while (!qu.empty())
	{
		now = qu.front();
		qu.pop();
		if (mp.count(now.str) == 1) continue;
		if (now.str == ed[0])
		{
			ans = now.step;
			return;
		}
		mp[now.str] = 1;
		int len = now.str.size();
		for (int i = 0; i < len; i++)
			for (int j = 1; j < n; j++)
			{
				std::string temp = Replace(now.str, i, j);
				if (temp != "") qu.push({temp, now.step + 1});
			}
	}
}

int main()
{
	// std::ios::sync_with_stdio(false);
	// std::cin.tie(nullptr), std::cout.tie(nullptr);
	std::cin >> st[0] >> ed[0];
	n = 1;
	while (std::cin >> st[n] >> ed[n]) n++;
	BFS();

	if (ans > 10 || !ans)
		std::cout << "NO ANSWER!";
	else
		write(ans);

	return 0;
}
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
// #include <deque>
// #include <functional>
// #include <bitset>W

int n;
char matrix[100][100], stand[] = "yizhong";
bool IsWord[100][100];
struct point
{
	int x, y;
};
std::vector<point> st;
int nowX, nowY;

void DFS(int x, int y, int path, int cur)
{
	if (cur == 6)
	{
		for (int i = 0; i < 7; i++) IsWord[nowX + i * dxEight[path]][nowY + i * dyEight[path]] = 1;
		return;
	}
	if (x >= n || y >= n || x < 0 || y < 0) return;
	int nextX = x + dxEight[path], nextY = y + dyEight[path];
	if (matrix[nextX][nextY] == stand[cur + 1]) DFS(nextX, nextY, path, cur + 1);
}

int main()
{
	// 	std::ios::sync_with_stdio(false);
	// 	std::cin.tie(nullptr), std::cout.tie(nullptr);

	n = read();
	for (int i = 0; i < n; i++)
		for (int j = 0; j < n; j++)
		{
			std::cin >> matrix[i][j];
			if (matrix[i][j] == 'y') st.push_back({i, j});
		}
	int sz = st.size();
	for (int i = 0; i < sz; i++)
	{
		nowX = st[i].x, nowY = st[i].y;
		for (int j = 0; j < 8; j++)
			if (matrix[nowX + dxEight[j]][nowY + dyEight[j]] == 'i')
				DFS(nowX, nowY, j, 0);
	}
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
			if (IsWord[i][j])
				putchar(matrix[i][j]);
			else
				putchar('*');
		putchar('\n');
	}

	return 0;
}
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

// #include <vector>
// #include <map>
// #include <unordered_map>
// #include <set>
// #include <queue>
// #include <deque>
// #include <functional>
// #include <bitset>

const int MAX = 1e5 + 1;

struct node
{
	int id;
	node *front = NULL, *back = NULL;
} qu[MAX];
node *head = &qu[1];
bool inQueue[MAX];

void AddQueue(int num, int id, bool back)
{
	node *find = &qu[id], *add = &qu[num];
	if (back)
	{
		add->front = find;
		add->back = find->back;
		find->back = add;
		find = find->back->back;
		find->front = add;
		return;
	}
	add->back = find;
	add->front = find->front;
	find = find->front;
	find->back = add;
	find = find->back->back;
	find->front = add;
	if (id == head->id) head = add;
}

void CutQueue(int id)
{
	node *cut = &qu[id];
	if (cut->id == head->id) head = cut->back;
	cut = cut->front;
	cut->back = cut->back->back;
	cut = cut->back;
	cut->front = cut->front->front;
}

int main()
{
	// std::ios::sync_with_stdio(false);
	// std::cin.tie(nullptr), std::cout.tie(nullptr);

	int n = read();
	for (int i = 1; i <= n; i++) qu[i].id = i;
	qu[1].back = &qu[1], qu[1].front = &qu[1], inQueue[1] = true;
	for (int i = 2; i <= n; i++)
	{
		inQueue[i] = true;
		int a = read(), b = read();
		AddQueue(i, a, b);
	}
	n = read();
	for (int i = 0; i < n; i++)
	{
		int a = read();
		if (inQueue[a])
		{
			inQueue[a] = false;
			CutQueue(a);
		}
	}
	int now = head->id;
	do
	{
		write(head->id), putchar(' ');
		head = head->back;
	} while (now != head->id);

	return 0;
}
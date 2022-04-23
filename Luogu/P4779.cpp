#include <iostream>
#include <cstring>
#include <queue>

const int MAX = 1e5 + 1;
const int INF = 0x3f3f3f3f;

int PointNum, EdgeNum, Start, cnt,
	Head[MAX], Visit[MAX], Dij[MAX];

struct edge
{
	int To,
		Dis,
		Next;
} Edge[MAX << 1];

struct node
{
	int id,
		dis;
	friend bool operator<(node a, node b)
	{
		return a.dis > b.dis;
	}
};

void Add(int u, int v, int w)
{
	Edge[++cnt].To = v;
	Edge[cnt].Dis = w;
	Edge[cnt].Next = Head[u];
	Head[u] = cnt;
}

void Dijkstra()
{
	std::priority_queue<node> qu;
	for (int i = 1; i <= PointNum; i++)
		Dij[i] = INF;
	node Current;
	Current.id = Start;
	Current.dis = 0;
	qu.push(Current);
	Dij[Start] = 0;
	while (!qu.empty())
	{
		Current = qu.top();
		qu.pop();
		if (Visit[Current.id])
			continue;
		Visit[Current.id] = 1;
		for (int i = Head[Current.id]; i; i = Edge[i].Next)
		{
			int j = Edge[i].To;
			if (Dij[Current.id] + Edge[i].Dis < Dij[j])
			{
				Dij[j] = Dij[Current.id] + Edge[i].Dis;
				qu.push(node{j, Dij[j]});
			}
		}
	}
}

int main()
{
	std::ios::sync_with_stdio(false);
	std::cin.tie(nullptr);
	std::cin >> PointNum >> EdgeNum >> Start;
	int u, v, w;
	for (int i = 0; i < EdgeNum; i++)
	{
		std::cin >> u >> v >> w;
		Add(u, v, w);
	}
	Dijkstra();
	for (int i = 1; i < PointNum; i++)
		std::cout << Dij[i] << ' ';
	std::cout << Dij[PointNum] << '\n';
	return 0;
}
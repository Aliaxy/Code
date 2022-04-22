#include <iostream>
#include <algorithm>

const int MAX = 2e5 + 1;

int StudentNum, OperateNum, Score[MAX],
	x, y;

struct SegTreeNode
{
	int Score,
		Lazy,
		Max;
} SegTree[MAX << 2];

void Build(int root, int left, int right)
{
	SegTree[root].Lazy = 0;
	SegTree[root].Max = -1;
	if (left == right)
	{
		SegTree[root].Score = SegTree[root].Max = Score[left];
		return;
	}
	int mid = (left + right) / 2;
	Build(root << 1, left, mid);
	Build(root << 1 | 1, mid + 1, right);
	SegTree[root].Score = SegTree[root << 1].Score + SegTree[root << 1 | 1].Score;
	SegTree[root].Max = std::max(SegTree[root << 1].Max, SegTree[root << 1 | 1].Max);
}

void Update(int root, int l, int r)
{
	if (l == r)
	{
		SegTree[root].Score = SegTree[root].Max = y;
		return;
	}
	int mid = (l + r) >> 1;
	if (x <= mid)
		Update(root << 1, l, mid);
	else
		Update(root << 1 | 1, mid + 1, r);
	SegTree[root].Score = SegTree[root << 1].Score + SegTree[root << 1 | 1].Score;
	SegTree[root].Max = std::max(SegTree[root << 1].Max, SegTree[root << 1 | 1].Max);
}

int Query(int root, int l, int r)
{
	if (x <= l && y >= r)
		return SegTree[root].Max;
	if (x > r || y < l)
		return 0;
	int mid = (l + r) >> 1;
	return std::max(Query(root << 1, l, mid), Query(root << 1 | 1, mid + 1, r));
}

int main()
{
	std::ios::sync_with_stdio(false);
	std::cin.tie(nullptr);
	while (std::cin >> StudentNum >> OperateNum)
	{
		for (int i = 1; i <= StudentNum; i++)
			std::cin >> Score[i];
		Build(1, 1, StudentNum);
		char Type;
		while (OperateNum--)
		{
			std::cin >> Type >> x >> y;
			if (Type == 'Q')
				std::cout << Query(1, 1, StudentNum) << '\n';
			else if (Type == 'U' && Score[x] < y)
			{
				Score[x] = y;
				Update(1, 1, StudentNum);
			}
		}
	}

	return 0;
}
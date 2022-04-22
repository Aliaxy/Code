#include <iostream>

const int MAX = 1e5 + 1;

int Num, OperateNum, a[MAX];
struct Node
{
	int left,
		right,
		Range;
	long long Val,
		Lazy;

} SegTree[MAX << 2];

void Build(int root, int left, int right)
{
	SegTree[root].left = left;
	SegTree[root].right = right;
	SegTree[root].Range = right - left + 1;
	SegTree[root].Lazy = 0;
	if (left == right)
	{
		SegTree[root].Val = a[left];
		return;
	}
	int mid = (left + right) >> 1;
	Build(root << 1, left, mid);
	Build(root << 1 | 1, mid + 1, right);
	SegTree[root].Val = SegTree[root << 1].Val + SegTree[root << 1 | 1].Val;
}

void PushDown(long long root)
{
	if (SegTree[root].Lazy)
	{
		SegTree[root << 1].Lazy += SegTree[root].Lazy;
		SegTree[root << 1 | 1].Lazy += SegTree[root].Lazy;
		SegTree[root << 1].Val += SegTree[root].Lazy * SegTree[root << 1].Range;
		SegTree[root << 1 | 1].Val += SegTree[root].Lazy * SegTree[root << 1 | 1].Range;
		SegTree[root].Lazy = 0;
	}
}

void Update(int root, int left, int right, int vary)
{
	if (left <= SegTree[root].left && right >= SegTree[root].right)
	{
		SegTree[root].Val += (long long)vary * SegTree[root].Range;
		SegTree[root].Lazy += vary;
		return;
	}
	PushDown(root);
	int mid = (SegTree[root].left + SegTree[root].right) >> 1;
	if (left <= mid)
		Update(root << 1, left, right, vary);
	if (right > mid)
		Update(root << 1 | 1, left, right, vary);
	SegTree[root].Val = SegTree[root << 1].Val + SegTree[root << 1 | 1].Val;
}

long long Query(int root, int left, int right)
{
	if (left <= SegTree[root].left && right >= SegTree[root].right)
		return SegTree[root].Val;
	if (left > SegTree[root].right || right < SegTree[root].left)
		return 0;
	PushDown(root);
	int mid = (SegTree[root].left + SegTree[root].right) >> 1;
	return Query(root << 1, left, right) + Query(root << 1 | 1, left, right);
}

int main()
{
	std::ios::sync_with_stdio(false);
	std::cin.tie(nullptr);
	std::cin >> Num >> OperateNum;
	for (int i = 1; i <= Num; i++)
		std::cin >> a[i];
	Build(1, 1, Num);
	while (OperateNum--)
	{
		int flag, x, y;
		std::cin >> flag >> x >> y;
		if (flag == 1)
		{
			int vary;
			std::cin >> vary;
			Update(1, x, y, vary);
		}
		else
		{
			std::cout << Query(1, x, y) << '\n';
		}
	}

	return 0;
}
#include <iostream>

const int MAX = 1e5 + 1;

int Num, OperateNum, Mod, a[MAX];
struct Node
{
	int Left,
		Right,
		Range;
	long long Val,
		Add,
		Mul;
} SegTree[MAX << 2];

void Build(int root, int left, int right)
{
	SegTree[root].Left = left;
	SegTree[root].Right = right;
	SegTree[root].Add = 0;
	SegTree[root].Mul = 1;
	SegTree[root].Range = right - left + 1;
	if (left == right)
	{
		SegTree[root].Val = a[left];
		return;
	}
	int mid = left + right >> 1;
	Build(root << 1, left, mid);
	Build(root << 1 | 1, mid + 1, right);
	SegTree[root].Val = (SegTree[root << 1].Val + SegTree[root << 1 | 1].Val) % Mod;
}

void PushDown(int root)
{
	SegTree[root << 1].Val = (SegTree[root << 1].Val * SegTree[root].Mul + SegTree[root].Add * SegTree[root << 1].Range) % Mod;
	SegTree[root << 1 | 1].Val = (SegTree[root << 1 | 1].Val * SegTree[root].Mul + SegTree[root].Add * SegTree[root << 1 | 1].Range) % Mod;

	SegTree[root << 1].Mul = (SegTree[root << 1].Mul * SegTree[root].Mul) % Mod;
	SegTree[root << 1 | 1].Mul = (SegTree[root << 1 | 1].Mul * SegTree[root].Mul) % Mod;
	SegTree[root << 1].Add = (SegTree[root << 1].Add * SegTree[root].Mul + SegTree[root].Add) % Mod;
	SegTree[root << 1 | 1].Add = (SegTree[root << 1 | 1].Add * SegTree[root].Mul + SegTree[root].Add) % Mod;
	SegTree[root].Add = 0;
	SegTree[root].Mul = 1;
}

void Update(int root, int left, int right, long long vary, int flag)
{
	if (left <= SegTree[root].Left && right >= SegTree[root].Right)
	{
		if (flag == 1)
		{
			SegTree[root].Val = (SegTree[root].Val * vary) % Mod;
			SegTree[root].Mul = (SegTree[root].Mul * vary) % Mod;
			SegTree[root].Add = (SegTree[root].Add * vary) % Mod;
			return;
		}
		else
		{
			SegTree[root].Val = (SegTree[root].Val + vary * SegTree[root].Range) % Mod;
			SegTree[root].Add = (SegTree[root].Add + vary) % Mod;
			return;
		}
	}
	PushDown(root);
	int mid = SegTree[root].Left + SegTree[root].Right >> 1;
	if (left <= mid)
		Update(root << 1, left, right, vary, flag);
	if (right > mid)
		Update(root << 1 | 1, left, right, vary, flag);
	SegTree[root].Val = (SegTree[root << 1].Val + SegTree[root << 1 | 1].Val) % Mod;
}

long long Query(int root, int left, int right)
{
	if (left <= SegTree[root].Left && right >= SegTree[root].Right)
		return SegTree[root].Val;
	if (left > SegTree[root].Right || right < SegTree[root].Left)
		return 0;
	PushDown(root);
	int mid = SegTree[root].Left + SegTree[root].Right >> 1;
	return (Query(root << 1, left, right) + Query(root << 1 | 1, left, right)) % Mod;
}

int main()
{
	std::ios::sync_with_stdio(false);
	std::cin.tie(nullptr);
	std::cin >> Num >> OperateNum >> Mod;
	for (int i = 1; i <= Num; i++)
		std::cin >> a[i];
	Build(1, 1, Num);
	while (OperateNum--)
	{
		int s, a, b;
		long long x;
		std::cin >> s >> a >> b;
		if (s == 3)
		{
			std::cout << Query(1, a, b) % Mod << '\n';
		}
		else
		{
			std::cin >> x;
			Update(1, a, b, x, s);
		}
	}

	return 0;
}
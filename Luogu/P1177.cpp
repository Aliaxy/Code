#include <iostream>
#include <utility>

const int MAX = 1e6 + 1;

int Num[MAX];

void quick_sort(int l, int r)
{
	int mid = Num[l + r >> 1];
	int i = l, j = r;
	while (i <= j)
	{
		while (Num[i] < mid)
			i++;
		while (Num[j] > mid)
			j--;
		if (i <= j)
		{
			std::swap(Num[i], Num[j]);
			i++;
			j--;
		}
	}
	if (l < j)
		quick_sort(l, j);
	if (i < r)
		quick_sort(i, r);
}

int main()
{
	std::ios::sync_with_stdio(false);
	std::cin.tie(nullptr);

	int n;
	std::cin >> n;
	for (int i = 1; i <= n; i++)
		std::cin >> Num[i];
	quick_sort(1, n);
	for (int i = 1; i <= n; i++)
		std::cout << Num[i] << ' ';

	return 0;
}
#include <iostream>
#include <utility>

const int MAX = 5e6 + 1;

int Num[MAX], k;

void qsort(int l, int r)
{
	int i = l, j = r, mid = Num[l + r >> 1];
	do
	{
		while (Num[j] > mid)
			j--;
		while (Num[i] < mid)
			i++;
		if (i <= j)
		{
			std::swap(Num[i], Num[j]);
			i++;
			j--;
		}
	} while (i <= j);

	if (k <= j)
		qsort(l, j);
	else if (i <= k)
		qsort(i, r);
	else
	{
		printf("%d", Num[j + 1]);
		exit(0);
	}
}

int main()
{
	std::ios::sync_with_stdio(false);
	std::cin.tie(nullptr);
	int n;
	std::cin >> n >> k;
	for (int i = 0; i < n; i++)
		std::cin >> Num[i];
	qsort(0, n - 1);
}
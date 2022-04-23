#include <iostream>
#include <cstdio>

int cnt, tot, n, k, SumA, SumB;

int main()
{
	std::cin >> n >> k;
	for (int i = 1; i <= n; i++)
	{
		if (i % k)
		{
			SumA += i;
			cnt++;
		}
		else
		{
			SumB += i;
			tot++;
		}
	}
	printf("%.1f %.1f\n", (double)SumB / tot, (double)SumA / cnt);

	return 0;
}